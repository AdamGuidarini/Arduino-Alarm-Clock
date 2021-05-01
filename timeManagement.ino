/********************************************************************************
 * Program: Arduino Alarm Clock
 * Programmer: Adam Guidarini
 * file: timeManagement.ino
 * 
 * Purpose: Allows user to use the 3 buttons to change time 
 ********************************************************************************/

 /**
 * Changes time on LCD in orderd: hours, minutes, AM/PM
 ********************************************************************************/
void changeTime()
{
  wipeBottom();
  seconds = 0;
  printTime(hours, minutes, seconds, amPM);
  
  // Update Hours
  hours = changeHour(hours);
  delay(300);

  //Update Minutes
  minutes = changeMinute(minutes);
  delay(300);

  // Update AM/PM
  changeAmPm();
  delay(300);

  wipeBottom();
  
  // Ensure seconds is set to 0
  timeLoopStart = millis() / 1000;
}

/**
 * Allows user to change hour with buttons
 * 
 * @param hour 
 ********************************************************************************/
unsigned int changeHour(unsigned int hour)
{
  changeHourMessage();
  while(true)
  {
    if (digitalRead(button1) == LOW)
    {
      break;
    }
    
    if (digitalRead(button2) == LOW)
    {
      hour--;
      
      if (hour == 0)
        hour += 12;
       
      printTimeUnit(hour, 0);
      delay(300);
    }    
    
    if (digitalRead(button3) == LOW)
    {
      hour++;

      if (hour > 12)
        hour -= 12;

      printTimeUnit(hour, 0);
      delay(300);
    }
  }

  return hour;
}

/**
 * Allows user to change minute with buttons
 * 
 * @param minute The minute value to use for initializing 
 * 
 * @return the new value for the minute after 
 ********************************************************************************/
unsigned int changeMinute(unsigned int minute)
{
  changeMinuteMessage();
  while(true)
  {
    if (digitalRead(button1) == LOW)
    {
      break;
    }

    if (digitalRead(button2) == LOW)
    {
      minute--;

      if (minute == 0)
        minute = 59;

      printTimeUnit(minute, 3);
      delay(300);     
    }
    
    if (digitalRead(button3) == LOW)
    {
      minute++;

      if(minute >= 60)
        minute = 0;

      printTimeUnit(minute, 3);
      delay(300);
    }
  }

  return minute;
}

/**
 * Allow user to change AM/PM with buttons
 ********************************************************************************/
void changeAmPm()
{
  changeAmPmMessage();
  while(true)
  {
    if (digitalRead(button1) == LOW)
      break;

    if (digitalRead(button2) == LOW)
    {
      updateAmPm();
      printTime(hours, minutes, seconds, amPM);
      delay(300);
    }
  }
}
