int redPin = 11;
int greenPin = 10;
int bluePin = 9;
int dt = 500;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  int readedValue = analogRead(A0);
  Serial.println(readedValue);

  if (readedValue <= 50) setColor(0,0,0);
  else if (readedValue > 50 && readedValue <= 341) setColor(255,0,0);
  else if (readedValue > 341 && readedValue <= 682) setColor(0,255,0);
  else setColor(0,0,255);

  while(readedValue == analogRead(A0)){}
  Serial.println((String)"Change: " + readedValue + " to " + analogRead(A0));
}

void setColor(int red, int green, int blue){
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
  delay(dt);
}

int toAnode(int value){
  return (value-255) * -1;
}
