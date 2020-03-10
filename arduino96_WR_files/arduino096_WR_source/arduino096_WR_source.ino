/*

  Passos para utilização do Digispark com a IDE Arduino:

    1 - Instale os drivers Digistump
    2 - Vá em File > Preferences e cole o link http://digistump.com/package_digistump_index.json na aba "Additional Boards Manager URLs"
    3 - Vá em Tools > Board > Boards Manager e instale Digistump AVR Boards
    4 - Clique no botão de upload do código e quando solicitado, conecte o digispark na USB


*/

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(0, OUTPUT); //LED on Model B
  pinMode(1, OUTPUT); //LED on Model A  or Pro
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(0, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(1, HIGH);
  delay(100);               // wait for a second
  digitalWrite(0, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(1, LOW); 
  delay(1000);               // wait for a second
}
