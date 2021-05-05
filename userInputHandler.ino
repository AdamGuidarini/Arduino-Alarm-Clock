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
  // Change time
  if (digitalRead(button1) == LOW)
  {
    safe_delay(300);
    changeTime();
  }

  // Set Alarm
  if (digitalRead(button2) == LOW)
  {
    safe_delay(300);
    setAlarm();
  }

  // Enable/disable alarm if set
  if (digitalRead(button3) == LOW)
  {
    safe_delay(300);
    toggleAlarm();
  }
}

/**
 * Similar to delay, but instead of halting execution it enters a loop
 * until the number of milliseconds passed to it have passed.
 * 
 * @param offset The number of milliseconds for which the program will be stopped
 ********************************************************************************/
void safe_delay(unsigned int offset)
{
  unsigned long timeAtStart = millis();

  while (millis() < (timeAtStart + offset))
  {
    if (millis() < timeAtStart)
      rolloverProtection(timeAtStart, seconds);
  }
}

/**
 * Designed to handle rollover by adding current value of millis() and difference
 * between unsigned long max value minus older value of millis to secs.
 * 
 * @param val Ideally an older value of millis. Difference between it and millis()
 *            will be added to secs.
 * @param milliSecs A millisecond counter to be corrected at moment of millis()           
 *                  rollover.
 ********************************************************************************/
void rolloverProtection(unsigned long val, unsigned long& milliSecs)
{
  const unsigned long longMax = 0xffffffff;
  
  milliSecs += (millis() + (longMax - val));
}
