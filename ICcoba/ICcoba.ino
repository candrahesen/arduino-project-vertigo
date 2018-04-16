//---------------------------------------------------------------------------------------------------------------------------------------
int a = 2;
int b = 3;
int c = 4;
bool on = true;

void setup() {       
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  Serial.begin(9600);
}

void loop() {
    Serial.println("IC & 7 Segment: ON");

    // tentukan apakah perlu ON atau tidak
    if (on) {
      digitalWrite(a, HIGH); 
      digitalWrite(b, LOW); 
      digitalWrite(c, LOW); 
      delay(1000);
    
      digitalWrite(a, LOW);
      digitalWrite(b, HIGH); 
      digitalWrite(c, LOW); 
      delay(1000);
    
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH); 
      digitalWrite(c, LOW); 
      delay(1000);
    
      digitalWrite(a, LOW); 
      digitalWrite(b, LOW); 
      digitalWrite(c, HIGH); 
      delay(1000);
    
      digitalWrite(a, HIGH); 
      digitalWrite(b, LOW); 
      digitalWrite(c, HIGH); 
      delay(1000);
    
      digitalWrite(a, LOW); 
      digitalWrite(b, HIGH); 
      digitalWrite(c, HIGH); 
      delay(1000);
    
      digitalWrite(a, HIGH); 
      digitalWrite(b, HIGH); 
      digitalWrite(c, HIGH); 
      delay(1000);
    
      digitalWrite(a, LOW); 
      digitalWrite(b, LOW); 
      digitalWrite(c, LOW); 
      delay(1000);
    
      digitalWrite(a, HIGH); 
      digitalWrite(b, LOW); 
      digitalWrite(c, LOW); 
      delay(1000);
    
      digitalWrite(a, LOW); 
      digitalWrite(b, LOW); 
      digitalWrite(c, LOW); 
      delay(1000);
    }
}

void other() {
  digitalWrite(a, HIGH); 
  digitalWrite(b, HIGH); 
  digitalWrite(c, HIGH); 
}
