#include <stdio.h>
int main(void)
{
    int n,i,j=-1,sn=0,se=0,so=0;
    printf("How many integer numbers to be taken? ");
    scanf("%d",&n);
    int num[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&num[i]);
        if(num[i]<0)
            sn=sn+num[i];
        else
        {
            if(num[i]==0)
                {j=0;break;}
            else if(num[i]%2==0)
                se=se+num[i];
            else
                so=so+num[i];
        }
    }
    if(j==0)
        printf("\nSorry! You have given the input 0 which could not be classified.\n");
    else
        printf("\nSum of negative numbers= %d\nSum of positive even numbers= %d\nSum of positive odd numbers= %d\n",sn,se,so);
        return 0;

}
