//**************************************************************************
//* Codigo para teste de Arduino acionando rele do kit Multilogica,  
//* ligado na saida digital 2 e GND, monitorado pelo Led 13
//* este codigo tem dominio publico
//**************************************************************************

//inicializa uma variavel do tipo char que utiliza 1 byte para armazenar 
//1 caracter
char input= 0; 
int rele=2;
int led=13;
boolean y=true;  // inicializa uma variavel do tipo booleano 

void setup() {
  pinMode(rele,OUTPUT);
  pinMode(led,OUTPUT);

  Serial.begin(9600);  
  Serial.println(); 
  Serial.print("**Codigo para acionar rele conectado ao pino 2 do Arduino ");
  Serial.println("atraves do monitor serial**");
  Serial.println("");
  Serial.println("Pressione 1 e depois ENTER para inverter o estado do rele novamente");
  Serial.println("Aguardando comando :");
}
void loop() {
  if (Serial.available() > 0) {
    input= Serial.read();

    if (input =='1'){
      Serial.print("O rele agora esta ");

      if(y){
        digitalWrite(rele, HIGH);
        digitalWrite(led, HIGH);     
        Serial.println("ligado");    
      } 
      else {
        digitalWrite(rele, LOW);
        digitalWrite(led, LOW);
        Serial.println("desligado");
      }   
      y=!y; // altera o valor de y, se le y e igual a nao y
    } 
    else {
      Serial.println("Comando invalido");
    } 
  }
}
