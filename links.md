# まえがき

## サンプルコードと、本文中のリンク先

> https://github.com/74th/stackchan-book-code

> https://github.com/74th/stackchan-book-code/blob/main/links.md

# 1. ｽﾀｯｸﾁｬﾝの基礎知識と組み立て方

## 1.1. ｽﾀｯｸﾁｬﾝとは

> ｽﾀｯｸﾁｬﾝ（Stack-chan） | ProtoPedia<br/>https://protopedia.net/prototype/2345

> stack-chan/stack-chan: A JavaScript-driven M5Stack-embedded super-kawaii robot.<br/>https://github.com/stack-chan/stack-chan

## 1.2. ｽﾀｯｸﾁｬﾝの主な部品

### サーボモータ

> マイクロサーボ9g SG-90: 制御部品・駆動部品 秋月電子通商-電子部品・ネット通販<br/>https://akizukidenshi.com/catalog/g/g108761/

#### ししかわさん製作の原典のｽﾀｯｸﾁｬﾝ

> https://github.com/stack-chan/stack-chan/tree/dev/v1.0/case

> https://github.com/stack-chan/stack-chan/tree/dev/v1.0/schematics

> https://github.com/74th/stackchan-book.git

#### タカヲさん製作のｽﾀｯｸﾁｬﾝケースを利用する

> M5Stack CoreS3用バッテリーボトム — スイッチサイエンス<br/>https://www.switch-science.com/products/9421

> https://github.com/mongonta0716/3DPrinter_Models

> Arpeggio Factory - BOOTH<br/>https://mongonta.booth.pm/

> SG90用<br/>https://github.com/akita11/Stack-chan_Takao_Base

> SCS0009用<br/>https://github.com/akita11/Stack-chan_Takao_Base_SCS0009

> Stack-chan_Takao_Base（完成品） — スイッチサイエンス<br/>https://www.switch-science.com/products/8905?srsltid=AfmBOooEdyxzos8dJEO0sTrcJS4lOOe49Zeag5PuIKCvxcufYfWA7XcL

> Stack-chan_TakaoBase_SCS0009（完成品） — スイッチサイエンス<br/>https://www.switch-science.com/products/9288?_pos=4&_sid=786cb8bae&_ss=r

## 1.3. ｽﾀｯｸﾁｬﾝのファームウェア

### ししかわさん製作の原典のｽﾀｯｸﾁｬﾝ

> stack-chan/stack-chan: A JavaScript-driven M5Stack-embedded super-kawaii robot.<br/>https://github.com/stack-chan/stack-chan

> https://github.com/stack-chan/stack-chan/blob/dev/v1.0/firmware/README_ja.md

### AIｽﾀｯｸﾁｬﾝ

> robo8080/AI_StackChan2: AI_StackChan2<br/>https://github.com/robo8080/AI_StackChan2

> ronron-gh/AI_StackChan_Ex<br/>https://github.com/ronron-gh/AI_StackChan_Ex

## 1.5. 自分で接続ボードとケースを製造する方法

### PCBの発注方法

> https://github.com/akita11/Stack-chan_Takao_Base

> JLCPCB<br/>https://jlcpcb.com/jp/

### 3Dプリントケースを自宅で印刷、もしくは発注する方法

> Bambu Lab A1 mini 3D Printer<br/>https://jp.store.bambulab.com/products/a1-mini

## 1.6. ケースと接続部品以外に必要な部品

### M5StackコアシリーズとM5GO Bottom3

> M5Stack CoreS3 SE — スイッチサイエンス<br/>https://www.switch-science.com/products/9690

> M5Stack CoreS3用バッテリーボトム — スイッチサイエンス<br/>https://www.switch-science.com/products/9421

> M5Stack Official Store<br/>https://m5stack.ja.aliexpress.com/store/911661199

#### サーボモータ

> マイクロサーボ9g SG-90: 制御部品・駆動部品 秋月電子通商-電子部品・ネット通販<br/>https://akizukidenshi.com/catalog/g/g108761/

### ケーブル

> M5Stack用GROVE互換ケーブル 10 cm（5本セット）[A034] — スイッチサイエンス<br/>https://www.switch-science.com/products/5213?_pos=24&_sid=fa9928272&_ss=r

> コネクター付コード 4P 黒赤白黄 Grove用ケーブル: ケーブル・コネクター 秋月電子通商-電子部品・ネット通販<br/>https://akizukidenshi.com/catalog/g/g116938/

## 1.7. タカヲさん製作ケースでの組み立て方

> ｽﾀｯｸﾁｬﾝ タカオ版 組み立て方法【分解あり】【その2 ケースセットの組み立てと完成まで】 | M5Stack沼人の日記<br/>https://raspberrypi.mongonta.com/how-to-make-stackchan-m5gobottom-2/

#### 接続ボードとサーボの動作チェック

> mongonta0716/stack-chan-tester: stack-chan test application for pwm servo<br/>https://github.com/mongonta0716/stack-chan-tester

## 1.9. その他

### コアシリーズ以外を使ったｽﾀｯｸﾁｬﾝ

