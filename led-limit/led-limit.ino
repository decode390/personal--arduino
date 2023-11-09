struct button_t {
  int pin;
  int state;
  int readedValue;
};

struct led_t {
  int pin;
  int potency;
  int scale;
};

struct buzz_t {
  int pin;
  int delay;
  int loopRep;
};

struct button_t lessButton = {pin: 12, state:1, readedValue: 1};
struct button_t moreButton = {pin: 11, state:1, readedValue: 1};

struct led_t led = {pin: 3, potency: 0, scale: 32};

struct buzz_t buzz = {pin: 2, delay: 2, loopRep: 100};

int defaultDelay = 100;


void setup() {
  pinMode(lessButton.pin, INPUT);
  pinMode(moreButton.pin, INPUT);
  pinMode(led.pin, OUTPUT);
  pinMode(buzz.pin, OUTPUT);
  Serial.begin(9600);
}


void loop() {
  if (checkButtonPressed(lessButton) || checkButtonPressed(moreButton)) {

    if (lessButton.state == 0) pressedLess();
    if (moreButton.state == 0) pressedMore();

  }
  delay(defaultDelay);
}


bool checkButtonPressed(struct button_t & btn){
  btn.readedValue = digitalRead(btn.pin);
  int prevState = btn.state;
  btn.state = btn.readedValue;

  if(btn.readedValue == 0 && prevState == 1) return true;
  return false;
}


void pressedLess(){
  if(led.potency == 0) return buzzLoop();
  changePinPotency(led.potency - led.scale);
  Serial.println((String)"Pressed less " + led.potency);
}


void pressedMore(){
  if(led.potency == 255) return buzzLoop();
  changePinPotency(led.potency + led.scale);
  Serial.println((String)"Pressed more " + led.potency);
}


void changePinPotency(int potency){
  if(potency < 0) potency = 0;
  if(potency > 255) potency = 255;
  led.potency = potency;
  analogWrite(led.pin, potency);
}


void buzzLoop(){
  for(int i = 0; i < buzz.loopRep; i++){
    digitalWrite(buzz.pin, 1);
    delay(buzz.delay);
    digitalWrite(buzz.pin, 0);
    delay(buzz.delay);
  }
}

