#include <Arduino.h>
#include <ArduinoJson.h>
#include <Adafruit_NeoPixel.h>
#include <WiFi.h>
#include <WebServer.h>
#include <IRremoteESP8266.h>
#include <IRsend.h>
#include <IRrecv.h>
#include <IRac.h>
#include <IRutils.h>
#include <ssid.hpp>

#ifdef ARDUINO_M5STACK_ATOM_LITE

#define LED_PIN GPIO_NUM_27 // LEDピン

#ifdef USE_UNIT_IR
#define IR_SEND_PIN GPIO_NUM_26 // Port.A D1
#else
#define IR_SEND_PIN GPIO_NUM_12 // ATOM Liteの赤外線送信ピン
#endif
#define IR_RECEIVER_PIN GPIO_NUM_32 // Port.A D0

#elif defined(IOT_SERVER_BOARD)

#define LED_PIN GPIO_NUM_2         // LEDピン
#define IR_SEND_PIN GPIO_NUM_5     // GPIO D1
#define IR_RECEIVER_PIN GPIO_NUM_4 // GPIO D0

#elif defined(CONFIG_IDF_TARGET_ESP32C3)

#define LED_PIN GPIO_NUM_2 // LEDピン
#define IR_SEND_PIN GPIO_NUM_1 // Port.A D1
#define IR_RECEIVER_PIN GPIO_NUM_0 // Port.A D0

#endif

// LEDの色の定義
#define LED_COLOR_GREEN Adafruit_NeoPixel::Color(0, 32, 0)
#define LED_COLOR_BLUE Adafruit_NeoPixel::Color(0, 0, 32)
#define LED_COLOR_YELLOW Adafruit_NeoPixel::Color(32, 32, 0)
#define LED_COLOR_RED Adafruit_NeoPixel::Color(32, 0, 0)

// 受信設定（エアコン向けに大きめ）
static const uint16_t kCaptureBufferSize = 1024;
static const uint8_t kReceiveTimeoutMs = 50;
static const uint16_t kMinUnknownSize = 12;
static const uint16_t kDefaultFrequencyKHz = 38;
static const uint32_t kReceiveApiTimeoutMs = 10000;

// LEDの定義（数、制御ピン、仕様）
Adafruit_NeoPixel led(1, LED_PIN, NEO_GRB + NEO_KHZ800);

// SSID、パスワードの文字列化
const char *ssid = WIFI_SSID_H;
const char *pass = WIFI_PASSWORD_H;

// 赤外線送信用オブジェクト
IRsend irsend(IR_SEND_PIN);

// 赤外線受信オブジェクト
// 引数: ピン番号、バッファサイズ、タイムアウト(ms)、デコード時に二次バッファを使うか
IRrecv irrecv(IR_RECEIVER_PIN, kCaptureBufferSize, kReceiveTimeoutMs, true);

WebServer server(80);

// hexの文字列をuint64_tに変換
uint64_t hexStringToUint64(const char *hexString)
{
    if (hexString[0] == '0' && (hexString[1] == 'x' || hexString[1] == 'X'))
    {
        hexString += 2;
    }

    uint64_t result = strtoull(hexString, NULL, 16);

    return result;
}

// 16進数文字を対応する数値に変換
unsigned char hexCharToValue(char hexChar)
{
    if ('0' <= hexChar && hexChar <= '9')
    {
        return hexChar - '0';
    }
    else if ('a' <= hexChar && hexChar <= 'f')
    {
        return hexChar - 'a' + 10;
    }
    else if ('A' <= hexChar && hexChar <= 'F')
    {
        return hexChar - 'A' + 10;
    }
    else
    {
        return 0;
    }
}

// 文字が16進数として有効か判定
bool isHexChar(char hexChar)
{
    return ('0' <= hexChar && hexChar <= '9') || ('a' <= hexChar && hexChar <= 'f') || ('A' <= hexChar && hexChar <= 'F');
}

