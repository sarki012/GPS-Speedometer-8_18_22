/*
 * File:   display_lap.c
 * Author: eriks
 *
 * Created on August 2nd, 2020, 11:50 AM
 */

#include <xc.h>
#include <stdio.h>
#include <pic18f4520.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

/*
*RD4 = ID3 RD3 = ID2 RD2 = ID1 RD1 = ID0 RD0 = DP         
*/
#define ZERO_DECIMAL 0b000000001
#define ONE_DECIMAL 0b00000011
#define TWO_DECIMAL 0b00000101
#define THREE_DECIMAL 0b00000111
#define FOUR_DECIMAL 0b00001001
#define FIVE_DECIMAL 0b000001011
#define SIX_DECIMAL 0b000001101
#define SEVEN_DECIMAL 0b000001111
#define EIGHT_DECIMAL 0b000010001
#define NINE_DECIMAL 0b000010011

#define ZERO 0b00000010
#define ONE 0b00000010
#define TWO 0b00000100
#define THREE 0b00000110
#define FOUR 0b00001000
#define FIVE 0b00001010
#define SIX 0b00001100
#define SEVEN 0b00001110
#define EIGHT 0b00010000
#define NINE 0b00010010

/*
 * DA0 = RA0 DA1 = RA1 DA2 = RA2
 * D1  D2  D3  D4
 * 8 . 8 . 8 . 8
 */
#define DIGIT1 0b00000000
#define DIGIT2 0b00000001
#define DIGIT3 0b00000010
#define DIGIT4 0b00000011


