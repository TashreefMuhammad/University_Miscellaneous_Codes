#include <stdio.h>
#include <string.h>
int main(void)
{
    char st[50];
    int i,j,a,flag=1;
    printf("Please enter a string (within 50 characters): ");
    gets(st);
    a=strlen(st);
    for(i=0,j=(a-1);;i++,j--)
    {
        if(a%2==0)
        {
            if(st[i]!=st[j])
            {
                flag=0;break;
            }
            if(i==(j-1))
                break;
        }
        else
        {
          if(st[i]!=st[j])
            {
                flag=0;break;
            }
            if(i==j)
                break;
        }
    }
    if(flag==0)
        printf("String is not palindrome.");
    else
        printf("String is a palindrome.");
    return 0;
}
