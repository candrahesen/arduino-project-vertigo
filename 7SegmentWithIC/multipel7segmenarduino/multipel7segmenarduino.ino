//--------------------------------------------------------------------------------------------------------------------------------------
int a = 0;
int b = 1;
int c = 2;
int d = 3;

int x = 0;
int y = 0;
int z = 0;
int multiplex1 = 5;
int multiplex2 = 4;

void setup() {                
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  
  pinMode(multiplex1, OUTPUT);
  pinMode(multiplex2, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  led1(y);
  delay(10);
  led2(z);
  delay(10);
  x++;
  if(x>50){
    y++;
    x=0;
  }
  if(y>9){
    z++;
    y=0;
  }
  if(z>9){
    z=0;
  }
}



void led1(int data1){
  digitalWrite(multiplex1, LOW);//
  digitalWrite(multiplex2, HIGH);//
  if(data1==1){
    digitalWrite(a, HIGH);   // 
    digitalWrite(b, LOW);   // 
    digitalWrite(c, LOW);   // 
    digitalWrite(d, LOW);   // 
  }
  if(data1==2){
    digitalWrite(a, LOW);   // 
    digitalWrite(b, HIGH);   // 
    digitalWrite(c, LOW);   // 
    digitalWrite(d, LOW);   //
  }
  if(data1==3){
    digitalWrite(a, HIGH);   // 
    digitalWrite(b, HIGH);   // 
    digitalWrite(c, LOW);   // 
    digitalWrite(d, LOW);   //
  }
  if(data1==4){
    digitalWrite(a, LOW);   // 
    digitalWrite(b, LOW);   // 
    digitalWrite(c, HIGH);   // 
    digitalWrite(d, LOW);   //
  }
  if(data1==5){
    digitalWrite(a, HIGH);   // 
    digitalWrite(b, LOW);   // 
    digitalWrite(c, HIGH);   // 
    digitalWrite(d, LOW);   //
  }
  if(data1==6){
    digitalWrite(a, LOW);   // 
    digitalWrite(b, HIGH);   // 
    digitalWrite(c, HIGH);   // 
    digitalWrite(d, LOW);   //
  }
  if(data1==7){
    digitalWrite(a, HIGH);   // 
    digitalWrite(b, HIGH);   // 
    digitalWrite(c, HIGH);   // 
    digitalWrite(d, LOW);   //
  }
  if(data1==8){
    digitalWrite(a, LOW);   // 
    digitalWrite(b, LOW);   // 
    digitalWrite(c, LOW);   // 
    digitalWrite(d, HIGH);   //
  }
  if(data1==9){
    digitalWrite(a, HIGH);   // 
    digitalWrite(b, LOW);   // 
    digitalWrite(c, LOW);   // 
    digitalWrite(d, HIGH);   //
  }
  if(data1==0){
    digitalWrite(a, LOW);   // 
    digitalWrite(b, LOW);   // 
    digitalWrite(c, LOW);   // 
    digitalWrite(d, LOW);   //
  }
}

void led2(int data2){
  digitalWrite(multiplex1, HIGH);//
  digitalWrite(multiplex2, LOW);//
  if(data2==1){
    digitalWrite(a, HIGH);   // 
    digitalWrite(b, LOW);   // 
    digitalWrite(c, LOW);   // 
    digitalWrite(d, LOW);   // 
  }
  if(data2==2){
    digitalWrite(a, LOW);   // 
    digitalWrite(b, HIGH);   // 
    digitalWrite(c, LOW);   // 
    digitalWrite(d, LOW);   //
  }
  if(data2==3){
    digitalWrite(a, HIGH);   // 
    digitalWrite(b, HIGH);   // 
    digitalWrite(c, LOW);   // 
    digitalWrite(d, LOW);   //
  }
  if(data2==4){
    digitalWrite(a, LOW);   // 
    digitalWrite(b, LOW);   // 
    digitalWrite(c, HIGH);   // 
    digitalWrite(d, LOW);   //
  }
  if(data2==5){
    digitalWrite(a, HIGH);   // 
    digitalWrite(b, LOW);   // 
    digitalWrite(c, HIGH);   // 
    digitalWrite(d, LOW);   //
  }
  if(data2==6){
    digitalWrite(a, LOW);   // 
    digitalWrite(b, HIGH);   // 
    digitalWrite(c, HIGH);   // 
    digitalWrite(d, LOW);   //
  }
  if(data2==7){
    digitalWrite(a, HIGH);   // 
    digitalWrite(b, HIGH);   // 
    digitalWrite(c, HIGH);   // 
    digitalWrite(d, LOW);   //
  }
  if(data2==8){
    digitalWrite(a, LOW);   // 
    digitalWrite(b, LOW);   // 
    digitalWrite(c, LOW);   // 
    digitalWrite(d, HIGH);   //
  }
  if(data2==9){
    digitalWrite(a, HIGH);   // 
    digitalWrite(b, LOW);   // 
    digitalWrite(c, LOW);   // 
    digitalWrite(d, HIGH);   //
  }
  if(data2==0){
    digitalWrite(a, LOW);   // 
    digitalWrite(b, LOW);   // 
    digitalWrite(c, LOW);   // 
    digitalWrite(d, LOW);   //
  }
}
//-------------------------------------------------------------------------------------------------------------------------------------

