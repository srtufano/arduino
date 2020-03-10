#define led1 9
#define led2 8
#define led3 7
#define led4 6
int time = 200;
void setup() {
pinMode(led1, OUTPUT);
pinMode(led2, OUTPUT);
pinMode(led3, OUTPUT);
pinMode(led4, OUTPUT);
}

void loop() {

  if (condition)
{
  //statement(s)
}

digitalWrite(led1, HIGH);
digitalWrite(led2, LOW);
digitalWrite(led3, LOW);
digitalWrite(led4, LOW);
delay(time);
digitalWrite(led1, LOW);
digitalWrite(led2,HIGH);
digitalWrite(led3, LOW);
digitalWrite(led4, LOW);
delay(time);
digitalWrite(led1, LOW);
digitalWrite(led2, LOW);
digitalWrite(led3, HIGH);
digitalWrite(led4, LOW);
delay(time);
digitalWrite(led1, LOW);
digitalWrite(led2,LOW);
digitalWrite(led3, LOW);
digitalWrite(led4, HIGH);
delay(time);
digitalWrite(led1, LOW);
digitalWrite(led2, LOW);
digitalWrite(led3, HIGH);
digitalWrite(led4, LOW);
delay(time);
digitalWrite(led1, LOW);
digitalWrite(led2,HIGH);
digitalWrite(led3, LOW);
digitalWrite(led4, LOW);
delay(time);
}
