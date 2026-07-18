//USER-CONFIGURABLE MEDICINE REMINDER SYSTEM
#include <lpc21xx.h>
#include "mp_defines.h"
#include "mp_declaration.h"

int hour,min,sec,date,month,year,day;
int main()
{
  	   IODIR0|=1<<20;
    INIT_LCD(); //initialize lcd
	INIT_KPM();   //initialize keypad
	// Initialize RTC 
		RTC_Init();
	INTERRUPT_INIT();  //initialize interrupt
    STR_LCD("MEDICINE");  //display messege
    CMD_LCD(0xC0);        //move to second line on lcd
    STR_LCD("REMINDER");  //display reminder
    delay_s(2);         
    CMD_LCD(0x01);       //clear lcd
    // Set the initial data (date, month, year)
		SetRTCDateInfo(12,4,2025);

    while (1) 
    {
        // Get and display the current time info on LCD
				GetRTCTimeInfo(&hour,&min,&sec);
				DisplayRTCTime(hour,min,sec);

				// Get and display the current date info on LCD
				GetRTCDateInfo(&date,&month,&year);
				DisplayRTCDate(date,month,year);
				// Get and display the current day info on LCD
				GetRTCDay(&day);
				DisplayRTCDay(day);
			CHECK_MEDICINE();

    }
}

