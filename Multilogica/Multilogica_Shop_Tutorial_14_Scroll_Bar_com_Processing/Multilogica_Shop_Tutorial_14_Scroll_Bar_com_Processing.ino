/*
VU_meter
 */
char val;      // variavel para guardar o valor recebido pela interface serial
char val_old;  // variavel para guardar o valor anterior recebido pela interface serial

// funcao setup roda apenas uma vez quando a execucao do programa se inicia
void setup() {
  // inicializamos os pinos de 2 a 6 como saidas
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
 
  // inicializamos a comunicacao serial com velocidade de 115200 bauds 
  Serial.begin(115200);
}

// a funcao loop e executada indefinidamente
void loop() {
   if (Serial.available()) { //verifica se ha dados sisponiveis para a leitura
     val = Serial.read(); // le o dado e o armazena em val
   }
   if (val!=val_old){ // somente atua se houver variacao no valor de val
     alloff(); // executa a funcao alloff que apaga todos os LEDs
       for (int i=2; i<(int(val)+2); i++){ // faz com que o valor de i varie de 2 ate val+2
                                           // note que val armazena um caractere e necessitamos 
                                           // da funcao int(val) para tranformar em um valor numerico
         digitalWrite(i, HIGH); // acende o led no pino i
       }
     val_old=val; // guarda o valor de val em val_old
  }
}

void alloff() { // funcao para apagar todos os LEDs
  for(int i = 2; i < 7; i++){ // faz com que i varie de 2 a 6
    digitalWrite(i, LOW); // apaga o led no pino i
  }
}
