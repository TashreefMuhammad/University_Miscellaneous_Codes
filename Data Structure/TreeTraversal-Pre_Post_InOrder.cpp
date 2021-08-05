//Graph Traversal. Assignment 9
#include <stdio.h>

//Global 2D Array. It will contain the graph.
//The 1st Dimension contains the node. 2nd dimension contains node's children
char grp[30][30];

//Prototype Declaration
void rec_preorder(char s);
void rec_postorder(char s);
void rec_inorder(char s);

void nrec_preorder(char s);
void nrec_postorder(char s);
void nrec_inorder(char s);

//Main function
int main(void)
{
    int n,i,j;
    char c;
    char s;
    //Number of Vertex is taken as User Input
    printf("Enter number of vertexes: ");
    scanf("%d",&n);
    getchar();
    printf("\n");
    for(i=0;i<n;i++)
    {
        //i is used to express the node itself. i+'A' provides the character which the node is represented by.
        //j is used to put the values of child nodes of i.
        j=0;
        printf("Left child node of node %c (if node is empty enter '#'):  ",i+'A');
        c=getchar();
        getchar();
        if(c!='#')
        {
            grp[i][j]=c;
            j++;
        }
        printf("Right child node of node %c (if node is empty enter '#'): ",i+'A');
        c=getchar();
        getchar();
        if(c!='#')
        {
            grp[i][j]=c;
            j++;
        }
        c='\0';
        grp[i][j]=c;
        printf("\n");
    }
    printf("\n");

    printf("Root: ");
    c=getchar();
    s=c;

    printf("Paths:");
    printf("\n\n Pre-order Recursive Path: \t");
    rec_preorder(s);

    printf("\n Pre-order Non-Recursive Path: \t");
    nrec_preorder(s);

    printf("\n\n Post-order Recursive Path: \t");
    rec_postorder(s);

    printf("\n Post-order Non-Recursive Path: ");
    nrec_postorder(s);

    printf("\n\n In-order Recursive Path: \t");
    rec_inorder(s);

    printf("\n In-order Non-Recursive Path: \t");
    nrec_inorder(s);

    return 0;
}

//Recursive function traverses and prints the path in preorder.
void rec_preorder(char s)
{
    int i,j;
    printf("%c ",s);
    i=s-'A';
    for(j=0;grp[i][j]!='\0';j++)
        rec_preorder(grp[i][j]);
}

//Recursive function traverses and prints the path in postorder.
void rec_postorder(char s)
{
    int i,j;
    i=s-'A';
    for(j=0;grp[i][j]!='\0';j++)
        rec_postorder(grp[i][j]);
    printf("%c ",s);
}

//Recursive function traverses and prints the path in inorder.
void rec_inorder(char s)
{
    if(s!='\0')
    {
        int i;
        i=s-'A';
        rec_inorder(grp[i][0]);
        printf("%c ",s);
        rec_inorder(grp[i][1]);
    }
}

//Non-recursive function traverses and prints the path in preorder.
void nrec_preorder(char s)
{
    int i,j,top=-1;
    char stack_array[30];
    top++;
    stack_array[top]=s;
    while(top!=-1)
    {
        i=stack_array[top]-'A';
        printf("%c ",stack_array[top]);
        top--;
        if(grp[i][1]!='\0')
        {
            top++;
            stack_array[top]=grp[i][1];
        }
        if(grp[i][0]!='\0')
        {
            top++;
            stack_array[top]=grp[i][0];
        }
    }
}

//Non-recursive function traverses and prints the path in postorder.
void nrec_postorder(char s)
{
    int i,j,mtop=-1,top=-1;
    char stack_array[30],out_stack[30];
    top++;
    stack_array[top]=s;
    while(top!=-1)
    {
        i=stack_array[top]-'A';
        mtop++;
        out_stack[mtop]=stack_array[top];
        top--;
        if(grp[i][0]!='\0')
        {
            top++;
            stack_array[top]=grp[i][0];
        }
        if(grp[i][1]!='\0')
        {
            top++;
            stack_array[top]=grp[i][1];
        }
    }
    while(mtop!=-1)
    {
        printf("%c ",out_stack[mtop]);
        mtop--;
    }
}

//Non-recursive function traverses and prints the path in inorder.
void nrec_inorder(char s)
{
    int i,j,top=-1;
    char stack_array[30];
    while(top!=-1 || s!='\0')
    {
        while(s!='\0')
        {
            i=s-'A';
            top++;
            stack_array[top]=s;
            s=grp[i][0];
        }
        printf("%c ",stack_array[top]);
        i=stack_array[top]-'A';
        s=grp[i][1];
        i=grp[i][1]-'A';
        top--;
    }
}
