//Exemplo de termostato experimental simples com Arduino
//Esta montagem faz com que o rele e um Led 
//liguem quando a temperatura abaixe de um mínimo
//e desliguem quando ultrapasse um máximo
//A medição de temperatura é uma aproximação empírica
//Não utilize como instrumento preciso e sim como um
//modelo didático de termostato. 

// rele ligado ao pino 2 digital
// Led ligado ao pino 13 digital
// divisor resistivo do termistor ligado ao pino A0 analogico


// declaração de variáveis :
#define pino_termistor A0
int rele=2;
int led=13;
float leitura;
float leitura1;

// defino modo de atuacao :
void setup(void) {
  pinMode(rele,OUTPUT);
  pinMode(led,OUTPUT);
  Serial.begin(9600);
}

// loop infinito :
void loop(void) {
  leitura = analogRead(pino_termistor);
  Serial.print("Leitura pino A0 = ");
  Serial.println(leitura);
  leitura1 = (leitura*0.2027)-85; // Calcula a temp. aproximada
  if (leitura1 < 30) // define temperatura de acionamento 
    {
     digitalWrite(rele,HIGH);  // liga rele
     digitalWrite(led,HIGH);   // liga Led
    }
  if (leitura1 > 40)  // define ponto de desligamento
    {
     digitalWrite(rele,LOW);   // desliga rele
     digitalWrite(led,LOW);    // desliga Led
    }  
  Serial.print("Temperatura aprox. Celsius = ");  //  envia e temp. para o monitor serial
  Serial.println(leitura1);
  Serial.println("");
  delay(2500);
}

