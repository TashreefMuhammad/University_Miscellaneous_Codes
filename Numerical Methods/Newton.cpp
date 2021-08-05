#include <stdio.h>
#include <math.h>

int n;

double horner_equ(double x,double ar[]);
double derive_equ(double x,double ar[]);
void deflat_equ(double x,double ar[]);
void newton_met(double x,double ar[]);

int main(void)
{
    int a,i;
    scanf("%d",&n);
    double x,ar[n+1];
    for(i=n;i>=0;i--)
    {
        printf("a%d = ",i);
        scanf("%lf",&ar[i]);
    }
    scanf("%lf",&x);

    newton_met(x,ar);
    return 0;
}
double horner_equ(double x,double ar[])
{
    double out = ar[n];
    for(int i=n-1;i>=1;i--)
        out= out*x+ar[i];
    return out;
}
double derive_equ(double x,double ar[])
{
    double out = ar[n]*n;
    for(int i=n-1;i>=0;i--)
        out = out*x+(double)ar[i]*(n-i);
    return out;
}
void deflat_equ(double x,double ar[])
{
    double b[n+1];
    int i;
    b[n]=0;
    for(i=n-1;i>=0;i--)
        b[i]=ar[i+1]+x*b[i+1];
    for(i=n-1;i>=0;i--)
        ar[i]=b[i];
    n--;
}
void newton_met(double x,double ar[])
{
    double x1,f,fd;
    int i=0;
    f=horner_equ(x,ar);
    fd=derive_equ(x,ar);
    x1=x-(f/fd);

    while(n>1)
    {
        while(fabs((x1-x)/x1)>=0.00000000001)
        {
            x=x1;
            f=horner_equ(x,ar);
            fd=derive_equ(x,ar);
            x1=x-(f/fd);
        }
        deflat_equ((x1+x)/2.0,ar);
        printf("Root %d: %lf\n",++i,(x1+x)/2.0);
        x=(x1+x)/2.0;
    }
    printf("Root %d: %lf",++i,-(ar[0]/ar[1]));
}
