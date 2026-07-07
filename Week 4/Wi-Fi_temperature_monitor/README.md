# Wi-Fi Temperature Monitor (ESP32 + DHT22)

## Objective
Build a Wi-Fi-enabled temperature monitoring system using an ESP32. The ESP32 connects to a Wi-Fi network and hosts a web server that displays live temperature and humidity readings from a DHT22 sensor. The webpage also allows the user to toggle an LED and displays the device uptime.

---

## Components Used

- ESP32 DevKit V1
- DHT22 Sensor (DHT11 can also be used by changing the sensor type in the code)
- LED
- 220Ω Resistor
- Jumper Wires

---

## Circuit Connections

### DHT22

| DHT22 Pin | ESP32 Pin |
|------------|-----------|
| VCC | 3.3V |
| DATA | GPIO 4 |
| GND | GND |

### LED

| LED Pin | ESP32 Pin |
|----------|-----------|
| Anode (+) | GPIO 2 (through 220Ω resistor) |
| Cathode (-) | GND |

---

## Features

- Connects ESP32 to a Wi-Fi network.
- Hosts an HTTP web server.
- Displays:
  - Temperature
  - Humidity
  - Device uptime
- Automatically refreshes every 10 seconds.
- Allows LED ON/OFF control through a web page button.

---

## Libraries Used

- WiFi.h
- WebServer.h
- DHT.h (Adafruit DHT Sensor Library)

---

## How to Run

1. Open the project in Arduino IDE or Wokwi.
2. Install the required libraries.
3. Update the Wi-Fi credentials:

```cpp
const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";
```

4. Upload the program to the ESP32.
5. Open the Serial Monitor (115200 baud).
6. Note the IP address displayed.
7. Open the IP address in a web browser.

Example:

```
http://192.168.1.108
```

---

## Expected Output

The web page displays:

- Temperature (°C)
- Humidity (%)
- LED Status
- Toggle LED Button
- Device Uptime

The page refreshes automatically every 10 seconds.

---

## Folder Structure

```
week4/
└── wifi_webserver/
    ├── wifi_webserver.ino
    ├── README.md
    └── screenshots/
        └── webpage.png
```

---

## Notes

- This project was developed using an ESP32.
- During simulation in Wokwi, browser access to the web server may require the Wokwi Private Gateway feature. On a physical ESP32 connected to the same Wi-Fi network as the computer, the web page can be accessed directly using the IP address displayed in the Serial Monitor.