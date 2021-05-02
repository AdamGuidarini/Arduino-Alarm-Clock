# Arduino-Alarm-Clock
An alarm clock made with an Ardiuno, a breadboard, and various other components.

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
	
		OK - Accept currently selected value.
		
		-Hour - Decrement hour.
		
		+Hour - Increment hour.
		
		-Min - Decrement minute.
		
		+Min - Increment minute.
		
		AM/PM - Toggle between AM or PM.
		
	Indicators:
	
		* - Indicates an alarm is active.

Notes:

    This project is a work in progress, and will likely
    be updated a several times in the coming week.

Known Bugs:

    - Timer stalls - the clock will occasionally fail to
      count a second causing it to fall behind.

    - Time freeze - because of my use of the function delay()
      timer is often halted several times while taking user
      input. This bug will be patched soon.
