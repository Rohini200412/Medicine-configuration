#include<lpc21xx.h>
#include "mp_defines.h"
#include "mp_declaration.h"

//buzzer on
void BUZZER_ON(void)
{
    IOSET0 = (1<<BUZZER);
}
//buzzer off
void BUZZER_OFF(void)
{
    IOCLR0 = (1<<BUZZER);
}

