#include<lpc21xx.h>
#include "mp_defines.h"
#include "mp_declaration.h"
int choice=0;
// ---------------- INTERRUPT INITIALIZATION ----------------
void INTERRUPT_INIT()
{
	// Clear existing pin configuration for EINT0 and EINT1
    PINSEL0&=((unsigned int)~(3<<2))|((unsigned int)~(3<<6));  
	// Configure pins as EINT0 and EINT1
    PINSEL0|= (EINT0_INPUT_PIN)|(EINT1_INPUT_PIN);
	 // Enable interrupts in VIC (Vector Interrupt Controller)
    VICIntEnable |= (1<<EINT0_VIC_CHNO)|(1<<EINT1_VIC_CHNO);

	// Configure vector slot 0 for EINT0
    VICVectCntl0 = (1<<5)|EINT0_VIC_CHNO;
    VICVectAddr0 = (unsigned int)EINT0_ISR;  // Address of ISR

	// Configure vector slot 1 for EINT1
    VICVectCntl1 = (1<<5)|EINT1_VIC_CHNO;
	VICVectAddr1 = (unsigned int)EINT1_ISR;
	
	// Configure interrupts as edge triggered
	EXTMODE=((1<<1)|(1<<0));
	
	 // Falling edge trigger
	EXTPOLAR=0x00;
}

// ---------------- INTERRUPT SERVICE ROUTINE FOR EINT0 ----------------
void EINT0_ISR(void)__irq
{
    CONFIG_MENU();  // Open configuration menu when interrupt occurs
    EXTINT = (1<<0); // Clear interrupt flag
    VICVectAddr = 0;  // End of interrupt
	CMD_LCD(0x01);    // Clear LCD
}

// ---------------- MEDICINE STORAGE ARRAYS ----------------
int med_hour[3] = {-1,-1,-1};  // Store medicine reminder hours
int med_min[3]  = {-1,-1,-1};   // Store medicine reminder minutes
int med_flag[3] = {0,0,0};      // Flag to prevent repeated reminder

int med_count = 0;   //number of reminders triggered

// ---------------- MEDICINE CHECK FUNCTION ----------------
void CHECK_MEDICINE(void)
{
    int i;
    for(i=0;i<3;i++)
    {
			 // Check if RTC time matches reminder time
        if((HOUR==med_hour[i]) && (MIN==med_min[i]) && (med_flag[i]==0))
        {
                med_count=0;
                BUZZER_ON();  // Start buzzer alert
                while(med_count<60)
									{
                CMD_LCD(0X01);
            CMD_LCD(0xC0);
            STR_LCD("TAKE MEDICINE");
										 // If user presses acknowledgement button
                        if(((IOPIN0>>20)&1)==0)
													{
                        break;
                        }
            delay_ms(100);
            med_flag[i] = 1;
            med_count++;    
                        } //increment medication count after reminder
                        BUZZER_OFF();
						 CMD_LCD(0X01);
        }
        //reset flag after time changes
        if((HOUR!=med_hour[i]) || (MIN!=med_min[i]))
        {
            med_flag[i] = 0;
        }
    }
}

// ---------------- MENU FUNCTION ----------------
void CONFIG_MENU(void)
{
lab:	CMD_LCD(0x01);
        CMD_LCD(0x80);
        STR_LCD("****MENU****");
        CMD_LCD(0xC0);
    STR_LCD("1RTC 2MED 3EXIT");
    // Read keypad input
    choice = KEY_SCAN();
		
    if(choice == '1')
        {
        EDIT_RTC(); // Edit RTC settings
				}
    else if(choice =='2')
        {
        SET_MEDICINE();  // Set medicine reminders
                }
    else if(choice=='3') 
	   return;
    else
	{
	    STR_LCD("INVALID...!");
		delay_ms(500);
		goto lab;
		}

}

