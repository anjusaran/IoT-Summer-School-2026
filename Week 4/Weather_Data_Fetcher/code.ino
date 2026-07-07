#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include "DHT.h"

// --- Wi-Fi Settings ---
const char* ssid = " ";
const char* password = " ";

// --- OpenWeatherMap Config ---
const String apiKey = " "; 

// Coordinates
// Delhi
const String delhi_lat = "28.6520";
const String delhi_lon = "77.2315";
// IIT Jammu (Jagti / Nagrota Area)
const String jammu_lat = "32.8167";
const String jammu_lon = "74.9167";

// --- DHT11 Settings ---
#define DHTPIN 23       // GPIO Pin connected to DHT11 Data pin
#define DHTTYPE DHT11   // DHT 11
DHT dht(DHTPIN, DHTTYPE);

unsigned long lastTime = 0;
unsigned long timerDelay = 10000; // Fetch data every 10 seconds

void setup() {
  Serial.begin(115200);
  dht.begin();

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected to WiFi network successfully!");
}

void loop() {
  // Execute code at intervals set by timerDelay
  if ((millis() - lastTime) > timerDelay) {
    if (WiFi.status() == WL_CONNECTED) {
      
      Serial.println("\n================================================");
      
      // ----------------- DATA FOR DELHI -----------------
      Serial.println(">>> FETCHING DATA FOR DELHI <<<");
      fetchWeatherData("Delhi", delhi_lat, delhi_lon, true);

      // --------------- DATA FOR IIT JAMMU ---------------
      Serial.println("\n>>> DATA FOR IIT JAMMU <<<");
      
      // 1. Reading local DHT11 Sensor
      float localTemp = dht.readTemperature();
      float localHum = dht.readHumidity();
      
      if (isnan(localTemp) || isnan(localHum)) {
        Serial.println("❌ Failed to read from DHT11 sensor!");
      } else {
        Serial.print("Local Temperature (DHT11): ");
        Serial.print(localTemp);
        Serial.println(" °C");
        Serial.print("Local Humidity (DHT11): ");
        Serial.print(localHum);
        Serial.println(" %");
      }
      
      // 2. Fetching Remaining Data (Lat, Lon, AQI) from OpenWeatherMap
      fetchWeatherData("IIT Jammu", jammu_lat, jammu_lon, false);
      
      Serial.println("================================================");
      
    } else {
      Serial.println("WiFi Disconnected!");
    }
    lastTime = millis();
  }
}

// Helper function to handle OpenWeatherMap endpoints
void fetchWeatherData(String locName, String lat, String lon, bool fetchWeatherAPI) {
  HTTPClient http;
  JsonDocument doc;

  // --- 1. Fetch Weather Data (If enabled, e.g. for Delhi) ---
  if (fetchWeatherAPI) {
    String weatherUrl = "http://api.openweathermap.org/data/2.5/weather?lat=" + lat + "&lon=" + lon + "&appid=" + apiKey + "&units=metric";
    http.begin(weatherUrl);
    int httpResponseCode = http.GET();
    
    if (httpResponseCode == 200) {
      String payload = http.getString();
      deserializeJson(doc, payload);
      
      float temp = doc["main"]["temp"];
      int humidity = doc["main"]["humidity"];
      
      Serial.print("Latitude: "); Serial.println(lat);
      Serial.print("Longitude: "); Serial.println(lon);
      Serial.print("Temperature: "); Serial.print(temp); Serial.println(" °C");
      Serial.print("Humidity: "); Serial.print(humidity); Serial.println(" %");
    } else {
      Serial.print("Error fetching weather data code: "); Serial.println(httpResponseCode);
    }
    http.end();
  } else {
    // Just printing static local location data requested for IIT Jammu
    Serial.print("Latitude: "); Serial.println(lat);
    Serial.print("Longitude: "); Serial.println(lon);
  }

  // --- 2. Fetch Air Pollution Data (AQI) ---
  String pollutionUrl = "http://api.openweathermap.org/data/2.5/air_pollution?lat=" + lat + "&lon=" + lon + "&appid=" + apiKey;
  http.begin(pollutionUrl);
  int httpResponseCode = http.GET();
  
  if (httpResponseCode == 200) {
    String payload = http.getString();
    deserializeJson(doc, payload);
    
    int aqi = doc["list"][0]["main"]["aqi"];
    Serial.print("Air Quality Index (AQI): "); 
    Serial.print(aqi);
    
    // Interpret OpenWeather AQI scale (1 = Good, 5 = Very Poor)
    switch(aqi) {
      case 1: Serial.println(" (Good)"); break;
      case 2: Serial.println(" (Fair)"); break;
      case 3: Serial.println(" (Moderate)"); break;
      case 4: Serial.println(" (Poor)"); break;
      case 5: Serial.println(" (Very Poor)"); break;
      default: Serial.println(" (Unknown)"); break;
    }
  } else {
    Serial.print("Error fetching AQI data code: "); Serial.println(httpResponseCode);
  }
  http.end();
}