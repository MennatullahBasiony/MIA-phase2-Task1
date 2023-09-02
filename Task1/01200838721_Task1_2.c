/*
* file: 01200838721_Task1_2.c
* Author: Menna Elmahdy
* Description: Counting Down program
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void delay(int secs);

int main()
{
    //take number from user for count down
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    for(int i = number; i > 0; i --)
    {
        printf("%d\n", i);  //printing i in count down form
        delay(1);   //wait for a second
    }

    printf("\nBlast off to the Moon!\n");


    return 0;
}

void delay(int secs)
{
    // Converting time to milli seconds
    int msec = 1000 * secs;

    // Storing start time
    clock_t startTime = clock();

    //stuck in loop till time is finished
    while (clock() < startTime + msec);

}

