#include <ssid.hpp>
#include <WiFi.h>
#include <M5Unified.h>
#include <WebSocketsClient.h>

// クライアントオブジェクト
static WebSocketsClient wsClient;

const char *WIFI_SSID = WIFI_SSID_H;
const char *WIFI_PASS = WIFI_PASSWORD_H;
const char *SERVER_HOST = SERVER_HOST_H; // サーバのIP
const int SERVER_PORT = SERVER_PORT_H;   // WebSocketのポート
const char *SERVER_PATH = SERVER_PATH_H; // WebSocketのパス

enum class MessageKind : uint8_t
{
    AudioPcm = 1,     // クライアントマイク音声
    AudioWav = 2,     // クライアントスピーカー
    StateCmd = 3,     // クライアントのステート変更コマンド
    WakeWordEvt = 4,  // ウェイクアップワード検出
    StateEvt = 5,     // クライアントのステート変更イベント
    SpeakDoneEvt = 6, // クライアントの発話完了イベント
};

// ストリーミング転送時のSTART/END命令
enum class MessageType : uint8_t
{
    START = 1,
    DATA = 2,
    END = 3,
};

struct __attribute__((packed)) WsHeader
{
    uint8_t kind;          // 種類
    uint8_t messageType;   // メッセージタイプ
    uint8_t reserved;      // 0 (flags/reserved)
    uint16_t seq;          // シーケンス番号
    uint16_t payloadBytes; // ヘッダーに続くバイト数
};

void handleWsEvent(WStype_t type, uint8_t *payload, size_t length)
{
    switch (type)
    {
    case WStype_DISCONNECTED:
        // 切断された
        M5.Display.clear();
        M5.Display.setCursor(0, 0);
        M5.Display.println("WebSocket Disconnected!");
        log_i("WebSocket Disconnected!");
        break;
    case WStype_CONNECTED:
        // 接続が成功した
        M5.Display.clear();
        M5.Display.setCursor(0, 0);
        M5.Display.println("WebSocket Connected!");
        log_i("WebSocket Connected!");
        break;
    case WStype_TEXT:
        // テキストメッセージが届いた
        // payloadにテキストデータが入っている
        // 切断された
        M5.Display.clear();
        M5.Display.setCursor(0, 0);
        M5.Display.println("Text Message Received!");
        M5.Display.println((char *)payload);
        log_i("Text Message Received!");
        log_i("Text Message: %s", (char *)payload);
        break;
    case WStype_BIN:
        // バイナリメッセージが届いた
        // payloadにバイナリデータが入っている
        WsHeader rx{};
        memcpy(&rx, payload, sizeof(WsHeader));
        size_t rx_payload_len = length - sizeof(WsHeader);

        const uint8_t *body = payload + sizeof(WsHeader);
        log_i("WS bin kind=%u len=%d", (unsigned)rx.kind, (int)length);

        // kindに応じてそれぞれのモジュールを呼び出す
        switch (static_cast<MessageKind>(rx.kind))
        {
        case MessageKind::AudioWav:
            // スピーカー再生
            // 略
            break;
        case MessageKind::StateCmd:
            // 状態変更
            // 略
            M5.Display.clear();
            M5.Display.setCursor(0, 0);
            M5.Display.println("State Command Received!");
            M5.Display.printf("State: %d\n", body[0]);
            log_i("State Command Received!");
            log_i("State: %d", body[0]);
            break;
        default:
            break;
        }
    }
}

void connectWiFi()
{
    // アクセスポイントへ接続するモード
    WiFi.mode(WIFI_STA);
    // WiFiに接続
    WiFi.begin(WIFI_SSID, WIFI_PASS);
    while (WiFi.status() != WL_CONNECTED)
    {
        // 接続完了まで待機
        delay(300);
    }

    log_i("WiFi connected! IP address: %s", WiFi.localIP().toString().c_str());
}

void setup()
{
    M5.begin();

    log_i("Connecting to WiFi...");
    connectWiFi();

    log_i("Connected to WiFi!");

    log_i("Connecting to WebSocket server...");

    // 接続開始
    wsClient.begin(SERVER_HOST, SERVER_PORT, SERVER_PATH);
    log_i("connecting to %s:%d%s", SERVER_HOST, SERVER_PORT, SERVER_PATH);
    // ハンドラの登録
    wsClient.onEvent(handleWsEvent);
    // 自動再接続周期
    wsClient.setReconnectInterval(2000);
    // 接続が生きているかチェックされる周期
    // 引数1: 送信するpingの周期
    // 引数2: pongが返ってこないときに切断するまでの時間
    // 引数3: pongが返ってこないときに切断するまでの回数
    wsClient.enableHeartbeat(15000, 3000, 2);
}

void loop()
{
    M5.update();

    if (wsClient.isConnected())
    {
        log_i("WebSocket is connected");
    }
    else
    {
        log_i("WebSocket is not connected");
    }

    delay(500);
}
