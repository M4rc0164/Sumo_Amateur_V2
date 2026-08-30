#include "Movimiento.h"
#include "Laser.h"

#include "Infrarrojo.h"

//Estados de maniobra
enum EstadoLRT {BUSQUEDA, RETROCO, GIRO_DER, GIRO_IZQ}
EstadoLRT estadoActual = BUSQUEDA;

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

  retrocesoDer();
  delay(300);
  
)

void loop(){

  bool rivalDer = rivalDetectado(distDer());
  bool rivalIzq = rivalDetectado(distIzq());

  switch(estadoActual){
    case BUSQUEDA:
      if(rivalDer && rivalIzq){
        avance();
        delay(1000);
      }else if(rivalIzq){
        ejeIzquierda();
        delay(1000);
        detener();
      }else if(rivalDer){
        ejeDerecha();
        delay(1000);
        detener();
      }else{
        busqueda();
      }
    break;
    case RETROCO:
      retroceso();
      delay(1500);
    break;

    case: GIRO_DER:
      
    break;

    case: GIRO_IZQ:
  }

  if(){
  }
  
}
