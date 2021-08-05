#include <stdio.h>
int n;
int fun_recur(int x);
int fun_var(void);
int main(void)
{
    int a,recurse;
    printf("ENTER THE NUMBER OF DISKS: ");
    scanf("%d",&a);
    if(a%2!=0)
    {
        n=a;
        recurse=fun_recur(a);
        fun_var();
        printf("\nTHE NUMBER OF MOVES (using recursive function) ARE: %d",recurse);
        printf("\nTHE NUMBER OF MOVES (using global variables) ARE: %d",n);
    }
    else
        printf("\nInvalid number of disk for Hanoi Tower.");
    return 0;
}
int fun_recur(int x)
{
    if(x==0)
        return 0;
    else
        return (2*(x-1))+1;

}
int fun_var(void)
{
    n=2*(n-1)+1;
    return n;
}
