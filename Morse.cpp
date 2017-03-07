/*
 * Library for creating morse code
 */

#include "Arduino.h"
#include "Morse.h"

String letter;

MClass::MClass(){
}

/*
 * Adds a 0 to String letter
 */
void MClass::dot(){
  letter += "0";
}

/*
 * Adds a 1 to String letter
 */
void MClass::dash(){
  letter += "1";
}

/*
 * Removes all entries from String letter
 */
void MClass::clearLetter(){
  letter = "";
}

/*
 * Returns alphabetic letter that correlates
 * to morse code value in String letter
 */
String MClass::toMorseCode(){
  if(letter == "01"){
    return("A");
  }
  if(letter == "1000"){
    return("B");
  }
  if(letter == "1010"){
    return("C");
  }
  if(letter == "100"){
    return("D");
  }
  if(letter == "0"){
    return("E");
  }
    if(letter == "0010"){
    return("F");
  }
  if(letter == "110"){
    return("G");
  }
  if(letter == "0000"){
    return("H");
  }
  if(letter == "00"){
    return("I");
  }
  if(letter == "0111"){
    return("J");
  }
    if(letter == "101"){
    return("K");
  }
  if(letter == "0100"){
    return("L");
  }
  if(letter == "11"){
    return("M");
  }
  if(letter == "10"){
    return("N");
  }
  if(letter == "111"){
    return("O");
  }
    if(letter == "0110"){
    return("P");
  }
  if(letter == "1101"){
    return("Q");
  }
  if(letter == "010"){
    return("R");
  }
  if(letter == "000"){
    return("S");
  }
  if(letter == "1"){
    return("T");
  }
  if(letter == "001"){
    return("U");
  }
  if(letter == "0001"){
    return("V");
  }
  if(letter == "011"){
    return("W");
  }
  if(letter == "1001"){
    return("X");
  }
  if(letter == "1011"){
    return("Y");
  }
  if(letter == "1100"){
    return("Z");
  }
  if(letter == "11111"){
    return("0");
  }
  if(letter == "01111"){
    return("1");
  }
  if(letter == "00111"){
    return("2");
  }
  if(letter == "00011"){
    return("3");
  }
  if(letter == "00001"){
    return("4");
  }
  if(letter == "00000"){
    return("5");
  }
  if(letter == "10000"){
    return("6");
  }
  if(letter == "11000"){
    return("7");
  }
  if(letter == "11100"){
    return("8");
  }
  if(letter == "11110"){
    return("9");
  }
  if(letter ==  ""){
    return(" ");
  }
  else{
    return(" ");
  }
}

