// Aumentar o brilho de um LED usando um pino PWM 
int PWMpin = 13; // um LED  no pino 13
void setup(){
  // nenhum setup é necessário 
} 
void loop() {
  for (int i=0; i <= 255; i++){
analogWrite(PWMpin, i);
delay(10);
}
} 
