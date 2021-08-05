#include <stdio.h>

int main(void)
{
    int n,i,r,sw,sf,sd;
    sw=sf=sd=0;

    printf("\nENTER THE NUMBER OF TERMS: ");
    scanf("%d",&n);

    i=1;
    while(i<=n)
    {
        r=(i+1)*(i+2);
        sw=sw+r;
        i++;
    }

    for(i=1;i<=n;i++)
    {
        r=(i+1)*(i+2);
        sf=sf+r;
    }

    i=1;
    do
    {
        r=(i+1)*(i+2);
        sd=sd+r;
        i++;
    }while(i<=n);

    if((sw==sf)&&(sf==sd))
        printf("\nTHE LOOPS ARE CORRECT AND THE ANSWER IS %d\n",sd);
    else
        printf("\nSomething Wrong.\n");

    return 0;
}
