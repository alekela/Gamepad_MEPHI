#include <SoftwareSerial.h>

// втыкаем rx и tx блютуз модуля в пины 2 и 3 (tx в 2, rx в 3)
SoftwareSerial mySerial(2, 3);  // указываем пины, которые будут выполнять роль rx и tx

void setup()  {
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  mySerial.begin(38400);
  Serial.begin(9600);
  delay(500);
  Serial.write("TEST\n");
}

void loop() {
  if (mySerial.available()){
    Serial.write(mySerial.read());
  }
  if (Serial.available()) {
    mySerial.write(Serial.read());
  }
}
