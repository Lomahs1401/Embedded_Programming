  #include <DHT.h>
  #include <SD.h>
  #include <RTClib.h>
  #include <Wire.h>

  #define DHTPIN 2
  #define DHTTYPE DHT11

  //MISO 12
  //MOSI 11
  //SCK 13
  //CS 4

  // SCL A5
  // SDA A4

  DHT dht(DHTPIN, DHTTYPE);
  File dataFile;
  RTC_DS1307 rtc;
  unsigned long previousMillis = 0;
  const long interval = 10000;  // Thời gian giữa các lần ghi vào file là 10 giây
  float globalTemp = 0;

  void setup() {
    Serial.begin(9600);

    Wire.begin();
    dht.begin();

    // Khởi tạo module thẻ nhớ SD
    if (!SD.begin(4)) {
      Serial.println("Card failed, or not present");
      // don't do anything more:
      while (1)
        ;
    }
    Serial.println("card initialized.");

    // Khởi tạo mô-đun RTC
    // rtc.begin();
    if (!rtc.begin()) {
      Serial.println("RTC failed");
      while (1)
        ;
    }

    // Đặt thời gian cho RTC, chỉ uncomment khi bị sai giờ
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }

  void loop() {
    float tempC = dht.readTemperature();
    unsigned long currentMillis = millis();
    // CAU A
    if (currentMillis - previousMillis >= interval) {
      writeSD(tempC);
      previousMillis = currentMillis;
    }

    // CAU B
    // if (tempC != globalTemp) {
    //   writeSD(tempC);
    //   globalTemp = tempC;
    // }

    // Delay 1 giây trước khi lấy dữ liệu mới
    delay(1000);
  }

  void writeSD(float tempC) {
    // Mở tệp để lưu trữ dữ liệu nhiệt độ và thời gian
    DateTime now = rtc.now();

    //ghi de
    // SD.remove("datalog.txt");

    dataFile = SD.open("datalog.txt", FILE_WRITE);



    // Ghi dữ liệu nhiệt độ và độ ẩm vào tệp
    if (dataFile) {
      Serial.print(now.year(), DEC);
      Serial.print('/');
      Serial.print(now.month(), DEC);
      Serial.print('/');
      Serial.print(now.day(), DEC);
      Serial.print(' ');
      Serial.print(now.hour(), DEC);
      Serial.print(':');
      Serial.print(now.minute(), DEC);
      Serial.print(':');
      Serial.print(now.second(), DEC);
      Serial.print(" - ");
      Serial.print(tempC);
      Serial.println();

      dataFile.print(now.year(), DEC);
      dataFile.print('/');
      dataFile.print(now.month(), DEC);
      dataFile.print('/');
      dataFile.print(now.day(), DEC);
      dataFile.print(',');
      dataFile.print(now.hour(), DEC);
      dataFile.print(':');
      dataFile.print(now.minute(), DEC);
      dataFile.print(':');
      dataFile.print(now.second(), DEC);
      dataFile.print(',');
      dataFile.print(tempC);
      dataFile.println();

      // Đóng tệp
      dataFile.close();
    } else {
      Serial.println("Error opening datalog.txt");
    }
  }