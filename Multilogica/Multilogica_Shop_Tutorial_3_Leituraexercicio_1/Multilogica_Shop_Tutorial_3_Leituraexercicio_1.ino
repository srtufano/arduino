/*
  Contador de pulsos (edge detection)
  criado em 27/09/2005, modificado em 30/08/2011 por Tom Igoe
  Este exemplo e de dominio publico.   
  http://arduino.cc/en/Tutorial/ButtonStateChange
*/

// constantes nao sao alteradas:
const int buttonPin = 2;     // o numero do pino do botao
const int ledPin = 13;       // o numero do pino do LED

// variaveis que devem mudar:
int buttonPushCounter = 0;   // contador para o numero de impressoes do botao
int buttonState = 0;         // atual estado do botao
int lastButtonState = 0;     // anterior estado do botao

void setup() {
  pinMode(buttonPin, INPUT);     // inicializa o pino do botao como entrada
  pinMode(ledPin, OUTPUT);       // inicializa o pino digital como saida
  Serial.begin(9600);            // inicializa a comunicacao serial
} 

void loop() {
  // faz a leitura do valor do botao:
  buttonState = digitalRead(buttonPin);

  // compara o estado atual do botao com seu estado anterior
  if (buttonState != lastButtonState) {
    // se o estado do botao foi alterado, incrementar o contador
    if (buttonState == HIGH) {
      buttonPushCounter++;
      Serial.print("numero de pulsos:  ");
      Serial.println(buttonPushCounter);
    }
 }
      // salva o estado atual do botao como ultimo estado para iniciar o                    
      // proximo loop
  lastButtonState = buttonState;

  // Liga o LED cada 4 pulsacoes checando o modulo de contador de botao
     if (buttonPushCounter % 4 == 0) {
     digitalWrite(ledPin, HIGH);
     }else {
     digitalWrite(ledPin, LOW);
  }
}
