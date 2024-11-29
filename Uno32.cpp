#include "Arduino.h"
#include "Uno32.h"

Uno32::Uno32(){}

void Uno32::init(int baudrate) {
    Serial.begin(baudrate);
    Serial.setTimeout(5000);
    delay(1000);

    Serial.println("");
    Serial.println("Initializing Uno32");

    Serial2.begin(19200, SERIAL_8N1, 16, 17);
    delay(100);
    
    Serial2.println("start");

    String s = Serial2.readStringUntil('\n');
    Serial.println(s);
}

void Uno32::sendCmd(String cmd) {
    Serial2.println(cmd);
}

void Uno32::sendCmd(String cmd, int pin) {
    Serial2.print(cmd);
    Serial2.print(";");
    Serial2.println(pin);
}

void Uno32::sendCmd(String cmd, int pin, int value) {
    Serial2.print(cmd);
    Serial2.print(";");
    Serial2.print(pin);
    Serial2.print(";");
    Serial2.println(value);
}

void Uno32::pinMode(int pin, int value) {
    sendCmd("pm", pin, value);
}

void Uno32::digitalWrite(int pin, int value) {
    sendCmd("dw", pin, value);
}

int Uno32::digitalRead(int pin) {
    sendCmd("dr", pin);
    delay(5);
    String s = Serial2.readStringUntil('\n');
    return s.toInt();
}

void Uno32::analogWrite(int pin, int value) {
    sendCmd("aw", pin, value);
}

int Uno32::analogRead(int pin) {
    sendCmd("ar", pin);
    delay(5);
    String s = Serial2.readStringUntil('\n');
    return s.toInt();
}
