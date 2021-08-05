/****
    * Name          : Tashreef Muhammad
    * ID No.        : 17 01 04 014
    * Assignment No.: 10 (iii)
    * Assignment On : Matrix Chain Multiplication
****/

#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

int MCM(int p[],int n);

int main(void)
{
    int n,mul,i;
    printf("Enter the number of dimensions to be given: ");
    scanf("%d",&n);
    int p[n];
    printf("Enter the numbers:\n");
    for(i=0;i<n;i++)
    {
        printf("Enter number %d: ",i+1);
        scanf("%d",&p[i]);
    }
    mul=MCM(p,n);
    printf("Minimum number of multiplication: %d",mul);
    return 0;
}
int MCM(int p[],int n)
{
    int i,j,k,l,mat[n][n],b_store[n][n];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            mat[i][j]=b_store[i][j]=0;
    }
    for(l=2;l<n;l++)
    {
        for(i=1;i<n-(l-1);i++)
        {
            j=i+l-1;
            mat[i][j]=INFINITY;
            for(k=i;k<=j-1;k++)
            {
                if(mat[i][j]>mat[i][k]+mat[k+1][j]+p[i-1]*p[k]*p[j])
                    b_store[i][j]=k;
                mat[i][j]=min(mat[i][j],mat[i][k]+mat[k+1][j]+p[i-1]*p[k]*p[j]);
            }
        }
    }
    return mat[1][n-1];
}
