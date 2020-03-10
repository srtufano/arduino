// Ligar motor no pino 2 em serie com um resistor de 15 ohms
// para limitar a corrente em 40mA para nao sobrecarregar o Arduino

//Este codigo e de dominio publico. 
//Criado em 2014 por Multilogica-Shop.

const int motorPin = 2;
const int buttonPin = 7;
int buttonState = 0;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(motorPin, OUTPUT);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
    digitalWrite(motorPin, HIGH);
  }
  else {
    digitalWrite(motorPin, LOW);
  }
}