// HEX文字列をバイト列に変換する関数
void hexStringToByteArray(const char *hexString, unsigned char *byteArray, size_t *byteArraySize)
{
    if (hexString[0] == '0' && (hexString[1] == 'x' || hexString[1] == 'X'))
    {
        hexString += 2;
    }

    size_t hexLen = strlen(hexString);
    *byteArraySize = hexLen / 2;

    for (size_t i = 0; i < hexLen / 2; ++i)
    {
        byteArray[i] = (hexCharToValue(hexString[2 * i]) << 4) | hexCharToValue(hexString[2 * i + 1]);
    }
}

// uint16_t配列をHEX文字列に変換する関数
String uint16ArrayToHexString(const uint16_t *values, size_t valuesLength)
{
    String hexString = "0x";
    hexString.reserve(2 + valuesLength * 4);

    char buf[5];
    for (size_t i = 0; i < valuesLength; ++i)
    {
        snprintf(buf, sizeof(buf), "%04X", values[i]);
        hexString += buf;
    }

    return hexString;
}

// HEX文字列のuint16_t要素数を取得する関数
bool getUint16ArrayLengthFromHexString(const char *hexString, size_t *valuesLength)
{
    if (hexString == NULL)
    {
        return false;
    }

    if (hexString[0] == '0' && (hexString[1] == 'x' || hexString[1] == 'X'))
    {
        hexString += 2;
    }

    size_t hexLen = strlen(hexString);
    if (hexLen == 0 || hexLen % 4 != 0)
    {
        return false;
    }

    for (size_t i = 0; i < hexLen; ++i)
    {
        if (!isHexChar(hexString[i]))
        {
            return false;
        }
    }

    *valuesLength = hexLen / 4;
    return true;
}

// HEX文字列をuint16_t配列に変換する関数
bool hexStringToUint16Array(const char *hexString, uint16_t *values, size_t valuesLength)
{
    size_t parsedLength;
    if (!getUint16ArrayLengthFromHexString(hexString, &parsedLength) || parsedLength != valuesLength)
    {
        return false;
    }

    if (hexString[0] == '0' && (hexString[1] == 'x' || hexString[1] == 'X'))
    {
        hexString += 2;
    }

    for (size_t i = 0; i < valuesLength; ++i)
    {
        values[i] = (hexCharToValue(hexString[i * 4]) << 12) |
                    (hexCharToValue(hexString[i * 4 + 1]) << 8) |
                    (hexCharToValue(hexString[i * 4 + 2]) << 4) |
                    hexCharToValue(hexString[i * 4 + 3]);
    }

    return true;
}

uint16_t getFrequencyKHzOrDefault(const JsonDocument &doc)
{
    if (!doc["frequency"].isNull())
    {
        return doc["frequency"].as<uint16_t>();
    }
    return kDefaultFrequencyKHz;
}

void sendJsonResponse(int statusCode, JsonDocument &doc)
{
    String body;
    serializeJson(doc, body);
    Serial.println(body);
    server.send(statusCode, "application/json", body);
}

void setIdleLed()
{
    led.setPixelColor(0, LED_COLOR_BLUE);
    led.show();
}

// GET /
void handleRootAPI()
{
    Serial.println("access GET /");
    server.send(200, "application/json", "{}");
}

// 404 Not Found
void handleNotFoundAPI()
{
    server.send(404, "application/json", "{\"message\": \"Not Found.\"}");
}

