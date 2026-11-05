
#define UP_BUTTON 7
#define SELECT_BUTTON 8
#define DOWN_BUTTON 9

void setup() {
  Serial.begin(115200);

  pinMode(UP_BUTTON, INPUT_PULLUP);
  pinMode(SELECT_BUTTON, INPUT_PULLUP);
  pinMode(DOWN_BUTTON, INPUT_PULLUP);

  Serial.println("ClipCharm button test ready!");
}

void loop() {
  if (digitalRead(UP_BUTTON) == LOW) {
    Serial.println("UP pressed!");
    delay(250);
  }

  if (digitalRead(SELECT_BUTTON) == LOW) {
    Serial.println("SELECT pressed!");
    delay(250);
  }

  if (digitalRead(DOWN_BUTTON) == LOW) {
    Serial.println("DOWN pressed!");
    delay(250);
  }
}
