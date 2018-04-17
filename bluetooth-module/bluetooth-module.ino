char incomingByte;  // incoming data
int  LED = 13;      // LED pin
int buttonState = 0;
const int buttonPin = 4;

void setup() {
  Serial.begin(9600); // initialization
  pinMode(LED, OUTPUT);
  Serial.println("Press 1 to LED ON or 0 to LED OFF...");
  digitalWrite(LED, HIGH);  // if 1, switch LED Off
}

void loop() {
  pushButtonListener();
  if (Serial.available() > 0) {  // if the data came
    incomingByte = Serial.read(); // read byte
    if(incomingByte == '0') {
       digitalWrite(LED, LOW);  // if 1, switch LED Off
//       Serial.println("LED OFF. Press 1 to LED ON!");  // print message
    }
    if(incomingByte == '1') {
       digitalWrite(LED, HIGH); // if 0, switch LED on
//       Serial.println("LED ON. Press 0 to LED OFF!");
    }
  }
}

void pushButtonListener() {
    buttonState = digitalRead(buttonPin);
    if (buttonState) {
      Serial.println("0");
      Serial.write("1");
      delay(30);
    }
}
