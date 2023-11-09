#include <IRremote.hpp>
#include <TinyIRSender.hpp>
#define IR_RECEIVE_PIN 2

void setup() {
  // put your setup code here, to run once:
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);
  sendNECMinimal(3, 0, 18, 1);
  delay(500);

  if (IrReceiver.decode()) {
      //Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX); // Print "old" raw data
      // USE NEW 3.x FUNCTIONS
       IrReceiver.printIRResultShort(&Serial); // Print complete received data in one line
      // IrReceiver.printIRSendUsage(&Serial);   // Print the statement required to send this data
      delay(500);
      IrReceiver.resume(); // Enable receiving of the next value
  }
}
