#include<lpc21xx.h>
#include "mp_declaration.h"
#include "mp_defines.h"

void WRITE_LCD(char data)
{
IOCLR0=1<<RW;   // Set RW = 0 -> Write operation
IOCLR0=1<<17;
	// Clear previous data bits and place new 8-bit data on LCD data pins
IOPIN0=(IOPIN0&~(255<<LCD_DATA_PINS))|(data<<LCD_DATA_PINS);
IOSET0=1<<EN;  // Enable pin HIGH ? LCD reads data
delay_us(1);   // Small enable pulse width
IOCLR0=1<<EN;   // Enable pin LOW ? latch data into LCD
delay_ms(2);
}

// Function to send command to LCD
void CMD_LCD(char cmd)
{
IOCLR0=1<<RS;
WRITE_LCD(cmd);  // Send command to LCD
}

void INIT_LCD(void){
        IODIR0|=(255<<LCD_DATA_PINS);  // Configure LCD data pins as OUTPUT
        IODIR0|=(1<<RS)|(1<<EN)|(1<<RW);  // Configure RS, EN, RW as OUTPUT

          delay_ms(15);   //delay of 15 ms for the power on of lcd
          CMD_LCD(0x30); //8bit mode 1st line pos0
    delay_ms(5);   //delay 5ms
    CMD_LCD(0x30);  //8 bit mode 1st line pos0
    delay_us(100); //delay 100us
    CMD_LCD(0x30); //8 bit mode 1st line pos0
    CMD_LCD(0x38); //8 bit mode 2nd line pos0
    CMD_LCD(0x0F); //display on cursor blink
    CMD_LCD(0x01); //clear lcd
    CMD_LCD(0x06); //SHIFT CURSOR RIGHT
}
 
//for displaying characters on lcd
void CHAR_LCD(char ascii)
{
    //DATA_LCD(ascii);
        IOCLR0=1<<RW;
         IOSET0=1<<RS;
         WRITE_LCD(ascii);
}

//displaying string on lcd
void STR_LCD(char *p)
{
    while(*p)
    {
        //DATA_LCD(*p);
        //p++;^M
                CHAR_LCD(*p++);
    }
}

//displaying integer values on lcd
void INT_LCD(int num)
{
    char arr[5];
    int i=0;
    if(num==0)
    {
        //DATA_LCD('0');
                CHAR_LCD('0');
        return;
    }
    while(num>0)
    {
        arr[i++] = num%10 + '0';
        num/=10;
    }
    while(i--)
        //DATA_LCD(arr[i]);
                CHAR_LCD(arr[i]);
}

