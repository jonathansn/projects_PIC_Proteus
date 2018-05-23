
// PIC16F877A Configuration Bit Settings

// 'C' source line config statements

// CONFIG
#pragma config FOSC = XT        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = ON         // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3/PGM pin has PGM function; low-voltage programming enabled)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#include <pic16f877a.h>

#define _XTAL_FREQ 4000000
#define desloca 1
#define inv RB3

void blink(int inv);
void sq1(int inv);
void sq2(int inv);
void sq3(int inv);

void main(void) {
    CMCON = 7;
    TRISB = 0;
    PORTB = 0;
    
    TRISD = 0;
    PORTD = 0b00000001;
    
    while(1){
        if(RB0 == 1){
            sq1(inv);
        }
        if(RB1 == 1){
            sq2(inv);
        }
        if(RB2 == 1){
            sq3(inv);
        }
        else{
            blink(inv);
        }        
    }
    
}

void blink(int inv){
    if(inv == 0){
        __delay_ms(1000);
        if(PORTD == 8)
        PORTD = desloca;
        else{
            PORTD <<= desloca;
        }
    } else {
        __delay_ms(1000);
        if(PORTD == 1)
        PORTD = 8;
        else{
            PORTD >>= desloca;
        }
    }
}
void sq1(int inv){
    if(inv == 0){
        PORTD = 0;
        RD0 = 1;
        __delay_ms(1000);
        RD0 = 0;
        RD2 = 1;
        __delay_ms(1000);
        RD2 = 0;
        RD3 = 1;
        __delay_ms(1000);
        RD3 = 0;
        RD1 = 1;
        __delay_ms(1000);
    } else {
        PORTD = 0;
        RD1 = 1;
        __delay_ms(1000);
        RD1 = 0;
        RD3 = 1;
        __delay_ms(1000);
        RD3 = 0;
        RD2 = 1;
        __delay_ms(1000);
        RD2 = 0;
        RD0 = 1;
        __delay_ms(1000);
    }
}
void sq2(int inv){
    if(inv == 0){
        PORTD = 0;
        RD3 = 1;
        __delay_ms(1000);
        RD3 = 0;
        RD1 = 1;
        __delay_ms(1000);
        RD1 = 0;
        RD0 = 1;
        __delay_ms(1000);
        RD0 = 0;
        RD2 = 1;
        __delay_ms(1000);
    } else {
        PORTD = 0;
        RD2 = 1;
        __delay_ms(1000);
        RD2 = 0;
        RD0 = 1;
        __delay_ms(1000);
        RD0 = 0;
        RD1 = 1;
        __delay_ms(1000);
        RD1 = 0;
        RD3 = 1;
        __delay_ms(1000);
    }
}
void sq3(int inv){
    if(inv == 0){
        PORTD = 0;
        RD3 = 1;
        RD0 = 1;
        __delay_ms(1000);
        RD3 = 0;
        RD0 = 0;
        RD1 = 1;
        RD2 = 1;
        __delay_ms(1000);
        RD1 = 0;
        RD2 = 0;
        RD3 = 1;
        __delay_ms(1000);
    } else {
        PORTD = 0;
        RD3 = 1;
        __delay_ms(1000);
        RD3 = 0;
        RD1 = 1;
        RD2 = 1;
        __delay_ms(1000);
        RD1 = 0;
        RD2 = 0;
        RD3 = 1;
        RD0 = 1;
        __delay_ms(1000);
    }
}