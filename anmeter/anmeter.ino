//version
#define NAME "Fonte Ajustavel"
#define VERSION "1.0"

//debug flag (avoid enabling. it makes your device slower)
//#define DEBUG

//pins
//onst int PIN_BACKLIGHT = 7;
const int PIN_BUZZER = 3;
const int PIN_VOLTAGE = 0;
const int PIN_CURRENT = 1;
const int PIN_BUTTON_UP = 6;
const int PIN_BUTTON_SETUP = 5;
const int PIN_BUTTON_DOWN = 4;

// includes
#include <LiquidCrystal_I2C.h>
#include "Wire.h"
#include <EEPROM.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal_I2C lcd(0x3F,2,1,0,4,5,6,7,3, POSITIVE);

//variables
//voltage
int VOLTAGE_CURRENT;
int VOLTAGE_LAST=99999;
unsigned long VOLTAGE_MILLIS;
float VOLTAGE_CALCULATED;
float VOLTAGE_MAP = 50; //default voltage map... calibration needed
//current
int CURRENT_CURRENT;
int CURRENT_LAST=99999;
unsigned long CURRENT_MILLIS;
float CURRENT_CALCULATED;
float CURRENT_MAP = 10; //default current map... calibration needed 
//buttons
boolean BUTTON_PRESSED = false;
unsigned long BUTTON_MILLIS = false;
byte BUTTON_LAST;
boolean SETUP_MODE = false;
byte SETUP_ITEM;
boolean SETUP_DELAYBEEP;
//...
unsigned long MILLIS;
unsigned long SETUP_BLINKMILLIS;
boolean SETUP_BLINKSTATE;

//parameters
const int SENSOR_INTERVAL = 500;
const int BUTTON_HOLDTIME = 2000;
const int SETUP_MAXITEMS = 2;
const int SETUP_BLINKINTERVAL = 300;
const byte EEPROM_VALIDATOR = 73; //random number
const float VOLTAGE_STEP = 0.1;
const float CURRENT_STEP = 0.1;

//configuration
const byte EEPROM_CONFIGADDRESS = 0;
struct config_t
{
  byte Validator;
  /////////////////////
  float VOLTAGE_MAP;
  float CURRENT_MAP;
  /////////////////////
  byte ValidatorX2;
} EEPROM_DATA;

void setup() {
  //configure pins
  //pinMode(PIN_BACKLIGHT, OUTPUT);
  pinMode(PIN_BUZZER, OUTPUT);
  pinMode(PIN_VOLTAGE, INPUT);
  pinMode(PIN_CURRENT, INPUT);
  pinMode(PIN_BUTTON_UP, INPUT);
  pinMode(PIN_BUTTON_SETUP, INPUT);
  pinMode(PIN_BUTTON_DOWN, INPUT);

  //set up LCD
  lcd.begin(16, 2);

  //initial message  
  lcd.setCursor(0, 0);
  lcd.print(NAME);
  lcd.setCursor(0, 1);
  lcd.print("Versao ");
  lcd.print(VERSION);
  
  //lights up
  lcd.setBacklight(HIGH);
  
#ifdef DEBUG
  delay(2000);
  lcd.setCursor(0, 1);
  lcd.print("Debug enabled!  ");
  lcd.print(VERSION);

  Serial.begin(9600);
  Serial.println("============================");
  Serial.println(NAME);
  Serial.println("Version ");
  Serial.println(VERSION);
  Serial.println("============================");
  Serial.println("Debug messages:");
  Serial.println("----------------------------");
#endif
  
  //try to load the configuration
  loadConfiguration();

  //show initial message for a while then clear and beep
  delay(2000);
  lcd.clear();
  showLabels();
  
  //beep
  beepStart();
}

void loop() {
  processButtons();
  
  MILLIS = millis();

  if ( (MILLIS - VOLTAGE_MILLIS) >= SENSOR_INTERVAL )
  {
    readVoltage();
    
    if (!SETUP_MODE || SETUP_ITEM!=1) {
      showVoltage();
    }

    VOLTAGE_MILLIS = MILLIS;
  }

  if ( (MILLIS - CURRENT_MILLIS) >= SENSOR_INTERVAL )
  {
    readCurrent();
    
    if (!SETUP_MODE || SETUP_ITEM!=2) {
      showCURRENT();
    }

    CURRENT_MILLIS = MILLIS;
  }

  if (SETUP_MODE)
  {
    if ( (MILLIS - SETUP_BLINKMILLIS) >= SETUP_BLINKINTERVAL )
    {
      if (SETUP_BLINKSTATE)
      {
        if (SETUP_ITEM==1)
          showVoltage();
        else if (SETUP_ITEM==2)
          showCURRENT();
        
        SETUP_BLINKSTATE = false;
      } else {
        if (SETUP_ITEM==1)
          hideVoltage();
        else if (SETUP_ITEM==2)
          hideCURRENT();        
        
        SETUP_BLINKSTATE = true;
      }
      
      SETUP_BLINKMILLIS = MILLIS;
    }
  }
}

