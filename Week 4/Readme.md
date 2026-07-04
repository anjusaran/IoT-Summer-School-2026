# Bluetooth LED Controller

## Hardware
- Arduino Uno
- HC-05 Bluetooth Module
- Red, Green, Blue LEDs
- 220Ω resistors

## Bluetooth Pairing

1. Power the Arduino.
2. The HC-05 LED will blink rapidly.
3. Open Bluetooth Settings on your Android phone.
4. Search for devices.
5. Select "HC-05".
6. Enter PIN:
   1234
   or
   0000
7. Once paired, open any Bluetooth Terminal app.
8. Connect to HC-05.
9. Send the following commands:

R → Red LED ON
G → Green LED ON
B → Blue LED ON
X → All LEDs OFF
F → Flash all LEDs 5 times