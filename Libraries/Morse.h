#ifndef Morse_h
#define Morse_h

class MClass{
  public:
    MClass();
    void dot();             //Adds a 0 to String letter
    void dash();            //Adds a 1 to String letter
    void clearLetter();     //Removes all entries from String letter
    String toMorseCode();   // Returns alphabetic letter that correlates to morse code value in String letter
};

extern MClass morse;

#endif
