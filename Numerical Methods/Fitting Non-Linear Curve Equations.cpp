#include <stdio.h>
#include <math.h>

int main(void)
{
    int i,n;
    double x,y,xy,x2,a,b;

    printf("Enter the number of points for input: ");
    scanf("%d",&n);

    double stx[n],sty[n];

    for(i=0;i<n;i++)
    {
        printf("The %d no point:\n",i);
        printf("\tx: ");
        scanf("\t%lf",&stx[i]);
        printf("\ty: ");
        scanf("%lf",&sty[i]);
        printf("\n");
    }


    ///Applying the formula from collected input

    x=y=xy=x2=0;

    for(i=0;i<n;i++)
    {
        x+=log(stx[i]);
        y+=log(sty[i]);
        xy+=log(stx[i])*log(sty[i]);
        x2+=log(stx[i])*log(stx[i]);
    }

    b=(n*xy-x*y)/(n*x2-x*x);
    a=(y-b*x)/n;

    a = exp(a);

    printf("Found values:\n");
    printf("a = %lf\tb = %lf\n\n",a,b);

    printf("So, the linear equation is:\n");
    printf("y = %.2lf(x^%.2lf)\n",a,b);


    return 0;
}