// ---------------- RTC EDIT FUNCTION ----------------
void EDIT_RTC(void)
{
    int h,m,s,d,mm,y;
   lable:     CMD_LCD(0x01);
        CMD_LCD(0x80);
        STR_LCD("1.TIME  2.DATE");
        CMD_LCD(0xC0);
        STR_LCD("3.DAY  4.exit");
            choice = KEY_SCAN();
	if(choice>'4')
	{
		CMD_LCD(0x01);
		CMD_LCD(0x80);
		STR_LCD("INVALID CHOICE");
		delay_ms(500);
		goto lable;
		}
	 // -------- TIME SETTING --------
   if(choice=='1')
   {
   lable1: CMD_LCD(0x01);
        CMD_LCD(0x80);
       STR_LCD("1.HOUR 2.MIN");
        CMD_LCD(0xC0);
        STR_LCD("3.SEC 4.exit");
                choice =KEY_SCAN();
        
                if(choice=='1')
                {
				   hr:	CMD_LCD(0x01);
                  CMD_LCD(0x80);
                  STR_LCD("1.HOUR(0-23):");
                  h = READ_NUM();   // Enter hour
					if(h>23)
					{
					  CMD_LCD(0x01);
                      CMD_LCD(0x80);
					  STR_LCD("INVALID CHOICE");
					  delay_ms(500);
					  goto hr;
					}
					 HOUR = h;
										
                  goto lable1;
				 }
				 else if(choice=='2')
				 {
					min:CMD_LCD(0x01);
                    CMD_LCD(0x80);
                    STR_LCD("2.MIN(0-59):");
                    m = READ_NUM();  // Enter minute
					if(m>59)
					{
					 CMD_LCD(0x01);
                      CMD_LCD(0x80);
					  STR_LCD("INVALID CHOICE");
					  delay_ms(500);
					  goto min;
					  }
					  MIN = m;
                    goto lable1;
				 }
        

                else if(choice=='3')
                {
				  CMD_LCD(0x01);
                  CMD_LCD(0x80);
				  STR_LCD("3.SEC(0-59:");
				  CMD_LCD(0x0C);
                  s = READ_NUM();  // Enter seconds
				  SEC = s;
                  goto lable1;
				  
				}
				else if(choice=='4')
                   goto lable;
								
			else
			{
			  CMD_LCD(0x01);
			  CMD_LCD(0x80);
			  STR_LCD("INVALID CHOICE");
			  delay_ms(500);
			  goto lable1;
			}
		}
	 
	 // -------- DATE SETTING --------					
  else if(choice=='2')
        {
					lable2:CMD_LCD(0x01);
         CMD_LCD(0x80);
         STR_LCD("1.DOM  2.MONTH");
         CMD_LCD(0xc0);
         STR_LCD("3.YEAR  4.exit");
                 choice = KEY_SCAN();
					if(choice=='1')
                {
									dom:	CMD_LCD(0x01);
                  CMD_LCD(0x80);
									//STR_LCD("dom(0-31)");
									delay_ms(500);
									CMD_LCD(0x01);
									CMD_LCD(0x80);
                  STR_LCD("1.DAY(1-31):");
                  d = READ_NUM();
									if(d>31)
										goto dom;
										 DOM = d;
                  goto lable2;
								}
								else if(choice=='2')
									{
										mn: CMD_LCD(0x01);
                    CMD_LCD(0x80);
										
									//	STR_LCD("month(0-12)");
										delay_ms(500);
									CMD_LCD(0x01);
									CMD_LCD(0x80);
                    STR_LCD("2.MONTH(1-12):");
                    mm = READ_NUM();
										if(mm>12)
											goto mn;
											MONTH = mm;
                                  goto lable2;
									}
									else if(choice=='3')
									{
									yr:	CMD_LCD(0x01);
                                        CMD_LCD(0x80);
										STR_LCD("YEAR(>2000)");
										delay_ms(500);
										CMD_LCD(0x01);
										CMD_LCD(0x80);
                                        STR_LCD("3.YEAR(>2000):");
										CMD_LCD(0xC0);
						                y = READ_NUM();
										if(!(y>2000 && y<=2026))
										goto yr;
										 YEAR = y;
                                        goto lable2;
									}
									else if(choice=='4')
									goto lable;
	                     else
						 {							 
									CMD_LCD(0x01);
							 CMD_LCD(0x80);
									STR_LCD("INVALID CHOICE");
							 delay_ms(500);
							    goto lable2;
								}
					}
				
					// -------- DAY SETTING --------
else if(choice=='3')
				{
					day:	CMD_LCD(0x01);
          CMD_LCD(0x80);
          STR_LCD("Enter DAY(0-6):");
          CMD_LCD(0xC0);
          DOW=READ_NUM();
					if(DOW>7)
						goto day;
          CMD_LCD(0x01);
          CMD_LCD(0x80);
          STR_LCD("DAY UPDATED");
				}
					

				 // -------- UPDATE RTC REGISTERS --------
    CCR = (1<<1);
    CCR = (1<<0);
    CMD_LCD(0x01);
        CMD_LCD(0x80);
	STR_LCD("  RTC UPDATED  ");
    delay_s(2);
		}


		// ---------------- SET MEDICINE TIME ----------------
void SET_MEDICINE(void)
{
    int i;
    CMD_LCD(0x01);
        CMD_LCD(0x80);
    STR_LCD("NUM MED:");

    med_count = READ_NUM();  // Number of medicines
    if(med_count > 3)
       med_count = 3;
    for(i=0;i<med_count;i++)
    {
	hur:
			CMD_LCD(0x01);
			//STR_LCD("HUR<=23only");
			delay_ms(500);
			CMD_LCD(0x01);
        CMD_LCD(0x80);
        STR_LCD("HOUR(0-23):");
        med_hour[i] = READ_NUM();
			if(med_hour[i]>23)
				goto hur;

			min:
        CMD_LCD(0x01);
			  //STR_LCD("MIN(0-59)only");
			delay_ms(500);
			CMD_LCD(0x01);
        CMD_LCD(0x80);
        STR_LCD("MIN(0-59):");
        med_min[i] = READ_NUM();
			if(med_min[i]>59)
				goto min;
    }
    CMD_LCD(0x01);
    CMD_LCD(0x80);
		STR_LCD("   SAVED  ");
    delay_s(2);
		CMD_LCD(0x01);
}

// ---------------- INTERRUPT FOR BUZZER STOP ----------------
void EINT1_ISR(void)__irq
{
    BUZZER_OFF();//when sw2 is on ,then buzzer off,due to the ack from the user
    EXTINT = (1<<1);
    VICVectAddr = 0;
}

