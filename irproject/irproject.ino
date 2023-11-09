#include <IRremote.hpp>

#define IR_RECEIVE_PIN 2
#define IR_SEND_PIN 3

#define DELAY_AFTER_SEND 5000

int pullUpPin = 4;
int readedPullUp;

void setup(){
  Serial.begin(115200);
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
  IrSender.begin(IR_SEND_PIN);
  pinMode(pullUpPin, INPUT);
  digitalWrite(pullUpPin, 1);
  IrSender.enableIROut(38);
}

void loop(){
  // receive_ir_data();
  // delay(100);
  readedPullUp = digitalRead(pullUpPin);
  // Serial.println(readedPullUp);
  // printActiveIRProtocols(&Serial);

  if(readedPullUp == 0){
    send_ir_data();

  }

  receive_ir_data();

  delay(1000);
}

void send_ir_data() {
    // IrSender.sendNEC(0x0, 0x1C, 1);
  IrSender.sendNEC(0xBA45FF00, 32);
  delay(40);
}


void receive_ir_data() {
    if (IrReceiver.decode()) {
        IrReceiver.printIRResultShort(&Serial);
        IrReceiver.resume();
    }
}