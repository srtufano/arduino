/* ======================================================================================================
   
   Curso de Arduino WR Kits Channel
   
   RTC Completo utilizando apenas o Arduino UNO
   
    
   Autor: Eng. Wagner Rambo  Data: Fevereiro de 2018
    
   
   www.wrkits.com.br | facebook.com/wrkits | youtube.com/canalwrkits


   Funcionamento: obtém-se uma base de tempo precisa de 1 segundo a partir do estouro do Timer2.

   Chama-se a função de controle do RTC a cada segundo, controlando as variáveis de data e hora.



   Cálculos:
 
    Ciclo de máquina = 1/Fosc = 1/16E6 = 62,5ns = 62,5E-9s

    
    T2_ovf = (256-TCNT2) x prescaler x ciclo de máquina

    T2_ovf =   (256-56)  x    32     x      62,5E-9

    T2_ovf = 400E-6
   
    
====================================================================================================== */


// ======================================================================================================
// --- Máscaras ---
#define     mask_pin     B10000000                   //cria uma máscara para inverter o digital 7


// ======================================================================================================
// --- Protótipo das Funções ---
void rtc_system();                                   //Função de controle dos parâmetros do RTC
void rtc_disp();                                     //Função para imprimir valores do RTC


// ======================================================================================================
// --- Variáveis Globais ---
int    T2_aux = 0x00;                                //contador auxiliar para o Timer2 (base de tempo de 1 seg)

// variáveis do RTC
short  hora          =   20, 
       minuto        =   21,
       segundo       =   55,  
       dia           =   3,
       mes           =   3;
int    ano           =   2020;
       


// ======================================================================================================
// --- Interrupção ---
ISR(TIMER2_OVF_vect)
{
    TCNT2   = 56;                                    //Reinicializa o registrador do Timer2
    T2_aux +=  1;                                    //incrementa o contador auxiliar


    if(T2_aux == 2500)                               //T2_aux chegou em 2500?  (2500 x 400µs = 1 seg.)
    {                                                //Sim
       T2_aux = 0x00;                                //Reinicia T2_aux


       // -- BASE DE TEMPO DE 1 SEGUNDO --
       PORTD ^= mask_pin;                            //PORTD = PORTD XOR mask_pin
                                                     //inverte estado do pino digital 7 (PD7 do atmega328p)
       
       rtc_disp();                                   //imprime parâmetros do RTC no monitor serial
       rtc_system();                                 //chama função de controle do RTC
       
       
   
    } //end if T2_aux
    
} //end ISR


// ======================================================================================================
// --- Configurações Iniciais ---
void setup()
{

     DDRD   = 0x80;                                  //configura digital 7 (PD7) como saída digital
     PORTD  = 0x00;                                  //inicializa o digital 7 (PD7) em LOW

     TCCR2A = 0x00;                                  //Timer2 operando em modo normal
     TCCR2B = 0x03;                                  //Prescaler 1:32
     TCNT2  = 56;                                    //Inicializa TCNT2 em 56 (contará até 200)
     TIMSK2 = 0x01;                                  //Habilita interrupção do Timer2

     Serial.begin(115200);                           //Inicializa serial em 115200 baud rate
 
} //end setup
 

// --- Loop Infinito ---
void loop()
{
 
   //aguarda interrupção

   
} //end loop


// ======================================================================================================
// --- Desenvolvimento das Funções ---

void rtc_system()                                    //Função de controle dos parâmetros do RTC
{
  short n_dias;                                      //armazena o número de dias de cada mês

  switch(mes)                                        //testa o mês
  {
    case  2:                                         //Fevereiro?
            if((ano%4 == 0 && ano%100 != 0) || ano%400 == 0)
              n_dias = 29; //se bissexto, terá 29 dias
            else
              n_dias = 28; //se não bissexto, terá 28 dias

              break;
    case  4:               //meses de 30 dias...
    case  6:
    case  9:
    case 11: n_dias = 30; break;
    default: n_dias = 31;  //meses de 31 dias...
    
  } //end switch

// ================================================== 
  segundo += 1;                                      //incrementa segundos

  if(segundo > 59)                                   //segundos maior que 59?
  {                                                  //sim
    segundo = 0;                                     //reinicia
    minuto += 1;                                     //incrementa minutos

     if(minuto > 59)                                 //minutos maior que 59?
     {                                               //sim
        minuto = 0;                                  //reinicia
        hora += 1;                                   //incrementa horas

         if(hora > 23)                               //horas maior que 23?
         {                                           //sim
            hora = 0;                                //reinicia
            dia += 1;                                //incrementa dias

             if(dia > n_dias)                        //dias maior que n_dias?
             {                                       //sim
                dia = 1;                             //reinicia
                mes += 1;                            //incrementa meses

                 if(mes > 12)                        //meses maior que 12?
                 {                                   //sim
                    mes = 1;                         //reinicia
                    ano += 1;                        //incrementa anos
                  
                 } //end if mes
              
             } //end if dia
          
         } //end if hora
      
     } //end if minuto
    
  } //end if segundo


} //end rtc_system


void rtc_disp()                                      //Função para imprimir valores do RTC
{

   if(hora < 10) Serial.print(" ");
   Serial.print(hora);
   Serial.print(" : ");
   if(minuto < 10) Serial.print(" ");
   Serial.print(minuto);
   Serial.print(" : ");
   if(segundo < 10) Serial.print(" ");
   Serial.print(segundo);
   Serial.print(" | ");
   if(dia < 10) Serial.print(" ");
   Serial.print(dia);
   Serial.print(" / ");
   if(mes < 10) Serial.print(" ");
   Serial.print(mes);
   Serial.print(" / ");
   Serial.println(ano);
   
  
} //end rtc_disp
