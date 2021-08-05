#include <stdio.h>
int sum(int x);
int main(void)
{
    int n,ans;
    printf("ENTER THE NUMBER OF TERMS: ");
    scanf("%d",&n);
    ans=sum(n);
    printf("The sum is %d.",ans);
    return 0;
}
int sum(int x)
{
    if(x==0)
        return 0;
    else
        return sum(x-1)+(x+(x-1));
}
