#include <Wire.h>

const long velocidadBaud = 9600;

const int pinMotorL1 = 5;
const int pinMotorR2 = 6;

const int velocidadPwm = 224;

typedef enum { D_SUBIR, D_BAJAR, D_ALTO, D_PASAR, D_PREV
             } DIRECCION;

const int v = 2, a = 3, r = 4;
const int EsperaAmarillo=2000;

void setup() {
  Wire.begin();
  pinMode(pinMotorL1, OUTPUT);
  pinMode(pinMotorR2, OUTPUT);

  pinMode(r, OUTPUT);
  pinMode(a, OUTPUT);
  pinMode(v, OUTPUT);

  Serial.begin(velocidadBaud);
  Serial.println(F("Listo"));
}

void loop() {
  char dato;

  if (Serial.available()) {
    dato = Serial.read();
    procesarComando(dato);
  }
}

void procesarComando(char dato) {

  switch (dato) {
    case 'A':
      digitalWrite(a, HIGH);
      delay(EsperaAmarillo);
      controlMotor(D_BAJAR);
      digitalWrite(a, LOW);
      digitalWrite(r, HIGH);
      digitalWrite(v, LOW);
      break;
    case 'B':
      digitalWrite(a, HIGH);
      delay(EsperaAmarillo);
      controlMotor(D_SUBIR);
      digitalWrite(a, LOW);
      digitalWrite(r, HIGH);
      digitalWrite(v, LOW);
      break;
    case 'a':
    case 'b':
      controlMotor(D_ALTO);
      digitalWrite(r, LOW);
      digitalWrite(a, HIGH);
      digitalWrite(v, LOW);
      break;
    case 'D':
      digitalWrite(a, HIGH);
      delay(EsperaAmarillo);
      controlMotor(D_PASAR);
      digitalWrite(a, LOW);
      digitalWrite(r, LOW);
      digitalWrite(v, HIGH);
      break;
    case 'E':
      controlMotor(D_PREV);
      break;
  }
}

void controlMotor(DIRECCION dir) {
  switch (dir) {
    case D_SUBIR:
      digitalWrite(pinMotorL1, HIGH);
      digitalWrite(pinMotorR2, LOW);
      break;
    case D_BAJAR:
      digitalWrite(pinMotorL1, LOW);
      digitalWrite(pinMotorR2, HIGH);
      break;
    case D_ALTO:
      digitalWrite(pinMotorL1, LOW);
      digitalWrite(pinMotorR2, LOW);
      break;
    case D_PASAR:
      digitalWrite(pinMotorL1, LOW);
      digitalWrite(pinMotorR2, LOW);
      break;
    case D_PREV:
      digitalWrite(a, HIGH);
      digitalWrite(v, LOW);
      digitalWrite(r, LOW);
      break;
  }
}



