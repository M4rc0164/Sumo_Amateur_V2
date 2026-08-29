#ifndef INFRARROJO_H
#define INFRARROJO_H

#include <Arduino.h>

//Sensor TCRT5000
const int infraFrontDer = A0;
const int infraFrontIzq = A1;
const int infraTrasDer = A2;
const int infraTrasIzq = A3;

const int umbralLineaBlanca = 100;

int detectarFrontDer();
int detectarFrontIzq();
int detectarTrasDer();
int detectarTrasIzq();

#endif
