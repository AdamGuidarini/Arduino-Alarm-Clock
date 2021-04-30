/********************************************************************************
 * Program: Arduino Alarm Clock
 * Programmer: Adam Guidarini
 * file: timeManagement.ino
 * 
 * Purpose: Keep track of time and print time to display 
 ********************************************************************************/

/**
 * Prints 2 digit time unit to LCD display
 * 
 * @param t Time passed to for printing
 * @param cursorRow Row of display to start printing from
 ********************************************************************************/
void printTimeUnit(int t, int cursorRow)
{
  if (t < 10)
  {
    lcd.setCursor(cursorRow,0);
    lcd.print(0);
    lcd.setCursor(cursorRow + 1,0);
    lcd.print(t);
  }
  else
  {
    lcd.setCursor(cursorRow,0);
    lcd.print(t);
  }
}

/**
 * Prints current values of hours, minutes, and seconds to LCD
 ********************************************************************************/
void printTime()
{
  // Print hour
  printTimeUnit(hours, 0);

  // Print :
  lcd.setCursor(2,0);
  lcd.print(':');

  // Print minutes
  printTimeUnit(minutes, 3);

  // Print :
  lcd.setCursor(5,0);
  lcd.print(':');

  // Print seconds
  printTimeUnit(seconds, 6);

  // Print AM or PM
  lcd.setCursor(9, 0);
  lcd.print(amPM);
}

/**
 * Updates value of first 
 ********************************************************************************/
void updateAmPm()
{
  if (amPM[0] == 'A')
    amPM[0] = 'P';
  else
    amPM[0] = 'A';
}

/**
 * Update values of minutes, hours, amPM, and amPmFlag
 ********************************************************************************/
void updateTimes()
{
  // Update minutes, and hours
  if (seconds >= 60)
  {
    minutes++;
    seconds -= 60;  
  }
  if (minutes >= 60)
  {
    hours++;
    minutes = 0;
  }

  // Update AM/PM
  if (hours == 12 && !minutes && !seconds && amPmFlag)
  {
    updateAmPm();
    amPmFlag = 0;
  }

  // Reset AM/PM flag
  if (hours == 12 && !minutes && seconds == 1)
  {
    amPmFlag = 1;
  }

  // Set hours back to 1 if greater than 0
  if (hours > 12)
  {
    hours -= 12;
  }  
}
