/****
    *Name               : Tashreef Muhammad
    *ID                 : 17.01.04.014
    *Course No.         : CSE 2208
    *Course Title       : Algorithm Lab
    *Assignment No.     : 02 (DFS)
    *Assignment Name    : DFS (Depth First Search)
    *Date of Submission : 05.02.109
****/

#include <stdio.h>
#include <vector>

using namespace std;

vector <char> col;

void DFS(int node,vector <int> vec[]);

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

    printf("\nThe DFS traverse sequence when %d is root:\n",e);
    DFS(e-1,vec);
    printf("\b \b\nThis is the traversal.");

    return 0;
}

void DFS(int node,vector <int> vec[])
{
    col[node]='G';
    for(int i=0;i<vec[node].size();i++)
        if(col[vec[node][i]]=='W')
            DFS(vec[node][i],vec);
    printf("%d>",node+1);
}
