#include "Infrarrojo.h"

int detectarFrontDer(){
  int lecturaFrontDer = analogRead(infraFrontDer);
  return lecturaFrontDer;
}

int detectarFrontIzq(){
  int lecturaFrontIzq = analogRead(infraFrontIzq);
  return lecturaFrontIzq;
}
int detectarTras(){
  int lecturaTras = analogRead(infraTras);
  return lecturaTras;
}

