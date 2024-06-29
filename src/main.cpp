#include <Arduino.h>
#include <Servo.h>

Servo servo;

int button_pin = A4;
int servo_pin = A3;
int valve_pin = A5; // клапан

void setup()
{
    // pinMode(LED_BUILTIN, OUTPUT);
    servo.attach(servo_pin);
    Serial.begin(9600);
    pinMode(button_pin, INPUT_PULLUP);
    pinMode(valve_pin, OUTPUT);

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
    if (digitalRead(button_pin) == 0){
        // Выстрел
        digitalWrite(valve_pin, 1); // открыть клапан
        delay(20);           // жду открытие клапана
        digitalWrite(valve_pin, 0); // закрываю клапан
        delay(10);           // жду пока выйдет воздух

        // Перезарядка
        servo.write(50); // открыть затвор
        delay(300);      // подождать открытие затвора
        servo.write(10); // закрыть затвор
        delay(100);      // жду закрытие затвора
        
    }
}