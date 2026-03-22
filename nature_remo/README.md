## Nature Remo Cloud APIをClaude Agent SDKのツール化する

- [get_appliances.py](./get_appliances.py): 機器リストの取得
- [control_aircon.py](./control_aircon.py): エアコンの操作のツール化サンプル

.env.sampleを参考に、.envファイルを作成して、環境変数を設定をしてください。

```
NATURE_REMO_CLOUD_API_TOKEN=xxx
GOOGLE_APPLICATION_CREDENTIALS=xxxx
NATURE_REMO_LIVING_AIRCON_APPLIANCE_ID=xxx
NATURE_REMO_BEDROOM_AIRCON_APPLIANCE_ID=xxx
CLAUDE_CODE_USE_VERTEX=1
```
