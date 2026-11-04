#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "clipcharm.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

Adafruit_SSD1306 display(
  SCREEN_WIDTH,
  SCREEN_HEIGHT,
  &Wire,
  OLED_RESET
);

void setup() {
  Wire.begin(5, 6);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    while (true);
  }

  display.clearDisplay();

  display.drawBitmap(
    0, 0,
    clipcharm_frame_0,
    128, 64,
    SSD1306_WHITE
  );

  display.display();
}

void showFrame(const unsigned char* frame) {
  display.clearDisplay();
  display.drawBitmap(0, 0, frame, 128, 64, SSD1306_WHITE);
  display.display();
  delay(700);
}

void loop() {
  for (int i = 0; i < CLIPCHARM_FRAME_COUNT; i++) {

    const unsigned char* frame =
      (const unsigned char*)pgm_read_ptr(&clipcharm_frames[i]);

    display.clearDisplay();

    display.drawBitmap(
      0, 0,
      frame,
      CLIPCHARM_WIDTH,
      CLIPCHARM_HEIGHT,
      SSD1306_WHITE
    );

    display.display();

    delay(clipcharm_delays[i]);
  }
}