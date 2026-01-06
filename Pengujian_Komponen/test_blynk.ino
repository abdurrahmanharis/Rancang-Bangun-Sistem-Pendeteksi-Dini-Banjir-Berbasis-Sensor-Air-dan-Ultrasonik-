#define BLYNK_TEMPLATE_ID "TMPL6ej-IPqPo"
#define BLYNK_TEMPLATE_NAME "Siaga Banjir"
#define BLYNK_AUTH_TOKEN "nTlnWVNxBY0b96M1O2EjNisdOXAFmS8X"

#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "Ryan D Gracia";
char pass[] = "99999999";

void setup()
{
  Serial.begin(9600);
  delay(1000);

  Serial.println("Menghubungkan ke WiFi...");
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  Serial.println("ESP32 berhasil terhubung ke WiFi dan Blynk!");
}

void loop()
{
  Blynk.run();   // Menjaga koneksi tetap aktif
}
