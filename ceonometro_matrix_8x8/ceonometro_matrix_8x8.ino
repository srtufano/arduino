#include <LedControl.h>
#include <Wire.h>
#include <Time.h>
#include <TimeLib.h>


/*
  DIN connects to pin 12
  CLK connects to pin 10
  CS connects to pin 11
*/

LedControl lc = LedControl(12, 10, 11, 2);

byte mm1, mm5, h, m, s;
byte ultM = 10, ultH = 10;
byte hPin = 7, mPin = 6;
boolean ajustaH = true, ajustaM = true;


void setup() {
  lc.shutdown(0, false);      // power-saving mode on startup
  lc.setIntensity(0, 0);     // Set the brightness to maximum value
  lc.clearDisplay(0);         // and clear the display
  lc.shutdown(1, false);      // power-saving mode on startup
  lc.setIntensity(1, 0);     // Set the brightness to maximum value
  lc.clearDisplay(1);         // and clear the display




  Serial.begin(9600);
  pinMode(hPin, INPUT_PULLUP);
  pinMode(mPin, INPUT_PULLUP);
}

void Display() {
  /* here is the data for the characters */
  // 0-9
  byte zero[8] = {0x00, 0x7C, 0x44, 0x7C, 0x00, 0x7C, 0x44, 0x7C}; //00
  byte one[8] = {0x00, 0x7C, 0x44, 0x7C, 0x00, 0x00, 0x7C, 0x00}; //01
  byte two[8] = {0x00, 0x7C, 0x44, 0x7C, 0x00, 0x74, 0x54, 0x5C}; //02
  byte three[8] = {0x00, 0x7C, 0x44, 0x7C, 0x00, 0x44, 0x54, 0x7C}; //03
  byte four[8] = {0x00, 0x7C, 0x44, 0x7C, 0x00, 0x1C, 0x10, 0x78}; //04
  byte five[8] = {0x00, 0x7C, 0x44, 0x7C, 0x00, 0x5C, 0x54, 0x74}; //05
  byte six[8] = {0x00, 0x7C, 0x44, 0x7C, 0x00, 0x7C, 0x54, 0x74}; //06
  byte seven[8] = {0x00, 0x7C, 0x44, 0x7C, 0x00, 0x04, 0x04, 0x7C}; //07
  byte eight[8] = {0x00, 0x7C, 0x44, 0x7C, 0x00, 0x7C, 0x54, 0x7C}; //08
  byte nine[8] = {0x00, 0x7C, 0x44, 0x7C, 0x00, 0x5C, 0x54, 0x7C}; //09
  // 10-19
  byte ten[8] = {0x00, 0x7C, 0x00, 0x7C, 0x44, 0x7C, 0x00, 0x00}; //10
  byte eleven[8] = {0x00, 0x7C, 0x00, 0x00, 0x7C, 0x00, 0x00, 0x00}; //11
  byte twelve[8] = {0x00, 0x7C, 0x00, 0x74, 0x54, 0x5C, 0x00, 0x00}; //12
  byte thirteen[8] = {0x00, 0x7C, 0x00, 0x44, 0x54, 0x7C, 0x00, 0x00}; //13
  byte fourteen[8] = {0x00, 0x7C, 0x00, 0x1C, 0x10, 0x78, 0x00, 0x00}; //14
  byte fifteen[8] = {0x00, 0x7C, 0x00, 0x5C, 0x54, 0x74, 0x00, 0x00}; //15
  byte sixteen[8] = {0x00, 0x7C, 0x00, 0x7C, 0x54, 0x74, 0x00, 0x00}; //16
  byte seventeen[8] = {0x00, 0x7C, 0x00, 0x04, 0x04, 0x7C, 0x00, 0x00}; //17
  byte eighteen[8] = {0x00, 0x7C, 0x00, 0x7C, 0x54, 0x7C, 0x00, 0x00}; //18
  byte nineteen[8] = {0x00, 0x7C, 0x00, 0x5C, 0x54, 0x7C, 0x00, 0x00}; //19

  // 20-29
  byte twenty[8] = {0x00, 0x74, 0x54, 0x5C, 0x00, 0x7C, 0x44, 0x7C}; //20
  byte twentyone[8] = {0x00, 0x74, 0x54, 0x5C, 0x00, 0x00, 0x7C, 0x00}; //21
  byte twentytwo[8] = {0x00, 0x74, 0x54, 0x5C, 0x00, 0x74, 0x54, 0x5C}; //22
  byte twentythree[8] = {0x00, 0x74, 0x54, 0x5C, 0x00, 0x44, 0x54, 0x7C}; //23
  byte twentyfour[8] = {0x00, 0x74, 0x54, 0x5C, 0x00, 0x1C, 0x10, 0x78}; //24
  byte twentyfive[8] = {0x00, 0x74, 0x54, 0x5C, 0x00, 0x5C, 0x54, 0x74}; //25
  byte twentysix[8] = {0x00, 0x74, 0x54, 0x5C, 0x00, 0x7C, 0x54, 0x74}; //26
  byte twentyseven[8] = {0x00, 0x74, 0x54, 0x5C, 0x00, 0x7C, 0x54, 0x74}; //27
  byte twentyeight[8] = {0x00, 0x74, 0x54, 0x5C, 0x00, 0x7C, 0x54, 0x7C}; //28
  byte twentynine[8] = {0x00, 0x74, 0x54, 0x5C, 0x00, 0x5C, 0x54, 0x7C}; //29

  // 30-39
  byte thirty[8] = {0x00, 0x44, 0x54, 0x7C, 0x00, 0x7C, 0x44, 0x7C}; //30
  byte thirtyone[8] = {0x00, 0x44, 0x54, 0x7C, 0x00, 0x00, 0x7C, 0x00}; //31
  byte thirtytwo[8] = {0x00, 0x44, 0x54, 0x7C, 0x00, 0x74, 0x54, 0x5C}; //32
  byte thirtythree[8] = {0x00, 0x44, 0x54, 0x7C, 0x00, 0x44, 0x54, 0x7C}; //33
  byte thirtyfour[8] = {0x00, 0x44, 0x54, 0x7C, 0x00, 0x1C, 0x10, 0x78}; //34
  byte thirtyfive[8] = {0x00, 0x44, 0x54, 0x7C, 0x00, 0x5C, 0x54, 0x74}; //35
  byte thirtysix[8] = {0x00, 0x44, 0x54, 0x7C, 0x00, 0x7C, 0x54, 0x74}; //36
  byte thirtyseven[8] = {0x00, 0x44, 0x54, 0x7C, 0x00, 0x04, 0x04, 0x7C}; //37
  byte thirtyeight[8] = {0x00, 0x44, 0x54, 0x7C, 0x00, 0x7C, 0x54, 0x7C}; //38
  byte thirtynine[8] = {0x00, 0x44, 0x54, 0x7C, 0x00, 0x5C, 0x54, 0x7C}; //39


  // 40-49
  byte forty[8] = {0x00, 0x1C, 0x10, 0x78, 0x00, 0x7C, 0x44, 0x7C}; //40
  byte fortyone[8] = {0x00, 0x1C, 0x10, 0x78, 0x00, 0x00, 0x7C, 0x00}; //41
  byte fortytwo[8] = {0x00, 0x1C, 0x10, 0x78, 0x00, 0x74, 0x54, 0x5C}; //42
  byte fortythree[8] = {0x00, 0x1C, 0x10, 0x78, 0x00, 0x44, 0x54, 0x7C}; //43
  byte fortyfour[8] = {0x00, 0x1C, 0x10, 0x78, 0x00, 0x1C, 0x10, 0x78}; //44
  byte fortyfive[8] = {0x00, 0x1C, 0x10, 0x78, 0x00, 0x5C, 0x54, 0x74}; //45
  byte fortysix[8] = {0x00, 0x1C, 0x10, 0x78, 0x00, 0x7C, 0x54, 0x74}; //46
  byte fortyseven[8] = {0x00, 0x1C, 0x10, 0x78, 0x00, 0x04, 0x04, 0x7C}; //47
  byte fortyeight[8] = {0x00, 0x1C, 0x10, 0x78, 0x00, 0x7C, 0x54, 0x7C}; //48
  byte fortynine[8] = {0x00, 0x1C, 0x10, 0x78, 0x00, 0x5C, 0x54, 0x7C}; //49

  // 50-59
  byte fifty[8] = {0x00, 0x5C, 0x54, 0x74, 0x00, 0x7C, 0x44, 0x7C}; //50
  byte fiftyone[8] = {0x00, 0x5C, 0x54, 0x74, 0x00, 0x00, 0x7C, 0x00}; //51
  byte fiftytwo[8] = {0x00, 0x5C, 0x54, 0x74, 0x00, 0x74, 0x54, 0x5C}; //52
  byte fiftythree[8] = {0x00, 0x5C, 0x54, 0x74, 0x00, 0x44, 0x54, 0x7C}; //53
  byte fiftyfour[8] = {0x00, 0x5C, 0x54, 0x74, 0x00, 0x1C, 0x10, 0x78}; //54
  byte fiftyfive[8] = {0x00, 0x5C, 0x54, 0x74, 0x00, 0x5C, 0x54, 0x74}; //55
  byte fiftysix[8] = {0x00, 0x5C, 0x54, 0x74, 0x00, 0x7C, 0x54, 0x74}; //56
  byte fiftyseven[8] = {0x00, 0x5C, 0x54, 0x74, 0x00, 0x04, 0x04, 0x7C}; //57
  byte fiftyeight[8] = {0x00, 0x5C, 0x54, 0x74, 0x00, 0x7C, 0x54, 0x7C}; //58
  byte fiftynine[8] = {0x00, 0x5C, 0x54, 0x74, 0x00, 0x5C, 0x54, 0x7C}; //59

  // Setup of Hours & Minutes
  ajustaH = digitalRead(hPin);
  ajustaM = digitalRead(mPin);

  if (!ajustaH) {
    adjustTime(3600);
  }

  if (!ajustaM) {
    adjustTime(60);
  }

  h = hour();
  m = minute();
  s = second ();
  Serial.print (hour());
  Serial.print(":");
  Serial.print (minute());
  Serial.print(":");
  Serial.print (second());
  Serial.println();

  delay(000);

  if ( m > 59)
  {
    m = (m - 59);
  }



  // now set hour
   if (m == 0)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(0, n, zero[n]);
    }

  }

  if (m == 1)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(0, n, one[n]);
    }

  }

  if (m == 2)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(0, n, two[n]);
    }

  }

  if (m == 3)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(0, n, three[n]);
    }

  }

  if (m == 4)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(0, n, four[n]);
    }

  }

  if (m == 5)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(0, n, five[n]);
    }

  }

  if (m == 6)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(0, n, six[n]);
    }

  }

  if (m == 7)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(0, n, seven[n]);
    }

  }

  if (m == 8)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(0, n, eight[n]);
    }

  }
  if (m == 9)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(0, n, nine[n]);
    }

  }

  if (m == 10)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(0, n, ten[n]);
    }

  }

  if ( m == 11)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(0, n, eleven[n]);
    }

  }

  if (m == 12)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(0, n, twelve[n]);
    }

  }

  if (m == 13)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(0, n, thirteen[n]);
    }

  }

  if (m == 14)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(0, n, fourteen[n]);
    }

  }
  if (m == 15)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(0, n, fifteen[n]);
    }

  }
  if (m == 16)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(0, n, sixteen[n]);
    }

  }

  if (m == 17)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(0, n, seventeen[n]);
    }

  }

  if (m == 18)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(0, n, eighteen[n]);
    }

  }

  if (m == 19)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(0, n, nineteen[n]);
    }

  }

  if (m == 20)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(0, n, twenty[n]);
    }

  }

  if (m == 21)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(0, n, twentyone[n]);
    }

  }

  if (m == 22)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(0, n, twentytwo[n]);
    }

  }

  if (m == 23)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(0, n, twentythree[n]);
    }

  }
