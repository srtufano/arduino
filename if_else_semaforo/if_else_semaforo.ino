//=======================================================================//
#define pinVermelho 10
#define pinAmarelo 9
#define pinVerde 8
#define pinBotao 7
#define pinPedestreVermelho 3
#define pinPedestreVerde 2
//=======================================================================//
int faseSemaforo;

int estadoBotao;
int estadoAnteriorBotao;

int tempoPisca;
int estadoPisca;

//=======================================================================//

void setup() {
  
  pinMode(pinVerde, OUTPUT);
  pinMode(pinAmarelo, OUTPUT);
  pinMode(pinVermelho, OUTPUT);
  pinMode(pinBotao, INPUT);
  pinMode(pinPedestreVerde, OUTPUT);
  pinMode(pinPedestreVermelho, OUTPUT);

  faseSemaforo = 1;

  estadoAnteriorBotao = digitalRead(pinBotao);

  tempoPisca = 0;
  estadoPisca = HIGH;
}

//=======================================================================//

void loop() {

  estadoBotao = digitalRead(pinBotao);

  if ((estadoBotao == LOW) && (estadoAnteriorBotao == HIGH)) {
     
     if (faseSemaforo < 4) {
       faseSemaforo = faseSemaforo + 1;
     } else {
       faseSemaforo = 1;
     }  
  }

  estadoAnteriorBotao = estadoBotao;

  if (faseSemaforo == 1) {    //SEMAFORO ABERTO (VERDE)
     digitalWrite(pinVerde, HIGH);
     digitalWrite(pinAmarelo, LOW);
     digitalWrite(pinVermelho, LOW);

     digitalWrite(pinPedestreVerde, LOW);
     digitalWrite(pinPedestreVermelho, HIGH);     
  }

  if (faseSemaforo == 2) {   //SEMAFORO AMARELO
     digitalWrite(pinVerde, LOW);
     digitalWrite(pinAmarelo, HIGH);
     digitalWrite(pinVermelho, LOW);

     digitalWrite(pinPedestreVerde, LOW);
     digitalWrite(pinPedestreVermelho, HIGH);       
  }

  if (faseSemaforo == 3) {   //SEMAFORO FECHADO (VERMELHO)
     digitalWrite(pinVerde, LOW);
     digitalWrite(pinAmarelo, LOW);
     digitalWrite(pinVermelho, HIGH);
     
     digitalWrite(pinPedestreVerde, HIGH);
     digitalWrite(pinPedestreVermelho, LOW);       
  }

  if (faseSemaforo == 4) {   //SEMAFORO PEDESTRE PISCANDO
     digitalWrite(pinVerde, LOW);
     digitalWrite(pinAmarelo, LOW);
     digitalWrite(pinVermelho, HIGH);

     tempoPisca = tempoPisca + 1;
     if (tempoPisca == 400) {
        estadoPisca = !estadoPisca;
        tempoPisca = 0;
     }
     
     digitalWrite(pinPedestreVerde, LOW);
     digitalWrite(pinPedestreVermelho, estadoPisca);       
     
  }

  delay(1);
}
