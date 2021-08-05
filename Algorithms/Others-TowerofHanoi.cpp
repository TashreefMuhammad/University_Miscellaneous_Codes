//Tower of Hanoi

#include <stdio.h>

typedef struct ite_var_hanoi ite_var_hanoi;

struct ite_var_hanoi
{
    int n;
    char i,j,k;
    ite_var_hanoi()
    {
        ;
    }
};

void rec_hanoi(int n,char i,char j,char k);
void ite_hanoi(int num);

ite_var_hanoi push(int n,char i,char j,char k);
ite_var_hanoi pop(ite_var_hanoi ar);

int top=-1;

int main(void)
{
    int n;
    printf("Enter the number of disks:  ");
    scanf("%d",&n);
    printf("Solution from Recursive Method:\n");
    rec_hanoi(n,'S','A','D');
    printf("Solution from Iterative Method:\n");
    ite_hanoi(n);
    return 0;
}

void rec_hanoi(int n,char i,char j,char k)
{
    if(n==1)
        printf("%c -> %c\t(Recursion)\n",i,k);
    else
    {
        rec_hanoi(n-1,i,k,j);
        rec_hanoi(1,i,j,k);
        //printf("%c -> %c\n",i,k);
        rec_hanoi(n-1,j,i,k);
    }
}
void ite_hanoi(int num)
{
    ite_var_hanoi var,st_ar[num*num*num];
    st_ar[top+1]=push(num,'S','A','D');
    while(top!=-1)
    {
        var=pop(st_ar[top]);
        if(var.n==1)
            printf("%c -> %c\t(Iteration)\n",var.i,var.k);
        else
        {
            st_ar[top+1]=push(var.n-1,var.j,var.i,var.k);
            st_ar[top+1]=push(1,var.i,var.j,var.k);
            //printf("%c -> %c\n",var.i,var.k);
            st_ar[top+1]=push(var.n-1,var.i,var.k,var.j);
        }
    }
}
ite_var_hanoi push(int n,char i,char j,char k)
{
    top++;
    ite_var_hanoi temp;
    temp.n=n;
    temp.i=i;
    temp.j=j;
    temp.k=k;
    return temp;
}
ite_var_hanoi pop(ite_var_hanoi ar)
{
    top--;
    return ar;
}
