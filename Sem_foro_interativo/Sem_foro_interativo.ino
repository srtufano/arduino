//Semáforo interativo
int pinGnd = 13;
int carVermelho = 12; // estabelece o semáforo para carros
int carAmarelo = 11;
int carVerde = 10;
int pedVermelho = 9; // estabelece o semáforo para pedestres
int pedVerde = 8;
int button = 2; // pino do botão
int crossTime = 5000; // tempo para que os pedestres atravessem
unsigned long changeTime; // tempo desde que o botão foi pressionado
void setup() {
pinMode(pinGnd, OUTPUT);
pinMode(carVermelho, OUTPUT);
pinMode(carAmarelo, OUTPUT);
pinMode(carVerde, OUTPUT);
pinMode(pedVermelho, OUTPUT);
pinMode(pedVerde, OUTPUT);
pinMode(button, INPUT_PULLUP); // botão no pino 2
digitalWrite(pinGnd, LOW);
// acende a luz verde
digitalWrite(carVerde, HIGH);
digitalWrite(pedVermelho, HIGH);
}
void loop() {
int state = digitalRead(button);
/* verifica se o botão foi pressionado e se transcorreram 5 segundos desde a última vez que
 isso ocorreu */
if (state == HIGH && (millis() - changeTime) > 5000) {

// Chama a função para alterar as luzes
changeLights();
}
}
void changeLights() {
digitalWrite(carVerde, LOW); // apaga o verde
digitalWrite(carAmarelo, HIGH); // acende o amarelo
delay(2000); // espera 2 segundos
digitalWrite(carAmarelo, LOW); // apaga o amarelo
digitalWrite(carVermelho, HIGH); // acende o vermelho
delay(1000); // espera 1 segundo, por segurança
digitalWrite(pedVermelho, LOW); // apaga o vermelho dos pedestres
digitalWrite(pedVerde, HIGH); // acende o verde dos pedestres
delay(crossTime); // espera por um intervalo de tempo predefinido
// pisca o verde dos pedestres
for (int x=0; x<10; x++) {
digitalWrite(pedVerde, HIGH);
delay(250);
digitalWrite(pedVerde, LOW);
delay(250);
}
// acende o vermelho dos pedestres
digitalWrite(pedVermelho, HIGH);
delay(500);
digitalWrite(carAmarelo, HIGH); // acende o amarelo
digitalWrite(carVermelho, LOW); // apaga o vermelho
delay(1000);
digitalWrite(carVerde, HIGH); // acende o verde
digitalWrite(carAmarelo, LOW); // apaga o amarelo
// registra o tempo desde a última alteração no semáforo
changeTime = millis();
// depois retorna para o loop principal do programa
}