> https://github.com/A-Uta/AI_StackChan_Minimal

## まとめ

# 2. 筆者のAIｽﾀｯｸﾁｬﾝ製作アーキテクチャ

## 2.3. 今回作成したファームウェアとサーバのフレームワーク

> StackChan WebSocket Control Server<br/>https://github.com/74th/websocket-control-stackchan

> websocket-control-stackchan/docs/setup_ja.md at main · 74th/websocket-control-stackchan<br/>https://github.com/74th/websocket-control-stackchan/blob/main/docs/setup_ja.md

# 3. ファームウェア開発

## 3.1. PlatformIO

### PlatformIOのプロジェクトの作成

> 3110/m5stack-platformio-boilerplate-code: PlatformIO IDE 向け M5Stack 定型コード環境 / Boilerplate Code for M5Stack in PlatformIO IDE Environment<br/>https://github.com/3110/m5stack-platformio-boilerplate-code

```ini
# platformio.ini

; 以下のコメントアウトを外す
[env:m5stack-cores3-m5unified]
extends = m5stack-cores3, m5unified, build-target
build_flags =
	${m5stack-cores3.build_flags}
	${m5unified.build_flags}
	${build-target.build_flags}
lib_deps =
	${m5stack-cores3.lib_deps}
	${m5unified.lib_deps}
```

```ini
# platformio.ini

[platformio]
; default_envs = m5stack-core2-m5unified
; default_envs = m5stack-cores3
default_envs = m5stack-cores3-m5unified
; default_envs = m5stick-c
```

```ini
# platformio-m5stack.ini

[esp32s3]
extends = platform-pioarduino ; 追加
board_build.mcu = esp32s3
```

### PlatformIOでのCoreS3への書き込み

```ini
# platformio.ini

[env]
; windowsの場合の例
upload_port = COM16
; Linuxの場合の例
upload_port = /dev/ttyACM0
```

## 3.2. WebSocket通信

> Links2004/arduinoWebSockets: arduinoWebSockets<br/>https://github.com/Links2004/arduinoWebSockets

```ini
[env]
lib_deps =
		Links2004/WebSockets@^2.6.1
```

```cpp
#include <WiFi.h>

const char *WIFI_SSID = "hoge";
const char *WIFI_PASS = "hogehoge";

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
}

void setup() {
	connectWiFi();
}
```

```cpp
#include <WebSocketsClient.h>

void handleWsEvent(WStype_t type, uint8_t *payload, size_t length)
{
	switch (type)
	{
	case WStype_DISCONNECTED:
		// 切断された
		break;
	case WStype_CONNECTED:
		// 接続が成功した
		break;
	case WStype_TEXT:
		// テキストメッセージが届いた
		// payloadにテキストデータが入っている
		break;
	case WStype_BIN:
		// バイナリメッセージが届いた
		// payloadにバイナリデータが入っている
		break;
	default:
		break;
	}
}
```

```cpp
#include <WebSocketsClient.h>

const char *SERVER_HOST = "192.168.1.191"; // サーバのIP
const int SERVER_PORT = 8080;              // WebSocketのポート
const char *SERVER_PATH = "/ws/stackchan"; // WebSocketのパス

// クライアントオブジェクト
static WebSocketsClient wsClient;

void setup() {
	// 前略

	// 接続開始
	wsClient.begin(SERVER_HOST, SERVER_PORT, SERVER_PATH);
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
```

```cpp
void loop() {
	// WebSocketクライアントのループ処理
	wsClient.loop();
}
```

```cpp
enum class MessageKind : uint8_t
{
	AudioPcm = 1, // クライアントマイク音声
	AudioWav = 2, // クライアントスピーカー
	StateCmd = 3, // クライアントのステート変更コマンド
	WakeWordEvt = 4, // ウェイクアップワード検出
	StateEvt = 5, // クライアントのステート変更イベント
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
	uint8_t kind;        // 種類
	uint8_t messageType; // メッセージタイプ
	uint8_t reserved;    // 0 (flags/reserved)
	uint16_t seq;        // シーケンス番号
	uint16_t payloadBytes; // ヘッダーに続くバイト数
};
```

```cpp
void handleWsEvent(WStype_t type, uint8_t *payload, size_t length) {
	switch (type)
	{
	case WStype_BIN:
	{
		// ヘッダーの読み取り
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
			break;
		// 以下略
```

> https://github.com/74th/stackchan-book-code/tree/main/3.2_websocket

## 3.3. M5Unified

### M5Unifiedとは

> m5stack/M5Unified: Unified library for M5Stack series<br/>https://github.com/m5stack/M5Unified

### M5Unified利用の基本

```cpp
#include <M5Unified.h>

void setup() {
	M5.begin();
}

void loop() {
	M5.update();
}
```

### ディスプレイの描画

> M5GFX API<br/>https://docs.m5stack.com/ja/arduino/m5gfx/m5gfx_functions

#### 画面の塗りつぶし

```cpp
M5.Display.fillScreen(TFT_BLACK);
```

