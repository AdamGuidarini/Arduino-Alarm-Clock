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
void printTimeUnit(unsigned int t, int cursorRow)
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
 * 
 * @param hr The hour to display
 * @param mn The minute to display
 * @param sec The second to display
 * @param ap the AM or PM string to display
 ********************************************************************************/
void printTime(unsigned int hr, unsigned int mn, unsigned long sec, char ap[])
{
  // Print hour
  printTimeUnit(hr, 0);

  // Print :
  lcd.setCursor(2,0);
  lcd.print(':');

  // Print minutes
  printTimeUnit(mn, 3);

  // Print :
  lcd.setCursor(5,0);
  lcd.print(':');

  // Print seconds
  printTimeUnit(sec, 6);

  // Print AM or PM
  lcd.setCursor(9, 0);
  lcd.print(ap);
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
  while (seconds / 1000 >= 60)
  {
    minutes++;
    seconds -= 60000;  
  }
  while (minutes >= 60)
  {
    hours++;
    minutes -= 60;
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
  while(hours > 12)
  {
    hours -= 12;
  } 
}
