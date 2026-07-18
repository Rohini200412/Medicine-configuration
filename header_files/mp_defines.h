//defines.h

//KPM DEFINES
#define ROW0 16 //p1.16
#define ROW1 17 //p1.17
#define ROW2 18 //p1.18
#define ROW3 19 //p1.19

#define COL0 20 //p1.20
#define COL1 21 //p1.21
#define COL2 22 //p1.22
#define COL3 23 //p1.23


//SWITCHS defines
#define SWITCH1 1 //p0.1
#define SWITCH2 3 //p0.3


//LCD defines
#define LCD_DATA_PINS 8  //p0.8
#define RS            16 //p0.16
#define RW            18 //p0.17
#define EN            17 //p0.18

//BUZZER defines
#define BUZZER 20 //0.20


//DEFINING EINT0 and EINT1
#define EINT0_INPUT_PIN 0x0000000C       //P0.1
#define EINT0_VIC_CHNO 14

#define EINT1_INPUT_PIN 0x000000C0       //P0.3
#define EINT1_VIC_CHNO 15


//rtc
#define SUN 0
#define MON 1
#define TUE 2
#define WED 3
#define THU 4
#define FRI 5
#define SAT 6

#define FOSC 12000000
#define CCLK (5*FOSC)    
#define PCLK (CCLK/4)
#define PREINT_VAL (int) ((PCLK / 32768) - 1)
#define PREFRAC_VAL (PCLK -((PREINT_VAL + 1) * 32768))
#define RTC_ENABLE (1<<0)
#define RTC_RESET (1<<1)
#define RTC_CLKSRC (1<<4)
#define _LPC2148

