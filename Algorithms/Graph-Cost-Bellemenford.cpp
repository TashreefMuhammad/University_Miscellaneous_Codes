/****
    * Name          : Tashreef Muhammad
    * ID No.        : 17 01 04 014
    * Assignment No.: 07
    * Assignment On : MST Single Source Shortest Path Finding Using Bellman Ford's Algorithm
****/
#include <stdio.h>
#include <math.h>
#include <vector>

using namespace std;

int n;
vector <int> parent,cost;

void bellmenford(int node,vector <int> edge[],vector <int> weight[]);
void relax(int u,int v,int w);

int main(void)
{
    int i,j,e,u,v,node,w,p,k;

    printf("Enter the numbers of nodes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        parent.push_back(i);
        cost.push_back(INFINITY);
    }

    printf("Enter the number of edges: ");
    scanf("%d",&e);

    vector <int> edge[e],weight[e];

    printf("Enter the path from node to node & the cost:\n");

    for(i=0;i<e;i++)
    {
        scanf("%d %d %d",&u,&v,&w);
        edge[u-1].push_back(v-1);
        weight[u-1].push_back(w);
    }
    printf("Enter starting node: ");
    scanf("%d",&node);

    cost[node-1]=0;

    bellmenford(node-1,edge,weight);

    return 0;
}

void bellmenford(int node,vector <int> edge[],vector <int> weight[])
{
    int i,j,k;
    for(k=0;k<n-1;k++)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<edge[i].size();j++)
                relax(i,edge[i][j],weight[i][j]);
        }
    }
    int flag=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<edge[i].size();j++)
            if(cost[edge[i][j]]>cost[i]+weight[i][j])
                flag=1;
    }
    if(flag==1)
        printf("Negative Cycle Exists!\n");
    else
    {
        printf("The MST is:\n");
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                if(parent[j]==i && i!=j)
                    printf("   %d---%d -> Cost: %d\n",i+1,j+1,cost[j]);
    }
}

void relax(int u,int v,int w)
{
    if(cost[v]>cost[u]+w)
    {
        cost[v]=cost[u]+w;
        parent[v]=u;
    }
}
