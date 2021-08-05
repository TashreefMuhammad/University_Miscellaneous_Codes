// QuickSort & MergeSort

#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

typedef struct sorting sorting;

struct sorting
{
    double e_time;
    int mov,comp;
    sorting()
    {
        ;
    }
};

void quicksort(int f,int l,int *quick_array);
void mergesort(int p,int r,int *merge_array);
void merging(int p,int q,int r,int *merge_arr);

int movement,comparison;

int main(void)
{
    int i,n;
    clock_t start,finish;
    sorting avg_quick,best_quick,worst_quick,avg_merge,best_merge,worst_merge;

    printf("Array index size: ");
    scanf("%d",&n);

    int quick_main_array[n],merge_main_array[n],worst_case_array[n];

    for(i=0;i<n;i++)
        quick_main_array[i]=merge_main_array[i]=rand()%5000;

    //QuickSort Average Case Output Collection

    start=clock();
    quicksort(0,n-1,quick_main_array);
    finish=clock();
    avg_quick.e_time=((double)finish-(double)start)/CLOCKS_PER_SEC;
    avg_quick.comp=comparison;
    avg_quick.mov=movement;

    //QuickSort Best Case Output Collection

    comparison=movement=0;

    start=clock();
    quicksort(0,n-1,quick_main_array);
    finish=clock();
    best_quick.e_time=((double)finish-(double)start)/CLOCKS_PER_SEC;
    best_quick.comp=comparison;
    best_quick.mov=movement;

    //QuickSort Worst Case Output Collection

    for(i=0;i<n;i++)
        worst_case_array[n-i-1]=quick_main_array[i]; //Creating a reverse array of the quick sorted array

    comparison=movement=0;

    start=clock();
    quicksort(0,n-1,worst_case_array);
    finish=clock();
    worst_quick.e_time=((double)finish-(double)start)/CLOCKS_PER_SEC;
    worst_quick.comp=comparison;
    worst_quick.mov=movement;

    //MergeSort Average Case Output Collection

    comparison=movement=0;

    start=clock();
    mergesort(0,n-1,merge_main_array);
    finish=clock();
    avg_merge.e_time=((double)finish-(double)start)/CLOCKS_PER_SEC;
    avg_merge.comp=comparison;
    avg_merge.mov=movement;

    //MergeSort Best Case Output Collection

    comparison=movement=0;

    start=clock();
    mergesort(0,n-1,merge_main_array);
    finish=clock();
    best_merge.e_time=((double)finish-(double)start)/CLOCKS_PER_SEC;
    best_merge.comp=comparison;
    best_merge.mov=movement;

    //MergeSort Worst Case Output Collection

    for(i=0;i<n;i++)
        worst_case_array[n-i-1]=merge_main_array[i]; //Creating a reverse array of the merge sorted array

    comparison=movement=0;

    start=clock();
    mergesort(0,n-1,worst_case_array);
    finish=clock();
    worst_merge.e_time=((double)finish-(double)start)/CLOCKS_PER_SEC;
    worst_merge.comp=comparison;
    worst_merge.mov=movement;

    for(i=0;i<n;i++)
        printf("%d ",quick_main_array[i]);
    printf("\n");

    printf("\nAverage Case:\n");
    printf("-------------\n");
    printf("\t\tQuick Sort\t\tMerge Sort\n");
    printf("\t\t--------------\t\t--------------\n");
    printf("Movement:\t %d\t\t\t %d\n",avg_quick.mov,avg_merge.mov);
    printf("Comparison:\t %d\t\t\t %d\n",avg_quick.comp,avg_merge.comp);
    printf("Execution Time:\t %f second(s) \t %f second(s)\n",avg_quick.e_time,avg_merge.e_time);

    printf("\nBest Case:\n");
    printf("----------\n");
    printf("\t\tQuick Sort\t\tMerge Sort\n");
    printf("\t\t--------------\t\t--------------\n");
    printf("Movement:\t %d\t\t\t %d\n",best_quick.mov,best_merge.mov);
    printf("Comparison:\t %d\t\t\t %d\n",best_quick.comp,best_merge.comp);
    printf("Execution Time:\t %f second(s) \t %f second(s)\n",best_quick.e_time,best_merge.e_time);

    printf("\nWorst Case:\n");
    printf("-----------\n");
    printf("\t\tQuick Sort\t\tMerge Sort\n");
    printf("\t\t--------------\t\t--------------\n");
    printf("Movement:\t %d\t\t\t %d\n",worst_quick.mov,worst_merge.mov);
    printf("Comparison:\t %d\t\t\t %d\n",worst_quick.comp,worst_merge.comp);
    printf("Execution Time:\t %f second(s) \t %f second(s)\n",worst_quick.e_time,worst_merge.e_time);

    return 0;
}

void quicksort(int f,int l,int *quick_array)
{
    int i,j,temp;
    if(f<l)
    {
        for(i=f+1,comparison++;*(quick_array+i)<*(quick_array+f);i++,comparison++);
        for(j=l,comparison++;*(quick_array+j)>*(quick_array+f);j--,comparison++);

        while(i<j)
        {
            temp=*(quick_array+i);
            *(quick_array+i)=*(quick_array+j);
            *(quick_array+j)=temp;
            movement+=3;
            for(i++,comparison++;*(quick_array+i)<*(quick_array+f);i++,comparison++);
            for(j--,comparison++;*(quick_array+j)>*(quick_array+f);j--,comparison++);
        }

        temp=*(quick_array+f);
        *(quick_array+f)=*(quick_array+j);
        *(quick_array+j)=temp;
        movement+=3;

        quicksort(f,j-1,quick_array);
        quicksort(j+1,l,quick_array);
    }
}

void mergesort(int p,int r,int *merge_array)
{
    if(p<r)
    {
        int q=(p+r)/2;

        mergesort(p,q,merge_array);
        mergesort(q+1,r,merge_array);

        merging(p,q,r,merge_array);
    }
}

void merging(int p,int q,int r, int *merge_arr)
{
    int i,j,k,n1,n2;
    n1=q-p+1;
    n2=r-q;
    int L[n1+1],R[n2+1];

    L[n1]=R[n2]=INFINITY;

    for(i=0;i<n1;i++)
    {
        L[i]=*(merge_arr+p+i);
        movement++;
    }

    for(j=0;j<n2;j++)
    {
        R[j]=*(merge_arr+q+j+1);
        movement++;
    }

    i=j=0;
    for(k=p;k<=r;k++)
    {
        comparison++;
        if(L[i]<=R[j])
        {
            *(merge_arr+k)=L[i];
            i++;
            movement++;
        }
        else
        {
            *(merge_arr+k)=R[j];
            j++;
            movement++;
        }
    }
}
