#include <Arduino.h>
#include <TM1640.h>

// ピンの設定
#define DATA_PIN 3  // データピン (TM1640のDIN)
#define CLOCK_PIN 2 // クロックピン (TM1640のSCK)

// ディスプレイ設定
#define NUM_DIGITS 16 // ディスプレイ数
#define BRIGHTNESS 7  // 輝度（0から7までの範囲）

// TM1640インスタンスの作成
TM1640 tm1640(CLOCK_PIN, DATA_PIN);

void setup()
{
  tm1640.setDisplayToString("HALO");
  delay(500); // wait
}

void loop()
{

  // TM1640試してたんだけど、ラズパイピコの消費電力と１６個の７セグLEDダイナミック点灯は、おそらく電力不足なきがした…
  // ちっと組みなおさないといけないや。

  // サンプルプログラム
  tm1640.setupDisplay(true, 7);                                        // sometimes noise on the line may change the intensity level
  int nTime = ((millis() / 1000) / 60) * 100 + (millis() / 1000) % 60; // minutes+seconds as integer
  tm1640.setDisplayToDecNumber(nTime, _BV(4));                         // display dot on digit 4
  delay(500);                                                          // wait
  tm1640.setDisplayToDecNumber(nTime, _BV(3));                         // display colon on digit 3
  delay(500);                                                          // wait

  // for (int i = 0; i < NUM_DIGITS; i++)
  // {
  //   tm1640.setSegments(0x7F, i); // 7セグメントの「8」を表示（0x7Fは「8」のパターン）
  // }
  // delay(1000);
}

// void setup()
// {
//   // initial set up
// }

// void loop()
// {
//   // something happy todo
// }