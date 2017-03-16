/*
 * Arduino program that uses the time a photoresistor has been
 * exposed to create a string of 1's and 0's that is converted
 * to morse code and printed to an LCD.
 *
 * Created February 2017
 * By Melissa Bruno
 *
 * Wiki: https://github.com/MelissaBruno/arduino-telegraph/wiki
 *
 */

#include "Control.h"
#include "Morse.h"

ControlClass control = ControlClass();
MClass morse = MClass();

int sensorPin, sensorValue;
double startTime, endTime, timer, timeInSeconds;
boolean flag;
int switchState;
boolean backFlag;


void setup(){
  control.SETUP();
  Serial.begin(9600);
  sensorPin = A0;
  flag = false;
  backFlag = false;
  pinMode(8, OUTPUT);
}

void loop() {
  sensorValue = analogRead(sensorPin);                     //Photoresistor value
  switchState = digitalRead(8);                            //Back button state 

  /*
   * Measuring the time that the photoresistor is exposed
   */
  if(sensorValue > 300 && flag == false){
    startTime = millis();
    tone(7, 1250);
    flag = true;
  }
  if(sensorValue < 300 && flag == true){ 
    endTime = millis();
    noTone(7);
    timer = endTime - startTime;
    timeInSeconds = timer/1000;
    flag = false;

    if(timeInSeconds < 0.3) {                             //If time is < 0.3s, a "0" is added to a String
      morse.dot();
    }
    if(timeInSeconds > 0.3 && timeInSeconds < 0.6){       //If time is > 0.3s and < 1s, a "1" is added to the String
      morse.dash();
    }
    if(timeInSeconds > 0.6){                              //If time is > 1s, morse code letter is printed to LCD
      control.printLetter(morse.toMorseCode());
      morse.clearLetter();

      if(control.getCursorPosition() < 15){
        control.cursorForward();
      }
      else if(control.getCursorPosition() == 15){         //Moving cursor to next row if it has reached the end of current row
        control.incrementRow();
      }
    }
  }

  /*
   * Backspace
   */
  if(switchState == HIGH){
    backFlag = true;
    delay(500);
    control.backspace();
    backFlag = false;
  }
} //end loop
