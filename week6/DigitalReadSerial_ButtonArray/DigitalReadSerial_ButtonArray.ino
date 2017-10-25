/*
  DigitalReadSerial_ButtonArray
  Reads an array of digitalRead inputs, and formats into an array and sends to Serial.

  Written by Pamela Liou for SFPC
  
*/

// Declaring a Button Array
const int numberOfButtons = 4; // Try replacing const int with in and see what happens
// Arduino requires you declare the array length in brackets.
int buttonArray[numberOfButtons] = {8, 9, 10, 11}; 

void setup() {
  Serial.begin(9600);
  // loop through array and set each item to INPUT
  for (int i =0; i <numberOfButtons; i++) {
    pinMode(buttonArray[i], INPUT);
  }
}

/*
 * 
 */
 
void loop() {
  
  //loop through each item in array and print the Array to the Serial Port. 
  
for (int i =0; i <numberOfButtons; i++) {
    pinMode(buttonArray[i], INPUT);
      Serial.print(digitalRead(buttonArray[i]));
      Serial.print(", ");

  }
  Serial.println();
  delay(1);        // delay in between reads for stability
}




