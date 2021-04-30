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
    delay(300);
    changeTime();
  }

  // Set Alarm
  if (digitalRead(button2) == LOW)
  {
    delay(300);
    setAlarm();
  }

  // Enable/disable alarm if set
  if (digitalRead(button3) == LOW)
  {
    delay(300);
    if (alarm)
    {
      alarm = 0;
      alarmSetIndicator(alarm);
    }
    else if (!alarm)
    {
      if (!alarmHour)
        return;
      else
      {
        alarm = 1;
        alarmSetIndicator(alarm);
      }
    }
  }
}
