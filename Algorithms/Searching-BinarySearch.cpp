#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

typedef struct sorting sorting;

struct sorting{
    int time,comp,mov;
    sorting()
    {
        ;
    }

};

sorting insertion(int l,int ins[]);
sorting selection(int l,int sel[]);
//void binarysearch(int l);
int rec_binarysearch(int l,int h,int e);

int sorted_array[1000000];

int main(void)
{
    int sze,i,start,index,element;
    double ins_sort_time,sel_sort_time;
    sorting sel_sort,ins_sort;

    printf("Please Input Array Size: ");
    scanf("%d",&sze);

    int input_array[sze];

    for(i=0;i<sze;i++)
        input_array[i]=rand()%1000;

    start=clock();
    ins_sort=insertion(sze,input_array);
    ins_sort_time=((double)ins_sort.time-(double)start)/CLOCKS_PER_SEC;

    start=clock();
    sel_sort=selection(sze,input_array);
    sel_sort_time=((double)sel_sort.time-(double)start)/CLOCKS_PER_SEC;

    printf("\t\tInsertion Sort\t\tSelection Sort\n");
    printf("\t\t--------------\t\t--------------\n");
    printf("Movement:\t %d\t\t\t %d\n",ins_sort.mov,sel_sort.mov);
    printf("Comparison:\t %d\t\t\t %d\n",ins_sort.comp,sel_sort.comp);
    printf("Execution Time:\t %f second(s) \t %f second(s)\n",ins_sort_time,sel_sort_time);

    //binarysearch(sze);

    printf("Element to be searched: ");
    scanf("%d",&element);

    index=rec_binarysearch(0,sze-1,element);

    if(index==-1)
        printf("Requested element (%d) was not found in array.\n",element);
    else
        printf("%d was found in %d index of the sorted array.\n",element,index);

    return 0;
}

sorting insertion(int l,int ins[])
{
    int i,j,k,t,arr[l+1];
    sorting ins_var;

    arr[0]=-INFINITY;
    for(i=1;i<=l;i++)
        arr[i]=ins[i-1];

    ins_var.comp=ins_var.mov=0;
    for(j=1;j<=l;j++)
    {
        t=arr[j];
        i=j-1;
        while(t<arr[i])
        {
            ins_var.comp++;
            arr[i+1]=arr[i];
            i--;
            ins_var.mov++;
        }
        ins_var.comp++;
        arr[i+1]=t;
        ins_var.mov++;
    }
    ins_var.time=clock();

    for(i=1;i<=l;i++)
        printf("%d ",arr[i]);
    printf("\n");

    return ins_var;
}

sorting selection(int l,int sel[])
{
    int j,k,t,temp,arr[l];
    sorting sel_var;

    for(j=0;j<l;j++)
        arr[j]=sel[j];

    sel_var.comp=sel_var.mov=0;
    for(j=l-1;j>0;j--)
    {
        t=j;
        for(k=0;k<j;k++)
        {
            sel_var.comp++;
            if(arr[t]<arr[k])
                t=k;
        }
        temp=arr[t];
        arr[t]=arr[j];
        arr[j]=temp;
        sel_var.mov++;
    }
    sel_var.time=clock();

    for(j=0;j<l;j++)
        sorted_array[j]=arr[j];
    printf("\n");
    return sel_var;
}

/*void binarysearch(int l)
{
    int e,mid,low=0,high=l-1;
    mid=(low+high)/2;
    printf("\nElement to be searched for: ");
    scanf("%d",&e);
    while(low<=high)
    {
        if(sorted_array[mid]==e)
        {
            printf("%d is found at index %d of the sorted array.\n",e,mid);
            break;
        }
        else if(sorted_array[mid]<e)
            low=mid+1;
        else
            high=mid-1;
        mid=(low+high)/2;
    }
    if(low>high)
        printf("Requested element (%d) was not found in array.\n",e);
}*/

int rec_binarysearch(int l,int h,int e)
{
    if(l>h)
        return -1;
    else if(sorted_array[(l+h)/2]==e)
        return (l+h)/2;
    else if(sorted_array[(l+h)/2]>e)
        return rec_binarysearch(l,((l+h)/2)-1,e);
    else
        return rec_binarysearch(((l+h)/2)+1,h,e);
}
