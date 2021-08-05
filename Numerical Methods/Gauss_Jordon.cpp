#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n,i,j,k,maximum_index;
    printf("Enter the number of unknowns variables: ");
    scanf("%d",&n);
    double val,maximum_val,co_ef[n][n],con[n];

    /**
    Input value terms correspond to the following representation:
    a[0][0]x0+a[0][1]x1+....+a[0][n-1]x(n-1)=con[0] ................ Equation 1
    a[1][0]x0+a[1][1]x1+....+a[1][n-1]x(n-1)=con[1] ................ Equation 2
    a[2][0]x0+a[2][1]x1+....+a[2][n-1]x(n-1)=con[2] ................ Equation 3
    ...........................................................................
    ...........................................................................
    a[n-1][0]x0+a[n-1][1]x1+....+a[n-1][n-1]x(n-1)=con[n-1] ...... Equation n
    **/

    printf("Provide Input:\n");
    for(i=0;i<n;i++)
    {
        printf("For equation %d:\n",i+1);
        for(j=0;j<n;j++)
        {
            printf("Co-efficient of x%d: ",j);
            scanf("%lf",&co_ef[i][j]);
        }
        printf("Constant in equation: ");
        scanf("%lf",&con[i]);
    }

    ///Gauss Jordon
    for(i=0;i<n;i++)
    {
        j=i;
        maximum_val=0.0;
        for(k=j;k<n;k++)
        {
            if(co_ef[k][i]>maximum_val)
            {
                maximum_index=k;
                maximum_val=co_ef[i][k];
            }
        }
        for(k=0;k<n;k++)
            swap(co_ef[maximum_index][k],co_ef[j][k]);
        swap(con[maximum_index],con[j]);
        val=co_ef[i][i];
        for(k=0;k<n;k++)
            co_ef[i][k]=co_ef[i][k]/val;
        con[i]=con[i]/val;
        for(j=0;j<n;j++)
        {
            if(j==i)
                continue;
            val=co_ef[j][i];
            for(k=0;k<n;k++)
                co_ef[j][k]=co_ef[j][k]-co_ef[i][k]*val;
            con[j]=con[j]-con[i]*val;
        }
    }
    for(i=0;i<n;i++)
        printf("x%d: %lf\n",i,con[i]);
    return 0;
}