void processButtons()
{
  if (digitalRead(PIN_BUTTON_UP) == HIGH)
  {
    if (!BUTTON_PRESSED)
    {
#ifdef DEBUG  
      showDebug("Pressed UP");
#endif

      BUTTON_LAST = PIN_BUTTON_UP;
      BUTTON_PRESSED = true;
    }
  }
  else if (digitalRead(PIN_BUTTON_SETUP) == HIGH)
  {
    if (!BUTTON_PRESSED)
    {
#ifdef DEBUG  
      showDebug("Pressed SETUP");
#endif
      
      beepButton();
      BUTTON_LAST = PIN_BUTTON_SETUP;
      BUTTON_MILLIS = millis();
      BUTTON_PRESSED = true;
      SETUP_DELAYBEEP = false;
    } else {
      if ((millis() - BUTTON_MILLIS) > BUTTON_HOLDTIME)
        if (!SETUP_DELAYBEEP)
        {
          beepButton();
          SETUP_DELAYBEEP = true;
        }
      
    }
  }
  else if (digitalRead(PIN_BUTTON_DOWN) == HIGH)
  {
    if (!BUTTON_PRESSED)
    {
#ifdef DEBUG  
      showDebug("Pressed DOWN");
#endif 
      
      BUTTON_LAST = PIN_BUTTON_DOWN;
      BUTTON_PRESSED = true;

    }
  }
  else 
  {
    if (BUTTON_PRESSED) {
      if (BUTTON_LAST == PIN_BUTTON_SETUP)
      {
#ifdef DEBUG  
        showDebug("Released SETUP");
#endif
        
        if (!SETUP_MODE && (millis() - BUTTON_MILLIS) > BUTTON_HOLDTIME) {
#ifdef DEBUG  
          showDebug("Entered setup mode!");
#endif
          
          lcd.setCursor(0, 1);
          lcd.print("   Setup Mode   ");
          SETUP_MODE = true;
          SETUP_ITEM = 1;
        } 
        else {
          if (SETUP_ITEM == SETUP_MAXITEMS) {
#ifdef DEBUG  
          showDebug("Exited setup mode!");
#endif
            
            showLabels();
            SETUP_MODE = false;
            SETUP_ITEM = 0;
            saveConfiguration();
          } 
          else {
            SETUP_ITEM++;
          }
          
          showVoltage();
          showCURRENT();
        }
      } 
      else if (BUTTON_LAST == PIN_BUTTON_UP) {
#ifdef DEBUG  
        showDebug("Released UP");
#endif
        
        if (SETUP_MODE) {
          beepButton();
          
          if (SETUP_ITEM==1) { //voltage
            VOLTAGE_MAP+=VOLTAGE_STEP;
            readVoltage();
            
#ifdef DEBUG  
            startDebug("New VOLTAGE_MAP: ");
            Serial.println(VOLTAGE_MAP,6);
#endif
          } else if (SETUP_ITEM==2) { //current
            CURRENT_MAP+=CURRENT_STEP;
            readCurrent();
            
#ifdef DEBUG  
            startDebug("New CURRENT_MAP: ");
            Serial.println(CURRENT_MAP,6);
#endif
          }
        }
      } 
      else if (BUTTON_LAST == PIN_BUTTON_DOWN) {
#ifdef DEBUG  
        showDebug("Released DOWN");
#endif
        
        if (SETUP_MODE) {
          beepButton();
          
          if (SETUP_ITEM==1) { //voltage
            VOLTAGE_MAP-=VOLTAGE_STEP;
            readVoltage();
            
#ifdef DEBUG  
            startDebug("New VOLTAGE_MAP: ");
            Serial.println(VOLTAGE_MAP,6);
#endif
          } else if (SETUP_ITEM==2) { //current
            CURRENT_MAP-=CURRENT_STEP;
            readCurrent();
            
#ifdef DEBUG  
            startDebug("New CURRENT_MAP: ");
            Serial.println(CURRENT_MAP,6);
#endif
          }
        }
      }

      BUTTON_PRESSED = false;
    }
  }
}

#ifdef DEBUG  
void showDebug(char* Message)
{
  Serial.print(millis());
  Serial.print(": ");
  Serial.println(Message);
}

void startDebug(char* Message)
{
  Serial.print(millis());
  Serial.print(": ");
  Serial.print(Message);
}
#endif

void showLabels()
{
  lcd.setCursor(0, 1);
  lcd.print("Volts       Amps");
}

