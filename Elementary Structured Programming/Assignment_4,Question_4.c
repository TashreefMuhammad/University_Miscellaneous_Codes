#include <stdio.h>
#include <string.h>
int main(void)
{
    char st1[51],st2[51];
    int i,j=0,a,b;
    printf("Enter a string (within 50 characters): ");
    gets(st1);
    printf("Enter another string (within 50 characters): ");
    gets(st2);
    a=strlen(st1);
    b=strlen(st2);
    for(i=0;(i!=a)||(i!=b);i++)
    {
        if(st1[i]>st2[i])
        {
            j=1;break;
        }
        if(st1[i]<st2[i])
        {
            j=-1;break;
        }
    }
    if(j==1)
        printf("The returned value is 1. So, first string is bigger in code than second.");
    else if(j==-1)
        printf("The returned value is -1. So, second string is bigger in code than first.");
    else
        printf("The returned value is 0. So, the two strings are same.");
    return 0;
}
