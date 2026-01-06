#include "Ultrasonic.h"

// Pin
#define WATER_SENSOR 32
#define LED1 13   // LED Hijau
#define LED2 15   // LED Merah

Ultrasonic ultrasonic(27);

// Variabel utama
long RangeInCentimeters;
int waterState;

void setup()
{
  Serial.begin(9600);

  pinMode(WATER_SENSOR, INPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);

  Serial.println("Sistem Monitoring Ketinggian Air (Offline)");
}

void loop()
{
  // Baca sensor
  RangeInCentimeters = ultrasonic.MeasureInCentimeters();
  waterState = !digitalRead(WATER_SENSOR);

  // Tampilkan di Serial Monitor
  Serial.print("Jarak air: ");
  Serial.print(RangeInCentimeters);
  Serial.println(" cm");

  Serial.print("Status sensor air digital: ");
  Serial.println(waterState);

  // LOGIKA STATUS
  if (waterState == HIGH)
  {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, HIGH);
    Serial.println("STATUS: AIR TERDETEKSI (BAHAYA BANJIR)");
  }
  else if (RangeInCentimeters <= 15)
  {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
    Serial.println("STATUS: JARAK DEKAT (WASPADA)");
  }
  else
  {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    Serial.println("STATUS: AMAN");
  }

  Serial.println();
  delay(1500);
}
