int ledPins = 6;
int ledCount = 10;   // Số lượng đèn LED
int analogPin = A0;  // Chân kết nối với biến trở
int brightness;      // Giá trị đọc từ biến trở (0-1023)

void setup() {
  // Khai báo các chân là đầu ra
  pinMode(ledPins, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  // Đọc giá trị từ biến trở và chuyển đổi thành giá trị độ sáng (0-255)
  brightness = map(analogRead(analogPin), 0, 1023, 0, 255);

  Serial.println(brightness);
  // Sáng đèn LED từ mờ tới rõ
  analogWrite(ledPins, brightness);  // Điều khiển độ sáng của đèn LED
}