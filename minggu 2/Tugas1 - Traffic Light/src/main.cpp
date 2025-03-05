#include <Arduino.h>

// mendeklarasikan variabel sesuai nomor pin pada ESP32
int LampuMerah = 25;
int LampuKuning = 26;
int LampuHijau = 27;

void setup() {
  Serial.begin(115200);  // Inisialisasi komunikasi Serial
  Serial.println("Traffic Light");

  //pin output untuk mengalirkan listrik ke lampu
  pinMode(LampuMerah, OUTPUT);
  pinMode(LampuKuning, OUTPUT);
  pinMode(LampuHijau, OUTPUT);
}

void loop() {
  digitalWrite(LampuMerah, HIGH);
  Serial.println("Merah Nyala");
  delay(8000); // waktu lampu nyala
  digitalWrite(LampuMerah, LOW);
  

  digitalWrite(LampuHijau, HIGH);
  Serial.println("Hijau Nyala");
  delay(4000); // waktu lampu nyala
  digitalWrite(LampuHijau, LOW);
  

  digitalWrite(LampuKuning, HIGH);
  Serial.println("Kuning Nyala");
  delay(2000); // waktu lampu nyala
  digitalWrite(LampuKuning, LOW);
  

}
