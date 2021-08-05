#include <stdio.h>
int main(void)
{
    int i,j,k,a=0;
    for(i=1;i<=1000;i++)
        for(j=(i+1);j<=1000;j++)
            for(k=(j+1);k<=1000;k++)
            {
                a=a+1;
                if(((i*i)+(j*j))!=(k*k))
                    continue;
                else
                    printf("\nTriplets are %d, %d & %d and the equation stands %d+ %d = %d",i,j,k,i*i,j*j,k*k);
            }
    printf("\n Computational Cost: %d",a);
    return 0;
}
