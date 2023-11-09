int velPin = 9;
float velValue;
int in1 = 11;
int in2 = 12; 
int joystickPin = A1;
float joystickValue;

void setup() {
  pinMode(velPin, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  joystickValue = analogRead(joystickPin);

  if(joystickValue < 515){
    velValue = map(joystickValue, 515, 0, 0, 255);
    if(velValue < 100) velValue = 100;
    Serial.println((String) joystickValue + " - " + velValue);
    analogWrite(velPin, velValue);
    digitalWrite(in1, 1);
    digitalWrite(in2, 0);
  }

  if(joystickValue > 520) {
    velValue = map(joystickValue, 520, 1023, 0, 255);
    if(velValue < 100) velValue = 100;
    if(velValue > 255) velValue = 255;
    Serial.println((String) joystickValue + " - " + velValue);
    analogWrite(velPin, velValue);
    digitalWrite(in1, 0);
    digitalWrite(in2, 1);
  }

  delay(100);
}
