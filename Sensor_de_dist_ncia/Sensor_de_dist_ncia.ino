// Sensor de distância

int AZUL = 12; // LED Azul
int VERM = 11; // LED Vermelho
int AMAR = 10; // LED Amarelo
int VERD = 9; // LED Verde
int SENSOR = A0;
int valor;
 
void setup() {
Serial.begin(9600);
pinMode(AZUL, OUTPUT);
pinMode(VERM, OUTPUT);
pinMode(AMAR, OUTPUT);
pinMode(VERD, OUTPUT);
}
 
void loop() {
// Obter o valor do sensor (entre 0 e 1023)
valor = analogRead(SENSOR);
Serial.print("Valor: ");
Serial.println(valor);
int distancia = map(valor, 0, 1023, 0, 5);
switch (distancia) {
case 0:
digitalWrite(AZUL, HIGH);
digitalWrite(VERM, LOW);
digitalWrite(AMAR, LOW);
digitalWrite(VERD, LOW);
break;
case 1:
digitalWrite(AZUL, LOW);
digitalWrite(VERM, HIGH);
digitalWrite(AMAR, LOW);
digitalWrite(VERD, LOW);
break;
case 2:
digitalWrite(AZUL, LOW);
digitalWrite(VERM, LOW);
digitalWrite(AMAR, HIGH);
digitalWrite(VERD, LOW);
break;
case 3:
digitalWrite(AZUL, LOW);
digitalWrite(VERM, LOW);
digitalWrite(AMAR, LOW);
digitalWrite(VERD, HIGH);
break;
default:
digitalWrite(AZUL, LOW);
digitalWrite(VERM, LOW);
digitalWrite(AMAR, LOW);
digitalWrite(VERD, LOW);
break;
}
delay (100);
}
