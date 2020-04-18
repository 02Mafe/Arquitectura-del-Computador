#include <TimerOne.h>

byte ValorD;
byte secuencia [30];
int n;
volatile int ContarTiempo;

void setup() {

  ContarTiempo = 0;

  Timer1.initialize(1000000);
  Timer1.attachInterrupt(IniciarSecuencia);
  //Botones en pine 3, 4, 5 puerto D
  DDRD = B00000011;
  
  // puerto B 7, 6
  DDRB = B11111111;

  n = 0;
  
}

void loop() {
  ValorD = PIND; //leer pines de los botones
  PORTB = ValorD; //encender el led
  if (ValorD != 0){ // validar si no esta vacia la secuencia de pulsaciones
    ContarTiempo = 0;
   if (n < 30){ // valida que la secuencia no se mayor que el tamano del array
    secu [n] = ValorD;
    n++;
   }
   while (PIND != 0); // ejecuta el loop hasta que se presione el boton
  }
  if (ContarTiempo == 3){
     for (int i=0; i<n; i++){
      PORTB = secuencia[i];
      delay(2000);
      PORTB = 0;
      delay(1000);
     }
     n = 0;
  }
}

void IniciarSecuencia(){
  ContarTiempo++;
}
