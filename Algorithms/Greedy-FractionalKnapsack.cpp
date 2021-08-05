/****
    * Name          : Tashreef Muhammad
    * ID No.        : 17 01 04 014
    * Assignment No.: 09 (ii)
    * Assignment On : Fractional Knapsack
****/

#include <stdio.h>
#include <algorithm>

using namespace std;

typedef struct product product;

struct product
{
    int weight,price;
    double unitprice;
};

double compareSort(product p1,product p2)
{
    return p1.unitprice>p2.unitprice;
}

int main(void)
{
    int n,c,i;

    printf("Enter number of products: ");
    scanf("%d",&n);

    printf("Enter total Capacity: ");
    scanf("%d",&c);

    double profit,quantity[n];
    product st[n];

    for(i=0;i<n;i++)
    {
        printf("Weight of Product %d: ",i+1);
        scanf("%d",&st[i].weight);

        printf("Price of activity %d: ",i+1);
        scanf("%d",&st[i].price);

        st[i].unitprice=(double)st[i].price/(double)st[i].weight;

        printf("\n");
    }

    for(i=0;i<n;i++)
        quantity[i]=0;

    sort(st,st+n,compareSort);

    for(i=0;i<n;i++)
    {
        if(st[i].weight>c)
            break;
        quantity[i]=1.0;
        c-=st[i].weight;
    }

    if(i<=n)
        quantity[i]=(double)c/(double)st[i].weight;

    profit=0.0;

    for(i=0;i<n;i++)
    {
        printf("Take %.2lf units of %d priced item\n",quantity[i],st[i].price);
        profit+=quantity[i]*(double)st[i].price;
    }

    printf("Maximum Profit: %.2lf\n",profit);

    return 0;
}
