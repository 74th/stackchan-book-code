import asyncio
import json
import os

import aiohttp

TOKEN = os.getenv("NATURE_REMO_CLOUD_API_TOKEN")

if not TOKEN:
    raise ValueError("環境変数 NATURE_REMO_CLOUD_API_TOKEN が設定されていません。")

# 機器リスト取得
async def get_appliances():
    async with aiohttp.ClientSession() as session:
        headers = {"Authorization": f"Bearer {TOKEN}"}
        async with session.get("https://api.nature.global/1/appliances", headers=headers) as response:
            return await response.json()

async def main():
    appliances = await get_appliances()
    print(json.dumps(appliances, indent=2))

if __name__ == "__main__":
    asyncio.run(main())
