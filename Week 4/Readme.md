# REST API – Weather Data Fetcher

## Overview

This project uses an ESP32 to connect to a Wi-Fi network and fetch real-time weather data from the OpenWeatherMap API. It also reads local temperature and humidity from a DHT11 sensor and compares these values with the weather data received from the API. The results are displayed on the Serial Monitor.

## Features

* Connects ESP32 to a Wi-Fi network
* Fetches current weather data from the OpenWeatherMap REST API
* Reads local temperature and humidity using a DHT11 sensor
* Displays:

  * City Name
  * Weather Description
  * API Temperature
  * Local DHT11 Temperature
  * Temperature Difference
  * API Humidity
  * Local DHT11 Humidity
  * Humidity Difference
* Stores Wi-Fi credentials and API key in a separate `config.h` file
* Uses `.gitignore` to prevent the API key from being committed to GitHub

## Hardware Required

* ESP32 Development Board
* DHT11 Sensor (DHT22 may be used in Wokwi simulation)
* USB Cable
* Breadboard and Jumper Wires

## Software Requirements

* Arduino IDE 2.x
* ESP32 Board Package
* Adafruit DHT Sensor Library
* Adafruit Unified Sensor Library
* ArduinoJson Library

## Circuit Connections

| DHT11/DHT22 Pin | ESP32 Pin     |
| --------------- | ------------- |
| VCC             | 3.3V          |
| DATA            | GPIO4         |
| GND             | GND           |
| NC (if present) | Not Connected |



## Configuration

Create a `config.h` file with the following information:

* Wi-Fi SSID
* Wi-Fi Password
* OpenWeatherMap API Key
* City Name
* Country Code

Example:

```cpp
const char* WIFI_SSID = "Anju's iPhone";
const char* WIFI_PASSWORD = "Anjali@2425";

const char* API_KEY = "YOUR_OPENWEATHERMAP_API_KEY";

const char* CITY = "Jammu";
const char* COUNTRY = "IN";
```

## Git Ignore

To protect your API key, add the following line to `.gitignore`:

```text
config.h
```

## Working

1. ESP32 connects to the configured Wi-Fi network.
2. The DHT11 sensor measures the local temperature and humidity.
3. ESP32 sends an HTTP GET request to the OpenWeatherMap REST API.
4. The JSON response is parsed using the ArduinoJson library.
5. Weather information is extracted and displayed on the Serial Monitor.
6. The program compares the API values with the local sensor readings and prints the differences.
7. The process repeats every 10 seconds.

## Sample Serial Output

```text
WiFi Connected

----------------------------
City: Jammu
Weather: scattered clouds

API Temperature: 31.4 °C
Local Temperature: 29.0 °C
Temperature Difference: -2.4 °C

API Humidity: 63 %
Local Humidity: 69 %
Humidity Difference: 6 %
----------------------------
```

## Learning Outcomes

* Connect an ESP32 to a Wi-Fi network
* Use REST APIs from embedded devices
* Perform HTTP GET requests
* Parse JSON data using ArduinoJson
* Interface DHT sensors with ESP32
* Compare cloud-based weather data with local sensor readings
* Secure API credentials using `config.h` and `.gitignore`

## Author

**Name:** Anju
**Course:** IoT Summer School 2026
**Project:** Q35 – REST API Weather Data Fetcher
