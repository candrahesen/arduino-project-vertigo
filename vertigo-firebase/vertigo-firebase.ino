#include <ArduinoJson.h>



#include <Firebase.h>
#include <FirebaseArduino.h>
#include <FirebaseCloudMessaging.h>
#include <FirebaseError.h>
#include <FirebaseHttpClient.h>
#include <FirebaseObject.h>



// Set these to run example.

#define FIREBASE_HOST "https://vertigo-arduino.firebaseio.com/"
#define FIREBASE_AUTH "H3nIQ0PGnddDoDcBSJKzHdH60yavkrLdX19VqpMp"
#define WIFI_SSID "Yang itu"
#define WIFI_PASSWORD "12345678"

#define LED 2
void setup() {
  pinMode(LED,OUTPUT);
  digitalWrite(LED,0);
  Serial.begin(9600);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
  Serial.print(".");
  delay(500);
}

  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.setInt("LEDStatus",0);
}

void loop() {
  if(Firebase.getInt("LEDStatus")) {
    digitalWrite(LED,HIGH);
  } else {
    digitalWrite(LED,LOW);
  }
  
  if (Firebase.failed()) // Check for errors {
  Serial.print("setting /number failed:");
  Serial.println(Firebase.error());
  return;
}
delay(1000);
