#include<lpc21xx.h>
#include "mp_defines.h"
#include "mp_declaration.h"
// Keypad lookup table that maps row & column to actual key value
int KPMLUT[4][4]={{'1','2','3','A'},
									{'4','5','6','B'},
									{'7','8','9','C'},
									{'*','0','=','D'}};

void INIT_KPM(void)
{
	 IODIR1 |= (0xF<<16);// Set P1.16–P1.19 as OUTPUT (Rows)
	 IODIR1 &= ~(0xF<<20);  // Set P1.20–P1.23 as INPUT (Columns)
	  IOSET1 = (0xF<<16);    // Make all rows HIGH initially
}

// Function to check if any key is pressed
int KEY_DETECT(void)
{
	 // Read column bits and check if any column becomes LOW
	  return((((IOPIN1>>COL0)&15)<15)?0:1);
	// Return 0 ? key pressed
      // Return 1 ? no key pressed
}

// Function to detect which row is active
int ROW_CHECK(void)
{
	int rno;  // Variable to store row number
	for(rno=0; rno<4; rno++)
	{
		 // Make one row LOW and keep others HIGH
		IOPIN1=((IOPIN1&(~(255<<ROW0)))|(~(1<<rno)<<ROW0));
		 // Check if key is detected in this row
		if(KEY_DETECT()==0)
		{
			break;  // If key detected stop scanning
		}
	}
	//make rows as default
	IOPIN1=((IOPIN1&(~(255<<ROW0)))|(0x0<<ROW0));
	return rno;
}

// Function to detect which column is active
int COL_CHECK(void)
{
	int cno;   // Variable to store column number
	for(cno=0; cno<4; cno++)
	{
		// Check if column pin becomes LOW
		if(((IOPIN1>>(COL0+cno))&1)==0)
		{
			break;  // Column found
		}
	}
	return cno;   // Return column number
}

// Function to scan keypad and return pressed key
int KEY_SCAN(void)
{ 
	unsigned int r,c;  // r = row index, c = column index
    while(1)         // Infinite loop until key detected
    {
        for(r=0;r<4;r++)    // Scan each row
        {
            IOSET1 = (0xF<<16);  // Make all rows HIGH
            IOCLR1 = (1<<(16+r));  // Make current row LOW
            delay_ms(10);
            if(!(IOPIN1&(1<<20))) c=0;
            else if(!(IOPIN1&(1<<21))) c=1;  // Column 0 pressed
					else if(!(IOPIN1&(1<<22))) c=2;  // Column 1 pressed
            else if(!(IOPIN1&(1<<23))) c=3;  // Column 2 pressed
            else continue;                  // No key in this row
                         delay_ms(20);
					// Wait until key is released
            while(!(IOPIN1&(1<<(20+c))));
            delay_ms(20);
           return KPMLUT[r][c]; // Return the key value using lookup table
				}
    }
}


// Function to read multi-digit number from keypad
int READ_NUM(void)
{
	char key;
	int sum=0,c=0;
	while(1)
	{
	key=KEY_SCAN();  // Scan keypad and get key value
		if(key>='0'&&key<='9')   
		{
			sum=(sum*10)+(key-'0');  // Convert ASCII to integer and append digit
			CHAR_LCD(key);  // Display digit on LCD
			c++;
			
		}
		 // If '=' key pressed ? finish input
		else if(key=='=')
    	{
			break;
		} 
		
		// If '*' key pressed ? delete last digit
		else if(key=='*' && c)
		{
			sum=sum/10;
			CMD_LCD(0x10);
			CHAR_LCD(' ');
			CMD_LCD(0x10);
			c--;
		}
		
	}
	return sum;
}

