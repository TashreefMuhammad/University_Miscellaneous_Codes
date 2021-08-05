//Assignment on Queue (Non-circulation)

#include <stdio.h>

//Functions for given 4 Queue actions
int pushfunction(int ar[],int t,int m);
int popfunction(int ar[],int t,int l);
void searchfunction(int ar[],int t,int l);
void displayfunction(int ar[],int t,int l);

int main(void)
{
    int choice,top,low,info_array[1000];
    top=low=0;
    printf("Queue\n");
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
            case 1: top=pushfunction(info_array,top,3);
                    break;
            case 2: low=popfunction(info_array,top,low);
                    break;
            case 3: searchfunction(info_array,top,low);
                    break;
            case 4: displayfunction(info_array,top,low);
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

int popfunction(int ar[],int t,int l)
{
    printf("\n\nYou have Selected to Pop Data.\n");
    if(l==t)
    {
        printf("No Data Exists to be Deleted.\n");
        return l;
    }
    else
    {
        l++;

        printf("Successfully Deleted Data.\n");
        return l;
    }
}

void searchfunction(int ar[],int t,int l)
{
    printf("\n\nYou have Selected to Search Data.\n");
    if(t==l)
        printf("No Data to be Searched from Found.\n");
    else
    {
        int e;
        printf("The Element To Search: ");
        scanf("%d",&e);
        while(l!=t)
        {
            if(ar[l]==e)
                break;
                l++;
        }
        if(l==t)
            printf("Requested Data was Not Found.\n");
        else
            printf("Requested Data was Found at %d index\n",l);
    }
}

void displayfunction(int ar[],int t,int l)
{
    printf("\n\nYou have Selected to Display Data.\n");
    if(l==t)
        printf("No data for Display.\n");
    else
    {
        while(l!=t)
        {
            printf("%d ",ar[l]);
            l++;
            if(l==t)
                break;
        }
        printf("\nThis are all the data that are to be displayed.\n");
    }
}
