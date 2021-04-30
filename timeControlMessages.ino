/********************************************************************************
 * Program: Arduino Alarm Clock
 * Programmer: Adam Guidarini
 * file: timeControlMessages.ino
 * 
 * Purpose: Gives users messages for time controls
 ********************************************************************************/

void wipeBottom()
{
  for (int i = 0; i < 16; i++)
  {
    lcd.setCursor( i, 1);
    lcd.print(' ');
  }
}

 void changeHourMessage()
 {
  wipeBottom();
  lcd.setCursor(0,1);
  lcd.print("OK -Hour +Hour");
 }

 void changeMinuteMessage()
 {
  wipeBottom();
  lcd.setCursor(0,1);
  lcd.print("OK -Min +Min");
 }

 void changeAmPmMessage()
 {
  wipeBottom();
  lcd.setCursor(0,1);
  lcd.print("OK AM/PM");
 }
