int switchState = "off";
int lastSwitchState = "off";
int ledPin = 2;
int switchPin = 8;

void setup() {

  Serial.begin(9600);
  pinMode(switchPin, INPUT);

}

void loop() {

  switchState = digitalRead(switchPin);

  if (switchState) {
    Serial.println("1"); //print the state to serial
  } else {
    Serial.println("0");
  }


delay(5);
}
