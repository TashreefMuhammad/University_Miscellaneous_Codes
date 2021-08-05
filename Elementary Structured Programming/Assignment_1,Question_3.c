/*Write a program that asks the user for two angles of a triangle and display the third one.*/

#include<stdio.h>

int main(void)
{
    float x,y,z;

    printf("\nENTER TWO ANGLES OF A TRIANGLE (in degree unit): \n");
    scanf("%f%f",&x,&y);

    z=180-x-y;
    printf("\nTHE THIRD ANGLE OF THE TRIANGLE (in degree unit): %f\n",z);

    return 0;
}
