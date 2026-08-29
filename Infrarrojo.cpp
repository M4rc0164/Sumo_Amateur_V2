#include "Infrarrojo.h"

int detectar_der(){
  int value1 = 0;
  value1 = digitalRead(infraDer);
  return value1;
}
int detectar_izq(){
  int value2 = 0;
  value2 = digitalRead(infraIzq);
  return value2;
}