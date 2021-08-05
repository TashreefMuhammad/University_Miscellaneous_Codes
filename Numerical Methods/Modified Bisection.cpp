#include <stdio.h>
#include <math.h>

double hornerequation(int n,double x,double a[]);
void modifiedbisection(double a,double b,int n,double ar[]);

int main(void)
{
    int i,n;
    printf("Enter the highest order of polynomial equation: ");
    scanf("%d",&n);
    double x1,x2,ar[n+1];
    printf("Please provide value of following co-efficients:\n");
    for(i=n;i>=0;i--)
    {
        printf("a%d : ",i);
        scanf("%lf",&ar[i]);
    }
    printf("Enter the lower limit of search: ");
    scanf("%lf",&x1);
    printf("Enter the higher limit of search: ");
    scanf("%lf",&x2);
    modifiedbisection(x1,x2,n,ar);

    return 0;
}

double hornerequation(int n,double x,double ar[])
{
    double result=ar[n];
    int i;
    for(i=n-1;i>=0;i--)
        result=result*x+ar[i];

    return result;
}

void modifiedbisection(double a,double b,int n,double ar[])
{
    double x0,f0,f1,f2,x1,x2,dx=0.0001;
    int i=0;
    x2=a;
    while(x2<b)
    {
        i++;
        a=x2;
        x1=a;
        x2=x1+dx;
        f1=hornerequation(n,x1,ar);
        f2=hornerequation(n,x2,ar);
        while(fabs((x2-x1)/x2)>=0.00000001)
        {
            if(f1*f2>0)
                break;
            x0=(x1+x2)/2.0;
            f0=hornerequation(n,x0,ar);
            printf("\n%d\t%f\t%f\t%f\t%f\t%f\t%f\t%f\n",i,x2,x1,x0,f2,f1,f0,fabs((x2-x1)/x2));
            if(f0==0)
            {
                x2=x1=x0;
                break;
            }
            else if(f2*f0<0)
            {
                x1=x0;
                f1=hornerequation(n,x1,ar);
            }
            else
            {
                x2=x0;
                f2=hornerequation(n,x2,ar);
            }
        }
        if(fabs((x2-x1)/x2)<0.00000001)
        {
            printf("Error %d: %f\n",i,fabs((x2-x1)/x2));
            printf("Root %d: %f\n",i,(x1+x2)/2.0);
        }
    }
}
