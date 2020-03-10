/*
  Piscar
Acende um LED por um segundo, e depois apaga pelo mesmo tempo, repetidamente.
 */
 
// Estabeleca um nome para o pino 13:
int led = 13;

// Se executa cada vez que o Arduino inicia:
void setup() {                
  // Inicializa o pino digital como saída.
  pinMode(led, OUTPUT);    
}

// A funcao loop() continua executando enquanto o Arduino estiver alimentado, // ou ate que o botao reset seja acionado.

void loop() {
  digitalWrite(led, HIGH);   // Acende o LED
  delay(1000);               // Aguarda um segundo (1s = 1000ms)
  digitalWrite(led, LOW);    // Apaga o LED
  delay(1000);               // Aguarda um segundo (1s = 1000ms)
}
