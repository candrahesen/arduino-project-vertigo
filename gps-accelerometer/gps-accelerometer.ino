#include <stdio.h>
#include <stdlib.h>
#include <Wire.h>
#include <LiquidCrystal.h> 
#include "SoftwareSerial.h"
#include "TinyGPS.h"
float lat = 28.5458,lon = 77.1703; // create variable for latitude and longitude object  
SoftwareSerial gpsSerial(3,4);//rx,tx
TinyGPS gps; // create gps object 
const int MPU=0x68; 
int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;
int16_t old_AcX,old_AcY,old_AcZ,old_Tmp,old_GyX,old_GyY,old_GyZ;

// logic variables
bool first = true;
bool jatuh = false;
int threshold = 2000; // batas perubahan yg ditolerir

void setup(){ 
Serial.begin(9600); // connect serial 
Serial.println("The GPS Received Signal:"); 

Serial1.begin(9600);

// GPS STUFF
gpsSerial.begin(9600); // connect gps sensor 

// ACCELEROMETER STUFF
Wire.begin();
Wire.beginTransmission(MPU);
Wire.write(0x6B); 
Wire.write(0);    
Wire.endTransmission(true);
} 

void loop(){ 
  while(gpsSerial.available()){ // check for gps data 
    if(gps.encode(gpsSerial.read()))// encode gps data 
    {  
      gps.f_get_position(&lat,&lon); // get latitude and longitude 
    } 
  } 

  if (jatuh) {
    String latitude = String(lat,6); 
    String longitude = String(lon,6); 
    Serial.println("Vertigan ditemukan terjatuh di:");
    Serial.println("Lat: "+latitude); 
    Serial.println("Lng: "+longitude);
    Serial.println("Berikut lokasi menuju Vertigan");
    String link = "http://www.google.com/maps/place/" + String(latitude) + "," + String(longitude) ;
    Serial.println("Link Google Maps : ");
    Serial.println(link);
    Serial.println("");
    jatuh = false;

    // Kirimkan lokasi LatLng ke Server!
    kirimKeServer(latitude, longitude);
    
    delay(5000);
  }

accelLoop();
} 

void accelLoop() {
  Wire.beginTransmission(MPU);
  Wire.write(0x3B);  
  Wire.endTransmission(false);
  Wire.requestFrom(MPU,12,true);  

  if(!first) {
    old_AcX=AcX;
    old_AcY=AcY;
    old_AcZ=AcZ;
    old_GyX=GyX;
    old_GyY=GyY;
    old_GyZ=GyZ;
  }
  
  AcX=Wire.read()<<8|Wire.read();    
  AcY=Wire.read()<<8|Wire.read();  
  AcZ=Wire.read()<<8|Wire.read();  
  GyX=Wire.read()<<8|Wire.read();  
  GyY=Wire.read()<<8|Wire.read();  
  GyZ=Wire.read()<<8|Wire.read();  
  
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
  first = false;
  
  Serial.print("Gyroscope: ");
  Serial.print("X = "); Serial.print(GyX);
  Serial.print(" | Y = "); Serial.print(GyY);
  Serial.print(" | Z = "); Serial.println(GyZ);
  Serial.println(" ");
  delay(333);
  }

void kirimKeServer(String latitude, String longitude) {
  // kirim ke server
  // ...
  Serial1.println(latitude + "," + longitude);
}
