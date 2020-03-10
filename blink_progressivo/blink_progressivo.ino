/*
 * PROGRAMA: LOOP FOR PARA SUBSTITUIR O "CONHECIDO BLINK" através de SAÍDA PWM - PINO DIGITAL 9 do RODUINO
 *           LED com velocidade de piscadas variáveis (imperceptíveis à visão humana)
 *           "EMULANDO SAÍDAS ANALOGICAS" UTILIZANDO PINO "PWN" DO MCU ATMEGA 328P"
 * =======================================================================================================
 * PINO 09 DO ARDUINO - 328P MCU
 * AUTOR: RODRIGO COSTA.
 * 07/06/2017
 */

const int LED = 9;      //define o LED como pino 9 do Arduino

void setup() {
    
    pinMode(LED, OUTPUT);     //configura o pino do LED como saída

    //Serial.begin(9600);     //setamos o monitor serial para debug
}

void loop() {
  
  // primeiro o LED vai brilhando MAIS
  for(int i=0; i<256; i++)
  {
    analogWrite(LED, i);
    delay(3);

    //Serial.println(i);      //vamos saber o valor de i no final de cada loop FOR
  }

  // segundo o LED vai brilhando MENOS
  for(int i=255; i>=0; i--)
  {
    analogWrite(LED, i);
    delay(3);
    
    //Serial.println(i);      //vamos saber o valor de i no final de cada loop FOR
  }
  
    //delay(1000);
}
