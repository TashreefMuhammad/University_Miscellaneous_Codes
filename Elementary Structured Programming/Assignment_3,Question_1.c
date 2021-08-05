#include <stdio.h>
int main(void)
{
    int a,b,c,n,i;
    printf("How many times repeat? ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        printf("\nENTER AN INTEGER [20-99]: ");
        scanf("%d",&a);
        if(a>=20&&a<=99)
        {
            b=a/10;
            c=a%10;
            printf("\nIn words: ");
            switch(b)
            {
                case 2: printf("Twenty");
                        break;
                case 3: printf("Thirty");
                        break;
                case 4: printf("Forty");
                        break;
                case 5: printf("Fifty");
                        break;
                case 6: printf("Sixty");
                        break;
                case 7: printf("Seventy");
                        break;
                case 8: printf("Eighty");
                        break;
                default: printf("Ninety");
                        break;
            }
            switch(c)
            {
                case 1: printf(" one");
                        break;
                case 2: printf(" two");
                        break;
                case 3: printf(" three");
                        break;
                case 4: printf(" four");
                        break;
                case 5: printf(" five");
                        break;
                case 6: printf(" six");
                        break;
                case 7: printf(" seven");
                        break;
                case 8: printf(" eight");
                        break;
                case 9: printf(" nine");
                        break;
                default:break;
            }
        }
        else
            printf("Wrong Entry");

    }

    return 0;
}