> M5GFX ライブラリ関連データ定義<br/>https://docs.m5stack.com/ja/arduino/m5gfx/m5gfx_appendix

#### テキストの描画

> Font List :: M5Stack Unofficial Guide<br/>https://m5stack.lang-ship.com/howto/m5gfx/font/

```cpp
// カーソルの位置を指定（左上が(0, 0)）
M5.Display.setCursor(10, 10);
// フォントを指定
M5.Display.setTextFont(&fonts::lgfxJapanGothic_16);
// フォントサイズを指定（フォントに対して倍率を指定）
M5.Display.setTextSize(1);
// 文字描画の背景色、文字色を指定
M5.Display.setTextColor(TFT_BLACK, TFT_BLUE);
// 文字を描画
M5.Display.printf("コマンド: %d,", command_id);
```

#### 図形の描画

```cpp
// 黒で塗りつぶし
M5.Display.fillScreen(TFT_BLACK);

uint32_t eye_y = 102;
uint32_t between_eyes = 135;
uint32_t eye_size = 8;
uint32_t mouth_y = 157;
uint32_t mouth_width = 85;
uint32_t mouth_height = 4;
// 目を円で描画
M5.Display.fillCircle(160 - between_eyes / 2, eye_y, eye_size, TFT_WHITE);
M5.Display.fillCircle(160 + between_eyes / 2, eye_y, eye_size, TFT_WHITE);
// 口を四角で描画
M5.Display.fillRect(160 - mouth_width / 2, mouth_y, mouth_width, mouth_height,
	TFT_WHITE);
```

#### PNG、JPGの描画

```ini
[env]
board_build.embed_files =
	data/74th_64x64.png
```

```cpp
// main.cpp

// ファイルバイナリの最初の位置のポインタ
extern const uint8_t _binary_data_74th_64x64_png_start[];
// ファイルバイナリの最後の位置のポインタ
extern const uint8_t _binary_data_74th_64x64_png_end[];
```

```cpp
// ポインタからファイルサイズを計算
const uint8_t* png_start = _binary_data_74th_64x64_png_start;
const uint8_t* png_end = _binary_data_74th_64x64_png_end;
const uint32_t png_size = static_cast<uint32_t>(png_end - png_start);

// PNG画像の描画
// 引数1: PNGファイルのバイナリの開始位置のポインタ
// 引数2: PNGファイルのバイナリのサイズ
// 引数3: 描画するx座標
// 引数4: 描画するy座標
M5.Display.drawPng(png_start, png_size, 128, 32);
```

```ini
[env]
board_build.filesystem = spiffs
```

```bash
pio run --target uploadfs
```

```cpp
#include <SPIFFS.h>
#include <M5Unified.h>
```

```cpp
void setup() {
	M5.begin();

	if (!SPIFFS.begin(true))
	{
		M5.Display.println("SPIFFS mount failed");
		while (1)
			delay(100);
	}
}
```

```cpp
M5.Display.fillScreen(TFT_BLACK);

// PNGファイルの描画
// 引数1: SPIFFSオブジェクト（ファイルシステムオブジェクト）
// 引数2: ファイルパス
// 引数3: 描画するx座標
// 引数4: 描画するy座標
M5.Display.drawPngFile(SPIFFS, "/74th_64x64.png", static_cast<int>(pos_x),
	static_cast<int>(pos_y));
```

#### スプライトの描画

```cpp
LGFX_Sprite hud(&M5.Display);
```

```cpp
// スプライトに描画を追加
hud.fillScreen(TFT_BLACK);
hud.drawPngFile(SPIFFS, "/74th_64x64.png", static_cast<int>(pos_x),
	static_cast<int>(pos_y));

// スプライトを画面に描画
hud.pushSprite(0, 0);
```

### マイク音声のストリーミング取得

```cpp
// 一度にrecord()関数で読み込むサンプル数
const size_t MIC_READ_SAMPLES = 256;
// 音声のサンプリングレート
const int SAMPLE_RATE = 16000; // 16kHz

void setup() {
	// マイクの稼働開始
	M5.Mic.begin();
}

void loop() {
	M5.update();
	// バッファ
	static int16_t mic_buf[MIC_READ_SAMPLES];
	if (M5.Mic.record(mic_buf, MIC_READ_SAMPLES, SAMPLE_RATE)) {
		// バッファに書き込めた
	}
}
```

### スピーカーでストリーミング音声出力

```cpp
const int SAMPLE_RATE = 24000; // 24kHz

//　音声データのバッファ
std::vector<uint8_t> buf;

void setup() {
	// スピーカーの稼働開始
	M5.Speaker.begin();
	// buf
}

void loop() {
	M5.update();

	// ここにbufに音声データを入れる処理

	// 8bit配列を、16bitに置き換えて、スピーカーに渡す
	const int16_t *samples = reinterpret_cast<const int16_t *>(buf.data());
	size_t sample_len = buf.size() / sizeof(int16_t);
	// 音声を出力
	// 引数1: 音声データの配列
	// 引数2: 音声データのサンプル数
	// 引数3: サンプリングレート
	// 引数4: true: ステレオ, false: モノラル
	// 引数5: 繰返し回数
	// 引数6: スピーカーチャンネル、0で良い
	// 引数7: 現在の再生を中断するか
	M5.Speaker.playRaw(samples, sample_len, SAMPLE_RATE, false, 1, 0, false);
}
```

