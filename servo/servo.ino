#include <Servo.h>

struct ser_t {
  int pin;
  int position;
};

struct pot_t {
  int pin;
  float value;
};

ser_t ser = {pin: 5, position: 90};
Servo myServo;

pot_t pot = {pin: A4, value: 0};
int defaultDelay = 1500;

void setup() {
  myServo.attach(ser.pin);
  Serial.begin(9600);
}

// void loop() {
//   pot.value = analogRead(pot.pin);
//   ser.position = (160./1023.) * (pot.value) + 10.;
//   Serial.println(ser.position);
//   myServo.write(ser.position);
//   delay(defaultDelay);
// }

void loop() {
  myServo.write(10);
  delay(defaultDelay);
  myServo.write(50);
  delay(defaultDelay);
}
