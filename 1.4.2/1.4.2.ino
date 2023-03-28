int leds[] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };  // Mảng chứa các chân của các LED
int numLeds = sizeof(leds) / sizeof(leds[0]);     // Số lượng LED
int delayTime;                                    // Thời gian chờ giữa các LED
int fadeTime = 100;                               // Thời gian tắt dần của LED

void setup() {
  // Khởi tạo chân của các LED là đầu ra
  for (int i = 0; i < numLeds; i++) {
    pinMode(leds[i], OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  // Duyệt các LED từ hai bên vào trong và bật dần lên
  for (int i = 0, j = numLeds - 1; i <= j; i++, j--) {
    digitalWrite(leds[i], HIGH);  // Bật LED ở bên trái
    digitalWrite(leds[j], HIGH);  // Bật LED ở bên phải
    delayTime = analogRead(A0);   // Đọc giá trị từ biến trở để điều chỉnh tốc độ
    delay(delayTime);             // Chờ một khoảng thời gian nhất định
    Serial.println(delayTime);
  }

  // Tắt dần các LED từ trong ra hai bên
  for (int i = numLeds / 2 - 1, j = numLeds / 2; i >= 0 && j < numLeds; i--, j++) {
    digitalWrite(leds[i], LOW);  // Tắt LED ở bên trái
    digitalWrite(leds[j], LOW);  // Tắt LED ở bên phải
    // delay(fadeTime);             // Chờ một khoảng thời gian nhất định trước khi tắt LED
    delayTime = analogRead(A0);  // Đọc giá trị từ biến trở để điều chỉnh tốc độ
    delay(delayTime);            // Chờ một khoảng thời gian nhất định
    Serial.println(delayTime);
  }
}
