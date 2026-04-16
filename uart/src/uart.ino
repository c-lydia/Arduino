#include <Arduino.h>

#define LED 13

char incoming_data;

void setup() {
    Serial.begin(9600);
    pinMode(LED, OUTPUT);
}

void loop() {
    if (Serial.available() > 0) {
        incoming_data = Serial.read();
        
        if (incoming_data == 'H') {
            digitalWrite(LED, HIGH);
        } else if (incoming_data == 'L') {
            digitalWrite(LED, LOW);
        }

        Serial.print("Incoming data: ");
        Serial.print(incoming_data);
        Serial.print(" -> LED state: ");
        Serial.println(digitalRead(LED));
    }
}