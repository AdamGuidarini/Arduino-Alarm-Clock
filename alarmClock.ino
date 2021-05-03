/*************************************************************************
 *  Program: Arduino Alarm Clock
 *  Programmer: Adam Guidarini
 *  file: alarmClock.ino
 *  
 *  Purpose: Creates an alarm clock 
 *  
 *  Required Hardware:
 *    Arduino/Elegoo Uno R3
 *    Active Buzzer
 *    LCD1602 (with pin header)
 *    830 Tie-Points Breadboard
 *    Button (3)
 *    Potentionmeter 10k
 *    M - to - F Wires (2)
 *    M - to - M Wires (24) 
 ********************************************************************************/

#include<LiquidCrystal.h>
#include<string.h>

// Set up LCD
// Values passed to LCD are pins on Arduino
LiquidCrystal lcd(7,8,9,10,11,12);

// Vars for time
unsigned long seconds = 0;
unsigned int minutes = 0;
unsigned int hours = 12;

// AM/PM controls
char amPM[3] = "AM";
bool amPmFlag = 0; // 0 = not changed, 1 = changed

// Vars for alarm time
bool alarm = 0;
unsigned int alarmMin = 0;
unsigned int alarmHour = 0;
char alarmAmPm[3] = "AM";

// Button setup
const int button1 = 3;
const int button2 = 4;
const int button3 = 5;

// Buzzer pin
const int buzzer = 6;

// Records time in secods since start of program at beginning of loop
unsigned long timeLoopStart = 0;

/**
 * Initializations to perform at startup
 ********************************************************************************/
void setup() 
{
  lcd.begin(16,2);
  pinMode(buzzer, OUTPUT);
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
}

/**
 * Main function performs actions in a loop while powered on
 ********************************************************************************/
void loop() 
{
  timeLoopStart = millis();

  // Update values of minutes, hours, amPM, and amPmFlag
  updateTimes();

  // Check for user input
  inputCheck();

  // Check for alarm
  if(alarm && (alarmHour == hours) && (alarmMin == minutes) && (!strcmp(amPM, alarmAmPm)))
    soundTheAlarm();
  
  // Print time
  printTime(hours, minutes, seconds / 1000, amPM);
  
  // Add to seconds
  seconds += millis() - timeLoopStart;
}
