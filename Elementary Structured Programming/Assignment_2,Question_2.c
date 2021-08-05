#include <stdio.h>

int main(void)
{
    int SumT=0,SumX7=0,Sum7=0,n,i;

    printf("\nEnter the value of n: ");
    scanf("%d",&n);

    for(i=0;i<=n;i++)
        SumT=SumT+i;   //SumT+=i;

    i=7;
    while(i<=n)
    {
        Sum7+=i;     //Sum7=Sum7+i;
        i+=7;        //i=i+7;
    }

    i=1;

    do
    {
        if(i%7!=0)
            SumX7+=i;
            i++;
    }while(i<=n);

    if(SumT==Sum7+SumX7)
        printf("The result is %d and it is correct",SumX7);
    else
        printf("It is wrong");

    return 0;
}
