int buzzPin = 2;
float buzzDelay;
int potPin = A1;
float potValue;

void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(A1, INPUT);
}

void loop() {
  potValue = analogRead(A1);
  buzzDelay = ((1950./1023.) * potValue) + 50.;

  digitalWrite(buzzPin, HIGH);
  delayMicroseconds(buzzDelay);
  digitalWrite(buzzPin, LOW);
  delayMicroseconds(buzzDelay);

  // Serial.println(buzzDelay);
}