### サンプルコード

> https://github.com/74th/stackchan-book-code/tree/main/3.3_display

## 3.4. サーボモータの操作

### SG90

```ini
# platformio.ini

lib_deps =
	https://github.com/madhephaestus/ESP32Servo.git@^3.1.3
	https://github.com/ArminJo/ServoEasing.git@^3.6.0

lib_ldf_mode = deep
```

```c
#include <Ticker.h>
#include <M5Unified.h>
#include "ServoEasing.hpp"

const int SERVO1_PIN = 6;
const int SERVO2_PIN = 7;

// オブジェクトの作成
static ServoEasing Servo1;
static ServoEasing Servo2;

void setup() {
	M5.begin();

	// ピンと、初期の角度を指定して初期化
	Servo1.attach(SERVO1_PIN, 90);
	Servo2.attach(SERVO2_PIN, 90);
}
```

```c
// 移動開始
// targetAngle: 目標の角度（0,180の範囲で指定）
// speed: 1秒間に動かす角度（つまり、動く速度）
bool ServoEasing::startEaseTo(int aTargetDegreeOrMicrosecond,
	uint_fast16_t aDegreesPerSecond);
```

```c
void loop() {
	// 左向く
	Servo1.startEaseTo(100, 30);
	delay(1000);

	// 右向く
	Servo1.startEaseTo(80, 60);
	delay(1000);

	// 正面
	Servo1.startEaseTo(90, 30);
	delay(3000);
}
```

> https://github.com/74th/stackchan-book-code/tree/main/3.4_sg90

### SCS0009

> mongonta0716/SCServo: SCS/SMS servo library for Arduino [Not mine]<br/>https://github.com/mongonta0716/SCServo

```ini
lib_deps =
	https://github.com/mongonta0716/SCServo.git
```

```c
#include <M5Unified.h>
#include <SCServo.h>
#include <gob_unifiedButton.hpp>

#define PortC_RX_PIN 17 // Port.C Yellow
#define PortC_TX_PIN 18 // Port.C White

// サーボコントローラーオブジェクトの作成
SCSCL sc;

void setup()
{
	M5.begin();

	// UARTを初期化して、サーボコントローラーオブジェクトにセット
	// ボーレートは1Mbpsの必要がある
	Serial2.begin(1000000, SERIAL_8N1, PortC_RX_PIN, PortC_TX_PIN);
	sc.pSerial = &Serial2;
}
```

```c
SCSCL sc;

// IDの割当
// 引数1: 変更前のID
// 引数2: 変更後のID
void setSCS0009ID(uint8_t oldID, uint8_t newID) {
	// EEPROMのロックを解除して、IDを書き換えて、再度ロックする
	sc.unLockEprom(oldID);
	sc.writeByte(oldID, SCSCL_ID, newID);
	sc.LockEprom(newID);
}

void setup()
{
	M5.begin();
	Serial2.begin(1000000, SERIAL_8N1, PortC_RX_PIN, PortC_TX_PIN);
	sc.pSerial = &Serial2;

	// ID=1→2に変更
	setSCS0009ID(1, 2);
}

void loop() {
}
```

```c
// 移動
// ID: サーボのID
// Position: 目標位置 (0-1023、511が正面)
// Time: 目標到達時間 (ms、0は無指定)
// Speed: 目標到達速度 (0-1023、0は無指定)
// ※ Time、Speedのどちらかを指定する
int SCSCL::WritePos(u8 ID, u16 Position, u16 Time, u16 Speed);
```

```c
void loop() {
	// 右向く
	sc.WritePos(1, 511+128, 0, 100);
	delay(1000);

	// 左向く
	sc.WritePos(1, 511-128, 0, 200);
	delay(1000);

	// 正面
	sc.WritePos(1, 511, 0, 100);
	delay(3000);
}
```

> https://github.com/74th/stackchan-book-code/tree/main/3.4_scs0009

## 3.5. ウェイクアップワード検出をESP-SRで実現する

> espressif/esp-sr: Speech recognition<br/>https://github.com/espressif/esp-sr

> 74th/ESP-SR-For-M5Unified<br/>https://github.com/74th/ESP-SR-For-M5Unified

```cpp
#include <M5Unified.h>
#include <ESP_SR_M5Unified.h>

// 検出イベント
void onSrEvent(sr_event_t event, int command_id, int phrase_id) {
	(void)command_id;
	(void)phrase_id;
	if (event == SR_EVENT_WAKEWORD) {
		// ウェイクアップワードが検出された
		ESP_SR_M5.setMode(SR_MODE_WAKEWORD);
	}
}

void setup() {
	M5.begin();

	// マイクの有効化
	M5.Mic.begin();

	// ESP-SRの有効化
	ESP_SR_M5.onEvent(onSrEvent);
	ESP_SR_M5.begin(nullptr, 0, SR_MODE_WAKEWORD, SR_CHANNELS_MONO);
}

void loop() {
	M5.update();

	// 音声データをESP-SRに渡す
	static int16_t audio_buf[256];
	if (M5.Mic.record(audio_buf, 256, 16000, false)) {
		ESP_SR_M5.feedAudio(audio_buf, 256);
	}
}
```

