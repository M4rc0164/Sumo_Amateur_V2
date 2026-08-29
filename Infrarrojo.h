#ifndef INFRARROJO_H
#define INFRARROJO_H

#include <Arduino.h>

//Sensor TCRT5000
const int infraDer = 11;
const int infraIzq = 12;


int detectar_der();
int detectar_izq();

#endif