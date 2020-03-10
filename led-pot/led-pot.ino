#define potPin1 0   
#define ledPin1 9  
#define potPin2 1   
#define ledPin2 10


int valPot1 = 0; 
int valPot2 = 0;

void setup() { 

pinMode(ledPin1,OUTPUT); 
pinMode(ledPin2,OUTPUT); 
} 

void loop() {    

valPot1 =  analogRead(potPin1); 
valPot1 = map(valPot1,0,1023,0,255); 
analogWrite(ledPin1,valPot1 ); 

valPot2 =  analogRead(potPin2); 
valPot2 = map(valPot2,0,1023,0,255); 
analogWrite(ledPin2,valPot2 ); 
}
