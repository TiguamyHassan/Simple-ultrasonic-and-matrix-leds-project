#include <LedControl.h>

int trig = 7, echo = 6;
LedControl lc = LedControl(10,8,9,1);

void setup() {
  lc.shutdown(0, false);
  lc.setIntensity(0, 8);
  lc.clearDisplay(0);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

void loop() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  float t =pulseIn(echo, HIGH);
  float d = 0.034 * t / 2;

  int cols = 0;
  if(d < 18) cols = 1;
  if(d < 16) cols = 2;
  if(d < 14) cols = 3;
  if(d < 12) cols = 4;
  if(d < 10) cols = 5;
  if(d < 8)  cols = 6;
  if(d < 6)  cols = 7;
  if(d < 4)  cols = 8;

  byte row = 0;
  for(int c = 0; c < cols; c++)
    row |= (B10000000 >> c);

  for(int r = 0; r < 8; r++)
    lc.setRow(0, r, row);

  delay(30);
}
