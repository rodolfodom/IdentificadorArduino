#include <SoftwareSerial.h>

SoftwareSerial Serial1(10, 11);

void setup() {
  Serial.begin(9600);
  Serial1.begin(38400);

  Serial.println("Configuracion");
}

void loop() {
  /*
  Serial1.write("1");
  Serial.println("Enviado");
  delay(2000);
  */
  
  if(Serial1.available()){
    Serial.write(Serial1.read());
  }

  if(Serial.available()){
    Serial1.write(Serial.read());
  }
  
}
