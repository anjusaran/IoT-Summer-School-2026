#include <WiFi.h>
#include <WebServer.h>
#include <DHT.h>

#define DHTPIN 4
#define DHTTYPE DHT22
#define LED_PIN 2

const char* ssid = "Wokwi-GUEST";
const char* password = "";

DHT dht(DHTPIN, DHTTYPE);
WebServer server(80);

bool ledState = false;

void handleRoot() {

  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  String html = "<!DOCTYPE html><html>";
  html += "<head>";
  html += "<meta http-equiv='refresh' content='10'>";
  html += "<title>ESP32 Weather Station</title>";
  html += "</head>";

  html += "<body style='font-family:Arial;text-align:center;'>";

  html += "<h1>ESP32 Wi-Fi Temperature Monitor</h1>";

  html += "<h2>Temperature</h2>";
  html += "<p style='font-size:30px;'>";
  html += String(temp);
  html += " &deg;C</p>";

  html += "<h2>Humidity</h2>";
  html += "<p style='font-size:30px;'>";
  html += String(hum);
  html += " %</p>";

  html += "<h2>LED Status : ";
  html += (ledState ? "ON" : "OFF");
  html += "</h2>";

  html += "<a href='/toggle'>";
  html += "<button style='font-size:22px;padding:12px;'>Toggle LED</button>";
  html += "</a>";

  unsigned long seconds = millis() / 1000;

  int hrs = seconds / 3600;
  int mins = (seconds % 3600) / 60;
  int secs = seconds % 60;

  html += "<h3>Uptime</h3>";
  html += String(hrs) + "h ";
  html += String(mins) + "m ";
  html += String(secs) + "s";

  html += "</body></html>";

  server.send(200, "text/html", html);
}

void handleToggle() {

  ledState = !ledState;

  digitalWrite(LED_PIN, ledState);

  server.sendHeader("Location", "/");
  server.send(303);
}

void setup() {

  Serial.begin(115200);

  pinMode(LED_PIN, OUTPUT);

  digitalWrite(LED_PIN, LOW);

  dht.begin();

  WiFi.begin(ssid, password);

  Serial.print("Connecting");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();

  Serial.println("Connected!");

  Serial.print("IP Address: ");

  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);

  server.on("/toggle", handleToggle);

  server.begin();

  Serial.println("Web Server Started");
}

void loop() {

  server.handleClient();

}