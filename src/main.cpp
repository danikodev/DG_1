#include <Arduino.h>
#include <Servo.h>

Servo servo;

void setup()
{
    // pinMode(LED_BUILTIN, OUTPUT);
    servo.attach(A1);
    Serial.begin(9600);
    pinMode(DD2, INPUT_PULLUP);
    pinMode(LED_BUILTIN, OUTPUT);

    servo.write(10);
}

void loop()
{
    // for (uint8_t pos = 0; pos <= 180; pos += 1)
    // {
    //     servo.write(pos);
    //     delay(15);
    // }
    // for (uint8_t pos = 180; pos >= 0; pos -= 1)
    // {
    //     servo.write(pos);
    //     delay(15);
    // }
    if (digitalRead(DD2) == 0){
        digitalWrite(LED_BUILTIN, 1); // вкл лампу
        delay(500); // жду
        digitalWrite(LED_BUILTIN, 0); // выкл лампу
        servo.write(50); // открываю серво
        Serial.println(50); 
        delay(300); // жду
        servo.write(10); // закрываю серво
        Serial.println(10); 
        
    }
}