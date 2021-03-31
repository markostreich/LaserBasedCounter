#include "SevSeg.h" //needs lib from https://github.com/DeanIsMe/SevSeg
SevSeg sevseg;

int photoCellPin = 2; //Fotowiderstand am Analogen PIN A2
int counter = 0;
int value = 0;
boolean tictoc = true;

void setup()
{
  byte numDigits = 4; //Amount of digits
  byte digitPins[] = {2, 3, 4, 5}; //pins of digits
  byte segmentPins[] = {6, 7, 8, 9, 10, 11, 12, 13}; //pins for segments
  sevseg.begin(COMMON_CATHODE, numDigits, digitPins, segmentPins);
}

void loop()
{
  value = map(analogRead(photoCellPin), 0, 1023, 0, 20);
  if (value <= 16) {
    counter = tictoc ? counter + 1 : counter;
    tictoc = false;
  } else {
    tictoc = true;
  }
  if (counter > 9999)
    counter = 0;
  sevseg.setNumber(counter, 0);
  sevseg.refreshDisplay();
  sevseg.setBrightness(0);
}
