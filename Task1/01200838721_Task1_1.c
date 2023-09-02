/*
* file: 01200838721_Task1_1.c
* Author: Menna Elmahdy
* Description: Printing GRU to screen
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    //Array the contain no. of * and spaces needed to print the word GRU sequentially
    int arr[5][11] = { {5, 2, 4, 4, 1, 4, 1, 0, 0, 0, 0},
                       {1, 6, 1, 3, 1, 3, 1, 4, 1, 0, 0},
                       {1, 2, 2, 2, 4, 4, 1, 4, 1, 0, 0},
                       {1, 3, 1, 2, 1, 3, 1, 3, 1, 4, 1},
                       {5, 2, 1, 4, 1, 2, 6, 0, 0, 0, 0}
                    };

    //Initializing and Declaring variables that would be needed in printing
    int drawing = 0, space = 0;
    bool isdrawing;


    for(int i = 0; i < 5; i ++)
    {
        //checking for drawing * state
        isdrawing = false;
        for(int j = 0; j < 11; j ++)
        {
            //if you were drawing in previous iteration stop if not draw
            drawing = (isdrawing? 0 : arr[i][j]);
            //if you were printing spaces in previous iteration stop if not start again
            space = (isdrawing? arr[i][j] : 0);

            //if done drawing * and printing spaces for this line continue;
            if(drawing == 0 && space == 0)  continue;

            //draw * till drawing variable is 0
            while(drawing)
            {
                printf("*");
                -- drawing;
            }

            //print white spaces till space variable is 0
            while(space)
            {
                printf(" ");
                -- space;
            }

            //change state of isdrawing
            isdrawing = !isdrawing;
        }

        //go to next line
        printf("\n");
    }


    return 0;
}

