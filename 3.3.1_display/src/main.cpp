#include <M5Unified.h>

constexpr int kScreenWidth = 320;
constexpr int kScreenHeight = 240;

LGFX_Sprite hud(&M5.Display);

// 埋め込みPNG画像
extern const uint8_t _binary_data_74th_64x64_png_start[];
extern const uint8_t _binary_data_74th_64x64_png_end[];

void append_btna_info_to_hud() {
    // ボタンAの位置
    hud.setCursor(0, 240-16);
    hud.setTextFont(&fonts::lgfxJapanGothic_16);
    hud.setTextSize(1);
    hud.setTextColor(TFT_BLACK, TFT_BLUE);
    hud.printf("ボタンA: 切替");
}

void mode1_string() {
    static int32_t x = 0;
    static int32_t y = 0;
    static int32_t dx = 4;
    static int32_t dy = 4;

    int32_t fontSize = 16 * 2;
    int32_t textWidth = fontSize * 3;
    x += dx;
    y += dy;

    if(x < 0){
        x = 0;
        dx = 4;
    }
    else if (x + textWidth > kScreenWidth)
    {
        x = kScreenWidth - textWidth;
        dx = -4;
    }

    if(y < 0){
        y = 0;
        dy = 4;
    }else if(y + fontSize > kScreenHeight){
        y = kScreenHeight - fontSize;
        dy = -4;
    }

    log_i("x: %d, y: %d", x, y);
    hud.fillScreen(TFT_BLACK);

    // カーソルの位置を指定（左上が(0, 0)）
    hud.setCursor(x, y);
    // フォントを指定
    hud.setTextFont(&fonts::lgfxJapanGothic_16);
    // フォントサイズを指定（フォントに対して倍率を指定）
    hud.setTextSize(2);
    // 文字描画の背景色、文字色を指定
    hud.setTextColor(TFT_BLACK, TFT_WHITE);
    // 文字を描画
    hud.printf("日本語");

    append_btna_info_to_hud();
    hud.pushSprite(0, 0);
}

void mode2_draw_face() {
    // 黒で塗りつぶし
    hud.fillScreen(TFT_BLACK);

    uint32_t eye_y = 102;
    uint32_t between_eyes = 135;
    uint32_t eye_size = 8;
    uint32_t mouth_y = 157;
    uint32_t mouth_width = 85;
    uint32_t mouth_height = 4;

    // 目を円で描画
    hud.fillCircle(kScreenWidth / 2 - between_eyes / 2, eye_y, eye_size, TFT_WHITE);
    hud.fillCircle(kScreenWidth / 2 + between_eyes / 2, eye_y, eye_size, TFT_WHITE);
    // 口を四角で描画
    hud.fillRect(kScreenWidth / 2 - mouth_width / 2, mouth_y, mouth_width, mouth_height,
                        TFT_WHITE);

    append_btna_info_to_hud();
    hud.pushSprite(0, 0);
}

void mode3_draw_png() {
    constexpr int kPngWidth = 64;
    constexpr int kPngHeight = 64;

    static float x = (kScreenWidth - kPngWidth) * 0.5f;
    static float y = (kScreenHeight - kPngHeight) * 0.5f;
    static float dx = 1.0f;
    static float dy = 1.0f;
    static uint32_t last_update_ms = 0;

    constexpr float kSpeedX = 80.0f; // pixels per second
    constexpr float kSpeedY = 60.0f; // pixels per second
    const uint32_t now_ms = millis();
    const float delta = (last_update_ms == 0) ? 0.0f : static_cast<float>(now_ms - last_update_ms) / 1000.0f;
    last_update_ms = now_ms;

    x += dx * kSpeedX * delta;
    y += dy * kSpeedY * delta;

    if (x <= 0.0f)
    {
        x = 0.0f;
        dx = 1.0f;
    }
    else if (x >= kScreenWidth - kPngWidth)
    {
        x = static_cast<float>(kScreenWidth - kPngWidth);
        dx = -1.0f;
    }

    if (y <= 0.0f)
    {
        y = 0.0f;
        dy = 1.0f;
    }
    else if (y >= kScreenHeight - kPngHeight)
    {
        y = static_cast<float>(kScreenHeight - kPngHeight);
        dy = -1.0f;
    }

    hud.fillScreen(TFT_BLACK);

    // ポインタからファイルサイズを計算
    const uint8_t *png_start = _binary_data_74th_64x64_png_start;
    const uint8_t *png_end = _binary_data_74th_64x64_png_end;
    const uint32_t png_size = static_cast<uint32_t>(png_end - png_start);

    // PNG画像の描画
    // 引数1: PNGファイルのバイナリの開始位置のポインタ
    // 引数2: PNGファイルのバイナリのサイズ
    // 引数3: 描画するx座標
    // 引数4: 描画するy座標
    hud.drawPng(png_start, png_size, static_cast<int>(x), static_cast<int>(y));

    append_btna_info_to_hud();
    hud.pushSprite(0, 0);
}

void setup()
{
    M5.begin();

    hud.setColorDepth(16);
    hud.createSprite(320, 240);

    append_btna_info_to_hud();
    hud.pushSprite(0, 0);
}

void loop()
{
    M5.update();

    static uint8_t mode = 0;
    bool mode_changed = false;

    if (M5.BtnA.wasPressed())
    {
        mode = (mode + 1) % 4;
        mode_changed = true;
        log_i("mode: %d", mode);
    }

    if(mode == 0 && mode_changed) {
        M5.Display.fillScreen(TFT_BLACK);

        append_btna_info_to_hud();

        hud.pushSprite(0, 0);
    }
    if(mode == 1) {
        mode1_string();

        delay(10);
    }
    if(mode == 2 && mode_changed) {
        mode2_draw_face();
    }
    if(mode == 3) {
        mode3_draw_png();
    }
}
