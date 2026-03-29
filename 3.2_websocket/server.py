import asyncio
import logging
import struct

from fastapi import FastAPI, WebSocket, WebSocketDisconnect

# Uvicornの標準ロガーを使うと、uvicorn起動時の出力設定にそのまま乗る
logger = logging.getLogger("uvicorn.error")

# ヘッダー形式
# struct __attribute__((packed)) WsHeader
# {
#     uint8_t kind;          // 種類
#     uint8_t messageType;   // メッセージタイプ
#     uint8_t reserved;      // 0 (flags/reserved)
#     uint16_t seq;          // シーケンス番号
#     uint16_t payloadBytes; // ヘッダーに続くバイト数
# };
_WS_HEADER_FMT = "<BBBHH"
_WS_HEADER_SIZE = struct.calcsize(_WS_HEADER_FMT)

app = FastAPI(title="websocket server example")


@app.get("/health")
async def health() -> dict[str, str]:
    return {"status": "ok"}


@app.get("/")
async def root() -> dict[str, str]:
    return {"status": "ok"}


@app.websocket("/ws/stackchan")
async def websocket_audio(ws: WebSocket):
    async def send_loop() -> None:
        state_no = 0

        while True:
            try:
                await ws.send_text("Hello, StackChan!")

                await asyncio.sleep(1)

                # バイナリメッセージ
                b = struct.pack(
                    _WS_HEADER_FMT,
                    0x03,  # 種類
                    0x00,  # メッセージタイプ
                    0x00,  # 0 (flags/reserved)
                    0x00,  # シーケンス番号
                    0x01,  # ヘッダーに続くバイト数
                )
                b += bytes([state_no % 256])  # ペイロード（1バイト）
                await ws.send_bytes(b)

                await asyncio.sleep(1)

                state_no += 1
            except (WebSocketDisconnect, RuntimeError):
                return

    async def receive_loop() -> None:
        while True:
            try:
                b = await ws.receive_bytes()

                header_b = b[:_WS_HEADER_SIZE]
                payload_b = b[_WS_HEADER_SIZE:]

                # ヘッダーをパースしてログに出す
                kind, message_type, flags_reserved, seq, payload_bytes = struct.unpack(
                    _WS_HEADER_FMT, header_b)
                logger.info(f"Received message: kind={kind}, message_type={message_type}, flags_reserved={flags_reserved}, seq={seq}, payload_bytes={payload_bytes}, payload={payload_b}")
            except (WebSocketDisconnect, RuntimeError):
                return

    logger.info("WebSocket connection established")
    await ws.accept()
    logger.info("WebSocket connection accepted")

    # 送受信ともループを回す
    send_loop_task = asyncio.create_task(send_loop())
    receive_loop_task = asyncio.create_task(receive_loop())
    await send_loop_task
    await receive_loop_task


def main() -> None:
    import uvicorn

    uvicorn.run("server:app", host="0.0.0.0", port=8002, reload=True)


if __name__ == "__main__":
    main()
