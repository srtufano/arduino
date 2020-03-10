//Display/
#include <LiquidCrystal_I2C.h>
#include "Wire.h"
LiquidCrystal_I2C lcd(0x3F,2,1,0,4,5,6,7,3, POSITIVE);

//Sensor de tensão//
int analogInput = A0;
float Vo = 0.0, Vi = 0.0;
float value_aux = 0, value = 0;

//Valores dos Resistores//
float R1 = 97000.0; //Resistência R1 (100K) -veja no texto!
float R2 = 9700.0; //Resistência R2 (10K) - veja no texto!

void setup(){

pinMode(analogInput, INPUT);
lcd.begin(16, 2);
lcd.setBacklight(HIGH);
lcd.setCursor(2,0);
lcd.print("Voltimetro DC");
lcd.setCursor(14,1);
lcd.print("V");

}void loop(){

//Aquisição
for(int i=60;i>0;i--){
value_aux = analogRead(analogInput);
value += pow(value_aux,2);
}

value = sqrt(value/60);
Vo = (value * 5.0) / 1023.0;
Vi = Vo / (R2/(R1+R2));
if (Vi<0.09) {Vi=0.0;} //Filtrando medições errôneas!

lcd.setCursor(5,1);
lcd.print(" ");
lcd.setCursor(5,1);
lcd.print(Vi);
delay(500);

}
