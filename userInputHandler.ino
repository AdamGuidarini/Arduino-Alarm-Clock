/********************************************************************************
 * Program: Arduino Alarm Clock
 * Programmer: Adam Guidarini
 * file: userInputHandler.ino
 * 
 * Purpose: Allows user to use the 3 buttons control clock 
 ********************************************************************************/

/**
 * Determine which, if any button is pressed
 ********************************************************************************/
void inputCheck()
{
  if (digitalRead(button1) == LOW)
  {
    delay(300);
    changeTime();
  }
  
  if (digitalRead(button2) == LOW)
    return;
  
  if (digitalRead(button3) == LOW)
    return; 
}
