/****
    * Name                  : Tashreef Muhammad
    * ID No.                : 17 01 04 014
    * Assignment No.        : 03
    * Assignment Name       : Topological Sort
    * Date of Performance   : 06.02.2019
    * Date of Submission    : 13.02.2019
****/

#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
#include <map>

using namespace std;

vector <char> color;
vector <string> node;
map <string,int> node_num;
stack <string> st;

void DFS(int num,vector <string> grp[]);

int main(void)
{
    int n,con;
    string name,child;
    cout<<"Enter the number of works: ";
    cin>>n;
    vector <string> grp[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter the name of work "<<i+1<<":";
        cin>>name;
        node.push_back(name);
        node_num[name]=i;
        cout<<"Enter the number of works to be done after "<<name<<": ";
        cin>>con;
        cout<<endl;
        for(int j=0;j<con;j++)
        {
            cout<<"Enter the work no. "<<j+1<<" after work "<<name<<": ";
            cin>>child;
            grp[i].push_back(child);
        }
        color.push_back('W');
        cout<<endl<<endl;
    }
    cout<<"The serial of work possible to be done:"<<endl;
    for(int i=0;i<n;i++)
        DFS(i,grp);
    if(!st.empty())
    {
        cout<<st.top();
        st.pop();
    }
    while(!st.empty())
    {
        cout<<"->"<<st.top();
        st.pop();
    }
    node_num.clear();
    return 0;
}

void DFS(int num,vector <string> grp[])
{
    if(color[num]=='B')
        return ;
    else
    {
        color[num]='G';
        for(int i=0;i<grp[num].size();i++)
            if(color[node_num[grp[num][i]]]=='W')
                DFS(node_num[grp[num][i]],grp);
            st.push(node[num]);
        color[num]='B';
    }
}
