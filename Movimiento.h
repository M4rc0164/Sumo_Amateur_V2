#ifndef MOVIMIENTO_H
#define MOVIMIENTO_H

#include <Arduino.h>

//Driver TB6612FNG
const int STBY = 3;
const int AIN1 = 2;
const int AIN2 = 4;
const int PWMA = 5;
const int BIN1 = 8;
const int BIN2 = 7;
const int PWMB = 6;

//Variables
const int velocidadMid = 180;
const int velocidadMax = 230;
const int velocidadSuave = 150;

//Declaración de funciones
void giroDerecha();
void giroIzquierda();
void busqueda();
void avance();
void retroceso();

#endif
