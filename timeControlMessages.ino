/********************************************************************************
 * Program: Arduino Alarm Clock
 * Programmer: Adam Guidarini
 * file: timeControlMessages.ino
 * 
 * Purpose: Gives users messages for time controls
 ********************************************************************************/

/**
 * Clear bottom row of LCD
 ********************************************************************************/
void wipeBottom()
{
  for (int i = 0; i < 16; i++)
  {
    lcd.setCursor( i, 1);
    lcd.print(' ');
  }
}

/**
 * Print message for hour change controls
 ********************************************************************************/
void changeHourMessage()
{
  wipeBottom();
  lcd.setCursor(0,1);
  lcd.print("OK -Hour +Hour");
}

/**
 * Print message for minute change controls
 ********************************************************************************/
void changeMinuteMessage()
{
  wipeBottom();
  lcd.setCursor(0,1);
  lcd.print("OK -Min +Min");
}

/**
 * Print message for AM/PM change controls
 ********************************************************************************/
void changeAmPmMessage()
{
  wipeBottom();
  lcd.setCursor(0,1);
  lcd.print("OK AM/PM");
}
