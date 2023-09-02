/*
* file: 01200838721_Task1_4.c
* Author: Menna Elmahdy
* Description: Kalman Missile
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    //Initializing arrays of measurements from two sensors
    float mpu_sensor[10] = {0.0, 11.68, 18.95, 23.56, 25.72, 25.38, 22.65, 18.01, 10.14, -0.26};
    float bno_sensor[10] = {0.0, 9.49, 16.36, 21.2, 23.16, 22.8, 19.5, 14.85, 6.79, -2.69};

    //Assigning sensors accuracy and Declaring other essential variables
    float mpu_acc = 0.78, bno_acc = 0.92, kg, EST[10];

    //calculating variance of each sensor
    float mpu_variance = 1 - mpu_acc;
    float bno_variance = 1 - bno_acc;

    //calculating kalman gain
    kg = bno_variance / (bno_variance + mpu_variance);

    printf("Estimated Values: \n");
    for(int i = 0; i < 10; i ++)
    {
        //calculating estimated values
        EST[i] = bno_sensor[i] + kg * (mpu_sensor[i] - bno_sensor[i]);
        printf("\t%d : %f\n", (i+1), EST[i]);
    }

    return 0;
}


