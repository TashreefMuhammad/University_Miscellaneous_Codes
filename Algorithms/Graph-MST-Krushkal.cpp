/****
    * Name          : Tashreef Muhammad
    * ID No.        : 17 01 04 014
    * Assignment No.: 04 (ii)
    * Assignment On : Minimum Spanning Tree Using Krushkal's Algorithm
****/

#include <bits/stdc++.h>

using namespace std;

typedef struct grp grp;

struct grp
{
    int from,to,weight;
};

int parent[1000];

void quicksort(int l,int h,grp ar[]);
int Partition(grp ar[],int l,int h);
int find_parent(int node);

int main(void)
{
    int i,n,e,u,v,cost;

    printf("Enter the numbers of nodes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
        parent[i]=i;

    printf("Enter the number of edges: ");
    scanf("%d",&e);

    grp ar[e];
    printf("Enter the path from node to node & the cost:\n");

    for(i=0;i<e;i++)
    {
        scanf("%d %d %d",&u,&v,&cost);
        ar[i].from=u;
        ar[i].to=v;
        ar[i].weight=cost;
    }

    quicksort(0,n-1,ar);
    cost=0;
    for(i=0;i<e;i++)
    {
        u=find_parent(ar[i].from);
        v=find_parent(ar[i].to);
        if(u!=v)
        {
            parent[v]=u;
            cost+=ar[i].weight;
        }

    }

    printf("Cost of Minimum Spanning Tree: %d",cost);

    return 0;
}

void quicksort(int l,int h,grp ar[])
{
    if(l<h)
    {
        int p =Partition(ar,l,h);
        quicksort(l,p-1,ar);
        quicksort(p+1,h,ar);
    }
}

int Partition(grp ar[],int l,int h)
{
    int pivot=ar[h].weight;
    int i =l-1;
    int j = h;
    while(true)
    {
        while(ar[++i].weight<pivot){}
        while(j>0&&ar[--j].weight>pivot){}
        if(i>=j)
            break;
        else
            swap(ar[i],ar[j]);
    }
    swap(ar[i],ar[h]);
    return i;
}

int find_parent(int node)
{
    if(parent[node]==node)
        return node;
    else
        return parent[node]=find_parent(parent[node]);
}
