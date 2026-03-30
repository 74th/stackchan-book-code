# IRサーバー

M5Stack ATOM Liteと、Unit IRを使用する。

VS Codeのコマンド"PlatformIO: Pick Project Environment"で、利用する環境を選択してください。

- m5stack-atom-lite-use-own-ir: M5Stack ATOM Liteの内蔵IR LEDを使用する
- m5stack-atom-lite-use-unit-ir: Unit IRを使用する

自宅のWiFiに合わせて、include/ssid.hpp を include/ssid.hpp.sample からコピーして編集してください。

モジュールが取得したIPアドレスは、シリアルモニタに出力されます。
ルータのDHCP固定割当機能などを利用して、IPアドレスを固定しておくことをおすすめします。

## API仕様

### GET /ir/receive 赤外線受信API

メソッドGETのため、リクエストボディはありません。

レスポンスボディには、信号データを含みます。
resultToRawArray()、getCorrectedRawLength()を使って得た生データの配列を、16進数の文字列に変換して、`data.hex`プロパティに格納しています。

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

10秒以上受信できなかった場合には、エラーを返します。

```json
{
  "success": false,
  "error": "timeout"
}
```

### POST /ir/send_raw 赤外線Rawデータ送信API

リクエストボディには、以下の通り受信時のdata.rawと周波数を指定します。

```json
{
  "raw":  "0x098E02260...",
  "frequency": 38
}
```

成功時のレスポンスボディは、成功可否を返します。成功した場合にはステータスコード200を返します。

```json
{
  "success": true
}
```
