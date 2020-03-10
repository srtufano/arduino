int ledPin = 9;
int numero = -5;
void setup() {
pinMode(ledPin, OUTPUT);
Serial.begin(9600);
 Serial.println("Digite 1 para ligar o led");
 Serial.println("Digite 0 para desligar o led");
}

void loop() {
 if (Serial.available() >0) {
  numero = Serial.read();
 }

 if (numero > 0){
  if (numero == '1') {
    digitalWrite(ledPin, HIGH);
    Serial.println("Led Ligado");
    delay(2000);
    
  }
  else if (numero == '0') {
    digitalWrite(ledPin, LOW);
    Serial.println("Led Desligado");
    delay(2000);
  }
 }
    numero=-5;
}