## 3.6. WebSocketコントロールｽﾀｯｸﾁｬﾝ

> 74th/websocket-control-stackchan: StackChan WebSocket Control Server<br/>https://github.com/74th/websocket-control-stackchan/

```python
from google import genai
from stackchan_server.app import StackChanApp
from stackchan_server.ws_proxy import WsProxy

app = StackChanApp()

client = genai.Client(vertexai=True).aio

instruction = """
あなたは親切な音声アシスタントです。
音声で返答するため、マークダウンは記述せず、簡潔に答えてください。
だいたい3文程度で答えてください。
""".replace("\n", "")

@app.setup
async def setup(proxy: WsProxy):
	logger.info("WebSocket connected")

@app.talk_session
async def talk_session(proxy: WsProxy):
	chat = client.chats.create(
			model="gemini-3-flash-preview",
			config=types.GenerateContentConfig(
			system_instruction=instruction,
		),
	)

	while True:
		text = await proxy.listen()
		if not text:
			return
		logger.info("Human: %s", text)

		# AI応答の取得
		resp = await chat.send_message(text)

		# 発話
		logger.info("AI: %s", resp.text)
		if resp.text:
			await proxy.speak(resp.text)
```

# 4. AIエージェント開発

## 4.1. AIエージェント開発

> GitHub Copilotを使いこなす 実例に学ぶAIコーディング活用術 | IT/Webエンジニアの転職・求人サイトFindy<br/> https://findy-code.io/events/Ie5IPUat7pYE4

## 4.4. Claude Agent SDKを使う

#### Claude API

> Claude Console<br/>https://platform.claude.com/

#### Google VertexAI

> Google Cloudの開始ページ<br/>https://console.cloud.google.com/welcome/new

### 環境変数の準備

> direnv – unclutter your .profile | direnv<br/>https://direnv.net/

```
# .envrc
dotenv
```

```
# .env
# Anthropic APIキーを使う場合
ANTHROPIC_API_KEY=xxxx
# Google Cloud VertexAIを使う場合
CLAUDE_CODE_USE_VERTEX=1
GOOGLE_APPLICATION_CREDENTIALS=(サービスアカウントキーのJSONファイルパス)
```

### Pythonの準備

> uv<br/>https://docs.astral.sh/uv/

```
uv init
```

```
uv add claude-agent-sdk
```

### Claude Agent SDKの基本的な使い方

```py
from claude_agent_sdk import (
	ClaudeSDKClient,
	ClaudeAgentOptions,
)
import asyncio

prompt = """
# 役割
あなたは音声AIアシスタントのスタックチャンです
ユーザの質問に対して、3文程度の言葉で答えてください
音声案内であるため、マークダウンや絵文字等は用いずに、文字列だけで回答してください
"""

# 設定
agent_option = ClaudeAgentOptions(
	# モデル
	model="claude-haiku-4-5@20251001",
	# プロンプト
	system_prompt=prompt,
	# ワークスペースとして動作するディレクトリ
	cwd="./workspace",
	# スキル設定等の読み込み先
	setting_sources=["project"],
)


async def main():
	# クライアントの作成。ここでClaude Codeが起動される。
	async with ClaudeSDKClient(options=agent_option) as client:
		# 質問
		await client.query("東京から金沢市にはどうやって行けばいい")
		# メッセージを表示
		async for message in client.receive_response():
			print(message)


if __name__ == "__main__":
	asyncio.run(main())
```

> Models overview - Claude API Docs<br/>https://platform.claude.com/docs/en/about-claude/models/overview

> https://github.com/74th/stackchan-book-code/tree/main/4.4_claude_agent_sdk_first

### WebSocketｽﾀｯｸﾁｬﾝフレームワークと組み合わせる

```py
def create_agent() -> ClaudeSDKClient:
	agent_option = ClaudeAgentOptions(
		# 略
	)
	return ClaudeSDKClient(options=agent_option)

@app.talk_session
async def talk_session(proxy: WsProxy):
	client = create_agent()

	async with client:
		while True:
			try:
				text = await proxy.listen()
			except EmptyTranscriptError:
				logger.info("音声が聞き取れませんでした")
				return

			logger.info("Human: %s", text)

			# AI応答の取得
			await client.query(text)
			async for message in client.receive_response():
				logger.info(message)

				# 発話
				logger.info("AI: %s", message.result)
				if message.result:
					await proxy.speak(message.result)
```

## 4.5. スキルで知識を与える

> Overview - Agent Skills<br/>https://agentskills.io/home

