// CircleAnimation.h

#ifndef CIRCLEANIMATION_H
#define CIRCLEANIMATION_H

#include <U8g2lib.h>

/**
 * Default Pin Configuration
 * デフォルトピン設定
 *
 * The pin numbers refer to the GPIO numbers, not the physical pin numbers.
 * ピン番号は物理的なピン番号ではなく、GPIOの番号です。
 */
#define CIRCLE_ANIMATION_SCK 6  // Clock pin (クロックピン)
#define CIRCLE_ANIMATION_MOSI 7 // Data (MOSI) pin (データ(MOSI)ピン)
#define CIRCLE_ANIMATION_RST 3  // Reset pin (リセットピン)
#define CIRCLE_ANIMATION_DC 4   // Data/Command pin (データ／コマンドピン)
#define CIRCLE_ANIMATION_CS 5   // Chip Select pin (チップセレクトピン)

/*
 * Function: animateCircle
 * -----------------------
 *  Draws a moving circle from right to left across the screen.
 *  右から左へ画面を横切るように動く円を描画します。
 *
 * Example Usage:
 * -----------------------
 *  #include <U8g2lib.h>
 *  #include "CircleAnimation.h"
 *
 *  U8G2_SH1122_256X64_F_4W_SW_SPI u8g2(U8G2_R0, CIRCLE_ANIMATION_SCK, CIRCLE_ANIMATION_MOSI,
 *                                      CIRCLE_ANIMATION_CS, CIRCLE_ANIMATION_DC, CIRCLE_ANIMATION_RST);
 *
 *  void setup() {
 *    u8g2.begin();
 *  }
 *
 *  void loop() {
 *    animateCircle(u8g2, u8g2.getDisplayWidth(), u8g2.getDisplayHeight() / 2, 5);
 *  }
 */

void animateCircle(U8G2 &u8g2, int startX, int startY, int radius);

#endif // CIRCLEANIMATION_H
