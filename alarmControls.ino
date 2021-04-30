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
  for (int i = 0; i < 3; i++)
  {
    digitalWrite(buzzer, HIGH);
    
    if (i < 2)
      delay(250);
    else
      delay(499);     
    
    digitalWrite(buzzer, LOW);
  }
}

/**
 * Allows user to set or change alarm with buttons
 ********************************************************************************/
void setAlarm()
{
  wipeBottom();
  printTime(alarmHour, alarmMin, 0, alarmAmPm);

  alarmHour = changeHour(alarmHour);
  delay(300);

  alarmMin = changeMinute(alarmMin);
  delay(300);
  
  changeAmPm();
  delay(300);

  wipeBottom();
}

void updateAlarmAmPm()
{
  changeAmPmMessage();

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
