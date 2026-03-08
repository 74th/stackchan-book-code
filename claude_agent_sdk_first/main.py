from claude_agent_sdk import (
    ClaudeSDKClient,
    ClaudeAgentOptions,
)
import asyncio

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
)


async def main():
    async with ClaudeSDKClient(options=agent_option) as client:
        await client.query("東京から金沢市にはどうやって行けばいい")
        async for message in client.receive_response():
            print(message)


if __name__ == "__main__":
    asyncio.run(main())
