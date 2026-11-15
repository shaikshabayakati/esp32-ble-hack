# ESP32 BLE Keyboard Demo

An ESP32 acts as a Bluetooth Low Energy keyboard for a paired Windows PC. A button press opens Notepad, types a mock scam warning and fictional system messages as plain text, then opens a YouTube link in the default browser.

## Hardware and software

- A BLE-capable ESP32 board with GPIO 21 exposed, a momentary push button, and two jumper wires
- A Windows PC with Bluetooth and the US keyboard layout selected
- Arduino IDE with the **esp32** board package from Espressif (3.x), **HijelHID_BLEKeyboard**, and **NimBLE-Arduino** (2.3.8 or later). See the [library's installation guide](https://github.com/HijelHub/HijelHID_BLEKeyboard#installation).

## Wiring

Connect one side of the button to **GPIO 21** and the other to **GND**. The sketch enables the internal pull-up, so the input reads LOW when pressed.

## Run the demo

1. Open [ESP32BLEKeyboardDemo.ino](ESP32BLEKeyboardDemo/ESP32BLEKeyboardDemo.ino) in Arduino IDE.
2. Select your ESP32 board and serial port, then upload the sketch.
3. In Windows Bluetooth settings, add the keyboard named **HijelHID KB**.
4. On the unlocked, paired PC, press the button. For serial feedback, open Serial Monitor at **115200 baud** and look for `Done!` after the keystrokes are sent.

If the text appears in the wrong window, give the Run dialog or Notepad more time to open by increasing the corresponding `delay()` in the sketch. Video autoplay depends on your browser settings.
