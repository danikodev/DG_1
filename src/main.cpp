#include <Arduino.h>
#include <Servo.h>

Servo servo;

void setup()
{
    // pinMode(LED_BUILTIN, OUTPUT);
    servo.attach(LED_BUILTIN);
    Serial.begin(115200);
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
    servo.write(50);
    Serial.println(50);
    delay(300);
    servo.write(10);
    Serial.println(10);
    // end
    delay(200);
}
