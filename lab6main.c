/***************************************************************** 

    File: lab6main.c

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


int main(void) {
    int cents, q, d, n;
    printf("Enter the number of cents:\n");
    scanf("%d", &cents);
    makeChange(cents, &q, &d, &n);
    printf("Cents: %d, Quarters: %d, Dimes: %d, Nickles: %d\n", cents, q, d, n);

    char date[11];
    printf("Enter the date (dd/mm/yyyy):\n");
    scanf("%s", date);

    struct DateTime dt = {0};
    setDate(date, &dt);

    printf("Enter the hour and minute :\n");
    scanf("%d:%d", &dt.hour, &dt.minute);

    printDateTime(&dt);

    return 0;
}