const int latchPin = 12;//Pin connected to ST_CP of 74HC595
const int clockPin = 8;//Pin connected to SH_CP of 74HC595 
const int dataPin = 11; //Pin connected to DS of 74HC595 
int datArray[2] = {2, 158};

void setup ()
{
  //set pins to output
  pinMode(latchPin,OUTPUT);
  pinMode(clockPin,OUTPUT);
  pinMode(dataPin,OUTPUT);
}
void loop()
{
  //loop from 0 to 256
    for(int num = 0; num < 2; num++)
    {
      digitalWrite(latchPin,LOW);
      shiftOut(dataPin,clockPin,MSBFIRST,datArray[num]);
      digitalWrite(latchPin,HIGH);
      delay(1000);
    }
}
