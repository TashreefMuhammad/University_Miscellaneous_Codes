/****
    * Name          : Tashreef Muhammad
    * ID No.        : 17 01 04 014
    * Assignment No.: 05
    * Assignment On : Minimum Spanning Tree Using Prim's Algorithm
****/

#include <bits/stdc++.h>

using namespace std;

typedef struct prim prim;

struct prim
{
    int node,cost;
};

int len;
prim primcontrol[1000];
int parent[1000];

int find_parent(int node);
void heapsort();
void build_max_heap(int l);
void max_heapify(int i,int len);

int main(void)
{
    int i,j,n,e,u,v,node,w,p,k;

    printf("Enter the numbers of nodes: ");
    scanf("%d",&n);
    len=n;
    int cost[n];
    bool store[n];

    for(i=0;i<n;i++)
    {
        parent[i]=i;
        cost[i]=INFINITY;
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
        edge[v-1].push_back(u-1);
        weight[v-1].push_back(w);
    }
    printf("Enter starting node: ");
    scanf("%d",&node);

    cost[node-1]=0;
    u=node-1;
    store[u]=false;

    for(i=0;i<n;i++)
    {
        primcontrol[i].node=i;
        primcontrol[i].cost=cost[i];
        store[i]=true;
    }
    heapsort();
    for(j=0;j<n;j++)
    {
        for(i=0;i<edge[u].size();i++)
        {
            for(k=0;k<n-i;k++)
            {
                p=primcontrol[k].node;
                if(p==edge[u][i])
                    break;
            }
            if(store[edge[u][i]]==true && weight[u][i]<cost[edge[u][i]])
            {
                parent[edge[u][i]]=u;
                cost[edge[u][i]]=weight[u][i];
                primcontrol[k].cost=weight[u][i];
            }
        }
        len=n-j-1;
        swap(primcontrol[0],primcontrol[len]);
        heapsort();
        u=primcontrol[0].node;
        store[u]=false;
    }
    printf("The MST is:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(parent[j]==i && i!=j)
                printf("   %d---%d -> Cost: %d\n",i+1,j+1,cost[j]);

    return 0;
}

int find_parent(int node)
{
    if(parent[node]==node)
        return node;
    else
        return parent[node]=find_parent(parent[node]);
}
void heapsort()
{
    len--;
    build_max_heap(len);

    for (int i=len;i>0;i--)
    {
        swap(primcontrol[0],primcontrol[i]);
        len--;
        max_heapify(0,len);
    }
}
void build_max_heap(int l)
{
    for(int i=(l-1)/2;i>=0;i--)
        max_heapify(i,l);
}

void max_heapify(int i,int len)
{
    int largest;
    int l = 2*i+1;
    int r = 2*i+2;
    if(l<=len && primcontrol[l].cost>primcontrol[i].cost)
        largest=l;
    else
        largest=i;
    if(r<=len && primcontrol[r].cost>primcontrol[largest].cost)
        largest=r;
    if(largest!=i)
    {
        swap(primcontrol[i],primcontrol[largest]);
        max_heapify(largest,len);
    }
}
/*
1 2 4
1 8 8
2 8 11
2 3 8
8 9 7
8 7 1
3 9 2
3 6 4
3 4 7
7 9 6
7 6 2
4 5 9
4 6 14
5 6 10
*/
