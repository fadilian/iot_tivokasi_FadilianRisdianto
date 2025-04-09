#include <Arduino.h>

// Pin konfigurasi
const int trigPin = 18;
const int echoPin = 19;

const int ledHijau = 23; // LED hijau menyala jika objek dekat
const int ledMerah = 22; // LED merah menyala jika tidak ada objek

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledHijau, OUTPUT);
  pinMode(ledMerah, OUTPUT);

  Serial.begin(115200);
}

void loop() {
  // Trigger sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Baca pantulan echo
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Jarak: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance > 0 && distance < 20) {
    digitalWrite(ledHijau, HIGH);
    digitalWrite(ledMerah, LOW);
  } else {
    digitalWrite(ledHijau, LOW);
    digitalWrite(ledMerah, HIGH);
  }

  delay(300);
}
