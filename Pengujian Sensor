#include <WiFi.h>
#include "Ultrasonic.h"

// Pin Sensor
#define WATER_SENSOR 32
Ultrasonic ultrasonic(27);

// Variabel
long jarakAir;
int statusAir;

void setup() {
  Serial.begin(9600);
  pinMode(WATER_SENSOR, INPUT);
}

void loop() {

  // Baca sensor ultrasonik
  jarakAir = ultrasonic.MeasureInCentimeters();

  // Baca sensor air digital
  statusAir = !digitalRead(WATER_SENSOR);

  // ---- Output ke Serial Monitor ----
  Serial.print(jarakAir);
  Serial.println(" cm");     

  if(statusAir == HIGH){
    Serial.println("AIR TERDETEKSI");
  } else {
    Serial.println("TIDAK ADA AIR");
  }

  Serial.println(); // pemisah

  delay(1000);
}
