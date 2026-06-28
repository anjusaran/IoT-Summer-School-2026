# Environmental Monitoring Station

## Description

This project uses a DHT11 sensor to measure temperature and humidity every 2 seconds. The readings are displayed in CSV format on the Serial Monitor. A red LED indicates unsafe environmental conditions, while a green LED indicates normal conditions.

## Hardware

- Arduino Uno
- DHT11 Sensor
- Red LED
- Green LED
- 2 × 220 Ω Resistors
- Breadboard
- Jumper Wires

## Library

Library Name:
DHT sensor library by Adafruit

Version:
1.4.6

Dependency:
Adafruit Unified Sensor Library

## CSV Output

timestamp,temp_C,temp_F,humidity

## LED Conditions

Green LED:
Temperature ≤ 35°C and Humidity ≤ 80%

Red LED:
Temperature > 35°C or Humidity > 80%