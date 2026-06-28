/*
 * Project: Traffic Light System
 * Author: Your Name
 * Date: 28-06-2026
 * Description:
 * Simulates a traffic light with pedestrian crossing.
 */

const int RED = 13;
const int YELLOW = 12;
const int GREEN = 11;
const int BUTTON = 7;

void showRed() {
  digitalWrite(RED, HIGH);
  digitalWrite(YELLOW, LOW);
  digitalWrite(GREEN, LOW);

  Serial.print(millis());
  Serial.println(" ms : RED");
}

void showYellow() {
  digitalWrite(RED, LOW);
  digitalWrite(YELLOW, HIGH);
  digitalWrite(GREEN, LOW);

  Serial.print(millis());
  Serial.println(" ms : YELLOW");
}

void showGreen() {
  digitalWrite(RED, LOW);
  digitalWrite(YELLOW, LOW);
  digitalWrite(GREEN, HIGH);

  Serial.print(millis());
  Serial.println(" ms : GREEN");
}

void setup() {

  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);

  pinMode(BUTTON, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop() {

  // Pedestrian button pressed
  if (digitalRead(BUTTON) == LOW) {
    showRed();
    Serial.print(millis());
    Serial.println(" ms : Pedestrian Crossing");
    delay(8000);
    return;
  }

  // RED for 5 seconds
  showRed();
  delay(5000);

  if (digitalRead(BUTTON) == LOW) {
    showRed();
    Serial.print(millis());
    Serial.println(" ms : Pedestrian Crossing");
    delay(8000);
    return;
  }

  // YELLOW for 2 seconds
  showYellow();
  delay(2000);

  if (digitalRead(BUTTON) == LOW) {
    showRed();
    Serial.print(millis());
    Serial.println(" ms : Pedestrian Crossing");
    delay(8000);
    return;
  }

  // GREEN for 4 seconds
  showGreen();
  delay(4000);
}