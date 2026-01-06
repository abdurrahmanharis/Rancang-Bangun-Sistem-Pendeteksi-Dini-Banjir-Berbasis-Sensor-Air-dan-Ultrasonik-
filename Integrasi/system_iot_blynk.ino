#define BLYNK_TEMPLATE_ID "TMPL6ej-IPqPo"
#define BLYNK_TEMPLATE_NAME "Siaga Banjir"
#define BLYNK_AUTH_TOKEN "nTlnWVNxBY0b96M1O2EjNisdOXAFmS8X"

#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include "Ultrasonic.h"

char ssid[] = "Ryan D Gracia";
char pass[] = "99999999";

// Pin
#define WATER_SENSOR 32
#define LED1 13
#define LED2 15

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

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop()
{
  Blynk.run();

  RangeInCentimeters = ultrasonic.MeasureInCentimeters();
  waterState = !digitalRead(WATER_SENSOR);

  Serial.print("Jarak air: ");
  Serial.print(RangeInCentimeters);
  Serial.println(" cm");

  Serial.print("Status sensor air digital: ");
  Serial.println(waterState);

  // LOGIKA
  if (waterState == HIGH)
  {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, HIGH);
    Serial.println("STATUS: AIR TERDETEKSI");

    Blynk.virtualWrite(V2, "BAHAYA BANJIR TINGGI");
  }
  else if (RangeInCentimeters <= 15)
  {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
    Serial.println("STATUS: JARAK DEKAT");

    Blynk.virtualWrite(V2, "WASPADA BANJIR");
  }
  else
  {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    Serial.println("STATUS: AMAN");

    Blynk.virtualWrite(V2, "AMAN");
  }

  // Kirim data ke Blynk
  Blynk.virtualWrite(V0, RangeInCentimeters);
  Blynk.virtualWrite(V1, waterState);

  Serial.println();
  delay(1500);
}
