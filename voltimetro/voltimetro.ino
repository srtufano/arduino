
// --- Bibliotecas Auxiliares ---

#include <Wire.h>
#include <LiquidCrystal_I2C.h>


// --- Mapeamento de Hardware ---
               
#define tensao A0         // medida de tensão (carga no capacitor) no pino analógico 0
float v =0;
// --- Hardware do LCD I2C ---
LiquidCrystal_I2C lcd(0x3f,
                       2,
                       1,
                       0,
                       4,
                       5,
                       6,
                       7,
                       3,
                       POSITIVE);


void setup(){
 // Serial.begin(9600);
  lcd.begin(16, 2); //Ativa as linhas e colunas do display
}

void loop(){
  v = analogRead(tensao); //Leitura analógica do pino A0
  v = (25 * v)/1023;  //"V" varia de 0 a 1023 || 12 é a tensão máxima
  
  //Imprimir leitura no LCD
  lcd.setCursor(0, 0);
  lcd.print("Tensao: ");
  lcd.print(v);
  lcd.print(" V");

  //Serial.print("Tensao: ");
 // Serial.print(v);
 // Serial.println("V");
  
  delay(300); //Atualiza a medição
  lcd.clear();  //Limpa o display LCD para uma nova medição
}
