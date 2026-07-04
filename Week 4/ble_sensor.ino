#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>
#include <DHT.h>

#define DHTPIN 4
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

// UUIDs
#define SERVICE_UUID      "12345678-1234-1234-1234-1234567890ab"
#define TEMP_UUID         "12345678-1234-1234-1234-1234567890ac"
#define HUM_UUID          "12345678-1234-1234-1234-1234567890ad"
#define TIME_UUID         "12345678-1234-1234-1234-1234567890ae"

BLECharacteristic *tempCharacteristic;
BLECharacteristic *humCharacteristic;
BLECharacteristic *timeCharacteristic;

unsigned long lastUpdate = 0;

void setup() {

  Serial.begin(115200);
  dht.begin();

  BLEDevice::init("ESP32 Sensor Dashboard");

  BLEServer *server = BLEDevice::createServer();

  BLEService *service = server->createService(SERVICE_UUID);

  tempCharacteristic =
      service->createCharacteristic(
          TEMP_UUID,
          BLECharacteristic::PROPERTY_READ |
          BLECharacteristic::PROPERTY_NOTIFY);

  humCharacteristic =
      service->createCharacteristic(
          HUM_UUID,
          BLECharacteristic::PROPERTY_READ |
          BLECharacteristic::PROPERTY_NOTIFY);

  timeCharacteristic =
      service->createCharacteristic(
          TIME_UUID,
          BLECharacteristic::PROPERTY_READ |
          BLECharacteristic::PROPERTY_NOTIFY);

  // Add descriptors
  tempCharacteristic->addDescriptor(new BLE2902());
  humCharacteristic->addDescriptor(new BLE2902());
  timeCharacteristic->addDescriptor(new BLE2902());

  service->start();

  BLEAdvertising *advertising = BLEDevice::getAdvertising();
  advertising->addServiceUUID(SERVICE_UUID);
  advertising->start();

  Serial.println("BLE Sensor Dashboard Started");
}

void loop() {

  if (millis() - lastUpdate >= 3000) {

    lastUpdate = millis();

    float temperature = dht.readTemperature();
    float humidity = dht.readHumidity();

    if (isnan(temperature) || isnan(humidity)) {
      Serial.println("DHT Read Failed");
      return;
    }

    String timestamp = String(millis() / 1000);

    tempCharacteristic->setValue(String(temperature).c_str());
    humCharacteristic->setValue(String(humidity).c_str());
    timeCharacteristic->setValue(timestamp.c_str());

    tempCharacteristic->notify();
    humCharacteristic->notify();
    timeCharacteristic->notify();

    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.print(" °C  ");

    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.print("%  ");

    Serial.print("Timestamp: ");
    Serial.println(timestamp);
  }
}