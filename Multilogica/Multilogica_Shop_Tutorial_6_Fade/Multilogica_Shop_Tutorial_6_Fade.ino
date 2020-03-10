/*
 Fade
 
 Este exemplo mostra como executar um fade em um LED no pino 9 usando a funcao analogWrite().
 Este exemplo e de dominio publico
 */

int led = 9;           // pino do LED
int brightness = 0;    // intensidade do brilho do LED
int fadeAmount = 5;    // em quantos pontos aplicar o fade no LED

void setup()  {
  // define o pino 9 como saida:
  pinMode(led, OUTPUT);
}

// o loop roda em sequencia continuamente:
void loop()  {
  // define o brilho do pino 9:
  analogWrite(led, brightness);    

  // muda o brilho para o proximo loop:
  brightness = brightness + fadeAmount;

  // inverte a direcao do fade ao final do mesmo:
  if (brightness == 0 || brightness == 255) {
    fadeAmount = -fadeAmount ;
  }    
  // aguarda 30 milissegundos para ver o efeito dimer:    
  delay(30);                            
}
