/*
 * File:   parse_west.c
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

double west = 0;
int decimal_flag = 0;
void display_slow(int a);
void display_fast(int b);
double parse_west(char *nmea_string)
{
    while (*nmea_string != '*')
    {
        if(*nmea_string == 'N' || *nmea_string == 'S')
        {
            nmea_string++;
            nmea_string++;
            switch (*nmea_string)
            {
                case '0': west = 0;
                break;
                case '1': west = 1000;
                break;
                case '2': west = 2000;
                break;
                case '3': west = 3000;
                break;
                case '4': west = 4000;
                break;
                case '5': west = 5000;
                break;
                case '6': west = 6000;
                break;
                case '7': west = 7000;
                break;
                case '8': west = 8000;
                break;
                case '9': west = 9000;
                break;
                default : west = 0;
                break;
            } 
            nmea_string++;
            switch (*nmea_string)
            {

                case '0': west += 0;
                break;
                case '1': west += 100;
                break;
                case '2': west += 200;
                break;
                case '3': west += 300;
                break;
                case '4': west += 400;
                break;
                case '5': west += 500;
                break;
                case '6': west += 600;
                break;
                case '7': west += 700;
                break;
                case '8': west += 800;
                break;
                case '9': west = 900;
                break;
                default : west += 0;
                break;
            } 
            nmea_string++;
            switch (*nmea_string)
            {

                case '0': west += 0;
                break;
                case '1': west += 10;
                break;
                case '2': west += 20;
                break;
                case '3': west += 30;
                break;
                case '4': west += 40;
                break;
                case '5': west += 50;
                break;
                case '6': west += 60;
                break;
                case '7': west += 70;
                break;
                case '8': west += 80;
                break;
                case '9': west += 90;
                break;
                default : west += 0;
                break;
            }        
            nmea_string++;
            switch (*nmea_string)
            {

                case '0': west += 0;
                break;
                case '1': west += 1;
                break;
                case '2': west += 2;
                break;
                case '3': west += 3;
                break;
                case '4': west += 4;
                break;
                case '5': west += 5;
                break;
                case '6': west += 6;
                break;
                case '7': west += 7;
                break;
                case '8': west += 8;
                break;
                case '9': west += 9;
                break;
                default : west += 0;
                break;
            } 
            nmea_string++;      //skipping over the decimal point
            nmea_string++;
            switch (*nmea_string)
            {

                case '0': west += 0;
                break;
                case '1': west += 0.1;
                break;
                case '2': west += 0.2;
                break;
                case '3': west += 0.3;
                break;
                case '4': west += 0.4;
                break;
                case '5': west += 0.5;
                break;
                case '6': west += 0.6;
                break;
                case '7': west += 0.7;
                break;
                case '8': west += 0.8;
                break;
                case '9': west += 0.9;
                break;
                default : west += 0;
                break;
            }       
            nmea_string++;
            switch (*nmea_string)
            {

                case '0': west += 0;
                break;
                case '1': west += 0.01;
                break;
                case '2': west += 0.02;
                break;
                case '3': west += 0.03;
                break;
                case '4': west += 0.04;
                break;
                case '5': west += 0.05;
                break;
                case '6': west += 0.06;
                break;
                case '7': west += 0.07;
                break;
                case '8': west += 0.08;
                break;
                case '9': west += 0.09;
                break;
                default : west += 0;
                break;
            }                   
            return west;
        }
        
        nmea_string++;
    }
    return west;
}


