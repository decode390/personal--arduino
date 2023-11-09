#include <IRremote.hpp>

#define IR_SEND_PIN 2

struct Levels { 
  int level;
  uint8_t command;
};

Levels levels[] = {
  {level: 0, command: 0x45}, // PowerOff
  {level: 1, command: 0x18}, // Level 1
  {level: 2, command: 0x9}, // Level 2
  {level: 3, command: 0x7}, // Level 3
  {level: 4, command: 0x47} // Level 4
};
int arrLength = sizeof(levels) / sizeof(levels[0]);


int offPin = 3;
int levelPin = 4;
int prevLevel = 4;

void setup() {
  Serial.begin(115200);
  IrSender.begin(IR_SEND_PIN);
  IrSender.enableIROut(38);

  pinMode(offPin, INPUT);
  digitalWrite(offPin, HIGH);
  pinMode(levelPin, INPUT);
  digitalWrite(levelPin, HIGH);
}

void loop() {

  if(digitalRead(offPin) == 0){
    prevLevel = 4;
    send_ir_data(levels[0]);
  }

  if (digitalRead(levelPin) == 0) {
    prevLevel++;
    if (prevLevel >= arrLength) prevLevel = 1;
    send_ir_data(levels[prevLevel]);
  }

}

void send_ir_data(Levels level){
    Serial.println();
    Serial.print(F("Send now: address=0x00, command=0x"));
    Serial.print(level.command, HEX);
    Serial.print(F(", repeats="));
    Serial.print("1");
    Serial.println();

    IrSender.sendNEC(0x00, level.command, 1);
    Serial.flush();
    delay(100);
}

