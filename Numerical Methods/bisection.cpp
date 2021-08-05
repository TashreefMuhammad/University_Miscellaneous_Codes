#include <stdio.h>
#include <math.h>

double hornerequation(int n,double x,double a[]);
double bisection(double x1,double x2,int n,double a[]);

int main(void)
{
    int i,n;
    printf("Enter the highest order of polynomial equation: ");
    scanf("%d",&n);
    double a[n+1];
    printf("Please provide value of following co-efficients:\n");
    for(i=n;i>=0;i--)
    {
        printf("a%d : ",i);
        scanf("%lf",&a[i]);
    }
    printf("So the horner's rule equation of the given polynomial:\n");
    for(i=0;i<n-1;i++)
        printf("(");
    printf("%fx",a[n]);
    for(i=n-1;i>0;i--)
    {
        if(a[i]>=0)
            printf("+%f)x",a[i]);
        else
            printf("-%f)x",-a[i]);
    }
    if(a[i]>=0)
        printf("+%f = 0\n\n",a[0]);
    else
        printf("-%f = 0\n\n",-a[0]);
    double x=fabs(sqrt((pow(a[n-1]/a[n],2))-2.0*(a[n-2]/a[n])));
    x=bisection(x,-x,n,a);
    printf("%f is the solution root.",x);

    return 0;
}

double hornerequation(int n,double x,double a[])
{
    double result=a[n];
    int i;
    for(i=n-1;i>=0;i--)
        result=result*x+a[i];

    return result;
}

double bisection(double x1,double x2,int n,double a[])
{
    double x0,f0,f1,f2;
    f1=hornerequation(n,x1,a);
    f2=hornerequation(n,x2,a);
    printf("Iteration\tx2\t\tx1\t\tx0\t\tf2\t\tf1\t\tf0\t\tError\n");
    int i=0;
    while(abs((x2-x1)/x2)>=0.0001)
    {
        x0=(x1+x2)/2.0;
        f0=hornerequation(n,x0,a);
        printf("%d\t\t%f\t%f\t%f\t%f\t%f\t%f\t%f\n",++i,x2,x1,x0,f2,f1,f0,abs((x2-x1)/x2));
        if(f0==0)
        {
            x2=x1=x0;
            break;
        }
        else if(f2*f0<0)
        {
            x1=x0;
            f1=hornerequation(n,x1,a);
        }
        else
        {
            x2=x0;
            f2=hornerequation(n,x2,a);
        }
    }
    printf("Final Error: %f\n",fabs((x2-x1)/x2));

    return (x1+x2)/2.0;
}
