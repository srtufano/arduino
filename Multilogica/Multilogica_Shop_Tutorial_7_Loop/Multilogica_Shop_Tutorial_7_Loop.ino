/*
  Loop
 
 Demonstra o uso da funcao for() loop.
 Acende varios LEDs em sequencia, e logo ao reves.
 
 O circuito:
 * LEDs entre os pinos 2 ao 7 e ao terra
 
 Criado em 2006 por David A. Mellis
 Modificado em 30 de Agosto de 2011 por Tom Igoe

 Este codigo e de dominio publico.
  http://www.arduino.cc/en/Tutorial/ForLoop
 */

int timer = 100;     // Quanto maior o valor, mais lenta a sequencia de Leds.

void setup() {
  // Use for loop para inicializar cada pino como saida:
  for (int thisPin = 2; thisPin < 8; thisPin++)  {
    pinMode(thisPin, OUTPUT);      
  }
}

void loop() {
  // loop desde o pino mais baixo ate o mais alto:
  for (int thisPin = 2; thisPin < 8; thisPin++) {
    // liga este pino:
    digitalWrite(thisPin, HIGH);  
    delay(timer);                  
    // desliga este pino:
    digitalWrite(thisPin, LOW);    
  }

  // loop desde o pino mais alto ate o mais baixo:
  for (int thisPin = 7; thisPin >= 2; thisPin--) {
    // liga este pino:
    digitalWrite(thisPin, HIGH);
    delay(timer);
    // desliga este pino:
    digitalWrite(thisPin, LOW);
  }
}
