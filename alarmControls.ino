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