void display_lap(int timer)
{
    double total_seconds = 0;
    int minutes = 0;
    int seconds = 0, seconds_right = 0, seconds_left = 0;
    int minutes_right = 0, minutes_left = 0;
    total_seconds = timer /3.8;
    seconds = seconds % 60;
    seconds_right = seconds % 10;
    seconds_left = seconds / 10;
    minutes = seconds/60;
    minutes_right = minutes % 10;
    minutes_left = minutes / 10;
    LATEbits.LATE0 = 0;     //Turn on common cathode colon
    switch (seconds_right)
    {
        case 0:
        LATEbits.LATE1 = 0;  
        LATA = DIGIT4;
        LATD = ZERO;
        LATEbits.LATE1 = 1;
        break;
        case 1:
        LATEbits.LATE1 = 0;  
        LATA = DIGIT4;            
        LATD = ONE;
        LATEbits.LATE1 = 1;
        break;
        case 2:
        LATEbits.LATE1 = 0;  
        LATA = DIGIT4;            
        LATD = TWO;
        LATEbits.LATE1 = 1;
        break;
        case 3:
        LATEbits.LATE1 = 0;  
        LATA = DIGIT4;            
        LATD = THREE;
        LATEbits.LATE1 = 1;
        break;
        case 4:
        LATEbits.LATE1 = 0;  
        LATA = DIGIT4;            
        LATD = FOUR;
        LATEbits.LATE1 = 1;
        break;
        case 5:
        LATEbits.LATE1 = 0;  
        LATA = DIGIT4;            
        LATD = FIVE;
        LATEbits.LATE1 = 1;
        break;
        case 6:
        LATEbits.LATE1 = 0;  
        LATA = DIGIT4;            
        LATD = SIX;
        LATEbits.LATE1 = 1;
        break;
        case 7:
        LATEbits.LATE1 = 0;  
        LATA = DIGIT4;            
        LATD = SEVEN;
        LATEbits.LATE1 = 1;            
        break;
        case 8:
        LATEbits.LATE1 = 0;  
        LATA = DIGIT4;            
        LATD = EIGHT;
        LATEbits.LATE1 = 1;            
        break;
        case 9:
        LATEbits.LATE1 = 0;  
        LATA = DIGIT4;            
        LATD = NINE;
        LATEbits.LATE1 = 1;            
        default :
        LATEbits.LATE1 = 0;  
        LATA = DIGIT4;            
        LATD = ZERO;
        LATEbits.LATE1 = 1;
        break;
    }
    
    switch (seconds_left)
    {
        case 0:
        LATEbits.LATE1 = 0;  
        LATA = DIGIT3;
        LATD = ZERO;
        LATEbits.LATE1 = 1;
        break;
        case 1:
        LATEbits.LATE1 = 0;  
        LATA = DIGIT3;            
        LATD = ONE;
        LATEbits.LATE1 = 1;
        break;
        case 2:
        LATEbits.LATE1 = 0;  
        LATA = DIGIT3;            
        LATD = TWO;
        LATEbits.LATE1 = 1;
        break;
        case 3:
        LATEbits.LATE1 = 0;  
        LATA = DIGIT3;            
        LATD = THREE;
        LATEbits.LATE1 = 1;
        break;
        case 4:
        LATEbits.LATE1 = 0;  
        LATA = DIGIT3;            
        LATD = FOUR;
        LATEbits.LATE1 = 1;
        break;
        case 5:
        LATEbits.LATE1 = 0;  
        LATA = DIGIT3;            
        LATD = FIVE;
        LATEbits.LATE1 = 1;
        break;
        case 6:
        LATEbits.LATE1 = 0;  
        LATA = DIGIT3;            
        LATD = SIX;
        LATEbits.LATE1 = 1;
        break;
        case 7:
        LATEbits.LATE1 = 0;  
        LATA = DIGIT3;            
        LATD = SEVEN;
        LATEbits.LATE1 = 1;            
        break;
        case 8:
        LATEbits.LATE1 = 0;  
        LATA = DIGIT3;            
        LATD = EIGHT;
        LATEbits.LATE1 = 1;            
        break;
        case 9:
        LATEbits.LATE1 = 0;  
        LATA = DIGIT3;            
        LATD = NINE;
        LATEbits.LATE1 = 1;                    
        default :
        LATEbits.LATE1 = 0;  
        LATA = DIGIT3;            
        LATD = ZERO;
        LATEbits.LATE1 = 1;           
        break;
    }
    switch (minutes_right)
    {
        case 0:
        LATEbits.LATE1 = 0;  
        LATA = DIGIT2;
        LATD = ZERO;
        LATEbits.LATE1 = 1;
        break;
        case 1:
        LATEbits.LATE1 = 0;  
        LATA = DIGIT2;            
        LATD = ONE;
        LATEbits.LATE1 = 1;
        break;
        case 2:
        LATEbits.LATE1 = 0;  
        LATA = DIGIT2;            
        LATD = TWO;
        LATEbits.LATE1 = 1;
        break;
        case 3:
        LATEbits.LATE1 = 0;  
        LATA = DIGIT2;            
        LATD = THREE;
        LATEbits.LATE1 = 1;
        break;
        case 4:
        LATEbits.LATE1 = 0;  
        LATA = DIGIT2;            
        LATD = FOUR;
        LATEbits.LATE1 = 1;
        break;
        case 5:
        LATEbits.LATE1 = 0;  
        LATA = DIGIT2;            
        LATD = FIVE;
        LATEbits.LATE1 = 1;
        break;
        case 6:
        LATEbits.LATE1 = 0;  
        LATA = DIGIT2;            
        LATD = SIX;
        LATEbits.LATE1 = 1;
        break;
        case 7:
        LATEbits.LATE1 = 0;  
        LATA = DIGIT2;            
        LATD = SEVEN;
        LATEbits.LATE1 = 1;            
        break;
        case 8:
        LATEbits.LATE1 = 0;  
        LATA = DIGIT2;            
        LATD = EIGHT;
        LATEbits.LATE1 = 1;            
        break;
        case 9:
        LATEbits.LATE1 = 0;  
        LATA = DIGIT2;            
        LATD = NINE;
        LATEbits.LATE1 = 1;                    
        default :
        LATEbits.LATE1 = 0;  
        LATA = DIGIT2;            
        LATD = ZERO;
        LATEbits.LATE1 = 1;           
        break;
    }
    if(minutes_left == 0)
        return;
    switch (minutes_left)
    {
        case 0:
        LATEbits.LATE1 = 0;  
        LATA = DIGIT1;
        LATD = ZERO;
        LATEbits.LATE1 = 1;
        break;
        case 1:
        LATEbits.LATE1 = 0;  
        LATA = DIGIT1;            
        LATD = ONE;
        LATEbits.LATE1 = 1;
        break;
        case 2:
        LATEbits.LATE1 = 0;  
        LATA = DIGIT1;            
        LATD = TWO;
        LATEbits.LATE1 = 1;
        break;
        case 3:
        LATEbits.LATE1 = 0;  
        LATA = DIGIT1;            
        LATD = THREE;
        LATEbits.LATE1 = 1;
        break;
        case 4:
        LATEbits.LATE1 = 0;  
        LATA = DIGIT1;            
        LATD = FOUR;
        LATEbits.LATE1 = 1;
        break;
        case 5:
        LATEbits.LATE1 = 0;  
        LATA = DIGIT1;            
        LATD = FIVE;
        LATEbits.LATE1 = 1;
        break;
        case 6:
        LATEbits.LATE1 = 0;  
        LATA = DIGIT1;            
        LATD = SIX;
        LATEbits.LATE1 = 1;
        break;
        case 7:
        LATEbits.LATE1 = 0;  
        LATA = DIGIT1;            
        LATD = SEVEN;
        LATEbits.LATE1 = 1;            
        break;
        case 8:
        LATEbits.LATE1 = 0;  
        LATA = DIGIT1;            
        LATD = EIGHT;
        LATEbits.LATE1 = 1;            
        break;
        case 9:
        LATEbits.LATE1 = 0;  
        LATA = DIGIT1;            
        LATD = NINE;
        LATEbits.LATE1 = 1;                    
        default :
        LATEbits.LATE1 = 0;  
        LATA = DIGIT1;            
        LATD = ZERO;
        LATEbits.LATE1 = 1;           
        break;
    }
return;
}


