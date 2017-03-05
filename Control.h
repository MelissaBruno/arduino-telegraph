#ifndef Control_h
#define Control_h

class ControlClass{
  public:
    ControlClass();
    void SETUP();                       //Setup for LCD and cursor
    int getCursorPosition();            //Returns position of cursor
    int getCursorRow();                 //Returns the row the cursor is on
    void cursorForward();               //Moves cursor to the forward one position
    void cursorBack();                  //Move thes cursor back one positon
    void incrementRow();                //Moves the cursor down one row
    void decrementRow();                //Moves the cursor up one row
    void printLetter(String letter);    //Prints specified string to the LCD
    void backspace();                   //Moves cursor back one space and removes the current entry on LCD
};

extern ControlClass control;

#endif
