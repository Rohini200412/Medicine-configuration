#include "mp_declaration.h"

//delay in micro seconds
void delay_us(unsigned int dlyus)
{
        for(dlyus*=12;dlyus>0;dlyus--);
}
//delay milli seconds
void delay_ms(unsigned int dlyms)
{
        for(dlyms*=12000;dlyms>0;dlyms--);
}
//delay in seconds)
void delay_s(unsigned int dlys)
{
        for(dlys*=12000000;dlys>0;dlys--);
}

