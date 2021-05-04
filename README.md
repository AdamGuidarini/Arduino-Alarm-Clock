
# Arduino-Alarm-Clock
An alarm clock made with an Ardiuno, a breadboard, and various other components.


Schematic

![Arduino Alarm Clock](https://user-images.githubusercontent.com/45023561/116891210-0f2e6200-abf4-11eb-8b9f-0b664032c909.png)


Required Hardware:

     Arduino/Elegoo Uno R3
     
     Active Buzzer
     
     LCD1602 (with pin header)
     
     830 Tie-Points Breadboard
     
     Button (3)
     
     Potentionmeter 10k
     
     M - to - F Wires (2)
     
     M - to - M Wires (24) 

Description:

	- Once powered on the program begins counting starting at 12:00:00 AM.

	- Time is displayed in hh:mm:ss 12-hour format.

    - The user can use the three buttons to change the time and set the alarm.

Buttons:

    Button1:
	
         - Allows the user to change time.
         
         - Once pressed controls will be displayed on the bottom row of the LCD display.
         
    Button2:
	
         - Allows user to set the alarm.
         
         - Like with button1, controls will appear on the display.
         
    Button3:
	
         - Toggles alarm on and off if the alarm is set.
         
         - Also used to deactivate alarm when it goes off.

On Screen Controls & Indicators:

	Controls:
	
      |-------------------------------------------------------------------|
      |Message   |  Action                              |  Button         |
      |          |                                      |                 |
      |-------------------------------------------------------------------|
      |          |                                      |                 |
      | OK       |  Accept currently selected value.    | Button 1        |
      |          |                                      |                 |
      | -Hour    |  Decrement hour.                     | Button 2        |
      |          |                                      |                 |
      | +Hour    |  Increment hour.                     | Button 3        |
      |          |                                      |                 |
      | -Min     |  Decrement minute.                   | Button 2        |
      |          |                                      |                 |
      | +Min     |  Increment minute.                   | Button 3        |
      |          |                                      |                 |
      | AM/PM    |  Toggle between AM or PM.            | Button 2        |
      |-------------------------------------------------------------------|
		
	Indicators:
	
		* - Indicates an alarm is active.

Notes:

     This project is a work in progress, and will likely
     be updated a several times in the coming week.

     This is my first project with an Arduino and my first
     project with embedded software, bugs and other issues
     will be present for a while.

Known Bugs:

    - Clock runs slow
   
