/*
  Adapted code from:
  Let’s Build a Finger Drum Controller! (Sending Digital Values from Arduino to Max/MSP & Pure Data)
  https://youtu.be/1J6tLOGn0dw
*/ 

int val[4]; //Array for 4 sensors total

//Digital Inputs
const int buttonPin = 2;  //Digital pin #2
int buttonState = 0;  //State of the button press (0 or 1)

void setup() {
  Serial.begin(9600); //Serial communication set up

  //Digital Setup
  pinMode(buttonPin, INPUT);  //Digital pin #2 is set as input
}

void loop() {
  //Read analog inputs one by one and send them to Pure Data
  for(int i = 0; i < 4; i++) {  //Corresponds with the val[4]
    val[i] = analogRead(i);
    Serial.print(val[i]);
    Serial.print(" ");
  }

  //Read digital pin #2 and send that value to Pure Data
  buttonState = digitalRead(buttonPin);
  Serial.print(buttonState);
  Serial.println();
  delay(5);
}
