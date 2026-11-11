/***************************************************************** 

    File: lab6.c

    Author: [ihab yehia]
    Seneca email: [iyehia1@myseneca.ca]

    To compile program in codespaces, in terminal pane type:
        gcc -Wall lab6.c lab6main.c
    To run program in codespaces, in terminal pane type:
        ./a.out
        
***************************************************************/
//Uncomment the next line if you are using Visual Studio
//#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "lab6.h"

void makeChange(int cents, int* quarters, int* dimes, int* nickels){

    int last = cents % 10;

    if(last == 1 || last == 2 ){
     cents = cents - last;
    }

    else if(last == 6 || last == 7){
cents = cents - (last%5);
    }

    else if(   last == 3 || last == 4 ){
  cents = cents +(5 - last );
    }

    else if ( last == 8 || last == 9){
     cents = cents +(10 - last);
    }

   else {
    cents = cents;
   }

   *quarters = cents/25;
   cents = cents % 25;
   *dimes = cents/10;
   cents = cents%10;
   *nickels = cents/5;

}


void setDate(const char dateString[], struct DateTime* dt) {
    dt->day   = (dateString[0]-'0')*10 + (dateString[1]-'0');
    dt->month = (dateString[3]-'0')*10 + (dateString[4]-'0');
    dt->year  = (dateString[6]-'0')*1000 + (dateString[7]-'0')*100
               + (dateString[8]-'0')*10 + (dateString[9]-'0');

    dt->hour = 0;
    dt->minute = 0;
}

void printDateTime(const struct DateTime* dt) {
    char* months[12] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    int hour = dt->hour;
    int minute = dt->minute;
    char* period = "am";

    if (hour >= 12) {
        period = "pm";
        if (hour > 12) hour -= 12;
    } else if (hour == 0) {
        hour = 12;
    }

    printf("%s %d, %d %d:%02d %s\n",
           months[dt->month - 1],
           dt->day,
           dt->year,
           hour,
           minute,
           period);
}