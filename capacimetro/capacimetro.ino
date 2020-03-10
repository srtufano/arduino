
// --- Bibliotecas Auxiliares ---

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
//#include <LiquidCrystal.h> //inclui biblioteca lcd


// --- Mapeamento de Hardware ---
#define charge         7          // Digital 11 vai carregar o capacitor
#define discharge      6          // Digital 10 vai descarregar o capacitor
#define resistor       10000.0F    // Resistor de carga utilizado no projeto                                  
#define capLoad        A0         // medida de tensão (carga no capacitor) no pino analógico 0


// --- Hardware do LCD I2C ---
LiquidCrystal_I2C disp(0x3f,
                       2,
                       1,
                       0,
                       4,
                       5,
                       6,
                       7,
                       3,
                       POSITIVE);


// --- Variáveis Globais ---
unsigned long Time01;             // Tempo inicial
unsigned long Time02;             // Tempo transcorrido
float microFarads;                // Armazena o valor da capacitância em µF
float nanoFarads;                 // Armazana o valor da capacitância em nF


// --- Configurações Iniciais ---
void setup()
{
    pinMode(charge, OUTPUT);         //Configura pino de carga como saída digital
       
    digitalWrite(charge, LOW);       //Inicializa pino de carga
    
    disp.begin(16, 2);              //Display lcd 16 x 2
    disp.setCursor(2,0);            //Posiciona cursor na coluna 3, linha 1
    disp.print("Capacimetro");      //Escreve no display

   

} //end setup


// --- Loop Infinito ---
void loop()
{
  
  digitalWrite(charge, HIGH);              //Saída de carga em nível alto (carrega o capacitor com a tensão de alimentação do Arduino)
  Time01 = millis();                       //Armazena a contagem de programa em mili segundos em Time01


  while(analogRead(capLoad) < 648){ }      // Aguarda até atingir 63,2% da tensão da fonte
  
                                           /*
                                                 Conversor AD de 10 bits
                                                 
                                                 1024  -  100%      
                                                    n  -  63,2%
                                                    
                                                    n = 1024 x 0,632 ~~ 647
                                           
                                           */
  

  Time02 = millis() - Time01;              // Calcula o tempo transcorrido
  
  
 /*
    tau = RC -> C = tau/R  
    
                                Time02 x 10E-3 (segundos)                        Time02 (segundos)
    C x 10E-6 (micro Farad) = --------------------------- ->  C (micro Farad) = ------------------- x 10E3
                               resistor       (Ohms)                             Resistor (Ohms)
    
 */
 
  microFarads = ((float)Time02 / resistor) * 1000;     // Calcula a Capacitância em Micro Farads

   



  if (microFarads > 1)                //Capacitância maior que 1uF?
  {                                   //Sim...
    
    
    disp.setCursor(5,1);              //Posiciona cursor na coluna 6, linha 2
    disp.print((long)microFarads);    //Imprime valor atual da capacitância em uF
    disp.print(" uF");                //Imprime "uF"
    
  } //end if
  
  else                                //Senão...
  {
     

    nanoFarads = microFarads * 1000.0;      // Converte uF para nF
    
    
    disp.setCursor(5,1);              //Posiciona cursor na coluna 6, linha 2
    disp.print((long)nanoFarads);     //Imprime valor atual da capacitância em nF
    disp.print(" nF");                //Imprime "nF"
    
  } //end else

   
  digitalWrite(charge, LOW);                //Pino de carga fica em nível baixo
  pinMode(discharge, OUTPUT);               //Pino de descarga configurado temporariamente como saída
  digitalWrite(discharge, LOW);             //Pino de descarga em nível baixo (descarrega o capacitor)
  while(analogRead(capLoad) > 0){ }         //Aguarda até que a tensão no capacitor chegue a zero
  

  pinMode(discharge, INPUT);                //Pino de descarga volta a ser entrada
  
  
  delay(300); //atualização das leituras
  
  
} //end loop






