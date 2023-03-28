// C++ code
//
int count = 4;
int indexs[] = { 3, 5, 6, 9, 10 };
void setup() {
  for (int i = 0; i < 5; i++) {
    pinMode(indexs[i], OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  int value = analogRead(0) / 4;
  Serial.println(value);
  for (int i = 0; i < 5; i++) {
    analogWrite(indexs[i], value);
  }
}
