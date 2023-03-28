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
  // Duyệt qua từng LED và bật lần lượt từ trái sang phải
  for (int i = 0; i < numLeds; i++) {
    digitalWrite(leds[i], HIGH);  // Bật LED
    delayTime = analogRead(A0);   // Đọc giá trị từ biến trở để điều chỉnh tốc độ
    delay(delayTime);             // Chờ một khoảng thời gian nhất định
    digitalWrite(leds[i], LOW);   // Tắt LED
    Serial.println(delayTime);
  }

  // Tắt dần các LED từ phải về trái
  for (int i = numLeds - 1; i >= 0; i--) {
    digitalWrite(leds[i], HIGH);  // Bật LED
    // delay(fadeTime); // Chờ một khoảng thời gian nhất định trước khi tắt LED
    delayTime = analogRead(A0);  // Đọc giá trị từ biến trở để điều chỉnh tốc độ
    delay(delayTime);            // Chờ một khoảng thời gian nhất định
    digitalWrite(leds[i], LOW);  // Tắt LED
    Serial.println(delayTime);
  }
}
