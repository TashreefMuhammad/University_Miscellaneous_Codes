//Assignment on Stack
#include <stdio.h>

//Functions for given 4 Stack actions
int pushfunction(int ar[],int t,int m);
int popfunction(int ar[],int t);
void searchfunction(int ar[],int t);
void displayfunction(int ar[],int t);

int main(void)
{
    int choice,top,info_array[1000];
    top=0;
    printf("Stack\n");
    printf("-----\n");
    printf("-----\n");
    printf("Enter your choice:\n");
    printf("\tChoose 1 to push data.\n");
    printf("\tChoose 2 to pop data.\n");
    printf("\tChoose 3 to search data.\n");
    printf("\tChoose 4 to display data.\n");
    printf("\tChoose 5 to exit.\n");
    printf("\n\tYour Selected Option: ");
    scanf("%d",&choice);
    while(choice!=5)
    {
        switch(choice)
        {
            case 1: top=pushfunction(info_array,top,1000);
                    break;
            case 2: top=popfunction(info_array,top);
                    break;
            case 3: searchfunction(info_array,top);
                    break;
            case 4: displayfunction(info_array,top);
                    break;
            default: printf("Invalid Input Provided.\n");
                    break;
        }
        printf("\n\nEnter your choice:\n");
        printf("\tChoose 1 to push data.\n");
        printf("\tChoose 2 to pop data.\n");
        printf("\tChoose 3 to search data.\n");
        printf("\tChoose 4 to display data.\n");
        printf("\tChoose 5 to exit.\n");
        printf("\n\tYour Selected Option: ");
        scanf("%d",&choice);
    }
    return 0;
}

int pushfunction(int ar[],int t,int m)
{
    printf("\n\nYou have Selected to Push Data.\n");
    if(t<m)
    {
        int e;
        printf("Enter the element which is to be inserted: ");
        scanf("%d",&e);
        ar[t]=e;
        t++;
        printf("Successfully Inserted Requested Data.\n");
        return t;
    }
    else
    {
        printf("Overflow Detected. Can not Entry More Data.\n");
        return t;
    }
}

int popfunction(int ar[],int t)
{
    printf("\n\nYou have Selected to Pop Data.\n");
    if(t==0)
    {
        printf("No Data Exists to be Deleted.\n");
        return t;
    }
    else
    {
        t--;
        printf("Successfully Deleted Data.\n");
        return t;
    }
}

void searchfunction(int ar[],int t)
{
    printf("\n\nYou have Selected to Search Data.\n");
    if(t==0)
        printf("No Data to be Searched from Found.\n");
    else
    {
        int e;
        printf("The Element To Search: ");
        scanf("%d",&e);
        t--;
        while(t>=0)
        {
            if(ar[t]==e)
                break;
            t--;
        }
        if(t==-1)
            printf("Requested Data was Not Found.\n");
        else
            printf("Requested Data was Found at %d index\n",t);
    }
}

void displayfunction(int ar[],int t)
{
    printf("\n\nYou have Selected to Display Data.\n");
    if(t==0)
        printf("No data for Display.\n");
    else
    {
        t--;
        while(t>=0)
        {
            printf("%d ",ar[t]);
            t--;
        }
        printf("\nThis are all the data that are to be displayed.\n");
    }
}
