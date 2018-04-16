//74HC595
//You should now be able to see the 7-segment display cycle from 0 to F
//Email:support@sunfounder.com
//Website:www.sunfounder.com
//2015.5.7

const int latchPin = 12;//Pin connected to ST_CP of 74HC595
const int clockPin = 8;//Pin connected to SH_CP of 74HC595 
const int dataPin = 11; //Pin connected to DS of 74HC595 
//display 0,8,9,3,7,2,5,6,7,8,9,A,b,C,d,E
//int datArray[16] = {2, 0, 8, 12, 30, 36, 190, 224, 254, 246, 238, 62, 156, 122, 158, 142};
int datArray[2] = {2, 158};

// 252 = g
// 96 = a, d, e,f,g
// 218 = c,f
// 242 = e,f
// 102 = a, d, e
// 182 = b,e
// 190 = b
// 224 = d,e,f,g
// 254 = titik
// 246 = e
// 238 = c
// 142 = b,c,d
// 144 = H
// 146 = 11
// 158 = 1


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
      digitalWrite(latchPin,LOW); //ground latchPin and hold low for as long as you are transmitting
      shiftOut(dataPin,clockPin,MSBFIRST,datArray[num]);
      //return the latch pin high to signal chip that it 
      //no longer needs to listen for information
      digitalWrite(latchPin,HIGH); //pull the latchPin to save the data
      delay(1000); //wait for a second
    }
}
