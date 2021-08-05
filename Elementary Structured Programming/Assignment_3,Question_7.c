#include <stdio.h>
int main(void)
{
    int n,i,j,k;
    printf("Enter the number of terms: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        if(i==1)
            printf("(1)");
        if(i>1&&i<=n)
        {
            printf(" + (");
            for(j=1;j<=i;j++)
            {
                if(j<i)
                    printf("%d+",j);
                else
                    printf("%d)",j);
            }
        }
    }
    return 0;

}
