#include <Arduino.h>
#include "BarAnimation.h"

void setup()
{
  setupBarAnimation(); // BarAnimationの初期設定
}

void loop()
{
  updateBarAnimation(); // バーの高さ更新
  drawBarAnimation();   // バー描画
  delay(20);            // 更新速度調整
}