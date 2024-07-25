#include <xc.h>

void init_adc(void)
{
    ADCON0 = 0x41;  //selecting Fosc/8, channel 0, power up ADC module
    ADCON1 = 0x80;  //selecting right justification, Vref+ = Vdd, Vref- = Vss
}

unsigned short read_adc(void)
{
    unsigned short adc_reg_val; // 2byte
    GO = 1; //start conversion
    while (nDONE); //wait for conversion to complete
    adc_reg_val = (ADRESH << 8) | ADRESL;  // 11 1111 1111 -> 1023
    return adc_reg_val; // 0 to 1023
}
