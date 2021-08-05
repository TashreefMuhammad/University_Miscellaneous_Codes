#include <stdio.h>

int main(void)
{
    int r,n,s=0;

    printf("Enter the number: ");
    scanf("%d",&n);

    if (n<=32767&&n>0)
    {
        do
        {
            r=n%10;
            s=s+r;
            n=n/10;
        }while(n!=0);
        printf("The sum is %d",s);
    }
    else
        printf("Wrong Entry!!");


    return 0;
}
