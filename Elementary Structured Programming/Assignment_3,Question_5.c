#include <stdio.h>
int main(void)
{
    int j,n;
    float r,sum=1.0;
    printf("Enter the number of terms: ");
    scanf("%d",&n);
    printf("1");
    for(j=2;j<=(n-1);j++)
    {
            r=(float)j/(10*(float)j+1);
            if(j%2==0)
                {
                    printf("-%f",r);
                    sum=sum-r;
                }
            else
                {
                    printf("+%f",r);
                    sum=sum+r;
                }
    }
    r=(float)j/(10*(float)j+1);
    if(j%2==0)
    {
        printf("-%f=",r);
        sum=sum-r;
    }
    else
    {
        printf("+%f=",r);
        sum=sum+r;
    }
    printf(" %f",sum);
    return 0;

}
