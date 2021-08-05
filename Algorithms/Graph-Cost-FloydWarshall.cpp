/****
    * Name          : Tashreef Muhammad
    * ID No.        : 17 01 04 014
    * Assignment No.: 08
    * Assignment On : MST All Pair Shortest Path Finding Using Floyd Warshall's Algorithm
****/

#include <stdio.h>
#include <math.h>
#include <vector>
#define maximum 1000000

using namespace std;

int n;

void floydwarshall(vector <int> weight[],vector <int> through[]);

int main(void)
{
    int i,j,e,u,v,w;

    printf("Enter the numbers of nodes: ");
    scanf("%d",&n);

    printf("Enter the number of edges: ");
    scanf("%d",&e);

    vector <int> weight[n],through[n];

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            weight[i].push_back(maximum);
            through[i].push_back(-1);
        }

    for(i=0;i<n;i++)
        weight[i][i]=0;

    printf("Enter the path from node to node & the cost:\n");

    for(i=0;i<e;i++)
    {
        scanf("%d %d %d",&u,&v,&w);
        weight[u-1][v-1]=w;
        through[u-1][v-1]=u-1;
    }

    floydwarshall(weight,through);

    return 0;
}

void floydwarshall(vector <int> weight[],vector <int> through[])
{
    int i,j,k;

    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                if(weight[i][k]+weight[k][j]<weight[i][j])
                {
                    weight[i][j]=weight[i][k]+weight[k][j];
                    through[i][j]=through[k][j];
                }
    }

    printf("The Shortest Distance Between All The Nodes are:\n");
    printf("Column Denotes Source Index & Row Index Denotes Destination:\n");
    for(i=0;i<n;i++)
        printf("\t %d",i+1);
    printf("\n");
    for(i=0;i<n;i++)
        printf("__________________");
    printf("\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t|",i+1);
        for(j=0;j<n;j++)
        {
            ///Considering no cost from any node to node exceeds or reaches 100
            if(weight[i][j]>=100)
                printf("no_con\t");
            else
                printf("%d\t",weight[i][j]);
        }
        printf("\n");
    }
}
