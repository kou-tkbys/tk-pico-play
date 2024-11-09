#ifndef CUBEANIMATION_H
#define CUBEANIMATION_H

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

/**
 * Default Pin Configuration
 * デフォルトピン設定
 *
 * The pin numbers refer to the GPIO numbers, not the physical pin numbers.
 * ピン番号は物理的なピン番号ではなく、GPIOの番号です。
 */
#define CUBE_ANIMATION_SDA 0
#define CUBE_ANIMATION_SCL 1

/**
 * Default screen dimensions
 * デフォルト画面サイズ
 */
#define CUBE_ANIMATION_SCREEN_WIDTH 128
#define CUBE_ANIMATION_SCREEN_HEIGHT 64

/**
 * OLED reset pin
 * OLED リセットピン
 */
#define CUBE_ANIMATION_OLED_RESET -1

/**
 * Default rotation angles and line thickness
 * 回転角度と線の太さのデフォルト値
 */
#define CUBE_ANIMATION_DEFAULT_ANGLE_X 0.0
#define CUBE_ANIMATION_DEFAULT_ANGLE_Y 0.0
#define CUBE_ANIMATION_DEFAULT_LINE_THICKNESS 1 // Default line thickness is now an integer (1)

/*
 * Function: drawCube
 * ------------------
 *  Uses a rotation matrix to draw a rotating cube on the screen.
 *  回転行列を使って、回転する立方体を画面に描画します。
 *
 * Example Usage:
 * ------------------
 * #include <Adafruit_GFX.h>
 * #include <Adafruit_SSD1306.h>
 * #include <Wire.h>
 * #include "CubeAnimation.h"
 *
 * // I2C connection Wire instance
 * // I2C接続Wireインスタンス
 * TwoWire myWire = TwoWire(CUBE_ANIMATION_SDA, CUBE_ANIMATION_SCL);
 *
 * // Initialize display using default SDA, SCL, and OLED_RESET settings
 * // デフォルトのSDA、SCL、およびOLED_RESET設定を使用してディスプレイを初期化します
 * Adafruit_SSD1306 display(CUBE_ANIMATION_SCREEN_WIDTH, CUBE_ANIMATION_SCREEN_HEIGHT, &myWire, CUBE_ANIMATION_OLED_RESET);
 *
 * // Default values for various settings
 * // 各種デフォルト値
 * float angleX = CUBE_ANIMATION_DEFAULT_ANGLE_X;
 * float angleY = CUBE_ANIMATION_DEFAULT_ANGLE_Y;
 * int lineThickness = CUBE_ANIMATION_DEFAULT_LINE_THICKNESS;
 *
 * void setup()
 * {
 *   // Initialize the display with the I2C address and settings
 *   // I2Cアドレスと設定でディスプレイを初期化します
 *   display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
 *
 *   // Clear the display
 *   // ディスプレイをクリアします
 *   display.clearDisplay();
 * }
 *
 * void loop()
 * {
 *   display.clearDisplay();
 *
 *   // Update rotation angles
 *   // 回転角度を更新
 *   angleX += 0.05;
 *   angleY += 0.05;
 *
 *   // Draw rotating cube
 *   // 回転する立方体を描画
 *   drawCube(display, angleX, angleY, lineThickness, CUBE_ANIMATION_SCREEN_WIDTH, CUBE_ANIMATION_SCREEN_HEIGHT);
 *
 *   // Update display
 *   // ディスプレイを更新
 *   display.display();
 *
 *   // Adjust drawing speed
 *   // 描画速度調整
 *   delay(20);
 * }
 */

void drawCube(Adafruit_SSD1306 &display, float angleX, float angleY, int lineThickness, int screenWidth, int screenHeight);

#endif // CUBEANIMATION_H
