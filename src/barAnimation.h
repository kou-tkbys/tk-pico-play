// BarAnimation.h

#ifndef BARANIMATION_H
#define BARANIMATION_H

/*
 * Example Usage:
 * -----------------------
 * #include <Arduino.h>
 * #include "BarAnimation.h"

 * void setup()
 * {
 *   setupBarAnimation(); // BarAnimationの初期設定
 * }
 *
 * void loop()
 * {
 *   updateBarAnimation(); // バーの高さ更新
 *   drawBarAnimation();   // バー描画
 *   delay(20);            // 更新速度調整
 * }
 */

/**
 * Function: setupBarAnimation
 * -----------------------
 * Initializes the bar animation by setting up the display and random seed.
 * ディスプレイの初期化とランダムシードの設定を行い、バーアニメーションの準備をします。
 */
void setupBarAnimation();

/**
 * Function: updateBarAnimation
 * -----------------------
 * Updates the height of each bar using smoothing to create a smoother transition.
 * 各バーの高さを更新し、スムージングを適用して滑らかな遷移を作成します。
 */
void updateBarAnimation();

/**
 * Function: updateBarAnimation
 * -----------------------
 * Draws the bars on the display based on the current heights.
 * 現在の高さに基づいてディスプレイにバーを描画します。
 */
void drawBarAnimation();

#endif // BARANIMATION_H
