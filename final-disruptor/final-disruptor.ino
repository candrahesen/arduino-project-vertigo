// FINAL DISRUPTOR

#include <stdio.h>
#include <stdlib.h>
//#include <LiquidCrystal.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "SoftwareSerial.h"
#include "TinyGPS.h"
float lat = 28.5458, lon = 77.1703; // create variable for latitude and longitude object
SoftwareSerial gpsSerial(3, 4); //rx,tx
TinyGPS gps; // create gps object
const int MPU = 0x68;
int16_t AcX, AcY, AcZ, Tmp, GyX, GyY, GyZ;
int16_t old_AcX, old_AcY, old_AcZ, old_Tmp, old_GyX, old_GyY, old_GyZ;

// 7 SEGMENT
const int latchPin = 12;//Pin connected to ST_CP of 74HC595
const int clockPin = 8;//Pin connected to SH_CP of 74HC595
const int dataPin = 11; //Pin connected to DS of 74HC595
int datArray[2] = {2, 158};

// PWM
const int pwmPin = 9; //Pin connected to DS of 74HC595

// logic variables
bool first = true;
bool jatuh = false;
int threshold = 2000; // batas perubahan yg ditolerir

// PUSH BUTTNO
int buttonState = 0;
const int buttonPin = 4;

//// LCD i2c
LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

void setup() {
  Serial.begin(9600); // connect serial
  Serial.println("The GPS Received Signal:");

  // 7 Segment STUFF
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);

  // PWM
  pinMode(pwmPin, OUTPUT);

  // PUSH BUTTON
  pinMode(buttonPin, INPUT);

  // GPS STUFF
  gpsSerial.begin(9600); // connect gps sensor

  // ACCELEROMETER STUFF
  Wire.begin();
  Wire.beginTransmission(MPU);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);

  // LCD
  lcd.begin(16, 2);
  //    lcd.clear();
  //    lcd.print("HELP");
}

void loop() {
  while (gpsSerial.available()) { // check for gps data
    if (gps.encode(gpsSerial.read())) // encode gps data
    {
      gps.f_get_position(&lat, &lon); // get latitude and longitude
    }
  }

  // 7 segment stuff
  segment7(jatuh);

  // DETECT FALL
  if (jatuh) {
    printLocation();
  }



  accelLoop();
}

void printLocation() {
  String latitude = String(lat, 6);
  String longitude = String(lon, 6);
  Serial.println("Vertigan ditemukan terjatuh di:");
  Serial.println("Lat: " + latitude);
  Serial.println("Lng: " + longitude);
  Serial.println("Berikut lokasi menuju Vertigan");
  String link = "http://www.google.com/maps/place/" + String(latitude) + "," + String(longitude) ;
  Serial.println("Link Google Maps : ");
  Serial.println(link);
  Serial.println("");
  jatuh = false;

  // Kirimkan lokasi LatLng ke Server!
  kirimKeServer(latitude, longitude);

  //display LCD help
  lcd.clear();
  lcd.print("HELP MESSAGE");
  lcd.setCursor(0,1);
  lcd.print("SENT!");

  delay(5000);
}

void accelLoop() {
  Wire.beginTransmission(MPU);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU, 12, true);

  if (!first) {
    old_AcX = AcX;
    old_AcY = AcY;
    old_AcZ = AcZ;
    old_GyX = GyX;
    old_GyY = GyY;
    old_GyZ = GyZ;
  }

  AcX = Wire.read() << 8 | Wire.read();
  AcY = Wire.read() << 8 | Wire.read();
  AcZ = Wire.read() << 8 | Wire.read();
  GyX = Wire.read() << 8 | Wire.read();
  GyY = Wire.read() << 8 | Wire.read();
  GyZ = Wire.read() << 8 | Wire.read();

  Serial.print("Accelerometer: ");
  Serial.print("X = "); Serial.print(old_AcX);
  Serial.print(" | Y = "); Serial.print(old_AcY);
  Serial.print(" | Z = "); Serial.print(old_AcZ);
  Serial.println(" (OLD)");

  Serial.print("Accelerometer: ");
  Serial.print("X = "); Serial.print(AcX);
  Serial.print(" | Y = "); Serial.print(AcY);
  Serial.print(" | Z = "); Serial.println(AcZ);

  if ((abs(old_AcX - AcX) >= threshold || abs(old_AcY - AcY) >= threshold || abs(old_AcZ - AcZ) >= threshold) && !first) {
    Serial.println("TERDETEKSI JATUH!");
    jatuh = true;
  }

  // PUSH BUTTON detect
  pushButtonListener();
  first = false;

  Serial.print("Gyroscope: ");
  Serial.print("X = "); Serial.print(GyX);
  Serial.print(" | Y = "); Serial.print(GyY);
  Serial.print(" | Z = "); Serial.println(GyZ);
  Serial.println(" ");

  //display lcd vertigan safe
  lcd.clear();
  lcd.print("SAFE");

  delay(333);
}

void pushButtonListener() {
  buttonState = digitalRead(buttonPin);
  if (buttonState) {
    jatuh = true;
  }
}

void segment7(bool stat) {
  digitalWrite(latchPin, LOW);

  int num, pwm;
  if (stat) {
    // if jatuh
    num = 1;
    pwm = 200;
  } else {
    num = 0;
    pwm = 80;
  }
  shiftOut(dataPin, clockPin, MSBFIRST, datArray[num]);
  digitalWrite(latchPin, HIGH);

  analogWrite(pwmPin, pwm);
}

void kirimKeServer(String latitude, String longitude) {
  // kirim ke server
  // ...
}
