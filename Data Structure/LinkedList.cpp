#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct List linkedList;
struct List
{
    int info;                   //Linked List value variable
    List *link;           //Linked List Pointer variable
    List()                //Structure Constructor
    {
        ;
    }

};

void insertion(linkedList **L_location);    //Function for Linked List Insert Operation
void deletation(linkedList *p);             //Function for Linked List Delete Operation
void display(linkedList *p);                //Function for Linked List Display Operation

int main(void)
{
    int choice;
    linkedList *L = (linkedList*)malloc(sizeof(linkedList)); //Creation of Dummy Node
    L->info = -INFINITY;                          //Assigning value variable input for dummy node
    L->link = NULL;                               //Assigning pointer variable input for dummy node

    printf("<<<Linked List>>>\n");
    printf("-----------------\n");
    printf("-----------------\n");
    printf("Enter your choice:\n");
    printf("\tChoose 1 to Insert data.\n");
    printf("\tChoose 2 to Delete data.\n");
    printf("\tChoose 3 to Display data.\n");
    printf("\tChoose 4 to Exit.\n");
    printf("\n\tYour Selected Option: ");
    scanf("%d",&choice);
    while(choice!=4)
    {
        switch(choice)
        {
        case 1: insertion(&L);
                break;
        case 2: deletation(L);
                break;
        case 3: display(L);
                break;
        default:printf("Invalid Input Provided.\n");
                break;
        }
        printf("Enter your choice:\n");
        printf("\tChoose 1 to Insert data.\n");
        printf("\tChoose 2 to Delete data.\n");
        printf("\tChoose 3 to Display data.\n");
        printf("\tChoose 4 to Exit.\n");
        printf("\n\tYour Selected Option: ");
        scanf("%d",&choice);
    }

    return 0;
}

void insertion(linkedList **L_location)
{

    int element;
    printf("------------------------------------\n");
    printf("You have selected to Insert new data\n");
    printf("\nPlease insert a data: ");
    scanf("%d",&element);

    linkedList *new_node = (linkedList*)malloc(sizeof(linkedList)); //The new element which will be inserted
    linkedList *p = (linkedList*)malloc(sizeof(linkedList));        //Insertion helping variable
    linkedList *pred = (linkedList*)malloc(sizeof(linkedList));     //Insertion helping variable

    new_node->info = element;                                       //Assigning new element value

    pred=*L_location;
    p=*L_location;

    while((p!=NULL)&&(p->info < new_node->info))
    {
        pred=p;
        p=p->link;
    }
    new_node->link=pred->link;
    pred->link=new_node;

    printf("Data successfully Inserted to Linked List\n");
    printf("-----------------------------------------\n");
}

void deletation(linkedList *p)
{
    int element;
    printf("------------------------------------\n");
    printf("You have selected to Delete data\n");
    printf("\nPlease provide data which is to be deleted: ");
    scanf("%d",&element);

    linkedList *pred = (linkedList*)malloc(sizeof(linkedList));
    pred=p;
    p=p->link;
    while((p!=NULL)&&(p->info!=element))            //Searching for requested value
    {
        pred = p;
        p = p->link;
    }
    if(p == NULL)                                   //Condition if given value was not found
        printf("Requested Data does not exist in Linked List");
    else                                            //Operation if given value was found
    {
        pred->link = p->link;
        printf("Requested Data Successfully Deleted from Linked List");
    }
    printf("\n-------------------------------------------\n");
}

void display(linkedList *p)
{
    printf("------------------------------------\n");
    printf("You have selected to Display data\n");
    p = p->link;
    while(p != NULL)            //Loop continues until List ends
    {
        printf("%d ", p->info);
        p = p->link;
    }
    printf("\n");
    printf("That is all Data that were stored\n");
    printf("---------------------------------\n");
}
