/****
    * Name          : Tashreef Muhammad
    * ID No.        : 17 01 04 014
    * Assignment No.: 04 (i)
    * Assignment On : Strongly Connected Components
****/

#include <stdio.h>
#include <vector>
#include <stack>

using namespace std;

int c;
vector <char> color,trp_color;
stack <int> st;

void DFS(int node,vector <int> grp[]);
void SCC_print_DFS(int node,vector <int> trp_grp[]);

int main(void)
{
    int i,n,e,u,v;
    printf("Enter the numbers of nodes: ");
    scanf("%d",&n);
    vector <int> grp[n],trp_grp[n];
    for(i=0;i<n;i++)
    {
        color.push_back('W');
        trp_color.push_back('W');
    }
    printf("Enter the number of edges: ");
    scanf("%d",&e);
    printf("Enter the path from node to node:\n");
    for(i=0;i<e;i++)
    {
        scanf("%d %d",&u,&v);
        grp[u-1].push_back(v-1);
        trp_grp[v-1].push_back(u-1);
    }
    for(i=0;i<n;i++)
        if(color[i]=='W')
            DFS(i,grp);
    while(!st.empty())
    {
        if(color[st.top()=='W'])
        {
            c=0;
            printf("Elements of the new Component: ");
            SCC_print_DFS(st.top(),trp_grp);
        }
        printf("\nThe size of this component: %d\n",c);
    }
    return 0;
}

void DFS(int node,vector <int> grp[])
{
    color[node]='G';
    for(int i=0;i<grp[node].size();i++)
        if(color[grp[node][i]]=='W')
            DFS(grp[node][i],grp);
    st.push(node);
    color[node]='B';
}

void SCC_print_DFS(int node,vector <int> trp_grp[])
{
    c++;
    trp_color[node]='G';
    for(int i=0;i<trp_grp[node].size();i++)
        if(trp_color[trp_grp[node][i]]=='W')
            SCC_print_DFS(trp_grp[node][i],trp_grp);
    printf("%d ",st.top()+1);
    st.pop();
    trp_color[node]='B';
}
