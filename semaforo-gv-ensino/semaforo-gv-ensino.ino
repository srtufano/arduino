#define ledGnd 8
#define ledVermelho 13
#define ledAmarelo 12
#define ledVerde 11
void setup(){
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledGnd, OUTPUT);

  digitalWrite(ledGnd, LOW);
  }

 void loop(){
    digitalWrite(ledVermelho, HIGH);
    digitalWrite(ledAmarelo, HIGH);
    digitalWrite(ledVerde, LOW);
    
    digitalWrite(ledVermelho, LOW);
    digitalWrite(ledAmarelo, HIGH);
    digitalWrite(ledVerde, HIGH);
    
    digitalWrite(ledVermelho, LOW);
    digitalWrite(ledAmarelo, HIGH);
    digitalWrite(ledVerde, LOW);
    
    
 }
