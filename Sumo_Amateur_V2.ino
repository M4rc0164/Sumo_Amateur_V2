#include "Movimiento.h"
#include "Laser.h"

#include "Infrarrojo.h"

//Estados de maniobra
enum EstadoLRT {BASE, RETROCO, GIRO_DER, GIRO_IZQ}
EstadoLRT estadoActual = BASE;

unsigned long tiempoInicio = 0;


void setup(
  //Pines puente H
  pinMode(pinSTBY, OUTPUT);
  pinMode(pinPWMA, OUTPUT);
  pinMode(pinAIN1, OUTPUT);
  pinMode(pinAIN2, OUTPUT);
  pinMode(pinPWMB, OUTPUT);
  pinMode(pinBIN1, OUTPUT);
  pinMode(pinBIN2, OUTPUT);

  //Pines sensores infrarrojo
  pinMode(pinPisoIZQ, INPUT);
  pinMode(pinPisoDER, INPUT);

  inicializarLasers();

  delay(5000); //5 segundos

  digitalWrite(STBY, HIGH);
)

void loop(){

  bool rivalDer = rivalDetectado(distDer());
  bool rivalIzq = rivalDetectado(distIzq());

  switch(estadoActual){
    case BASE:
      if(rivalDer && rivalIzq){
        avance();
      }else if(rivalIzq){
        giroIzquierda();
        avance();
      }else if(rivalDer){
        giroDerecha();
        avance();
      }else{
        busqueda();
      }
    break;
    case RETROCO:
    break;

    case: GIRO_DER:
    break;

    case: GIRO_IZQ:

  }

}
