
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

#define UP_BUTTON 7
#define SELECT_BUTTON 8
#define DOWN_BUTTON 9

Adafruit_SSD1306 display(
  SCREEN_WIDTH,
  SCREEN_HEIGHT,
  &Wire,
  OLED_RESET
);

// Menu options
const char* menuItems[] = {
  "Games",
  "Display"
};

const int menuCount = 2;
int selectedItem = 0;

void drawMenu() {
  display.clearDisplay();

  // Header
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(34, 5);
  display.println("CLIPCHARM");

  display.drawLine(0, 17, 127, 17, SSD1306_WHITE);

  // Menu options
  for (int i = 0; i < menuCount; i++) {

    int y = 25 + (i * 18);

    if (i == selectedItem) {
      display.fillRect(8, y - 2, 112, 16, SSD1306_WHITE);
      display.setTextColor(SSD1306_BLACK);
    } else {
      display.setTextColor(SSD1306_WHITE);
    }

    display.setCursor(20, y);
    display.setTextSize(1);
    display.println(menuItems[i]);
  }

  display.display();
}

void setup() {
  Serial.begin(115200);

  Wire.begin(5, 6);

  pinMode(UP_BUTTON, INPUT_PULLUP);
  pinMode(SELECT_BUTTON, INPUT_PULLUP);
  pinMode(DOWN_BUTTON, INPUT_PULLUP);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED failed!");
    while (true);
  }

  drawMenu();
}

void loop() {

  if (digitalRead(UP_BUTTON) == LOW) {
    selectedItem--;

    if (selectedItem < 0) {
      selectedItem = menuCount - 1;
    }

    drawMenu();
    delay(200);
  }

  if (digitalRead(DOWN_BUTTON) == LOW) {
    selectedItem++;

    if (selectedItem >= menuCount) {
      selectedItem = 0;
    }

    drawMenu();
    delay(200);
  }

  if (digitalRead(SELECT_BUTTON) == LOW) {
    Serial.print("Selected: ");
    Serial.println(menuItems[selectedItem]);

    delay(200);
  }
}
