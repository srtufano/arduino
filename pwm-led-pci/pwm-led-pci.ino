void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(13, OUTPUT);
  Serial.begin (9600);

}

// the loop function runs over and over again forever
void loop() {
   for (int i=0; i <= 255; i++){    
  analogWrite(13, i); 
  Serial.println(i);   
  delay(10);
   
  }

