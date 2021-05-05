
# Arduino-Alarm-Clock
An alarm clock made with an Ardiuno, a breadboard, and various other components.


Schematic:

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
	
      |---------------------------------------------------------------|
      | Message  |  Action                              | Button      |
      |---------------------------------------------------------------|
      |          |                                      |             |
      | OK       |  Accept currently selected value.    | Button 1    |
      |          |                                      |             |
      | -Hour    |  Decrement hour.                     | Button 2    |
      |          |                                      |             |
      | +Hour    |  Increment hour.                     | Button 3    |
      |          |                                      |             |
      | -Min     |  Decrement minute.                   | Button 2    |
      |          |                                      |             |
      | +Min     |  Increment minute.                   | Button 3    |
      |          |                                      |             |
      | AM/PM    |  Toggle between AM or PM.            | Button 2    |
      |---------------------------------------------------------------|
		
	Indicators:
	
		* - Indicates an alarm is active.

Notes:

     - This project is a work in progress, and will likely
      be updated a several times in the coming week.

     - This is my first project with an Arduino and my first
       project with embedded software, bugs and other issues
       will be present for a while.
	
     - Because this project was not designed with an RTC, an offset
       to prevent the clock from drifting too far from real time.

Setting OFFSET:

     - The offset must will likely be different on each board, this will
       require changing OFFSET which is located in alarmClock.ino.
       
     - OFFSET is the number of milliseconds that the clock is off by every minute.
       this value is added back into the millisecond counter after each minute.
       
     Steps for setting OFFSET:
     
       - Open alarmClock.ino.
       - Scroll to line 24.
         + By default it will say: #define OFFSET 53.
       - Replace 53 with 0.
       - Set the clock based on a computer or other device's time.
       - Run for at least one hour and compare results.
       - Calculate the difference in milliseconds for each minute:
       	 + 1000 * ([difference in seconds] / ([hours tested] * 60 * 60)) = millisecond offset
       - Return to line 24 of alarmClock.ino and set OFFSET to the result from the formula above.

Known Bugs/Issues:

    - Due to the lack of an RTC in this porject, the clock cannot be 100% accurate
      see "Setting OFFSET" for more details.
   
