#include <IRremote.h>

//Codigos hexa das teclas do controle remoto
#define tecla1 0xE17A807F
#define tecla2 0xE17A40BF
#define tecla3 0xE17AC03F
#define tecla4 0xE17A20DF
#define tecla5 0xE17AA05F
#define tecla6 0xE17A609F
#define tecla7 0xE17AE01F
#define tecla8 0xE17A10EF
#define tecla9 0xE17A906F
#define tecla0 0xE17A00FF

//Define leds
#define led1 5
#define led2 6
#define led3 7
#define led4 8
#define rele 9

int RECV_PIN = 11;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  //Define saida do arduino para os leds
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(rele, OUTPUT);
  Serial.begin(9600);
  // In case the interrupt driver crashes on setup, give a clue
  // to the user what's going on.
  Serial.println("Enabling IRin");
  irrecv.enableIRIn(); // Start the receiver
  Serial.println("Enabled IRin");
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    
    //Logica de acionamento dos leds
    switch(results.value)
    {
      case tecla1:digitalWrite(led1, HIGH); break;
      case tecla4:digitalWrite(led1, LOW); break;
      case tecla2:digitalWrite(led2, HIGH); break;
      case tecla5:digitalWrite(led2, LOW); break;
      case tecla3:digitalWrite(led3, HIGH); break;
      case tecla6:digitalWrite(led3, LOW); break;
      case tecla8:digitalWrite(led4, HIGH); break;
      case tecla0:digitalWrite(led4, LOW); break;
      case tecla7:digitalWrite(rele, HIGH); break;
      case tecla9:digitalWrite(rele, LOW); break;
    }
    irrecv.resume(); // Receive the next value
  }
  delay(100);
}
