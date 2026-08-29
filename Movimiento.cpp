#include Movimiento.h
#include Laser.h
#include Infrarrojo.h

void avance(){
  digitalWrite(AI1, LOW);
  digitalWrite(AI2, HIGH);
  digitalWrite(BI1, LOW);
  digitalWrite(BI2, HIGH);
  analogWrite(PWMA, velocidadMax);
  analogWrite(PWMB, velocidadMax);
}

void retroceso(){
  digitalWrite(AI1, HIGH);
  digitalWrite(AI2, LOW);
  digitalWrite(BI1, HIGH);
  digitalWrite(BI2, LOW);
  analogWrite(PWMA, velociadMid);
  analogWrite(PWMB, velociadMid);
}

void giroDerecha(){
  digitalWrite(AI1, HIGH);
  digitalWrite(AI2, LOW);
  digitalWrite(BI1, LOW);
  digitalWrite(BI2, HIGH);
  analogWrite(PWMA, velocidadSuave);
  analogWrite(PWMB, velocidadSuave);
}

void giroIzquierda(){
  digitalWrite(AI1, LOW);
  digitalWrite(AI2, HIGH);
  digitalWrite(BI1, HIGH);
  digitalWrite(BI2, LOW);
  analogWrite(PWMA, velocidadSuave);
  analogWrite(PWMB, velocidadSuave);
}

void detener(){
  digitalWrite(AI1, LOW);
  digitalWrite(AI2, LOW);
  digitalWrite(BI1, LOW);
  digitalWrite(BI2, LOW);
  analogWrite(PWMA, 0);
  analogWrite(PWMB, 0);
}

void busqueda(){ //Gira sobre su propio eje hacia la derecha con mayor velocidad 
  digitalWrite(AI1, HIGH);
  digitalWrite(AI2, LOW);
  digitalWrite(BI1, LOW);
  digitalWrite(BI2, HIGH);
  analogWrite(PWMA, velociadMid);
  analogWrite(PWMB, velociadMid);
}