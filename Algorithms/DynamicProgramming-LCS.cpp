/****
    * Name          : Tashreef Muhammad     * ID No.        : 17 01 04 014
    * Assignment No.: 10 (ii)               * Assignment On : Longest Common Sub-sequence
****/
#include <iostream>
#include <cstring>
#include <stack>
using namespace std;
stack <char> sub_seq;
int LCS(string str1,string str2);
int main(void)
{
    string str,str1,str2;
    str1=str2=" ";
    int len;
    cout<<"Enter string 1: ";
    cin>>str;
    str1+=str;
    cout<<"Enter string 2: ";
    cin>>str;
    str2+=str;
    len=LCS(str1,str2);
    cout<<"\nThe longest sub sequence length: "<<len<<"\n";
    cout<<"\nThe string is:\n";
    while(!sub_seq.empty())
    {
        cout<<sub_seq.top();
        sub_seq.pop();
    }
    return 0;
}
int LCS(string str1,string str2)
{
    int l1,l2,i,j;
    l1=str1.size();
    l2=str2.size();
    int mat[l1][l2];
    for(i=0;i<l1;i++)
        mat[i][0]=0;
    for(j=0;j<l2;j++)
        mat[0][j]=0;
    for(i=1;i<l1;i++)
        for(j=1;j<l2;j++)
        {
            if(str1[i]==str2[j])
                mat[i][j]=mat[i-1][j-1]+1;
            else
                mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
        }
    i--;
    j--;
    while(i>=1 && j>=1)
    {
        if(str1[i]==str2[j])
        {
            sub_seq.push(str1[i]);
            i--;
            j--;
        }
        else if(mat[i-1][j]>=mat[i][j-1])
                i--;
        else
                j--;
    }
    return mat[l1-1][l2-1];
}
