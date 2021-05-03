/********************************************************************************
 * Program: Arduino Alarm Clock
 * Programmer: Adam Guidarini  
 * file: alarmControls.ino
 * 
 * Purpose: Set, cancel, and turn off alarm. 
 ********************************************************************************/


/**
 * Controls buzzer to set the alarm on and off 3 times
 ********************************************************************************/
void soundTheAlarm()
{
  digitalWrite(buzzer, HIGH);

  safe_delay(800);
  
  digitalWrite(buzzer, LOW);
}

/**
 * Allows user to set or change alarm with buttons
 ********************************************************************************/
void setAlarm()
{
  // Set hour of alarm to 12, prevents setting an alarm at hour 0
  alarmHour = 12;
  
  wipeBottom();
  printTime(alarmHour, alarmMin, 0, alarmAmPm);

  alarmHour = changeHour(alarmHour);
  safe_delay(300);

  alarmMin = changeMinute(alarmMin);
  safe_delay(300);
  
  changeAmPm();
  safe_delay(300);

  wipeBottom();

  alarm = 1;
  alarmSetIndicator(alarm);
}

/**
 * Allows user to choose between AM or PM for alarm
 ********************************************************************************/
void updateAlarmAmPm()
{
  changeAmPmMessage();
  printTime(alarmHour, alarmMin, 0, alarmAmPm);

  lcd.setCursor(9,0);
  lcd.print(alarmAmPm);

  while(true)
  {
    if (digitalRead(button1) == LOW)
      return;

    if (digitalRead(button2) == LOW)
    {
      if(alarmAmPm[0] == 'A')
        alarmAmPm[0] = 'P';
      else
        alarmAmPm[0] = 'A';
      
      lcd.setCursor(9,0);
      lcd.print(alarmAmPm);
    }
  }
}