// POST /ir/send
void handleIRSendAPI()
{
    Serial.println("access POST /ir/send");

    // 処理中を色で表示
    led.setPixelColor(0, LED_COLOR_YELLOW);
    led.show();

    JsonDocument resDoc; // レスポンスのJSON
    JsonDocument reqDoc; // リクエストのJSON

    // リクエストボディのJSONデシリアライズ
    String requestBody = server.arg("plain");
    Serial.print("request body:");
    Serial.println(requestBody);
    DeserializationError err = deserializeJson(reqDoc, requestBody);
    if (err)
    {
        resDoc["error"] = "failed to deserialize Json";
        resDoc["error_detail"] = err.c_str();
        resDoc["success"] = false;
        sendJsonResponse(401, resDoc);
        setIdleLed();
        return;
    }

    const char *type = reqDoc["type"];
    if (type == NULL || strlen(type) == 0)
    {
        resDoc["error"] = "type is required.";
        resDoc["success"] = false;
        sendJsonResponse(401, resDoc);
        setIdleLed();
        return;
    }

    const char *hexData = reqDoc["hex"];
    if (hexData == NULL || strlen(hexData) == 0)
    {
        resDoc["error"] = "hex is required.";
        resDoc["success"] = false;
        sendJsonResponse(401, resDoc);
        setIdleLed();
        return;
    }

    if (strcmp(type, "SONY") == 0)
    {
        uint64_t data_u64 = hexStringToUint64(hexData);
        Serial.printf("data: %llx\r\n", data_u64);

        int16_t dataSize_bits;
        if (data_u64 <= (1ULL << 12))
        {
            dataSize_bits = 12;
        }
        else if (data_u64 <= (1ULL << 15))
        {
            dataSize_bits = 15;
        }
        else
        {
            dataSize_bits = 20;
        }

        irsend.sendSony(data_u64, dataSize_bits, 2);
    }
    else if (strcmp(type, "MITSUBISHI_AC") == 0)
    {
        unsigned char data_bytes[64];
        size_t dataSize_bytes;

        hexStringToByteArray(hexData, data_bytes, &dataSize_bytes);
        irsend.sendMitsubishiAC(data_bytes, dataSize_bytes);
    }
    else
    {
        resDoc["error"] = "unknown type";
        resDoc["success"] = false;
        sendJsonResponse(401, resDoc);
        setIdleLed();
        return;
    }

    resDoc["success"] = true;
    sendJsonResponse(200, resDoc);
    setIdleLed();
}

// POST /ir/send_raw
void handleIRSendRawAPI()
{
    Serial.println("access POST /ir/send_raw");

    led.setPixelColor(0, LED_COLOR_YELLOW);
    led.show();

    JsonDocument resDoc;
    JsonDocument reqDoc;

    String requestBody = server.arg("plain");
    Serial.print("request body:");
    Serial.println(requestBody);
    DeserializationError err = deserializeJson(reqDoc, requestBody);
    if (err)
    {
        resDoc["error"] = "failed to deserialize Json";
        resDoc["error_detail"] = err.c_str();
        resDoc["success"] = false;
        sendJsonResponse(401, resDoc);
        setIdleLed();
        return;
    }

    uint16_t frequency = getFrequencyKHzOrDefault(reqDoc);
    const char *rawHex = reqDoc["raw"];
    if (rawHex == NULL || strlen(rawHex) == 0)
    {
        resDoc["error"] = "raw is required.";
        resDoc["success"] = false;
        sendJsonResponse(401, resDoc);
        setIdleLed();
        return;
    }

    size_t rawDataLength;
    if (!getUint16ArrayLengthFromHexString(rawHex, &rawDataLength))
    {
        resDoc["error"] = "raw must be a hex string of uint16 values.";
        resDoc["success"] = false;
        sendJsonResponse(401, resDoc);
        setIdleLed();
        return;
    }

    uint16_t *rawData = (uint16_t *)malloc(sizeof(uint16_t) * rawDataLength);
    if (rawData == NULL)
    {
        resDoc["error"] = "failed to allocate raw buffer";
        resDoc["success"] = false;
        sendJsonResponse(500, resDoc);
        setIdleLed();
        return;
    }

    if (!hexStringToUint16Array(rawHex, rawData, rawDataLength))
    {
        free(rawData);
        resDoc["error"] = "failed to parse raw.";
        resDoc["success"] = false;
        sendJsonResponse(401, resDoc);
        setIdleLed();
        return;
    }

    Serial.printf("send raw length=%u frequency=%u\n", (unsigned int)rawDataLength, frequency);
    irsend.sendRaw(rawData, rawDataLength, frequency);
    free(rawData);

    resDoc["success"] = true;
    resDoc["data"]["frequency"] = frequency;
    resDoc["data"]["raw_length"] = rawDataLength;
    sendJsonResponse(200, resDoc);
    setIdleLed();
}

