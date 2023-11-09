// A9
// B10
// C11
// D12
// E13
// F8
// G7

int numbers[9][7] = {
  {0,1,1,0,0,0,0},
  {1,1,0,1,1,0,1},
  {1,1,1,1,0,0,1},
  {0,1,1,0,0,1,1},
  {1,0,1,1,0,1,1},
  {1,0,1,1,1,1,1},
  {1,1,1,0,0,0,0},
  {1,1,1,1,1,1,1},
  {1,1,1,0,0,1,1},
};

void setup() {
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop() {

  for(int i = 0; i < 9; i++){
    digitalWrite(9, numbers[i][0]); // A
    digitalWrite(10, numbers[i][1]); // B
    digitalWrite(11, numbers[i][2]); // C
    digitalWrite(12, numbers[i][3]); // D
    digitalWrite(13, numbers[i][4]); // E
    digitalWrite(8, numbers[i][5]); // F
    digitalWrite(7, numbers[i][6]); // G
    delay(700);
  }
}
