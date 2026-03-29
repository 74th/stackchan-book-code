import struct
import wave
from datetime import datetime
from logging import StreamHandler, getLogger
from pathlib import Path

from fastapi import FastAPI, HTTPException, Request, WebSocket, WebSocketDisconnect

logger = getLogger(__name__)
logger.setLevel("INFO")

app = FastAPI(title="websocket server example")

@app.get("/health")
async def health() -> dict[str, str]:
    return {"status": "ok"}

@app.get("/")
async def root() -> dict[str, str]:
    return {"status": "ok"}


@app.websocket("/ws/stackchan")
async def websocket_audio(ws: WebSocket):
    logger.info("WebSocket connection established")
    await ws.accept()
    logger.info("WebSocket connection accepted")
    try:
        pass
    except WebSocketDisconnect:
        return


def main() -> None:
    import uvicorn

    uvicorn.run("server:app", host="0.0.0.0", port=8002, reload=True)


if __name__ == "__main__":
    main()
