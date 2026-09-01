#ifndef LASER_H
#define LASER_H

#include <Arduino.h>
#include <Wire.h>
#include <VL53L0X.h>

//Declaración de q los objetos existen en el .cpp
extern VL53L0X sensorDer;
extern VL53L0X sensorIzq; 

//Direcciones I2C de los sensores
#define direccionDer 0x30
#define direccionIzq 0x31


const uint8_t XSHUTA = 10; //Sensor Derecho 
const uint8_t XSHUTB = 9; //Sensor Izquierdo 

const int distanciaAtaque = 400; //mm

void inicializarLasers();
int distDer();
int distIzq();
bool rivalDetectado(int);


#endif