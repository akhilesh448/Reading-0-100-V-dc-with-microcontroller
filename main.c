/*
 * File:   main.c
 */

#include <xc.h>
#include "adc.h"
#include "ssd.h"
#pragma config WDTE = OFF        // Watchdog Timer Enable bit (WDT disabled)

static void init_config(void) 
{   //initialize required modules
    init_adc();
    init_ssd();
}
unsigned char digit[] = {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE};
void main(void)
{
    unsigned int adc_value;
    float voltage;
    unsigned char ssd[4];
    init_config();
    while (1) 
    {
        adc_value = read_adc();     //read from adc
        voltage = (adc_value * 5.0 / 1023.0) * (100.0 / 5.0);   //convert to voltage
        // Convert voltage to display on SSD
        unsigned int int_part = (unsigned int)voltage;
        unsigned int frac_part = (unsigned int)((voltage - int_part) * 100);

        ssd[0] = digit[int_part / 10];       //display first digit
        ssd[1] = (digit[int_part % 10])| DP; //display second digit and blink point
        ssd[2] = digit[frac_part / 10];  //display third digit
        ssd[3] = digit[frac_part % 10];         //display fourth digit
        display(ssd);
    }
    return;
}
