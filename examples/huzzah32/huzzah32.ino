/*
  Pilot Uno board from Adafruit Feather Huzzah 32
  Wiring:
  Huzzah32      Uno
  USB       ->  Vin
  GND       ->  GND
  16        ->  1
  17        ->  0

  This sketch is for the Huzzah32
*/

#include <Uno32.h>

Uno32 uno;

void setup() {
  uno.init(19200);
  uno.pinMode(13, UNO_OUTPUT);
}

void loop() {
  int potarValue = uno.analogRead(UNO_A5);

  Serial.println(potarValue);

  if(potarValue < 512) {
    for(int i = 0; i < 3; i ++) {
      uno.digitalWrite(13, UNO_HIGH);
      delay(20);
      uno.digitalWrite(13, UNO_LOW);
      delay(20);
    }
  }

  delay(50);
}