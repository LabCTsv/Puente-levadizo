#include <Wire.h>

const long velocidadBaud = 9600;

const int pinMotorL1 = 5;
const int pinMotorR2 = 6;

const int velocidadPwm = 224;

typedef enum { D_ADELANTE, D_ATRAS, D_ALTO, D_PASAR
             } DIRECCION;

const int v = 2, a = 3, r = 4;

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
      controlMotor(D_ADELANTE);
      digitalWrite(r, LOW);
      digitalWrite(a, HIGH);
      digitalWrite(v, LOW);
      break;
    case 'B':
      controlMotor(D_ATRAS);
      digitalWrite(r, HIGH);
      digitalWrite(a, LOW);
      digitalWrite(v, LOW);
      break;
    case 'a':
    case 'b':
      controlMotor(D_ALTO);
      digitalWrite(r, LOW);
      digitalWrite(a, LOW);
      digitalWrite(v, LOW);
      break;
    case 'D':
      controlMotor(D_PASAR);
      digitalWrite(r, LOW);
      digitalWrite(v, HIGH);
      break;

  }
}

void controlMotor(DIRECCION dir) {
  switch (dir) {
    case D_ADELANTE:
      digitalWrite(pinMotorL1, HIGH);
      digitalWrite(pinMotorR2, LOW);
      break;
    case D_ATRAS:
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
  }
}



