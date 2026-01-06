#include <WiFi.h>

const char* ssid = "Ryan D Gracia";
const char* pass = "99999999";

void setup() {
  Serial.begin(9600);
  delay(1000);

  Serial.println("Menghubungkan ke WiFi...");
  WiFi.begin(ssid, pass);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("ESP32 berhasil terhubung ke WiFi!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
/// memastikan status wifi
}
