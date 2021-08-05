#include <stdio.h>
#include <math.h>
#include <vector>

using namespace std;

double horner_equ(double x);
double derive_equ(double x);
double newton_raphson(double x);

vector <int> vec;

int main(void)
{
    int n,x,a,i;
    scanf("%d",&n);
    for(i=n;i>=0;i--)
    {
        printf("a%d = ",i);
        scanf("%d",&a);
        vec.push_back(a);
    }
    scanf("%lf",&x);

    printf("%lf",newton_raphson(x));
    return 0;
}
double horner_equ(double x)
{
    double out = vec[0];
    for(int i=1;i<vec.size();i++)
        out= out*x+vec[i];
    return out;
}
double derive_equ(double x)
{
    double out = vec[0]*(vec.size()-1);
    for(int i=1;i<vec.size()-1;i++)
        out = out*x+(double)vec[i]*(vec.size()-1-i);
    return out;
}
double newton_raphson(double x)
{
    double x1,f,fd;
    f=horner_equ(x);
    fd=derive_equ(x);
    x1=x-(f/fd);
    while(fabs((x1-x)/x1)>=0.00001)
    {
        x=x1;
        f=horner_equ(x);
        fd=derive_equ(x);
        x1=x-(f/fd);
    }
    return (x1+x)/2;
}
