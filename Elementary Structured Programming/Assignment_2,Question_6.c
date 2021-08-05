#include <stdio.h>

int main(void)
{
    int i,fact=1;
    float sumPrev=0.0,sumNew=0.0;

    i=1;
    do
    {
        sumPrev=sumNew;
        fact=fact*i;
        i++;
        sumNew=sumNew+(1/(float)fact);
    }while((sumNew-sumPrev)>=0.001);

    printf("\nThe sum is %f\n",sumNew);

    return 0;
}
