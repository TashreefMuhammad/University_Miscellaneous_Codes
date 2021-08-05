/****
    *Name               : Tashreef Muhammad
    *ID                 : 17.01.04.014
    *Course No.         : CSE 2208
    *Course Title       : Algorithm Lab
    *Assignment No.     : 02 (BFS)
    *Assignment Name    : BFS (Breadth First Search)
    *Date of Submission : 05.02.109
****/

#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

vector <char> col;
queue <int> store;

void BFS(int node,vector <int> vec[]);

int main(void)
{
    int i,n,e,u,v;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);

    printf("Enter the number of edges: ");
    scanf("%d",&e);

    vector <int> vec[n];
    printf("For a undirected graph, please provide which nodes are directly connected by edge.\n");
    for(i=0;i<e;i++)
    {
        printf("Edge %d: ",i+1);
        scanf("%d %d",&u,&v);
        vec[u-1].push_back(v-1);
        vec[v-1].push_back(u-1);
    }

    for(i=0;i<n;i++)
        col.push_back('W');

    printf("\nEnter the root: ");
    scanf("%d",&e);

    printf("\nThe BFS traverse sequence when %d is root:\n",e);
    BFS(e-1,vec);
    printf("\b \b\nThis is the traversal.");

    return 0;
}

void BFS(int node,vector <int> vec[])
{
    col[node]='G';
    store.push(node);
    while(!store.empty())
    {
        int u=store.front();
        store.pop();
        printf("%d>",u+1);
        for(int i=0;i<vec[u].size();i++)
            if(col[vec[u][i]]=='W')
            {
                store.push(vec[u][i]);
                col[vec[u][i]]='G';
            }
    }
}
