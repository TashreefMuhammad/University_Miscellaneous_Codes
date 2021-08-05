/*Write a program that receives as input through keyboard the measurement of length and breadth of a rectangular
piece of land in feet and display on the monitor the area of the land in square meter, taking 1ft=0.3048m.
Arrange input and output with appropriate text messages*/

#include<stdio.h>

int main(void)
{
    float l,b;
    double lm,bm,area;

    printf("\nENTER THE LENGTH OF LAND (in feet unit): ");
    scanf("%f",&l);
    printf("\nENTER THE BREADTH OF LAND (in feet unit): ");
    scanf("%f",&b);

    lm=l*0.3048;
    bm=b*0.3048;
    area=lm*bm;

    printf("\nTHE AREA OF THE LAND (in square meter): ");

    return 0;
}