```md
---
name: weather
description: 天気を聞かれたとき
---

天気を聞かれたとき、場所の指定がない場合には、埼玉県志木市の天気を調べてこたえること。
職場の天気を聞かれたときには、東京都港区六本木の天気を調べてこたえること。
```

> https://github.com/74th/stackchan-book-code/tree/main/4.5_claude_agent_sdk_skills

## 4.6. カスタムツール

```
uv add pydantic
```

```py
from pydantic import BaseModel
from typing import Literal

# ツールの作成の引数
class AirConRemoteInput(BaseModel):
	room: Literal["寝室", "リビング"]
	state: Literal["オフ", "暖房オン", "冷房オン"]
```

```py
import json

from claude_agent_sdk import tool

# ツールの関数定義
@tool(
	"aircon-control",
	"自宅のエアコンを操作する。寝室かリビングかを指定する。",
	AirConRemoteInput.model_json_schema(),
)
async def aircon_remote(dict_args: dict[str, Any]):
	args = AirConRemoteInput.model_validate(dict_args)
	print(f"🌳エアコンを操作します {args}")

	# TODO: エアコンを操作する

	return {
		"content": [
			{
				"type": "text",
				"text": "操作成功",
			}
		]
	}
```

```py
from claude_agent_sdk import create_sdk_mcp_server

# MCPサーバ化
home_remote_mcp = create_sdk_mcp_server(
	name="home-remote",
	version="1.0.0",
	tools=[aircon_remote],
)
```

```py
agent_option = ClaudeAgentOptions(
	model="claude-haiku-4-5@20251001",
	system_prompt=prompt,
	cwd="./workspace",
	setting_sources=["project"],
	# MCPサーバの登録
	mcp_servers={"home-remote": home_remote_mcp},
	# 全てのツールを許可する
	permission_mode="bypassPermissions",
)
```

> https://github.com/74th/stackchan-book-code/tree/main/4.6_claude_agent_sdk_custom_tool

## まとめ

# 5. ホームエージェントにする

## 5.1. Nature Remo シリーズを使って赤外線リモコンを操作する

> Nature Inc. | Nature Developer Page<br/>https://developer.nature.global/

### 機器リストを取得する

```py
# get_appliances.py
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
		async with session.get("https://api.nature.global/1/appliances",
			headers=headers) as response:
			return await response.json()

async def main():
	appliances = await get_appliances()
	print(json.dumps(appliances, indent=2))

if __name__ == "__main__":
	asyncio.run(main())
```

```json
[
	{
		"id": "xxxx",
		"type": "TV",
		"nickname": "TV",
		"tv": {
			...
		}
		...
	},
	{
		"id": "yyyy",
		"type": "AC",
		"nickname": "Living AC",
		"aircon": {
			...
		},
		...
	}
]
```

### エアコンの操作をツール化する

```json
[
	...
	{
		"id": "yyyy",
		"type": "AC",
		"nickname": "Living AC",
		"aircon": {
			"range": {
				"modes": {
					"cool": {
						"temp": ["16", "17", "18", "19", "20", ...],
						"dir": ["still", "swing"],
						"dirh": [""],
						"vol": ["1", "2", "3", "4", "auto"]
					},
					"warm": { ...  }
				},
				"fixedButtons": ["power-off" ]
			},
			"tempUnit": "c"
		}
	}
]
```

```py
# 暖房オン
payload = {
	"operation_mode": "warm",
	"air_direction": "still",
	"air_direction_h": "",
	"air_volume": "auto",
	"button": "",
	"temperature": "23",
	"temperature_unit": "c"
}
```

```py
import asyncio
import os
from typing import Any, Literal

import aiohttp
from claude_agent_sdk import tool
from pydantic import BaseModel

# APIトークン
NATURE_REMO_CLOUD_API_TOKEN = os.getenv("NATURE_REMO_CLOUD_API_TOKEN")
# 機器のapplicance_idの辞書
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
	"自宅のエアコンを操作する。寝室かリビングかを指定する。"
	+ "温度指定がない場合、temperatureにはnullを指定すること。",
	AirConRemoteInput.model_json_schema(),
)
async def aircon_remote(dict_args: dict[str, Any]):
	args = AirConRemoteInput.model_validate(dict_args)
	appliance_id = NATURE_REMO_LIVING_AIRCON_APPLIANCE_ID_DICT[args.room]
	print(f"エアコン操作ツールが呼び出されました。部屋: {args.room}, "
		+ f"状態: {args.state}, appliance_id: {appliance_id}")

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
		if args.temperature is None:
			args.temperature = 23
		payload = {
			"operation_mode": "warm",
			"air_direction": "still",
			"air_direction_h": "",
			"air_volume": "auto",
			"button": "",
			"temperature": str(args.temperature),
			"temperature_unit": "c"
		}
	elif args.state == "冷房オン":
		# 略
	else:
		raise ValueError("Invalid state")
	print(f"Payload: {payload}")

	async with aiohttp.ClientSession() as session:
		headers = {"Authorization": f"Bearer {NATURE_REMO_CLOUD_API_TOKEN}"}
		async with session.post(
			f"https://api.nature.global/2/appliances/{appliance_id}/aircon_settings",
			headers=headers, data=payload) as response:
			if  response.status != 200:
				response_text = await response.text()
				raise Exception(f"API request failed with status code {response.status},"
					+ f"response: {response_text}")
			return await response.json()

	return {"state": "success"}
```

