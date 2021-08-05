/****
    * Name          : Tashreef Muhammad
    * ID No.        : 17 01 04 014
    * Assignment No.: 11
    * Assignment On : nQueen Problem
****/
#include <stdio.h>
#include <vector>
using namespace std;
int n;
bool nQueen(int col,vector <int> board[]);
bool check(int row,int col,vector <int> board[]);
int main(void){
    int i,j;
    printf("Enter the value of n: ");
    scanf("%d",&n);
    vector <int> board[n];
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            board[i].push_back(0);
    nQueen(0,board);
    printf("The solution positions are: \n");
    for(i=0;i<n;i++){
        printf("One Queen at: %d,",i+1);
        for(j=0;j<n;j++)
            if(board[i][j]){
                printf("%d\n",j+1);
                break;
            }
    }
    printf("\nThe Queen positions in the board:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(board[i][j]) printf("Q ");
            else    printf("0 ");
        }
        printf("\n");
    }
    return 0;
}
bool nQueen(int col,vector <int> board[])
{
    if(col==n) return true;
    for(int i=0;i<n;i++)
        if(check(i,col,board)==true){
            board[i][col]=1;
            if(nQueen(col+1,board)) return true;
            board[i][col]=0;
        }
    return false;
}
bool check(int row,int col,vector <int> board[]){
    int i,j;
    for(i=0;i<col;i++)
        if(board[row][i])
            return false;
    for(i=row,j=col;i>=0 && j>=0;i--,j--)
        if(board[i][j])
            return false;
    for(i=row,j=col;i<n && j>=0;i++,j--)
        if(board[i][j])
            return false;
    return true;
}
