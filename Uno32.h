#pragma once

#include "Arduino.h"

#define UNO_HIGH 1
#define UNO_LOW 0
#define UNO_INPUT 0
#define UNO_OUTPUT 1
#define UNO_INPUT_PULLUP 2
#define UNO_A0 14
#define UNO_A1 15
#define UNO_A2 16
#define UNO_A3 17
#define UNO_A4 18
#define UNO_A5 19

class Uno32 {
    public:
        Uno32();
        void init(int baudrate);
        void sendCmd(String s);
        void sendCmd(String s, int pin);
        void sendCmd(String s, int pin, int value);
        void pinMode(int pin, int value);
        void digitalWrite(int pin, int value);
        int digitalRead(int pin);
        void analogWrite(int pin, int value);
        int analogRead(int pin);
    
    private:
};