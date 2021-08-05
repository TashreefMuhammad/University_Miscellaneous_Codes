/****
    * Name          : Tashreef Muhammad
    * ID No.        : 17 01 04 014
    * Assignment No.: 10 (i)
    * Assignment On : 0/1 Knapsack
****/
#include <stdio.h>
#include <stack>
using namespace std;
stack <int> item;
int knapsack(int w[],int v[],int n,int c);
int main(void)
{
    int n,c,i,profit;
    printf("Enter number of products: ");
    scanf("%d",&n);
    printf("Enter total Capacity: ");
    scanf("%d",&c);
    int weight[n+1],value[n+1];
    printf("\n");
    for(i=1;i<=n;i++)
    {
        printf("Weight of Product %d: ",i);
        scanf("%d",&weight[i]);
        printf("Price of activity %d: ",i);
        scanf("%d",&value[i]);
        printf("\n");
    }
    profit=knapsack(weight,value,n,c);
    printf("Maximum Profit: %d\n\n",profit);
    printf("Items taken are:\n");
    while(!item.empty())
    {
        printf("Item %d\n",item.top());
        item.pop();
    }
    return 0;
}
int knapsack(int w[],int v[],int n,int c)
{
    int i,j,mat[n+1][c+1];
    for(i=0;i<=n;i++)
        mat[i][0]=0;
    for(j=0;j<=c;j++)
        mat[0][j]=0;
    for(i=1;i<=n;i++)
        for(j=1;j<=c;j++)
        {
            if(w[i]>j)
                mat[i][j]=mat[i-1][j];
            else
                mat[i][j]=max(v[i]+mat[i-1][j-w[i]],mat[i-1][j]);
        }
    for(i=n,j=c;i>0;i--)
        if(mat[i][j]>mat[i-1][j])
        {
            item.push(i);
            j=j-w[i];
        }
    return mat[n][c];
}
