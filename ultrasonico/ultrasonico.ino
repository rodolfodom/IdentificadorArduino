#include <SoftwareSerial.h>

const float sonido = 34300.0;

const int trigger = 2; 
const int echo = 3; 

const int btn = 4;

const int led1 = 11;
const int led2 = 10;
const int led3 = 9;
const int led4 = 8;
const int led5 = 7;
const int led6 = 6;
const int led7 = 5;

const int RXPin = 12;
const int TXPin = 13;

const float distancia0 = 7.0;
const float distancia1 = 20.0;
const float distancia2 = 30.0;
const float distancia3 = 40.0;
const float distancia4 = 53.0;
const float distancia5 = 63.0;
const float distancia6 = 73.0;
const float distancia7 = 80.0;

SoftwareSerial mySerial(RXPin, TXPin);

void apagarLEDS(){
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
  digitalWrite(led6, LOW);
  digitalWrite(led7, LOW);
}


void pulso(){
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
}

float calcularDistancia(){
  unsigned long tiempo = pulseIn(echo, HIGH);
  float distancia = tiempo * 0.000001 * sonido / 2.0;
  Serial.print(distancia);
  Serial.print("cm");
  Serial.println();
  delay(500);
  return distancia;
}

void seleccionarLED(float distancia){
  if(distancia > distancia0 && distancia <= distancia1){
      digitalWrite(led1, HIGH);
      mySerial.write("1");
    }else if(distancia > distancia1 && distancia <= distancia2){
      digitalWrite(led2, HIGH);
      mySerial.write("2");
    }else if(distancia > distancia2 && distancia <= distancia3){
      digitalWrite(led3, HIGH);
      mySerial.write("3");
    }else if(distancia > distancia3 && distancia <= distancia4){
      digitalWrite(led4, HIGH);
      mySerial.write("4");
    }else if(distancia > distancia4 && distancia <= distancia5){
      digitalWrite(led5, HIGH);
      mySerial.write("5");
    }else if(distancia > distancia5 && distancia <= distancia6){
      digitalWrite(led6, HIGH);
      mySerial.write("6");
    }else if(distancia > distancia6 && distancia <= distancia7){
      digitalWrite(led7, HIGH);
      mySerial.write("7");
    }
}

void setup() {
  Serial.begin(9600);
  mySerial.begin(38400);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(btn, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
  apagarLEDS();
}




void loop(){
  if(digitalRead(btn)==HIGH){
    delay(300);
    apagarLEDS();
    pulso();
    float distancia = calcularDistancia();
    seleccionarLED(distancia);
  }
}
