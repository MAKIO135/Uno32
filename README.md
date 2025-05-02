# Uno32
Drive an Arduino Uno from an Adafruit Huzzah32

## Usage
Upload https://github.com/MAKIO135/Uno32/blob/main/examples/uno/uno.ino on an Arduino Uno or equivalent and do the following wiring:  
  Huzzah32      Uno  
  USB       ->  Vin  
  GND       ->  GND  
  16        ->  1  
  17        ->  0  

Then drive the Uno from the Huzzah32 using Uno32 library:
```cpp
/*
  Pilot Uno board from Adafruit Feather Huzzah 32


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
```

## Gerber
Gerber made with [EasyEDA](https://easyeda.com/) is freely available.  

![IMG_20250430_141554](https://github.com/user-attachments/assets/480f26b4-2f19-4977-ac82-04aca75529f0)  
![IMG_20250430_141612](https://github.com/user-attachments/assets/fc4d0ee5-6463-4da5-9f46-48b73aebf9b3)
