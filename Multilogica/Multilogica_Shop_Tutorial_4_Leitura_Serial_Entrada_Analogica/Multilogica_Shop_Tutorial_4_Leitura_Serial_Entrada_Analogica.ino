/*
  Entrada Analogica, Saida Analogica, Saida serial
 
Le o pino de entrada analogica, mapeia o resultado para um intervalo entre 0 e 255 e usa o resultado para estabelecer o pulso PWM do pino de saida.
Tambem e possivel acompanhar o resultado atraves do Monitor Serial.
 
 O circuito:
 - O pino central do Potenciometro conectado ao pino analogico 0. Os pinos lateriais do potenciometro conectados no terra e 5V.
 - LED conectado no pino digital 9 e no terra.

 Criado em 29/12/2008, Modificado em 09/04/2012 por Tom Igoe
 Este exemplo e de dominio publico.
 */

// constantes nao sao alteradas:
const int analogInPin = A0;  // Entrada analogica do potenciometro
const int analogOutPin = 9;  // Saida analogica onde o LED esta conectado

int sensorValue = 0;        // leitura do potenciometro
int outputValue = 0;        // leitura da saida PWM (analogica)

void setup() {
  // inicializa a comunicacao serial:
  Serial.begin(9600);
}

void loop() {
  // faz a leitura da entrada analogica:
  sensorValue = analogRead(analogInPin);            
  // mapeia o resultado da entrada analogica dentro do intervalo de 0 a 255:
  outputValue = map(sensorValue, 0, 1023, 0, 255);  
  
  // muda o valor da saida analogica:
  analogWrite(analogOutPin, outputValue);          

  // imprime o resultado no monitor serial:
  Serial.print("sensor = " );                      
  Serial.print(sensorValue);      
  Serial.print("\t output = ");      
  Serial.println(outputValue);  

  // Aguarda 2 milissegundos antes do proximo loop:
  delay(2);                    
}
