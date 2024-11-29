/*
  Pilot Uno board from Adafruit Feather Huzzah 32
  Wiring:
  Huzzah32      Uno
  USB       ->  Vin
  GND       ->  GND
  16        ->  1
  17        ->  0

  This sketch is for the Uno
*/

String params[3];
int paramsIndex = 0;

void setup() {
  for(int i = 0; i < 3; i ++) params[i].reserve(4);

  Serial.begin(19200);
  while(Serial.available() > 0) Serial.read(); // clear Serial
}

void loop() {
  while(Serial.available() > 0) {
    char c = char(Serial.read());

    if(c == ';') paramsIndex ++;
    else if(c == '\r') {}
    else if(c != '\n') params[paramsIndex] += c;
    else {
      if(params[0].equals("start") && paramsIndex == 0) {
        Serial.println("ready");
      }
      else if(params[0].equals("pm") && paramsIndex == 2) {
        pinMode(params[1].toInt(), params[2].toInt());
      }
      else if(params[0].equals("dr") && paramsIndex == 1) {
        Serial.println(digitalRead(params[1].toInt()));
      }
      else if(params[0].equals("ar") && paramsIndex == 1) {
        Serial.println(analogRead(params[1].toInt()));
      }
      else if(params[0].equals("dw") && paramsIndex == 2) {
        digitalWrite(params[1].toInt(), params[2].toInt());
      }
      else if(params[0].equals("aw") && paramsIndex == 2) {
        analogWrite(params[1].toInt(), params[2].toInt());
      }

      // reset params
      for(int i = 0; i < 3; i ++) params[i] = "";
      paramsIndex = 0;
    }
  }
}