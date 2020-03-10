void setup() {
Serial.begin(9600);

pinMode(8, INPUT_PULLUP);
pinMode(9, INPUT_PULLUP);
pinMode(10, INPUT_PULLUP);
}

void loop() {
Serial.print(5*digitalRead(8));
Serial.print(" ");
Serial.print((5*digitalRead(9))-10);
Serial.print(" ");
Serial.println((5*digitalRead(10))-20);
}
