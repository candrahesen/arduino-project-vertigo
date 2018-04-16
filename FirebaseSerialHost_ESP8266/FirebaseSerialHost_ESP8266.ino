#include <Boards.h>
#include <Firmata.h>



#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>

#include <Firebase.h>
#include <SerialTransceiver.h>

// Set these to run example.
#define WIFI_SSID "SSID"
#define WIFI_PASSWORD "PASSWORD"

SoftwareSerial data_serial(5 /*RX*/, 4/*TX*/);
firebase::modem::SerialTransceiver transceiver;

void setup() {
  Serial.begin(9600);

  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());

  data_serial.begin(9600);
  while (!data_serial) {
    Serial.println("Error initilizing serial.");
    delay(5000);
  }

  transceiver.RegisterProtocol(new DatabaseProtocol());
  transceiver.begin(&data_serial);
}

void loop() {
  transceiver.loop();
}
