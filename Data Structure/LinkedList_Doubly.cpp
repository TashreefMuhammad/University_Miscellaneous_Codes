//Doubly Linked List

#include <stdio.h>
#include <stdlib.h>

typedef struct linkedList linkedList;

struct linkedList
{
    int info;                   //Linked List value variable
    linkedList *blink,*flink;   //Linked List Pointer variable
    linkedList()                //Structure Constructor
    {
        ;
    }

};

void insertion(linkedList **L_location);    //Function for Linked List Insert Operation
void deletation(linkedList **L_location);   //Function for Linked List Delete Operation
void display(linkedList *p);                //Function for Linked List Display Operation

int main(void)
{
    int choice;
    linkedList *L = NULL;

    printf("<<<Doubly Linked List>>>\n");
    printf("-----------------\n");
    printf("-----------------\n");
    printf("Enter your choice:\n");
    printf("\tChoose 1 to Insert data.\n");
    printf("\tChoose 2 to Delete data.\n");
    printf("\tChoose 3 to Display data.\n");
    printf("\tChoose 4 to Exit.\n");
    printf("\n\tYour Selected Option: ");
    scanf("%d",&choice);
    while(choice!=4)            //Loop to control choice menu
    {
        switch(choice)
        {
        case 1:
            insertion(&L);
            break;
        case 2:
            deletation(&L);
            break;
        case 3:
            display(L);
            break;
        default:
            printf("Invalid Input Provided.\n");
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

void insertion(linkedList **L_location) //Function definition for sorted insertion
{

    int element;
    printf("------------------------------------\n");
    printf("You have selected to Insert new data\n");
    printf("\nPlease insert a data: ");
    scanf("%d",&element);

    linkedList *new_node = (linkedList*)malloc(sizeof(linkedList));
    new_node->blink=new_node->flink=NULL;
    new_node->info = element;

    linkedList *p = *L_location;
    //If the Linked List is empty
    if(*L_location==NULL)
        *L_location=new_node;
    //If the new data is to be inserted at the beginning
    else if(p->info>=new_node->info)
    {
        new_node->flink=p;
        p->blink=new_node;
        *L_location=new_node;
    }
    //For other conditions
    else
    {
        while((p->flink!=NULL)&&(p->flink->info<new_node->info))
            p=p->flink;
        new_node->flink=p->flink;
        //If the added node is not the last member in Linked List
        if(p->flink!=NULL)
            new_node->flink->blink=new_node;
        p->flink=new_node;
        new_node->blink=p;
    }

    printf("Data successfully Inserted to Linked List\n");
    printf("-----------------------------------------\n");
}

void deletation(linkedList **L_location)    //Function definition for deletion
{
    int element;
    printf("------------------------------------\n");
    printf("You have selected to Delete data\n");
    printf("\nPlease provide data which is to be deleted: ");
    scanf("%d",&element);
    linkedList *p = *L_location;
    //If the Linked List has no data
    if(*L_location==NULL)
        printf("Linked List is Empty");
    //If the Linked List has only 1 Data
    else if(p->info==element)
        *L_location=p->flink;
    //For other conditions
    else
    {
        while((p!=NULL)&&(p->info!=element))
            p = p->flink;
        //Linked List end has been reached but data not found
        if(p == NULL)
            printf("Requested Data does not exist in Linked List");
        //If the data was found
        else
        {
            p->blink->flink = p->flink;
            printf("Requested Data Successfully Deleted from Linked List");
        }
    }
    printf("\n-------------------------------------------\n");
}

void display(linkedList *p) //Function definition for display
{
    printf("------------------------------------\n");
    printf("You have selected to Display data\n");
    //Loop to display Linked List till last
    while(p != NULL)
    {
        printf("%d ", p->info);
        p = p->flink;
    }
    printf("\n");
    printf("That is all Data that were stored\n");
    printf("---------------------------------\n");
}

