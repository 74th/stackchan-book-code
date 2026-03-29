#include <M5Unified.h>

void describe_btna_info() {
    // ボタンAの位置
    M5.Display.setCursor(0, 240-16);
    M5.Display.setTextFont(&fonts::lgfxJapanGothic_16);
    M5.Display.setTextSize(1);
    M5.Display.setTextColor(TFT_BLACK, TFT_BLUE);
    M5.Display.printf("ボタンA: 切替");
}

void setup()
{
    M5.begin();

    describe_btna_info();
}


void mode1_string() {
    static int32_t x = 0;
    static int32_t y = 0;
    static int32_t dx = 4;
    static int32_t dy = 4;

    int32_t textWidth = 16 * 3 * 2;
    x += dx;
    y += dy;

    if(x < 0){
        x = 0;
        dx = 4;
    }
    else if (x + textWidth > M5.Display.width())
    {
        x = M5.Display.width() - textWidth;
        dx = -4;
    }

    if(y < 0){
        y = 0;
        dy = 4;
    }else if(y + 16 * 2 > M5.Display.height()){
        y = M5.Display.height() - 16 * 2;
        dy = -4;
    }

    log_i("x: %d, y: %d", x, y);
    M5.Display.fillScreen(TFT_BLACK);

    M5.Display.setCursor(x, y);
    M5.Display.setTextFont(&fonts::lgfxJapanGothic_16);
    M5.Display.setTextSize(2);
    M5.Display.setTextColor(TFT_BLACK, TFT_WHITE);
    M5.Display.printf("日本語");

    describe_btna_info();
}

void mode2_draw_face() {
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

    describe_btna_info();
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

        describe_btna_info();
    }
    if(mode == 1) {
        mode1_string();

        describe_btna_info();

        delay(10);
    }
    if(mode == 2 && mode_changed) {
        mode2_draw_face();

        describe_btna_info();
    }
}
