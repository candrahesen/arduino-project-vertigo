//// --------------------------------------
//// i2c_scanner
////
//
//#include <Wire.h>
// 
// 
//void setup()
//{
//  Wire.begin();
// 
//  Serial.begin(9600);
//  while (!Serial);             // Leonardo: wait for serial monitor
//  Serial.println("\nI2C Scanner");
//}
// 
// 
//void loop()
//{
//  byte error, address;
//  int nDevices;
// 
//  Serial.println("Scanning...");
// 
//  nDevices = 0;
//  for(address = 1; address < 127; address++ )
//  {
//    // The i2c_scanner uses the return value of
//    // the Write.endTransmisstion to see if
//    // a device did acknowledge to the address.
//    Wire.beginTransmission(address);
//    error = Wire.endTransmission();
// 
//    if (error == 0)
//    {
//      Serial.print("I2C device found at address 0x");
//      if (address<16)
//        Serial.print("0");
//      Serial.print(address,HEX);
//      Serial.println("  !");
// 
//      nDevices++;
//    }
//    else if (error==4)
//    {
//      Serial.print("Unknown error at address 0x");
//      if (address<16)
//        Serial.print("0");
//      Serial.println(address,HEX);
//    }    
//  }
//  if (nDevices == 0)
//    Serial.println("No I2C devices found\n");
//  else
//    Serial.println("done\n");
// 
//  delay(5000);           // wait 5 seconds for next scan
//}

/*
 * I2C Scanner
 * Explored by Elangsakti.com
 * # Hack Your Skill!
 */
 
#include <Wire.h>
 
void setup() {
    Wire.begin();
    Serial.begin(9600);
    while(!Serial);
 
    Serial.println("#============o0o=============#");
    Serial.println("#         I2C Scanner        #");
    Serial.println("# Explored by Elangsakti.com #");
    Serial.println("#============================#");
 
    Cari_Alamat();
}
 
void loop() { }
 
void Cari_Alamat()  {
    byte respon, alamat, modul = 0;
 
    Serial.println("Scanning...");
    Serial.println();
    
    for(alamat=0; alamat<127; alamat++){
        Wire.beginTransmission(alamat);
        respon = Wire.endTransmission();
        switch(respon){
            case 0:
                Serial.print("  ");
                Serial.print(modul+1);
                Serial.print(". Alamat = 0x");
                if( alamat < 16 ) Serial.print("0");
                Serial.println(alamat, HEX);
                modul++;
 
                break;
 
            case 4:
                Serial.print("  - Error ");
                if( alamat < 16 ) Serial.print("0");
                Serial.println(alamat, HEX);
        }
    }
    Serial.println();
 
    if(modul > 0){
        Serial.print("Ditemukan ");
        Serial.print(modul);
        Serial.println(" modul I2C.");
    }else{
        Serial.println("Tidak ada modul I2C.");
    }
 
    delay(2000);
}
