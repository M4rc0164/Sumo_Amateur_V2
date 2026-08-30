#include "Infrarrojo.h"

int detectarFrontDer(){
  int lecturaFrontDer = analogRead(infraFrontDer);
  return lecturaFrontDer;
}

int detectarFrontIzq(){
  int lecturaFrontIzq = analogRead(infraFrontIzq);
  return lecturaFrontIzq;
}
int detectarTrasDer(){
  int lecturaTrasDer = analogRead(infraTrasDer);
  return lecturaTrasDer;
}
int detectarTrasIzq(){
  int lecturaTrasIzq = analogRead(infraTrasIzq);
  return lecturaTrasIzq;
}
