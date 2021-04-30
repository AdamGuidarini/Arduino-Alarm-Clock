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

  // Update Hours
  changeHour();
  delay(200);

  //Update Minutes
  changeMinute();
  delay(200);

  // Update AM/PM
  changeAmPm();
  delay(200);

  wipeBottom();
  
  // Ensure seconds is set to 0
  timeLoopStart = millis() / 1000;
}

/**
 * Allows user to change hour with buttons
 ********************************************************************************/
void changeHour()
{
  changeHourMessage();
  while(true)
  {
    if (digitalRead(button1) == LOW)
    {
      return;
    }
    
    if (digitalRead(button2) == LOW)
    {
      hours--;
      
      if (hours == 0)
        hours += 12;
       
      printTime();
      delay(300);
    }    
    
    if (digitalRead(button3) == LOW)
    {
      hours++;

      if (hours > 12)
        hours -= 12;

      printTime();
      delay(300);
    }
  }
}

/**
 * Allows user to change minute with buttons
 ********************************************************************************/
void changeMinute()
{
  changeMinuteMessage();
  while(true)
  {
    if (digitalRead(button1) == LOW)
    {
      return;
    }

    if (digitalRead(button2) == LOW)
    {
      minutes--;

      if (minutes == 0)
        minutes = 59;

      printTime();
      delay(300);     
    }
    
    if (digitalRead(button3) == LOW)
    {
      minutes++;

      if(minutes >= 60)
        minutes = 0;

      printTime();
      delay(300);
    }
  }
}

void changeAmPm()
{
  changeAmPmMessage();
  while(true)
  {
    if (digitalRead(button1) == LOW)
      return;

    if (digitalRead(button2) == LOW)
    {
      updateAmPm();
      printTime();
      delay(300);
    }
  }
}