> https://github.com/74th/stackchan-book-code/tree/main/5.1_nature_remo

## 5.2. 赤外線リモコンをREST APIで操作できるようにする

### 赤外線信号を送受信する

> crankyoldgit/IRremoteESP8266: Infrared remote library for ESP8266/ESP32<br/>https://github.com/crankyoldgit/IRremoteESP8266

```ini
# platformio.ini
lib_deps =
	https://github.com/crankyoldgit/IRremoteESP8266.git#v2.9.0
```

```c
#include <Arduino.h>
#include <IRremoteESP8266.h>
#include <IRsend.h>
#include <IRrecv.h>
#include <IRutils.h>

#define BUTTON_PIN GPIO_NUM_39      // ボタンピン
#define IR_RECEIVER_PIN GPIO_NUM_32 // 赤外線受信ピン
#define IR_SEND_PIN GPIO_NUM_26     // 赤外線送信ピン

// 赤外線受信オブジェクト
// 引数: ピン番号、バッファサイズ、タイムアウト(ms)、デコード時に二次バッファを使うか
IRrecv irrecv(IR_RECEIVER_PIN, 1024, 50, true);

// 赤外線送信用オブジェクト
IRsend irsend(IR_SEND_PIN);
```

```c
void setup()
{
	// 赤外線送信の初期化
	irsend.begin();

	// 赤外線受信の初期化
	irrecv.setUnknownThreshold(12);
	irrecv.setTolerance(kTolerance);
	irrecv.enableIRIn();
}
```

```c
while (true)
{
	// 受信デコード結果
	decode_results results;
	if (!irrecv.decode(&results))
	{
		// 受信できていない
		continue;
	}

	// デコードした情報の出力
	Serial.println(resultToHumanReadableBasic(&results));

	// Rawのデータを配列で取得
	uint16_t *raw = resultToRawArray(&results);
	uint16_t len = getCorrectedRawLength(&results);

	break;
}
```

```c
uint16_t *raw; // 送信する生データの配列
uint16_t len;    // 生データの配列の長さ
uint16_t frequency_khz = 38; // 周波数（kHz）

irsend.sendRaw(raw, len, frequency_khz);
```

### Webサーバを立てる

```c
#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>
#include <ssid.hpp>

// 略: WiFi接続

// WebServerオブジェクト（引数はポート番号）
WebServer server(80);

// 404 Not Found
void handleNotFoundAPI()
{
	server.send(404, "application/json", "{\"message\": \"Not Found.\"}");
}

void setup()
{
	Serial.begin(115200);

	// 略: WiFi接続

	// Webサーバの開始
	// コールバック関数を設定
	server.on("/", HTTP_GET, handleRootAPI);
	server.on("/ir/send_raw", HTTP_POST, handleIRSendRawAPI);
	server.on("/ir/receive", HTTP_GET, handleIRReceiveAPI);
	server.onNotFound(handleNotFoundAPI);
	server.begin();
}

void loop()
{
	// サーバのリクエストを処理する
	server.handleClient();
}
```

```c
#include <ArduinoJson.h>

// POST /ir/send_raw
void handleIRSendRawAPI()
{
	JsonDocument resDoc;       // レスポンスのJSON
	JsonDocument reqDoc;       // リクエストのJSON
	char resBodyBuf[1024 * 2]; // レスポンスのバッファ

	// リクエストボディのJSONデシリアライズ
	String requestBody = server.arg("plain");
	Serial.print("request body:");
	Serial.println(requestBody);
	DeserializationError err = deserializeJson(reqDoc, requestBody);

	// リクエストボディのデータ
	uint16_t frequency = reqDoc["frequency"] | 38;
	const char *rawHex = reqDoc["data"]["raw"];

	// ここに赤外線送信処理を実装する

	// レスポンスボディのJSONを作成
	resDoc["success"] = true;

	// JSONをレスポンス
	serializeJson(resDoc, resBodyBuf, sizeof(resBodyBuf));
	Serial.println(resBodyBuf);
	server.send(200, "application/json", resBodyBuf);
}
```

### 実際に製作したAPI仕様

#### GET /ir/receive 赤外線受信API

```json
{
	"success": true,
	"data": {
		"type": "SONY",
		"hex": "0xAF0",
		"raw":  "0x098E02260..."
	}
}
```

```json
{
	"success": false,
	"error": "timeout"
}
```

#### POST /ir/send_raw 赤外線Rawデータ送信API

```json
{
	"raw":  "0x098E02260...",
	"frequency": 38
}
```

```json
{
	"success": true
}
```

### 完成したコード

> https://github.com/74th/stackchan-book-code/tree/main/5.2_ir_server

### Claude Agent SDKのツールにする

