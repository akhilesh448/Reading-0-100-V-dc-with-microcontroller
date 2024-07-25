/*
 * File:   ssd.c
 * Author: Akhilesh Kotwaliwale
 *Description: To display digit on ssd
 * Created on June 24, 2024, 6:42 PM
 */


#include <xc.h>
#include "ssd.h"

void init_ssd(void) 
{
    SSD_DATA_PORT_DDR = 0x00;   //port d as input for ssd
    SSD_CONTROL_PORT_DDR = SSD_CONTROL_PORT_DDR & 0xC3; //selecting 4 ssd
    SSD_CONTROL_PORT = SSD_CONTROL_PORT & 0xC3; //initially display 0000
}

void display(unsigned char data[]) 
{
    unsigned char digit = 0;
    for(digit = 0; digit < 4; digit++)
    {//To display on 4 ssd one by one
        SSD_DATA_PORT = data[digit];    
        SSD_CONTROL_PORT = (SSD_CONTROL_PORT & 0xC3) | (0x04 << digit);
        for(unsigned int wait = 100; wait--;);
    }
}
