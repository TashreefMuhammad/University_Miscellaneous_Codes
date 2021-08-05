#include <stdio.h>
#include <math.h>
#include <vector>

using namespace std;

double horner_equ(double x);
double secant(double x1,double x2);

vector <int> vec;

int main(void)
{
    int n,a,i;
    double x1,x2;
    scanf("%d",&n);
    for(i=n;i>=0;i--)
    {
        printf("a%d = ",i);
        scanf("%d",&a);
        vec.push_back(a);
    }
    scanf("%lf %lf",&x1,&x2);

    printf("%lf",secant(x1,x2));
    return 0;
}
double horner_equ(double x)
{
    double out = vec[0];
    for(int i=1;i<vec.size();i++)
        out= out*x+(double)vec[i];
    return out;
}
double secant(double x1,double x2)
{
    double x,f,f1,f2;
    f1=horner_equ(x1);
    f2=horner_equ(x2);
    x=x2-f2*((x2-x1)/(f2-f1));
    while((fabs(x-x2)/x)>=0.00001)
    {
        f=horner_equ(x);
        x1=x2;
        f1=f2;
        x2=x;
        f2=f;
        x=x2-f2*((x2-x1)/(f2-f1));
    }
    return (x+x2)/2;
}