// GET /ir/receive
void handleIRReceiveAPI()
{
    Serial.println("access GET /ir/receive");

    led.setPixelColor(0, LED_COLOR_YELLOW);
    led.show();

    JsonDocument resDoc;
    uint32_t start_time = millis();

    while (true)
    {
        server.handleClient();
        delay(1);

        if (millis() - start_time > kReceiveApiTimeoutMs)
        {
            resDoc["success"] = false;
            resDoc["error"] = "timeout";
            sendJsonResponse(400, resDoc);
            setIdleLed();
            return;
        }

        // 受信デコード結果
        decode_results results;
        if (!irrecv.decode(&results))
        {
            // 受信できていない
            continue;
        }

        // 受信、デコード結果をシリアルに出力
        Serial.println("received:");
        Serial.println(resultToHumanReadableBasic(&results));

        uint16_t *raw = resultToRawArray(&results);
        uint16_t len = getCorrectedRawLength(&results);
        if (raw == NULL)
        {
            resDoc["success"] = false;
            resDoc["error"] = "failed to allocate raw buffer";
            irrecv.resume();
            sendJsonResponse(500, resDoc);
            setIdleLed();
            return;
        }

        resDoc["data"]["type"] = typeToString(results.decode_type, results.repeat);
        resDoc["data"]["hex"] = resultToHexidecimal(&results);
        resDoc["data"]["raw"] = uint16ArrayToHexString(raw, len);
        resDoc["data"]["raw_length"] = len;
        resDoc["data"]["overflow"] = results.overflow;
        resDoc["data"]["bits"] = results.bits;
        resDoc["data"]["value"] = String((unsigned long long)results.value, HEX);
        resDoc["data"]["address"] = results.address;
        resDoc["data"]["command"] = results.command;
        resDoc["data"]["repeat"] = results.repeat;
        resDoc["data"]["receive_buffer_size"] = kCaptureBufferSize;
        resDoc["data"]["receive_timeout_ms"] = kReceiveTimeoutMs;
        resDoc["success"] = true;

        delete[] raw;
        irrecv.resume();

        sendJsonResponse(200, resDoc);
        setIdleLed();
        return;
    }
}

void setup()
{
    Serial.begin(115200);

    // LED
    led.begin();

    // セットアップ中は緑色にする
    led.setPixelColor(0, LED_COLOR_GREEN);
    led.show();

    // 赤外線送信の初期化
    irsend.begin();

    // 赤外線受信の初期化
    irrecv.setUnknownThreshold(kMinUnknownSize);
    irrecv.setTolerance(kTolerance);
    irrecv.enableIRIn();

    Serial.printf("IR receiver config: buffer=%u timeout_ms=%u unknown_threshold=%u\n",
                  kCaptureBufferSize,
                  kReceiveTimeoutMs,
                  kMinUnknownSize);

    Serial.print("setup wifi.");
    WiFi.begin(ssid, pass);
    while (WiFi.status() != WL_CONNECTED)
    {
        Serial.print(".");
        delay(500);
    }
    Serial.println("connected");
    Serial.print("IP:");
    Serial.println(WiFi.localIP());

    // Webサーバの開始
    server.on("/", HTTP_GET, handleRootAPI);
    server.on("/ir/send", HTTP_POST, handleIRSendAPI);
    server.on("/ir/send_raw", HTTP_POST, handleIRSendRawAPI);
    server.on("/ir/receive", HTTP_GET, handleIRReceiveAPI);
    server.onNotFound(handleNotFoundAPI);
    server.begin();

    setIdleLed();
}

// 最後のモニター出力
uint32_t last_monitor_time = 0;

void loop()
{
    if (millis() - last_monitor_time > 1000)
    {
        // モニター出力を1秒ごとにする
        last_monitor_time = millis();
        Serial.print("IP:");
        Serial.println(WiFi.localIP());
    }

    // サーバのリクエストを処理する
    server.handleClient();
}