```py
import asyncio
from typing import Literal

# TV横デバイスのIP
TV_REMOTE_IP = "192.168.1.103"

# ボタンリスト
TV_BUTTON_ENUM = Literal["電源", "NHK", "ビデオ", "音量アップ", "音量ダウン"]
# 信号データ
TV_BUTTON_IR: dict[TV_BUTTON_ENUM, str] = {
	"電源": "0x096A02..."
	"NHK": "0x097802..."
	"ビデオ":  "0x098A02..."
	# 略
}

# HTTP送信
async def request_ir(button: TV_BUTTON_ENUM) -> None:
	raw_hex = TV_BUTTON_IR[button]

	async with aiohttp.ClientSession() as session:
		req = {
			"raw": raw_hex,
			"frequency": 38000,
		}

		async with session.get(f'http://{TV_REMOTE_IP}/ir/send_raw', data=req) as
			response:
			if response.status != 200:
				raise Exception(f"Failed to send command: {response.status}")
			resData = await response.json()
			if not resData.get("success", False):
				raise Exception(f"Command not successful: {resData}")
```

```py
from typing import Literal

from pydantic import BaseModel

TV_COMMANDS = Literal["電源オン", "電源オフ", "NHK", "パソコン", "音量アップ",
	"音量ダウン"]

class TVRemoteParam(BaseModel):
	action: TV_COMMANDS
```

```py
from typing import Any

from claude_agent_sdk import tool

@tool(
	"tv-remote-control",
	"自宅のテレビを操作する。チャンネルや電源を指定する。",
	TVRemoteParam.model_json_schema(),
)
async def tv_remote_control(dict_args: dict[str, Any]):
	args = TVRemoteParam.model_validate(dict_args)
	print(f"📺TVを操作します {args}")
	if args.action == "パソコン":
		# 最初にNHKのチャンネル1に切り替え、
		# ビデオ切り替えを2回押すと、PCのHDMI入力に切り替わる
		await request_ir("NHK")
		await asyncio.sleep(5)
		await request_ir("ビデオ")
		await asyncio.sleep(1)
		await request_ir("ビデオ")
	elif args.action in ["電源オン", "電源オフ"]:
		# 電源オンとオフは同じ信号
		await request_ir("電源")
	elif args.action in TV_BUTTON_IR:
		await request_ir(args.action)
	else:
		raise ValueError(f"Unsupported action: {args.action}")
	return {"state": "success"}
```

```py
AIRCON_ROOM_ENUM = Literal["寝室", "リビング"]
AIRCON_STATE_ENUM = Literal["オフ", "暖房オン", "冷房オン"]

class AirConRemoteInput(BaseModel):
	room: AIRCON_ROOM_ENUM
	state: AIRCON_STATE_ENUM

@tool(
	"aircon-control",
	"自宅のエアコンを操作する。寝室かリビングかを指定する。",
	AirConRemoteInput.model_json_schema(),
)
async def aircon_remote(dict_args: dict[str, Any]):
	args = AirConRemoteInput.model_validate(dict_args)

	# エアコン操作関数を呼び出し
	await request_aircon_ir(args.room, args.state)

	print(f"🌳エアコンを操作します {args}")
	return {"state": "success"}
```

## 5.3. スキルで生活の知識を入れる

```py
prompt = """
# 環境情報
"""

prompt += [
	f"- 現在時刻(JST): {datetime.datetime.now(JST).strftime('%Y-%m-%d %H:%M:%S')}",
	"- 現在地: 日本埼玉県志木市上宗岡台"
].join("\n")

prompt += """
# 役割
あなたは音声AIアシスタントのスタックチャンです
自宅のリビングに置かれています。ユーザのメッセージに対して、3文程度の言葉で答えてください
音声案内であるため、マークダウンや絵文字等は用いずに、文字列だけで回答してください
"""
```

```md
---
name: バスの時刻表
description: 自宅の近くのバスの時刻表
---

自宅の近くのバス停は「志木高校入口」
最寄りの駅は「志木駅」
次のバスの時刻を聞かれた場合には、「志木高校入口 から 志木駅」の時刻表を答えればよい

以下の時刻表は「乗車時刻 -> 到着時刻」で書かれている

## 志木高校入口 から 志木駅

10分程で着く便、25分程度で着く便がある
25分程度で着くものは注意を促すこと

- 7:05 -> 7:14
- 7:26 -> 7:35
<!-- 以下略 -->
```

```
uv add --dev pytest pytest-asyncio
```

```py
# tests/conftest.py
import pytest
from claude_agent_sdk import ClaudeSDKClient

from app.main import setup_claude_agent_sdk


@pytest.fixture
def claude_client() -> ClaudeSDKClient:
	return setup_claude_agent_sdk()
```

```py
from logging import getLogger

logger = getLogger(__name__)

@pytest.mark.asyncio
async def test_get_next_bus(claude_client: ClaudeSDKClient):
	async with claude_client:
		await claude_client.query("次のバスは")
		async for message in claude_client.receive_response():
			logger.info(message)
```

```jsonc
// .vscode/settings.json
{
	"python.testing.pytestArgs": ["--log-cli-level=INFO"]
}
```
