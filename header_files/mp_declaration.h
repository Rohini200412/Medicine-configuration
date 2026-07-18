//declarations.h


//DELAY
void delay_us(unsigned int dlyus); //for micro seconds
void delay_ms(unsigned int dlyms); //for milli seconds
void delay_s(unsigned int dlys);   //for seconds


//KEYPAD MATRIX
void INIT_KPM(void);
int KEY_DETECT(void);
int ROW_CHECK(void);
int COL_CHECK(void);
int KEY_SCAN(void);
int READ_NUM(void);


//LCD
void INIT_LCD(void);
void CMD_LCD(char cmd);
void DATA_LCD(char data);
void CHAR_LCD(char ascii);
void STR_LCD(char *p);
void INT_LCD(int num);


//EINT0 & EINT1 Interrupts
void EINT0_ISR(void)__irq;
void EINT1_ISR(void)__irq;
void INTERRUPT_INIT(void);
void CHECK_MEDICINE(void);
void CONFIG_MENU(void);
void EDIT_RTC(void);
void SET_MEDICINE(void);

//RTC
void INIT_RTC(void);
void DISPLAY_TIME(void);
void RTC_Init(void);
void GetRTCTimeInfo(int *,int *,int *);
void DisplayRTCTime(int,int,int);
void GetRTCDateInfo(int *,int *,int *);
void DisplayRTCDate(int,int,int);
void SetRTCTimeInfo(int,int,int);
void SetRTCDateInfo(int,int,int);
void GetRTCDay(int *);
void DisplayRTCDay(int);
void SetRTCDay(int);

//BUZZER
void BUZZER_ON(void);
void BUZZER_OFF(void);

