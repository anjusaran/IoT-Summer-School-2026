# ESP32 BLE Sensor Dashboard

## Description

This project broadcasts DHT11 sensor data over Bluetooth Low Energy (BLE)
every 3 seconds.

The following data is available through BLE GATT characteristics:

- Temperature (°C)
- Humidity (%)
- Timestamp (seconds since ESP32 started)

Compatible BLE scanner apps:

- nRF Connect
- LightBlue

---

## Hardware

ESP32 Dev Board

DHT11 Sensor

Connections:

DHT11 VCC  -> ESP32 3.3V

DHT11 DATA -> GPIO4

DHT11 GND  -> GND

---

## BLE Service UUID

12345678-1234-1234-1234-1234567890ab

---

## Characteristics

Temperature

UUID:

12345678-1234-1234-1234-1234567890ac

Properties:

READ

NOTIFY

---

Humidity

UUID:

12345678-1234-1234-1234-1234567890ad

Properties:

READ

NOTIFY

---

Timestamp

UUID:

12345678-1234-1234-1234-1234567890ae

Properties:

READ

NOTIFY

---

## Update Rate

Every 3 seconds

---

## How to Test

1. Upload the sketch to ESP32.
2. Open nRF Connect or LightBlue on your phone.
3. Scan for BLE devices.
4. Connect to:

ESP32 Sensor Dashboard

5. Expand the custom service.
6. Read or subscribe to the three characteristics.
7. Observe Temperature, Humidity, and Timestamp updating every 3 seconds.