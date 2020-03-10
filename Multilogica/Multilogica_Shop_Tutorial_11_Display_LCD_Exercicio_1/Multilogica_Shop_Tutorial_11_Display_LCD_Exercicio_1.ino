/*
  LiquidCrystal Library - scrollDisplayLeft() and scrollDisplayRight()
 
 Biblioteca LiquidCrystal codigo Multilogica
 Demonstra o uso do display de 16x2 caracteres
 Esta biblioteca funciona com todos displays compativeis com o 
 driver Hitachi HD44780
 
 Este codigo escreve “Multilogica Shop” no LCD e usa
 scrollDisplayLeft() e scrollDisplayRight() para passar o texto.
 
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

 
 Library originally added 18 Apr 2008 by David A. Mellis
 library modified 5 Jul 2009 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009 by Tom Igoe
 modified 22 Nov 2010 by Tom Igoe
 
 Codigo de dominio publico baseado no tutorial original:
  http://arduino.cc/en/Tutorial/LiquidCrystalScroll
 */

// Inclui o codigo da biblioteca:
#include <LiquidCrystal.h>

// Inicializa a biblioteca e define os pinos utilizados
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // define o numero de colunas e linhas:
  lcd.begin(16, 2);
  // Envia a mensagem para o display.
  lcd.print("Multilogica Shop");
  delay(2000);
}

void loop() {
  // caminha 16 posicoes para o texto sair do display a esquerda:
  for (int positionCounter = 0; positionCounter < 16; positionCounter++) {
    // caminha uma posicao para a esquerda:
    lcd.scrollDisplayLeft();
    // Aguarda um instante:
    delay(250);
  }

  // caminha 32 posicoes para o texto sair do display a direita:
  for (int positionCounter = 0; positionCounter < 32; positionCounter++) {
    // caminha uma posicao para a direita:
    lcd.scrollDisplayRight();
    // Aguarda um instante:
    delay(250);
  }
 
    // caminha 16 posicoes para a esquerda para mover de novo ao centro:
  for (int positionCounter = 0; positionCounter < 16; positionCounter++) {
    // caminha uma posicao para a esquerda:
    lcd.scrollDisplayLeft();
    // Aguarda um instante:
    delay(250);
  }
 
  // delay no final do full loop:
  delay(2000);

}
