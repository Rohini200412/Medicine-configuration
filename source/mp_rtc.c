#include "mp_defines.h"
#include "mp_declaration.h"
#include <lpc214x.h>
// Array to hold names of days of the week
char week[][4] = {"SUN","MON","TUE","WED","THU","FRI","SAT"};

 void RTC_Init(void) 
{
	// Disable and reset the RTC
        CCR = RTC_RESET;
	// Set prescaler integer and fractional parts
	PREINT=PREINT_VAL;
	PREFRAC=PREFRAC_VAL;
	// Enable the RTC
	CCR=RTC_ENABLE;
	
}

/*
Get the current RTC time
hour Pointer to store the current hour
minute Pointer to store the current minute
second Pointer to store the current second
*/
void GetRTCTimeInfo(int *hour,int *minute,int *second)
	{
        *hour = HOUR;
        *minute = MIN;
        *second = SEC;
        }
	/*
Display the RTC time on LCD
hour value (0-23)
minute value (0-59)
second value (0-59) seperated by ':'
*/

void DisplayRTCTime(int hour,int minute,int second)
	{
        CMD_LCD(0x80);
        CHAR_LCD(hour/10+48);
        CHAR_LCD(hour%10+48);
        CHAR_LCD(':');
        CHAR_LCD(minute/10+48);
        CHAR_LCD(minute%10+48);
        CHAR_LCD(':');
        CHAR_LCD(second/10+48);         
        CHAR_LCD(second%10+48); 
}
/*
Get the current RTC date
day Pointer to store the current date (1-31)
month Pointer to store the current month (1-12)
year Pointer to store the current year (four digits)
*/
void GetRTCDateInfo(int *date,int *month,int *year)
	{
        *date = DOM;
        *month = MONTH;
        *year = YEAR;
        }
	/*
Display the RTC date on LCD
Day of month (1-31)
Month (1-12)
Year (four digits) and seperated by '/'
*/
void DisplayRTCDate(int date,int month,int year)
{
        CMD_LCD(0xC0);
        CHAR_LCD(date/10+48);
        CHAR_LCD(date%10+48);
        CHAR_LCD('/');
        CHAR_LCD(month/10+48);
        CHAR_LCD(month%10+48);
        CHAR_LCD('/');
        INT_LCD(year);
}
/*
Set the RTC time
Hour to set (0-23)
Minute to set (0-59)
Second to set (0-59)
*/
void SetRTCTimeInfo(int hour,int minute,int second)
{
        HOUR = hour;
        MIN = minute;
        SEC = second;
}
/*
Set the RTC date
day of month to set (1-31)
month to set (1-12)
year to set (four digits)
*/
void SetRTCDateInfo(int date,int month,int year)
{
        DOM = date;
        MONTH = month;
        YEAR = year;
}
/*
Get the current day of the week
dow Pointer to store Day of Week (0=Sunday, ..., 6=Saturday)
*/
void GetRTCDay(int *dow)
{
        *dow = DOW; 
}


/*
Display the current day of the week on LCD
dow (Day of Week) (0=Sunday, ..., 6=Saturday)
*/
void DisplayRTCDay(int dow)
{

        CMD_LCD(0x80+10);

        STR_LCD(week[dow]);
}

/*
Set the day of the week in RTC
Day of Week to set (0=Sunday, ..., 6=Saturday)
*/
void SetRTCDay(int dow)

{

        DOW = dow;

}