void showVoltage()
{
    lcd.setCursor(0, 0);
    lcd.print(VOLTAGE_CALCULATED, 2);
    lcd.print(" V");

    if (VOLTAGE_CALCULATED<10)
      lcd.print(" ");
}

void hideVoltage()
{
    lcd.setCursor(0, 0);
    lcd.print("       ");
}

void showCURRENT()
{
    lcd.setCursor(9, 0);

    if (CURRENT_CALCULATED<10)
      lcd.print(" ");

    lcd.print(CURRENT_CALCULATED, 2);
    lcd.print(" A");
}

void hideCURRENT()
{
    lcd.setCursor(9, 0);
    lcd.print("       ");
}

void beepStart()
{
  for (int i=0; i<300; i++) {
    digitalWrite(PIN_BUZZER, HIGH);
    delayMicroseconds(200);
    digitalWrite(PIN_BUZZER, LOW);
    delayMicroseconds(200);
  } 
}

void beepButton()
{
  for (int i=0; i<20; i++) {
    digitalWrite(PIN_BUZZER, HIGH);
    delayMicroseconds(700);
    digitalWrite(PIN_BUZZER, LOW);
    delayMicroseconds(700);
  } 
}

void readVoltage()
{
  VOLTAGE_CURRENT = analogRead(PIN_VOLTAGE);
  if ( VOLTAGE_CURRENT != VOLTAGE_LAST || SETUP_MODE ) {
    VOLTAGE_LAST = VOLTAGE_CURRENT;
    VOLTAGE_CALCULATED = fmap(VOLTAGE_CURRENT, 0, 1023, 0.0, VOLTAGE_MAP);
    
#ifdef DEBUG  
    if (!SETUP_MODE)
    {
      startDebug("New voltage: ");
      Serial.print(VOLTAGE_CALCULATED);
      Serial.println("V");
    }
#endif
  }
}

void readCurrent()
{
  CURRENT_CURRENT = analogRead(PIN_CURRENT);
  if ( CURRENT_CURRENT != CURRENT_LAST || SETUP_MODE ) {
    CURRENT_LAST = CURRENT_CURRENT;
    CURRENT_CALCULATED = fmap(CURRENT_CURRENT, 0, 1023, 0.0, CURRENT_MAP);
    
#ifdef DEBUG
    if (!SETUP_MODE)
    {
      startDebug("New current: ");
      Serial.print(CURRENT_CALCULATED);
      Serial.println("A");
    }
#endif
  }
}


float fmap(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

int EEPROM_writeConf()
{
    byte Address = EEPROM_CONFIGADDRESS;
  
    const byte* p = (const byte*)(const void*)&EEPROM_DATA;
    int i;
    for (i = 0; i < sizeof(EEPROM_DATA); i++)
      EEPROM.write(Address++, *p++);
    return i;
}

int EEPROM_readConf()
{
    byte Address = EEPROM_CONFIGADDRESS;
  
    byte* p = (byte*)(void*)&EEPROM_DATA;
    int i;
    for (i = 0; i < sizeof(EEPROM_DATA); i++)
      *p++ = EEPROM.read(Address++);
    return i;
}

void loadConfiguration()
{
  //read data from eeprom
  EEPROM_readConf();
  
  //verify validators
  if (EEPROM_DATA.Validator == EEPROM_VALIDATOR && EEPROM_DATA.ValidatorX2 == EEPROM_VALIDATOR*2)
  {
    //copy data
    VOLTAGE_MAP = EEPROM_DATA.VOLTAGE_MAP;
    CURRENT_MAP = EEPROM_DATA.CURRENT_MAP;

#ifdef DEBUG
    showDebug("Configuration loaded from EEPROM!");
    startDebug("   VOLTAGE_MAP: ");
    Serial.println(VOLTAGE_MAP,6);
    startDebug("   CURRENT_MAP: ");
    Serial.println(CURRENT_MAP,6);
#endif
  } else {
#ifdef DEBUG
    showDebug("Configuration NOT loaded from EEPROM!");
#endif    
  }
}

void saveConfiguration()
{
  if ( EEPROM_DATA.VOLTAGE_MAP != VOLTAGE_MAP ||
       EEPROM_DATA.CURRENT_MAP != CURRENT_MAP
  ) {
    //copy validators
    EEPROM_DATA.Validator = EEPROM_VALIDATOR;
    EEPROM_DATA.ValidatorX2 = EEPROM_VALIDATOR*2;
  
    //copy data
    EEPROM_DATA.VOLTAGE_MAP = VOLTAGE_MAP;
    EEPROM_DATA.CURRENT_MAP = CURRENT_MAP;
  
    //save data to eeprom
    EEPROM_writeConf();
    
#ifdef DEBUG
    showDebug("Configuration saved!");
#endif
  } else {
#ifdef DEBUG
    showDebug("Configuration not changed!");
#endif 
  }
}
