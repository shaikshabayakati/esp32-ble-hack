#include <Arduino.h>
#include <HijelHID_BLEKeyboard.h>

HijelHID_BLEKeyboard keyboard;

#define BUTTON_PIN 21

bool lastButtonState = HIGH;

void setup() {
  Serial.begin(115200);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  keyboard.begin();
}

void loop() {
  bool currentState = digitalRead(BUTTON_PIN);

  if (lastButtonState == HIGH && currentState == LOW) {
    delay(50); // Debounce

    if (digitalRead(BUTTON_PIN) == LOW && keyboard.isConnected()) {
      // Open Notepad
      keyboard.press(KEY_LGUI);
      keyboard.tap(KEY_R);
      keyboard.releaseAll();
      delay(700);

      keyboard.print("notepad");
      keyboard.tap(KEY_RETURN);
      delay(2000);

      // Write warning message
      keyboard.println("hello you are being scammed");
      keyboard.println();

      // Fake pseudocode - text only
      keyboard.println("SYSTEM_INIT()");
      keyboard.println("CONNECTING_TO_REMOTE_SERVER...");
      keyboard.println("AUTHENTICATION_BYPASS = TRUE");
      keyboard.println("SCANNING_LOCAL_NETWORK...");
      keyboard.println("FIREWALL_STATUS = DISABLED");
      keyboard.println("ACCESS_LEVEL = ADMINISTRATOR");
      keyboard.println("ENCRYPTION_KEY = ********");

      delay(800);

      // Open YouTube video
      keyboard.press(KEY_LGUI);
      keyboard.tap(KEY_R);
      keyboard.releaseAll();
      delay(700);

      keyboard.print(
        "https://www.youtube.com/watch?v=_6XiJ73XBfA&autoplay=1"
      );
      keyboard.tap(KEY_RETURN);
      keyboard.releaseAll();

      Serial.println("Done!");
    }
  }

  lastButtonState = currentState;
  delay(10);
}
