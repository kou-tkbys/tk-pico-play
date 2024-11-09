#include "CubeAnimation.h"
#include <math.h>

/**
 * Cube vertices
 * 立方体の頂点
 */
float vertices[8][3] = {
    {-1, -1, -1}, {1, -1, -1}, {1, 1, -1}, {-1, 1, -1}, {-1, -1, 1}, {1, -1, 1}, {1, 1, 1}, {-1, 1, 1}};

/**
 * Cube edges: which vertices are connected
 * 立方体のエッジ（どの頂点を結ぶか）
 */
int edges[12][2] = {
    {0, 1}, {1, 2}, {2, 3}, {3, 0}, {4, 5}, {5, 6}, {6, 7}, {7, 4}, {0, 4}, {1, 5}, {2, 6}, {3, 7}};

/**
 * Function to draw thick lines
 * 太い線を描画する関数
 */
void drawThickLine(Adafruit_SSD1306 &display, int x1, int y1, int x2, int y2, int thickness)
{
    // Draw multiple lines based on thickness
    // 線の太さ分、複数の線を描画
    for (int i = -thickness; i <= thickness; i++)
    {
        display.drawLine(x1 + i, y1, x2 + i, y2, SSD1306_WHITE);
    }
}

/**
 * Function to draw a rotated cube using rotation matrices
 * 回転行列を使って立方体を描画する関数
 */
void drawCube(Adafruit_SSD1306 &display, float angleX, float angleY, int lineThickness, int screenWidth, int screenHeight)
{
    // Draw the edges of the cube
    // 立方体のエッジ（線）を描画
    for (int i = 0; i < 12; i++)
    {
        int v1 = edges[i][0];
        int v2 = edges[i][1];
        float x1 = vertices[v1][0];
        float y1 = vertices[v1][1];
        float z1 = vertices[v1][2];
        float x2 = vertices[v2][0];
        float y2 = vertices[v2][1];
        float z2 = vertices[v2][2];

        // Rotate each vertex using rotation matrices
        // 回転行列を使って、各頂点を回転
        float tempX1 = x1 * cos(angleY) - z1 * sin(angleY);
        float tempZ1 = x1 * sin(angleY) + z1 * cos(angleY);
        z1 = tempZ1;
        x1 = tempX1;

        float tempY1 = y1 * cos(angleX) - z1 * sin(angleX);
        z1 = y1 * sin(angleX) + z1 * cos(angleX);
        y1 = tempY1;

        float tempX2 = x2 * cos(angleY) - z2 * sin(angleY);
        float tempZ2 = x2 * sin(angleY) + z2 * cos(angleY);
        z2 = tempZ2;
        x2 = tempX2;

        float tempY2 = y2 * cos(angleX) - z2 * sin(angleX);
        z2 = y2 * sin(angleX) + z2 * cos(angleX);
        y2 = tempY2;

        // Project the 3D coordinates onto a 2D plane
        // 2D平面に投影
        int screenX1 = screenWidth / 2 + (x1 * 10);
        int screenY1 = screenHeight / 2 - (y1 * 10);
        int screenX2 = screenWidth / 2 + (x2 * 10);
        int screenY2 = screenHeight / 2 - (y2 * 10);

        // Draw thick lines between the projected points
        // 太い線を描画
        drawThickLine(display, screenX1, screenY1, screenX2, screenY2, lineThickness);
    }
}
