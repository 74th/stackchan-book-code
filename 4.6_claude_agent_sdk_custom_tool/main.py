import asyncio
from typing import Any, Literal

from claude_agent_sdk import (
    ClaudeAgentOptions,
    ClaudeSDKClient,
    create_sdk_mcp_server,
    tool,
)
from pydantic import BaseModel


# ツールの作成の引数
class AirConRemoteInput(BaseModel):
    room: Literal["寝室", "リビング"]
    state: Literal["オフ", "暖房オン", "冷房オン"]


# ツールの関数定義
@tool(
    "aircon-control",
    "自宅のエアコンを操作する。寝室かリビングかを指定する。",
    AirConRemoteInput.model_json_schema(),
)
async def aircon_remote(dict_args: dict[str, Any]):
    args = AirConRemoteInput.model_validate(dict_args)
    print(f"🌳エアコンを操作します {args}")
    return {"state": "success"}


# MCPサーバ化
home_remote_mcp = create_sdk_mcp_server(
    name="home-remote",
    version="1.0.0",
    tools=[aircon_remote],
)

prompt = """
あなたは音声AIアシスタントのスタックチャンです。
ユーザの質問に対して、3文程度の言葉で答えてください。
音声案内であるため、マークダウンや絵文字等は用いずに、文字列だけで回答してください
"""

agent_option = ClaudeAgentOptions(
    model="claude-haiku-4-5-20251001",
    system_prompt=prompt,
    cwd="./workspace",
    setting_sources=["project"],
    mcp_servers={"home-remote": home_remote_mcp},
    permission_mode="bypassPermissions",
)


async def main():
    async with ClaudeSDKClient(options=agent_option) as client:
        await client.query("リビングのエアコンを暖房にして")
        async for message in client.receive_response():
            print(message)


if __name__ == "__main__":
    asyncio.run(main())
