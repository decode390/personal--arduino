int triggerPin = 7;
int echoPin = 8;
float time;
float distance;

void setup() {
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(triggerPin, HIGH);
  delay(1);
  digitalWrite(triggerPin, LOW);
  time = pulseIn(echoPin, HIGH);
  distance = time / 58.2;
  Serial.println(distance);
  delay(200);
}
