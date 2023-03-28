int r;
int g;
int b;
int redValue;
int greenValue;
int blueValue;
int delayValue;
int d;
int redPin = 3;
int greenPin = 5;
int bluePin = 6;

void setup() {
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  if (Serial.available()) {
    String s = Serial.readString();
    s.trim();

    r = s.indexOf("R");
    g = s.indexOf("G");
    b = s.indexOf("B");
    d = s.indexOf("D");

    // RxGyBzDt, đọc các chỉ số x, y, z
    if (r != -1) {
      redValue = s.substring(r + 1, g).toInt();
    } else {
      redValue = 0;
    }

    if (g != -1) {
      greenValue = s.substring(g + 1, b).toInt();
    } else {
      greenValue = 0;
    }

    if (b != -1) {
      blueValue = s.substring(b + 1, d).toInt();
    } else {
      blueValue = 0;
    }

    // Lấy các giá trị x, y, z để hiển thị độ sáng đèn led
    if (redValue >= 255) {
      analogWrite(redPin, 255);
    } else {
      analogWrite(redPin, redValue);
    }

    if (greenValue >= 255) {
      analogWrite(greenPin, 255);
    } else {
      analogWrite(greenPin, greenValue);
    }
    if (blueValue >= 255) {
      analogWrite(bluePin, 255);
    } else {
      analogWrite(bluePin, blueValue);
    }
    
    // Đọc giá trị delay t
    if (d != -1) {
      delayValue = s.substring(d + 1, s.length()).toInt();
      delay(delayValue);
      analogWrite(redPin, 0);
      analogWrite(greenPin, 0);
      analogWrite(bluePin, 0);
    }
  }
}
