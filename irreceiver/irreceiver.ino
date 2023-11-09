#include <IRremote.hpp>
#define IR_RECEIVE_PIN 2

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (IrReceiver.decode()) {
    IrReceiver.printIRResultShort(&Serial);
    IrReceiver.resume();
  }
}
