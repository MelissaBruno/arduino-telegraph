/*
 * Library for setting up and controlling the LCD
 */

#include "Arduino.h"
#include "Control.h"
#include "LiquidCrystal.h"

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int cursorPosition, cursorRow;

ControlClass::ControlClass(){
}

/*
 * Setup for LCD and cursor
 */
void ControlClass::SETUP(){
  lcd.begin(16, 2);
  lcd.cursor();
  cursorPosition = 0;
  cursorRow = 0;
}

/*
 * Returns position of cursor
 */
int ControlClass::getCursorPosition(){
  return cursorPosition;
}

/*
 * Returns row cursor is on
 */
int ControlClass:: getCursorRow(){
  return cursorRow;
}

/*
 * Moves cursor to the forward one position
 */
void ControlClass::cursorForward(){
  cursorPosition++;
  lcd.setCursor(cursorPosition, cursorRow);
  Serial.print(cursorPosition);
}

/*
 * Move thes cursor back one positon
 */
void ControlClass::cursorBack(){
  cursorPosition--;
  lcd.setCursor(cursorPosition, cursorRow);
  Serial.print(cursorPosition);
}

/*
 * Moves the cursor down one row
 */
void ControlClass::incrementRow(){
  cursorPosition = 0;
  cursorRow++;
  lcd.setCursor(cursorPosition, cursorRow);
}

/*
 * Moves the cursor up one row
 */
void ControlClass::decrementRow(){
  cursorPosition = 16;
  cursorRow--;
  lcd.setCursor(cursorPosition, cursorRow);
}

/*
 * Prints specified string to the LCD
 */
void ControlClass::printLetter(String letter){
  lcd.print(letter);
}

/*
 * Moves cursor back one space and removes the current entry on LCD
 */
void ControlClass::backspace(){
  if(getCursorPosition() == 0 && getCursorRow() > 0){
    decrementRow();
  }
  cursorBack();
  lcd.print(" ");
  lcd.setCursor(cursorPosition, cursorRow);
}
