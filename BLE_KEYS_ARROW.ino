#include <BleKeyboard.h>

BleKeyboard bleKeyboard;
const int GP_UP=15;
const int GP_DOWN = 2;
const int GP_LEFT=4;
const int GP_RIGHT = 5;
const int GP_EN=18;
void setup() {
  Serial.begin(115200);
  pinMode(GP_UP,INPUT_PULLUP);
  pinMode(GP_DOWN,INPUT_PULLUP );
  pinMode(GP_LEFT,INPUT_PULLUP);
  pinMode(GP_RIGHT,INPUT_PULLUP);
  pinMode(GP_EN,INPUT_PULLUP);
  Serial.println("Starting BLE work!");
  bleKeyboard.begin();
}
void loop() {
  if(bleKeyboard.isConnected()) {
    Serial.println("bluetooth is connected 'Hello world'...");
    //bleKeyboard.print("Hello world");
    delay(100);
    if (digitalRead(GP_UP) == LOW) {
      Serial.println("Moving cursor UP...");
      bleKeyboard.write(KEY_UP_ARROW);
      delay(100);
    }
    if (digitalRead(GP_DOWN) == LOW) {
      Serial.println("Moving cursor down...");
      bleKeyboard.write(KEY_DOWN_ARROW);
      delay(100);
    }
    if (digitalRead(GP_LEFT) == LOW) {
      Serial.println("Moving cursor left...");
      bleKeyboard.write(KEY_LEFT_ARROW);
      delay(100);
    }
    if (digitalRead(GP_RIGHT) == LOW) {
      Serial.println("Moving cursor right...");
      bleKeyboard.write(KEY_RIGHT_ARROW);
      delay(100);
    }
    if (digitalRead(GP_EN) == LOW) {
      Serial.println("Moving cursor Enter key...");
      bleKeyboard.write(KEY_NUM_ENTER);
      delay(100);
    }
  }
}
