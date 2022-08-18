/*
 * File:   parse_north.c
 * Author: eriks
 *
 * Created on May 28, 2020, 8:58 PM
 */

#include <xc.h>
#include <stdio.h>
#include <pic18f4520.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int average_buffer = 0;
int k = 0;

double north = 0;
int decimal_flag = 0;
void display_slow(int a);
void display_fast(int b);
double parse_north(char *nmea_string)
{
    while (*nmea_string != '*')
    {
        if(*nmea_string == 'A')
        {
            nmea_string++;
            nmea_string++;
            switch (*nmea_string)
            {
                case '0': north = 0;
                break;
                case '1': north = 1000;
                break;
                case '2': north = 2000;
                break;
                case '3': north = 3000;
                break;
                case '4': north = 4000;
                break;
                case '5': north = 5000;
                break;
                case '6': north = 6000;
                break;
                case '7': north = 7000;
                break;
                case '8': north = 8000;
                break;
                case '9': north = 9000;
                break;
                default : north = 0;
                break;
            } 
            nmea_string++;
            switch (*nmea_string)
            {

                case '0': north += 0;
                break;
                case '1': north += 100;
                break;
                case '2': north += 200;
                break;
                case '3': north += 300;
                break;
                case '4': north += 400;
                break;
                case '5': north += 500;
                break;
                case '6': north += 600;
                break;
                case '7': north += 700;
                break;
                case '8': north += 800;
                break;
                case '9': north += 900;
                break;
                default : north += 0;
                break;
            } 
            nmea_string++;
            switch (*nmea_string)
            {

                case '0': north += 0;
                break;
                case '1': north += 10;
                break;
                case '2': north += 20;
                break;
                case '3': north += 30;
                break;
                case '4': north += 40;
                break;
                case '5': north += 50;
                break;
                case '6': north += 60;
                break;
                case '7': north += 70;
                break;
                case '8': north += 80;
                break;
                case '9': north += 90;
                break;
                default : north += 8;
                break;
            }        
            nmea_string++;
            switch (*nmea_string)
            {

                case '0': north += 0;
                break;
                case '1': north += 1;
                break;
                case '2': north += 2;
                break;
                case '3': north += 3;
                break;
                case '4': north += 4;
                break;
                case '5': north += 5;
                break;
                case '6': north += 6;
                break;
                case '7': north += 7;
                break;
                case '8': north += 8;
                break;
                case '9': north += 9;
                break;
                default : north += 0;
                break;
            } 
            nmea_string++;      //skipping over the decimal point
            nmea_string++;
            switch (*nmea_string)
            {

                case '0': north += 0;
                break;
                case '1': north += 0.1;
                break;
                case '2': north += 0.2;
                break;
                case '3': north += 0.3;
                break;
                case '4': north += 0.4;
                break;
                case '5': north += 0.5;
                break;
                case '6': north += 0.6;
                break;
                case '7': north += 0.7;
                break;
                case '8': north += 0.8;
                break;
                case '9': north += 0.9;
                break;
                default : north += 0;
                break;
            }       
            nmea_string++;
            switch (*nmea_string)
            {

                case '0': north += 0;
                break;
                case '1': north += 0.01;
                break;
                case '2': north += 0.02;
                break;
                case '3': north += 0.03;
                break;
                case '4': north += 0.04;
                break;
                case '5': north += 0.05;
                break;
                case '6': north += 0.06;
                break;
                case '7': north += 0.07;
                break;
                case '8': north += 0.08;
                break;
                case '9': north += 0.09;
                break;
                default : north += 0;
                break;
            }                   
            return north;
        }
        
        nmea_string++;
    }
    return north;
}

