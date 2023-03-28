const int ledPin[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};  // khai báo các chân của LED

int potPin = A0;  // chân đọc giá trị từ biến trở
int potVal = 0;   // giá trị đọc được từ biến trở
int speedVal = 0; // tốc độ chuyển đổi LED

void setup() {
  for (int i = 0; i < 10; i++) {
    pinMode(ledPin[i], OUTPUT); // khai báo chân LED là OUTPUT
  }
  Serial.begin(9600);
}

void loop() {
  potVal = analogRead(potPin);        // đọc giá trị từ biến trở
  speedVal = map(potVal, 0, 1023, 50, 1000); // chuyển đổi giá trị đọc được từ biến trở sang tốc độ chuyển đổi LED

  // Duyệt các LED theo thứ tự chẵn trước
  for (int i = 0; i < 10; i += 2) {
    digitalWrite(ledPin[i], HIGH);
    delay(speedVal);
    digitalWrite(ledPin[i], LOW);
    Serial.println(speedVal);
  }

  // Duyệt các LED theo thứ tự lẻ sau
  for (int i = 9; i >= 0; i -= 2) {
    digitalWrite(ledPin[i], HIGH);
    delay(speedVal);
    digitalWrite(ledPin[i], LOW);
    Serial.println(speedVal);
  }
}
