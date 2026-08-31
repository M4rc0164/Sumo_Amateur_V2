#include "Movimiento.h"
#include "Laser.h"
#include "Infrarrojo.h"

//Estados de maniobra
enum EstadoLRT { ATAQUE,
                 RETROCO,
                 AVANCE,
                 BUSQUEDA } EstadoLRT estadoActual = ATAQUE;

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

  delay(5000);  //5 segundos
  digitalWrite(STBY, HIGH);

  retrocesoDer();
  delay(300);

  )

  void loop() {

  bool rivalDer = rivalDetectado(distDer());
  bool rivalIzq = rivalDetectado(distIzq());
  bool rival = rivalDetectado(distDer()) && rivalDetectado(distIzq());

  int lecturaFrontDer = detectarFrontDer();
  int lecturaFrontIzq = detectarFrontIzq();
  int lecturaTrasera = detectarTras();

  if (lecturaFrontDer < umbralLineaBlanca && lecturaFrontIzq < umbralLineaBlanca) {
    estadoActual = RETROCO;
  } else if (lecturaTrasera < umbralLineaBlanca) {
    estadoActual = AVANCE;
  } else if (lecturaFrontIzq < umbralLineaBlanca) {
    retrocesoDer();
    estadoActual = RETROCO;
  } else if (lecturaFrontDer < umbralLineaBlanca) {
    retrocesoIzq();
    estadoActual = RETROCO;
  } else{
    estadoActual = ATAQUE
  }

  switch (estadoActual) {
    case RETROCO:
      retroceso();
      delay(2000);
      break;
    case AVANCE:
      avance();
      delay(2000);
    case ATAQUE:
      if (rival) {
        avance();
        delay(1000);
      } else if (rivalIzq) {
        ejeIzquierda();
        delay(1000);
        detener();
      } else if (rivalDer) {
        ejeDerecha();
        delay(1000);
        detener();
      } else {
        estadoActual = BUSQUEDA;
      }
      break;
    case BUSQUEDA:
      ejeDerecha();
      delay(1000);
      if (rival || rivaDer || rivalIzq) {
        estadoActual = ATAQUE;
      }
      ejeIzq();
      delay(1200);
      break;
  }
}
