int led0 = 2;
int led1 = 3;
int led2 = 4;
int led3 = 5;
int led4 = 6;
int led5 = 7;
int led6 = 8;
int led7 = 9;
int led8 = 10;
int led9 = 11;
int potPin = 2;

void setup() {
      
pinMode(potPin, OUTPUT);
pinMode(led0, OUTPUT);
pinMode(led1, OUTPUT);
pinMode(led2, OUTPUT);
pinMode(led3, OUTPUT);
pinMode(led4, OUTPUT);
pinMode(led5, OUTPUT);
pinMode(led6, OUTPUT);
pinMode(led7, OUTPUT);
pinMode(led8, OUTPUT);
pinMode(led9, OUTPUT);
}
void loop() {
// EFEITO 5 - Policia 1 - ********************************
for(int i = 0; i < 7; i++){
for(int i = 0; i < 6; i++){
digitalWrite(led5, HIGH);
digitalWrite(led6, HIGH);
digitalWrite(led7, HIGH);
digitalWrite(led8, HIGH);
digitalWrite(led9, HIGH);
delay(60*2);
digitalWrite(led5, LOW);
digitalWrite(led6, LOW);
digitalWrite(led7, LOW);
digitalWrite(led8, LOW);
digitalWrite(led9, LOW);
delay(60*2);
}
for(int i = 0; i < 6; i++){
digitalWrite(led0, HIGH);
digitalWrite(led1, HIGH);
digitalWrite(led2, HIGH);
digitalWrite(led3, HIGH);
digitalWrite(led4, HIGH);
delay(60*2);
digitalWrite(led0, LOW);
digitalWrite(led1, LOW);
digitalWrite(led2, LOW);
digitalWrite(led3, LOW);
digitalWrite(led4, LOW);
delay(60*2);
}
}

}