if (m == 24)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(0, n, twentyfour[n]);
    }

  }
   if (m == 25)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(0, n, twentyfive[n]);
    }
  }

  if (m == 26)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(0, n, twentysix[n]);
    }

  }

  if (m == 27)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(0, n, twentyseven[n]);
    }

  }

  if (m == 28)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(0, n, twentyeight[n]);
    }

  }

  if (m == 29)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(0, n, twentynine[n]);
    }

  }

  if (m == 30)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(0, n, thirty[n]);
    }

  }

  if (m == 31)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(0, n, thirtyone[n]);
    }

  }

  if (m == 32)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(0, n, thirtytwo[n]);
    }

  }

  if (m == 33)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(0, n, thirtythree[n]);
    }

  }

  if (m == 34)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(0, n, thirtyfour[n]);
    }

  }

  if (m == 35)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(0, n, thirtyfive[n]);
    }

  }

  if (m == 36)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(0, n, thirtysix[n]);
    }

  }

  if (m == 37)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(0, n, thirtyseven[n]);
    }

  }

  if (m == 38)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(0, n, thirtyeight[n]);
    }

  }

  if (m == 39)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(0, n, thirtynine[n]);
    }

  }

  if (m == 40)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(0, n, forty[n]);
    }

  }

  if (m == 41)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(0, n, fortyone[n]);
    }

  }

  if (m == 42)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(0, n, fortytwo[n]);
    }

  }

  if (m == 43)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(0, n, fortythree[n]);
    }

  }

  if (m == 44)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(0, n, fortyfour[n]);
    }

  }

  if (m == 45)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(0, n, fortyfive[n]);
    }

  }

  if (m == 46)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(0, n, fortysix[n]);
    }

  }

  if (m == 47)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(0, n, fortyseven[n]);
    }

  }

  if (m == 48)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(0, n, fortyeight[n]);
    }

  }

  if (m == 49)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(0, n, fortynine[n]);
    }

  }

  if (m == 50)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(0, n, fifty[n]);
    }

  }

  if (m == 51)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(0, n, fiftyone[n]);
    }
  }

  if (m == 52)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(0, n, fiftytwo[n]);
    }

  }

  if (m == 53)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(0, n, fiftythree[n]);
    }

  }
  if (m == 54)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(0, n, fiftyfour[n]);
    }

  }

  if (m == 55)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(0, n, fiftyfive[n]);
    }

  }

  if (m == 56)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(0, n, fiftysix[n]);
    }

  }

  if (m == 57)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(0, n, fiftyseven[n]);
    }

  }
  if (m == 58)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(0, n, fiftyeight[n]);
    }

  }

  if (m == 59)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(0, n, fiftynine[n]);
    }

  }

 

  // now set minute
  if (s == 0)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(1, n, zero[n]);
    }

  }

  if (s == 1)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(1, n, one[n]);
    }

  }

  if (s == 2)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(1, n, two[n]);
    }

  }

  if (s == 3)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(1, n, three[n]);
    }

  }

  if (s == 4)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(1, n, four[n]);
    }

  }

  if (s == 5)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(1, n, five[n]);
    }

  }

  if (s == 6)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(1, n, six[n]);
    }

  }

  if (s == 7)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(1, n, seven[n]);
    }

  }

  if (s == 8)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(1, n, eight[n]);
    }

  }
  if (s == 9)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(1, n, nine[n]);
    }

  }

  if (s == 10)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(1, n, ten[n]);
    }

  }

  if (s == 11)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(1, n, eleven[n]);
    }

  }

  if (s == 12)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(1, n, twelve[n]);
    }

  }

  if (s == 13)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(1, n, thirteen[n]);
    }

  }

  if (s == 14)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(1, n, fourteen[n]);
    }

  }
  if (s == 15)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(1, n, fifteen[n]);
    }

  }
  if (s == 16)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(1, n, sixteen[n]);
    }

  }

  if (s == 17)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(1, n, seventeen[n]);
    }

  }

  if (s == 18)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(1, n, eighteen[n]);
    }

  }

  if (s == 19)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(1, n, nineteen[n]);
    }

  }

  if (s == 20)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(1, n, twenty[n]);
    }

  }

  if (s == 21)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(1, n, twentyone[n]);
    }

  }

  if (s == 22)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(1, n, twentytwo[n]);
    }

  }

  if (s == 23)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(1, n, twentythree[n]);
    }

  }

  if (s == 24)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(1, n, twentyfour[n]);
    }

  }

  if (s == 25)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(1, n, twentyfive[n]);
    }
  }

  if (s == 26)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(1, n, twentysix[n]);
    }

  }

  if (s == 27)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(1, n, twentyseven[n]);
    }

  }

  if (s == 28)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(1, n, twentyeight[n]);
    }

  }

  if (s == 29)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(1, n, twentynine[n]);
    }

  }

  if (s == 30)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(1, n, thirty[n]);
    }

  }

  if (s == 31)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(1, n, thirtyone[n]);
    }

  }

  if (s == 32)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(1, n, thirtytwo[n]);
    }

  }

  if (s == 33)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(1, n, thirtythree[n]);
    }

  }

  if (s == 34)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(1, n, thirtyfour[n]);
    }

  }

  if (s == 35)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(1, n, thirtyfive[n]);
    }

  }

  if (s == 36)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(1, n, thirtysix[n]);
    }

  }

  if (s == 37)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(1, n, thirtyseven[n]);
    }

  }

  if (s == 38)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(1, n, thirtyeight[n]);
    }

  }

  if (s == 39)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(1, n, thirtynine[n]);
    }

  }

  if (s == 40)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(1, n, forty[n]);
    }

  }

  if (s == 41)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(1, n, fortyone[n]);
    }

  }

  if (s == 42)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(1, n, fortytwo[n]);
    }

  }

  if (s == 43)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(1, n, fortythree[n]);
    }

  }

  if (s == 44)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(1, n, fortyfour[n]);
    }

  }

  if (s == 45)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(1, n, fortyfive[n]);
    }

  }

  if (s == 46)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(1, n, fortysix[n]);
    }

  }

  if (s == 47)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(1, n, fortyseven[n]);
    }

  }

  if (s == 48)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(1, n, fortyeight[n]);
    }

  }

  if (s == 49)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(1, n, fortynine[n]);
    }

  }

  if (s == 50)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(1, n, fifty[n]);
    }

  }

  if (s == 51)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(1, n, fiftyone[n]);
    }
  }

  if (s == 52)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(1, n, fiftytwo[n]);
    }

  }

  if (s == 53)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(1, n, fiftythree[n]);
    }

  }
  if (s == 54)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(1, n, fiftyfour[n]);
    }

  }

  if (s == 55)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(1, n, fiftyfive[n]);
    }

  }

  if (s == 56)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(1, n, fiftysix[n]);
    }

  }

  if (s == 57)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(1, n, fiftyseven[n]);
    }

  }
  if (s == 58)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(1, n, fiftyeight[n]);
    }

  }

  if (s == 59)
  {
    for (int n = 0; n < 8; n++) {
      lc.setRow(1, n, fiftynine[n]);
    }

  }
}
void loop() {

  Display();
  delay(1000);

}
