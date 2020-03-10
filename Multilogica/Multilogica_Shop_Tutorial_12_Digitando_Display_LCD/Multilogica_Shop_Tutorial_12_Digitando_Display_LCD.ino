/*
Biblioteca LiquidCrystal codigo Multilogica
Demonstra o uso do display de 16x2 caracteres
Esta biblioteca funciona com todos displays 
compativeis com o driver Hitachi HD44780.
Este codigo envia um texto digitado via USB para o display
Circuito :
* LCD pino RS no pino digital 12
* LCD pino R/W no pino 11
* LCD pino Enable no pino digital 10
* LCD pino D4 pin no pino digital 5
* LCD pino D5 pin no pino digital 4
* LCD pino D6 pin no pino digital 3
* LCD pino D7 pin no pino digital 2
* Trimpot de 10K :
* +5V no +5V
* Terra no terra
* wiper to LCD VO pin (pin 3)
*/
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2);
void setup()
{
Serial.begin(9600);
lcd.begin(2, 20);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Multilogica-shop");
lcd.setCursor(0,1);
lcd.print("(cc) 2015");
}
void loop()
{
if (Serial.available())
{
//faz a leitura atraves do monitor serial//
char cr = Serial.read();
//determina um caracter para limpar a tela//
if (cr == '%')
{
lcd.clear();
}
//determina um caracter para pular para a linha de baixo//
else if (cr == '>')
{
lcd.setCursor(0,1);
}
else
{
 // se o caracter digitado nao limpa e nem pula linha vai para o display//
 // nao aceita acentuacao //
lcd.write(cr);
}
}
}
