import asyncio
import os
from typing import Any, Literal

import aiohttp
from claude_agent_sdk import (
    ClaudeAgentOptions,
    ClaudeSDKClient,
    create_sdk_mcp_server,
    tool,
)
from pydantic import BaseModel

NATURE_REMO_CLOUD_API_TOKEN = os.getenv("NATURE_REMO_CLOUD_API_TOKEN")
NATURE_REMO_LIVING_AIRCON_APPLIANCE_ID_DICT = {
    "リビング": os.getenv("NATURE_REMO_LIVING_AIRCON_APPLIANCE_ID"),
    "寝室": os.getenv("NATURE_REMO_BEDROOM_AIRCON_APPLIANCE_ID"),
}

# ツールの作成の引数
class AirConRemoteInput(BaseModel):
    room: Literal["寝室", "リビング"]
    state: Literal["オフ", "暖房オン", "冷房オン"]
    temperature: int | None = None


# ツールの関数定義
@tool(
    "aircon-control",
    "自宅のエアコンを操作する。寝室かリビングかを指定する。温度指定がない場合、temperatureにはnullを指定すること。",
    AirConRemoteInput.model_json_schema(),
)
async def aircon_remote(dict_args: dict[str, Any]):
    args = AirConRemoteInput.model_validate(dict_args)
    appliance_id = NATURE_REMO_LIVING_AIRCON_APPLIANCE_ID_DICT[args.room]
    print(f"エアコン操作ツールが呼び出されました。部屋: {args.room}, 状態: {args.state}, appliance_id: {appliance_id}")

    if args.state == "オフ":
        payload = {
            "air_direction": "",
            "air_direction_h": "",
            "air_volume": "",
            "button": "power-off",
            "operation_mode": "",
            "temperature": "",
            "temperature_unit": ""
        }
    elif args.state == "暖房オン":
        payload = {
            "operation_mode": "warm",
            "air_direction": "still",
            "air_direction_h": "",
            "air_volume": "auto",
            "button": "",
            "temperature": str(args.temperature) if args.temperature is not None else "23",
            "temperature_unit": "c"
        }
    elif args.state == "冷房オン":
        payload = {
            "operation_mode": "cool",
            "air_direction": "still",
            "air_direction_h": "",
            "air_volume": "auto",
            "button": "",
            "temperature": str(args.temperature) if args.temperature is not None else "18",
            "temperature_unit": "c"
        }
    else:
        raise ValueError("Invalid state")
    print(f"Payload: {payload}")

    async with aiohttp.ClientSession() as session:
        headers = {"Authorization": f"Bearer {NATURE_REMO_CLOUD_API_TOKEN}"}
        async with session.post(f"https://api.nature.global/2/appliances/{appliance_id}/aircon_settings", headers=headers, data=payload) as response:
            if  response.status != 200:
                response_text = await response.text()
                raise Exception(f"API request failed with status code {response.status}, response: {response_text}")
            return await response.json()

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
    model="claude-haiku-4-5@20251001",
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
