//BST insert, delete and traversal

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//shortening name of structure
typedef struct linkedList linkedList;

//Creating structure for all nodes of tree
struct linkedList
{
    int data;
    linkedList *pnode,*cnodeleft,*cnoderight;
};

//Prototype declaration
void tree_Insert(linkedList **root);
void tree_Delete(linkedList **root);
void tree_Search(linkedList *root);

void nodemovement(linkedList **node);

int main(void)
{
    int choice;

    //root of tree initially provided as NULL
    linkedList *root=(linkedList*)malloc(sizeof(linkedList)) ;
    root->data=-INFINITY;
    root->cnodeleft=root->cnoderight=NULL;

    //Menu Design
    printf("                 =======================\n");
    printf("                 <<<<<<<<Menu>>>>>>>>>>>\n");
    printf("                 =======================\n");
    printf("\n\n");
    printf("\tTo Insert Data into Tree, Press   -> 1\n");
    printf("\tTo Delete Data from Tree, Press   -> 2\n");
    printf("\tTo Search Data from Tree, Press   -> 3\n");
    printf("\tTo Exit From the Program, Press   -> 4\n");

    //Option input
    printf("\nYour Choice -> ");
    scanf("%d",&choice);

    while(choice!=4)
    {
        //Action according to choice
        switch(choice)
        {
            case 1: printf("\nYou have selected to insert new Data\n");
                tree_Insert(&root);
                break;
            case 2: printf("\nYou have selected to delete old Data\n");
                tree_Delete(&root);
                break;
            case 3: printf("\nYou have selected to search for Data\n");
                tree_Search(root->cnoderight);
                break;
            default: printf("Invalid Option Provided\n");
                break;
        }
        printf("                 =======================\n");
        printf("                 <<<<<<<<Menu>>>>>>>>>>>\n");
        printf("                 =======================\n");
        printf("\n\n");
        printf("\tTo Insert Data into Tree, Press   -> 1\n");
        printf("\tTo Delete Data from Tree, Press   -> 2\n");
        printf("\tTo Search Dara from Tree, Press   -> 3\n");
        printf("\tTo Exit From the Program, Press   -> 4\n");

        printf("\nYour Choice -> ");
        scanf("%d",&choice);
    }

    return 0;
}

//Function to add new node to tree
void tree_Insert(linkedList **root)
{
    int d;

    //Creating 2 structure variables to assist in insertion
    linkedList *x=*root;
    linkedList *y=NULL;

    //Creating a new structure variable to make the new node
    linkedList *z=(linkedList*)malloc(sizeof(linkedList));

    printf("=========");
    printf("Insert");
    printf("=========");
    printf("\nEnter Data to be Inserted: ");
    scanf("%d",&d);
    //Assigning data to the new node
    z->data=d;
    z->cnodeleft=z->cnoderight=NULL;

    //Until Leaf is reached, traverse goes according to BST rules
    while(x!=NULL)
    {
        y=x;
        if(z->data<x->data)
            x=x->cnodeleft;
        else
            x=x->cnoderight;
    }

    //The point at which data to be inserted is found. Now data is added to the tree
    z->pnode=y;
    if(z->data<y->data)
        y->cnodeleft=z;
    else
        y->cnoderight=z;
}

//Function to delete a node
void tree_Delete(linkedList **root)
{
    //If there is no tree, then nothing can be deleted from it.
    linkedList *x=*root;
    if(x->cnoderight==NULL)
    {
        printf("Tree is empty. No data can be deleted from it.\n");
        return;
    }

    int del_el;

    //new structure variables to help the process
    linkedList *y=NULL;

    printf("=========");
    printf("Delete");
    printf("=========");
    printf("\nEnter Data to be Deleted: ");
    scanf("%d",&del_el);

    //Searching for the element to be deleted according to BST
    while(x!=NULL && del_el!=x->data)
    {
        y=x;
        if(del_el<x->data)
            x=x->cnodeleft;
        else
            x=x->cnoderight;
    }

    //In case requested data was not found in tree
    if(x==NULL)
        printf("Requested Data does not exist in Tree.\n");
    //If data was found in tree
    else
    {
        //For deleting there can be 3 cases which are as follows

        //If the node to be deleted is a leaf
        if(x->cnoderight==NULL && x->cnodeleft==NULL)
        {
            if(x==y->cnodeleft)
                y->cnodeleft=x->cnodeleft;
            else
                y->cnoderight=x->cnoderight;
        }

        //If the node to be deleted has only one node. It is divided into following 2 conditions

        //If there is no left node
        else if(x->cnoderight==NULL && x->cnodeleft!=NULL)
        {
            if(x==y->cnodeleft)
                y->cnodeleft=x->cnodeleft;
            else
                y->cnoderight=x->cnodeleft;
        }
        //If there is no right node
        else if(x->cnoderight!=NULL && x->cnodeleft==NULL)
        {
            if(x==y->cnodeleft)
                y->cnodeleft=x->cnoderight;
            else
                y->cnoderight=x->cnoderight;
        }
        //If the node is in middle of the tree.
        //Another function is invoked which handles such situations
        else
            nodemovement(&x);
    }
    printf("Requested Data Successfully Deleted.\n");
}

//Function to handle deletion of a node in middle of BST
void nodemovement(linkedList **node)
{
    //Structure variables to help the process
    linkedList *x=*node;
    linkedList *y=*node;

    /*Until a node is found whose right node is null, the data of a node is being replaced
    by the data of it's right node.*/
    while(x->cnoderight!=NULL)
    {
        y=x;
        x->data=x->cnoderight->data;
        x=x->cnoderight;
    }
    /*The node that we find will be omitted as it's value has already been shifted to it's parent
    and thus the node need not to exist anymore. However in case there is a right child of that node*/

    //Then we assign that node as the right node of previous parent.*/
    if(x->cnodeleft!=NULL)
        y->cnoderight=x->cnodeleft;
    //Else we declare the right node of the parent as NULL
    else
        y->cnoderight=NULL;

}

//Function to traverse the tree.
void tree_Search(linkedList *root)
{
    int s_el;
    linkedList *x=root;

    printf("=========");
    printf("Search");
    printf("=========");
    printf("\nEnter Data to be Searched: ");
    scanf("%d",&s_el);

    //Until tree search finishes or data is found we traverse the tree according to BST rules
    while(x!=NULL && s_el!=x->data)
    {
        if(s_el<x->data)
            x=x->cnodeleft;
        else
            x=x->cnoderight;
    }

    //In case the data was not in the tree
    if(x==NULL)
        printf("Requested Data was not found in tree.");
    //Else here information about the node is printed.
    else
    {
        printf("Requested Data %d was found whose:",s_el);
        printf("\n Parent node data is: ");
        if(x->pnode->data==-2147483648)
            printf("(It is the root, so there is no parent node)");
        else
            printf("%d",x->pnode->data);
        printf("\n Left child node data is: ");
        if(x->cnodeleft==NULL)
            printf("(There is no data as left child)");
        else
            printf("%d",x->cnodeleft->data);
        printf("\n Right child node data is: ");
        if(x->cnoderight==NULL)
            printf("(There is no data as right child)");
        else
            printf("%d",x->cnoderight->data);
        printf("\n ");
    }
    printf("\n");
}
