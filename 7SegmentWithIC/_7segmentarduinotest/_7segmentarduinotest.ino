//---------------------------------------------------------------------------------------------------------------------------------------
int a = 8;
int b = 9;
int c = 10;
int d = 11;
bool on = true;

void setup() {       
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  Serial.begin(9600);
}

void loop() {
    Serial.println("IC & 7 Segment: ON");

    // tentukan apakah perlu ON atau tidak
    if (on) {
      digitalWrite(a, HIGH); 
      digitalWrite(b, LOW); 
      digitalWrite(c, LOW); 
      digitalWrite(d, LOW);
      delay(1000);
    
      digitalWrite(a, LOW);
      digitalWrite(b, HIGH); 
      digitalWrite(c, LOW); 
      digitalWrite(d, LOW);
      delay(1000);
    
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH); 
      digitalWrite(c, LOW); 
      digitalWrite(d, LOW);
      delay(1000);
    
      digitalWrite(a, LOW); 
      digitalWrite(b, LOW); 
      digitalWrite(c, HIGH); 
      digitalWrite(d, LOW);
      delay(1000);
    
      digitalWrite(a, HIGH); 
      digitalWrite(b, LOW); 
      digitalWrite(c, HIGH); 
      digitalWrite(d, LOW);
      delay(1000);
    
      digitalWrite(a, LOW); 
      digitalWrite(b, HIGH); 
      digitalWrite(c, HIGH); 
      digitalWrite(d, LOW);
      delay(1000);
    
      digitalWrite(a, HIGH); 
      digitalWrite(b, HIGH); 
      digitalWrite(c, HIGH); 
      digitalWrite(d, LOW);
      delay(1000);
    
      digitalWrite(a, LOW); 
      digitalWrite(b, LOW); 
      digitalWrite(c, LOW); 
      digitalWrite(d, HIGH);
      delay(1000);
    
      digitalWrite(a, HIGH); 
      digitalWrite(b, LOW); 
      digitalWrite(c, LOW); 
      digitalWrite(d, HIGH);
      delay(1000);
    
      digitalWrite(a, LOW); 
      digitalWrite(b, LOW); 
      digitalWrite(c, LOW); 
      digitalWrite(d, LOW);
      delay(1000);
    }
}

void other() {
  digitalWrite(a, HIGH); 
  digitalWrite(b, HIGH); 
  digitalWrite(c, HIGH); 
  digitalWrite(d, HIGH); 
}
