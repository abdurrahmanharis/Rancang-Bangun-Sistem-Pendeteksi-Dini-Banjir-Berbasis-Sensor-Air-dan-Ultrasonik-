#define LED1 13
#define LED2 15

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
}

void loop() {
  digitalWrite(LED1, HIGH); digitalWrite(LED2, LOW); delay(2000);
  digitalWrite(LED1, LOW); digitalWrite(LED2, HIGH); delay(2000);
  digitalWrite(LED1, LOW); digitalWrite(LED2, LOW); delay(2000);
}
