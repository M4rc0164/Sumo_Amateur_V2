#include "Laser.h"

VL53L0X sensorDer;
VL53L0X sensorIzq;

void inicializarLasers(){
  pinMode(XSHUTA, OUTPUT);
  pinMode(XSHUTB, OUTPUT);
  
  Wire.begin();//Inicializa comunicacion I2C

  // Reset de sensores láser
  digitalWrite(XSHUTA, LOW);
  digitalWrite(XSHUTB, LOW);
  delay(10);

  // Configuracion sensor Derecho 
  digitalWrite(XSHUTA, HIGH);
  delay(10);
  sensorDer.init();
  sensorDer.setTimeout(500);
  sensorDer.setAddress(direccionDer);

  // Configuracion sensor Izquierdo
  digitalWrite(XSHUTB, HIGH);
  delay(10);
  sensorIzq.init();
  sensorIzq.setTimeout(500);
  sensorIzq.setAddress(direccionIzq);

  sensorIzq.startContinuous();
  sensorDer.startContinuous();

}

int distDer(){
  int distDer = sensorDer.readRangeContinuousMillimeters();
  return distDer;
}

int distIzq(){
  int distIzq = sensorIzq.readRangeContinuousMillimeters();
  return distIzq;
}

bool rivalDetectado(int dist){
  if(dist < distanciaAtaque){
    return true;
  }else{
    return false;
  }
}



