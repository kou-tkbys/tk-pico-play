// BarAnimation.cpp

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>
#include "BarAnimation.h"

/**
 * Default GPIO pin number
 * デフォルトのGPIOピン設定
 */
#define BAR_ANIMATION_SDA 0
#define BAR_ANIMATION_SCL 1

/**
 * Default screen dimensions
 * デフォルトスクリーンサイズ
 */
#define BAR_ANIMATION_SCREEN_WIDTH 128
#define BAR_ANIMATION_SCREEN_HEIGHT 64

/**
 * Default OLED_RESET parameter
 * デフォルトとのOLED_RESET設定値
 */
#define BAR_ANIMATION_OLED_RESET -1

/**
 * I2C connection Wire instance
 * I2C接続Wireインスタンス
 */
TwoWire myWire = TwoWire(BAR_ANIMATION_SDA, BAR_ANIMATION_SCL);

/**
 * Initialize display using default SDA, SCL, and OLED_RESET settings
 * デフォルトのSDA、SCL、およびOLED_RESET設定を使用してディスプレイを初期化します
 */
Adafruit_SSD1306 display(BAR_ANIMATION_SCREEN_WIDTH, BAR_ANIMATION_SCREEN_HEIGHT, &myWire, BAR_ANIMATION_OLED_RESET);

/**
 * Bar setting parameters
 * バーの設定
 */
const float smoothingFactor = 0.6; // Smoothing strength (0.0 to 1.0) / スムージングの強さ（0.0〜1.0）
const int barWidth = 8;            // Width of each bar / バーの幅
const int gapWidth = 1;            // Gap width between bars / バー間の隙間の幅

/**
 * Number of bars (calculated from bar width, gap width, and screen size)
 * バーの本数（バーの幅とバー間の隙間の幅、および画面サイズから算出）
 */
const int barCount = (BAR_ANIMATION_SCREEN_WIDTH - gapWidth) / (barWidth + gapWidth);

/**
 * 各バーの高さを保持する配列
 * Array that holds the height of each bar
 */
int barHeights[barCount];

void setupBarAnimation()
{
    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C, false, true))
    {
        Serial.println(F("SSD1306 allocation failed"));
        for (;;)
            ; // Infinite loop to stop execution / 無限ループで停止
    }
    display.clearDisplay();
    randomSeed(analogRead(A0)); // Random seed using A0 as a dummy / ダミーとしてA0でランダムシード

    // Set initial bar heights / 初期のバーの高さを設定
    for (int i = 0; i < barCount; i++)
    {
        barHeights[i] = random(BAR_ANIMATION_SCREEN_HEIGHT / 2, BAR_ANIMATION_SCREEN_HEIGHT);
    }
}

void updateBarAnimation()
{
    // Update each bar's height / 各バーの高さを更新
    for (int x = 0; x < barCount; x++)
    {
        int newHeight = random(BAR_ANIMATION_SCREEN_HEIGHT / 2, BAR_ANIMATION_SCREEN_HEIGHT); // Generate a new random height / 新しいランダムな高さ
        barHeights[x] += (newHeight - barHeights[x]) * smoothingFactor;                       // Apply smoothing / スムージングの適用
    }
}

void drawBarAnimation()
{
    display.clearDisplay();
    // Draw the bars / バーを描画
    for (int x = 0; x < barCount; x++)
    {
        // Draw each bar / 各バーを描画
        for (int y = BAR_ANIMATION_SCREEN_HEIGHT - barHeights[x]; y < BAR_ANIMATION_SCREEN_HEIGHT; y++)
        {
            for (int w = 0; w < barWidth; w++)
            {
                display.drawPixel(x * (barWidth + gapWidth) + w, y, SSD1306_WHITE); // Draw considering the gap between bars / 隙間を考慮した描画位置
            }
        }
    }
    display.display();
}
