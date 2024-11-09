// CircleAnimation.cpp

#include "CircleAnimation.h"

// Function: animateCircle
// 関数: animateCircle
// -----------------------
// Moves a circle from right to left across the screen.
// 画面を横切って右から左に円を移動させます。
//
// Parameters:
// 引数:
// u8g2       - The display object to draw on. (描画に使用するディスプレイオブジェクト)
// startX     - The starting X position of the circle. (円の開始位置X)
// startY     - The starting Y position of the circle. (円の開始位置Y)
// radius     - The radius of the circle. (円の半径)

void animateCircle(U8G2 &u8g2, int startX, int startY, int radius)
{
  int circleX = startX;

  while (circleX > -radius)
  {
    u8g2.setDrawColor(0);                       // Clear the previous position. (前の位置を消去)
    u8g2.drawDisc(circleX + 2, startY, radius); // Draw the previous position. (前の位置を描画)
    u8g2.setDrawColor(1);                       // Set the draw color to white. (描画色を白に設定)
    u8g2.drawDisc(circleX, startY, radius);     // Draw the current position. (現在の位置を描画)
    u8g2.sendBuffer();                          // Update the display. (表示を更新)
    circleX -= 2;                               // Move the circle to the left. (円を左に移動)
    delay(50);                                  // Set the movement speed. (移動速度)
  }
}
