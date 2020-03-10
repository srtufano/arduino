#define NOTE_D4 294
#define NOTE_G4 392
#define NOTE_A4 440
#define NOTE_A5 880

int tons[4] = { NOTE_A4, NOTE_G4, NOTE_D4 ,NOTE_A5};
int sequencia[100] = {};
int rodada_atual = 0;
int passo_atual_na_sequencia = 0;

int pinoAudio = 7;
int pinosLEDs[4] = { 8,9,10,11 };
int pinosBotoes[4] = {2,3,4,5};
int botao_pressionado = 0;
int perdeu_o_jogo = false;

void setup() {
for (int i = 0; i <= 3; i++) {
pinMode(pinosLEDs[i], OUTPUT);
}
for (int i = 0; i <= 3; i++) {
pinMode(pinosBotoes[i], INPUT);
}
pinMode(pinoAudio, OUTPUT);
randomSeed(analogRead(0));
}

void loop() {
if (perdeu_o_jogo) {
int sequencia[100] = {};
rodada_atual = 0;
passo_atual_na_sequencia = 0;
perdeu_o_jogo = false;
}

if (rodada_atual == 0) {
tocarSomDeInicio();
delay(500);
}

proximaRodada();
reproduzirsequencia();
aguardarJogador();
delay(1000);
}

void proximaRodada() {
int numero_sorteado = random(0, 3);
sequencia[rodada_atual++] = numero_sorteado;
}

void reproduzirsequencia() {
for (int i = 0; i < rodada_atual; i++) {
tone(pinoAudio, tons[sequencia[i]]);
digitalWrite(pinosLEDs[sequencia[i]], HIGH);
delay(500);
noTone(pinoAudio);
digitalWrite(pinosLEDs[sequencia[i]], LOW);
delay(100);
}
noTone(pinoAudio);
}

void aguardarJogador() {
for (int i = 0; i < rodada_atual; i++) {
aguardarJogada();
verificarJogada();
if (perdeu_o_jogo) {
break;
}
passo_atual_na_sequencia++;
}
passo_atual_na_sequencia = 0;
}

void aguardarJogada() {
boolean jogada_efetuada = false;
while (!jogada_efetuada) {
for (int i = 0; i <= 3; i++) {
if (digitalRead(pinosBotoes[i]) == HIGH) {
// Dizendo qual foi o botao pressionado.
botao_pressionado = i;
tone(pinoAudio, tons[i]);
digitalWrite(pinosLEDs[i], HIGH);
delay(300);
digitalWrite(pinosLEDs[i], LOW);
noTone(pinoAudio);
jogada_efetuada = true;
}
}
delay(10);
}
}

void verificarJogada() {
if (sequencia[passo_atual_na_sequencia] != botao_pressionado) {
  for (int i = 0; i <= 3; i++) {
tone(pinoAudio, tons[i]);
digitalWrite(pinosLEDs[i], HIGH);
delay(200);
digitalWrite(pinosLEDs[i], LOW);
noTone(pinoAudio);
}
tone(pinoAudio, tons[2]);
for (int i = 0; i <= 3; i++) {
digitalWrite(pinosLEDs[0], HIGH);
digitalWrite(pinosLEDs[1], HIGH);
digitalWrite(pinosLEDs[2], HIGH);
digitalWrite(pinosLEDs[3], HIGH);
delay(100);
digitalWrite(pinosLEDs[0], LOW);
digitalWrite(pinosLEDs[1], LOW);
digitalWrite(pinosLEDs[2], LOW);
digitalWrite(pinosLEDs[3], LOW);
delay(100);
}
noTone(pinoAudio);
perdeu_o_jogo = true;
}
}

void tocarSomDeInicio() {
tone(pinoAudio, tons[0]);
digitalWrite(pinosLEDs[0], HIGH);
digitalWrite(pinosLEDs[1], HIGH);
digitalWrite(pinosLEDs[2], HIGH);
digitalWrite(pinosLEDs[3], HIGH);
delay(500);
digitalWrite(pinosLEDs[0], LOW);
digitalWrite(pinosLEDs[1], LOW);
digitalWrite(pinosLEDs[2], LOW);
digitalWrite(pinosLEDs[3], LOW);
delay(500);
noTone(pinoAudio);
}

