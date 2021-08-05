#include <stdio.h>
int main(void)
{
    int i,j,k,l;
    printf("How many numbers to be taken to make list? ");
    scanf("%d",&l);
    int al[l+1];
    for(i=0;i<l;i++)
        scanf("%d",&al[i]);
    printf("The given list of integers are: {");
    for(i=0;i<l;i++)
    {
            if(i==l-1)
                printf("%d}",al[i]);
            else
                printf("%d, ",al[i]);
    }
    printf("\nIn which position you want to input your number? ");
    scanf("%d",&k);
    printf("Which Number do you want to input? ");
    scanf("%d",&j);
    for(i=l;i>=(k-1);i--)
        al[i+1]=al[i];
    al[k-1]=j;
    printf("The new list if integers is: {");
    for(i=0;i<=l;i++)
    {
            if(i==l)
                printf("%d}",al[i]);
            else
                printf("%d, ",al[i]);
    }
    return 0;
}
