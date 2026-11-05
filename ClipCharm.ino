
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

// Direct references to all 69 animation frames
const unsigned char* frames[] = {
  clipcharm_frame_0,  clipcharm_frame_1,
  clipcharm_frame_2,  clipcharm_frame_3,
  clipcharm_frame_4,  clipcharm_frame_5,
  clipcharm_frame_6,  clipcharm_frame_7,
  clipcharm_frame_8,  clipcharm_frame_9,
  clipcharm_frame_10, clipcharm_frame_11,
  clipcharm_frame_12, clipcharm_frame_13,
  clipcharm_frame_14, clipcharm_frame_15,
  clipcharm_frame_16, clipcharm_frame_17,
  clipcharm_frame_18, clipcharm_frame_19,
  clipcharm_frame_20, clipcharm_frame_21,
  clipcharm_frame_22, clipcharm_frame_23,
  clipcharm_frame_24, clipcharm_frame_25,
  clipcharm_frame_26, clipcharm_frame_27,
  clipcharm_frame_28, clipcharm_frame_29,
  clipcharm_frame_30, clipcharm_frame_31,
  clipcharm_frame_32, clipcharm_frame_33,
  clipcharm_frame_34, clipcharm_frame_35,
  clipcharm_frame_36, clipcharm_frame_37,
  clipcharm_frame_38, clipcharm_frame_39,
  clipcharm_frame_40, clipcharm_frame_41,
  clipcharm_frame_42, clipcharm_frame_43,
  clipcharm_frame_44, clipcharm_frame_45,
  clipcharm_frame_46, clipcharm_frame_47,
  clipcharm_frame_48, clipcharm_frame_49,
  clipcharm_frame_50, clipcharm_frame_51,
  clipcharm_frame_52, clipcharm_frame_53,
  clipcharm_frame_54, clipcharm_frame_55,
  clipcharm_frame_56, clipcharm_frame_57,
  clipcharm_frame_58, clipcharm_frame_59,
  clipcharm_frame_60, clipcharm_frame_61,
  clipcharm_frame_62, clipcharm_frame_63,
  clipcharm_frame_64, clipcharm_frame_65,
  clipcharm_frame_66, clipcharm_frame_67,
  clipcharm_frame_68
};

void setup() {
  Serial.begin(115200);
  Wire.begin(5, 6);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED initialization failed!");
    while (true) delay(1000);
  }

  Serial.println("ClipCharm animation ready!");
}

void loop() {
  for (int i = 0; i < CLIPCHARM_FRAME_COUNT; i++) {

    display.clearDisplay();

    display.drawBitmap(
      0, 0,
      frames[i],
      CLIPCHARM_WIDTH,
      CLIPCHARM_HEIGHT,
      SSD1306_WHITE
    );

    display.display();

    delay(70);
  }
}
