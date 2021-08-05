/*Write a multifunction program to find the sum of first 'n' terms of a series of natural numbers (positive integers).
Your program must ask in 'main' function for the 'nth' term of the series. Even though the calculation to find the sum
will be done in a user-defined function, the result will be displayed from the 'main' function*/

#include<stdio.h>

int sumcalc(int x);

int main(void)
{
    int n,sum;

    printf("\nENTER THE nth TERM OF THE SERIES: ");
    scanf("%d",&n);

    sum=sumcalc(n);
    printf("\nTHE SUM OF THE SERIES IS %d\n",sum);

    return 0;
}

int sumcalc(int x)
{
    int t;
    t=(x*(x+1))/2;

    return t;
}
