#include <stdio.h>
int r;
int a(void);
int b(void);
int main(void)
{
    printf("ENTER THE NUMBER OF ROWS: ");
    scanf("%d",&r);
    a();b();
    return 0;
}
int a(void)
{
    int i,j,k;
    printf("\n[a]\n");
    for(i=1;i<=r;i++)
    {
        for(j=1;j<=(r-i);j++)
            printf(" ");
        for(k=1;k<=(2*i-1);k++)
                printf("%d",i);
        printf("\n");
    }
    return 0;
}
int b(void)
{
    char k;
    int i,j,j1,k1,m;
    printf("\n[b]\n");
    for(i=1,j1=1;i<=r;i++,j1++)
        for(k='a',k1=1;k1<=i;k++,k1++)
        {
            printf("%c",k);
            if(k1==i)
            {
                for(j=1;j1<=(r+2)-j;j++)
                    printf(" ");
                for(m=1;m<=i;m++)
                    printf("%c",k);
             printf("\n");
             break;
            }
        }
    return 0;
}
