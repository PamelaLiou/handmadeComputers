/*
  DigitalReadSerial_State Change Array
  Reads an array of digitalRead inputs, and formats into an array and sends to Serial.

  Written by Pamela Liou for SFPC

*/

// Declaring a Button Array
const int numberOfButtons = 4; // Try replacing const int with in and see what happens
// Arduino requires you declare the array length in brackets.
int buttonArray[numberOfButtons] = {8, 9, 10, 11};
int previousState[numberOfButtons] = {0, 0, 0, 0};
int currentState[numberOfButtons] = {0, 0, 0, 0};


void setup() {
  Serial.begin(9600);
  // loop through array and set each item to INPUT
  for (int i = 0; i < numberOfButtons; i++) {
    pinMode(buttonArray[i], INPUT);
  }
}

void loop() {


  /*
     Arduino cannot simply evaluate "if (previousState != currentState)"
     you must check a state for each index in the array.
     Nested for loops example below.
  */


  for (int i = 0; i < numberOfButtons; i++) {
    currentState[i] = digitalRead(buttonArray[i]);
  }


  for (int j = 0; j < numberOfButtons; j++) {
    if (previousState[j] != currentState[j]) {

      for (int k = 0; k < numberOfButtons; k++) {
        Serial.print(currentState[k]);
        Serial.print(", ");
      }
     

      Serial.println();

    }
  }

  for (int l = 0; l < numberOfButtons; l++) {
    int assignment = currentState[l];
    previousState[l] = assignment;

  }

  delay(2);        // delay in between reads for stability

}




