/*
 Biblioteca LiquidCrystal codigo Multilogica
 Demonstra o uso do display de 16x2 caracteres
 Esta biblioteca funciona com todos displays compativeis com o 
 driver Hitachi HD44780.
 Este codigo escreve :
 
 Multilogica shop
   (cc)     2014    
 
  Circuito :
 * LCD pino RS no pino digital 12
 * LCD pino Enable no pino digital 11
 * LCD pino D4 pin no pino digital 5 
 * LCD pino D5 pin no pino digital 4
 * LCD pino D6 pin no pino digital 3
 * LCD pino D7 pin no pino digital 2
 * LCD pino R/W no terra
 * Trimpot de 10K :
 * +5V no +5V
 * Terra no terra
 * wiper to LCD VO pin (pin 3)
 
 Codigo de dominio publico baseado no tutorial original :
  http://www.arduino.cc/en/Tutorial/LiquidCrystal
 */

// Inclui o codigo da biblioteca:
#include <LiquidCrystal.h>

// Inicializa a biblioteca e define os pinos utilizados
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // define o numero de colunas e linhas do Display : 
  lcd.begin(16, 2);
  // Envia a mensagem para o display.
  lcd.print("Multilogica");
  lcd.setCursor(0, 1); //Posiciona o cursor na primeira coluna(0) e na segunda linha(1) do Display
  lcd.print("shop");
}

void loop() {
 }
