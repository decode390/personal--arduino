struct joystick_t{
  int xPin;
  float xValue;
  int yPin;
  float yValue;
  int swPin;
  int swValue;
};

joystick_t joystick = {
  xPin: A4,
  xValue: 0,
  yPin: A5,
  yValue: 0,
  swPin: 2,
  swValue: 0
};

int defaultDelay = 100;


void setup() {
  Serial.begin(9600);
  pinMode(joystick.swPin, INPUT);
  digitalWrite(joystick.swPin, 1);
}

void loop() {
  joystick.xValue = analogRead(joystick.xPin);
  joystick.yValue = analogRead(joystick.yPin);
  joystick.swValue = digitalRead(joystick.swPin);

  Serial.println((String)"x: " + joystick.xValue + " y: " + joystick.yValue + " sw: " + joystick.swValue);
  // delay(defaultDelay);
}
