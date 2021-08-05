/*****
    **ID            : 17.01.04.014
    **Name          : Tashreef Muhammad
    **Course No.    : CSE 2208
    **Course Name   : Algorithms Lab
    **Assignment    : Heap Sort (Assignment 1)
*****/

///Including header files
#include <stdio.h>
#include <vector>
#include <stdlib.h>

using namespace std;

///Vector where to store the elements
vector <int> vec;

///Three functions to implement HeapSort
void heapsort();
void build_max_heap(int l);
void max_heapify(int i,int len);

int main(void)
{
    int n,i;

    ///Taking user input of number of elements
    printf("Enter the number of elements: ");
    scanf("%d",&n);

    ///Taking random input as elements
    for(i=0;i<n;i++)
        vec.push_back(rand()%100);

    ///Showing how the elements look unsorted
    printf("\nUnsorted Input:\n");
    for(i=0;i<n;i++)
        printf("%d ",vec[i]);

    ///Sorting using Heap Sort
    heapsort();

    ///Showing sorted element
    printf("\n\nSorted Output:\n");
    for(i=0;i<n;i++)
        printf("%d ",vec[i]);

    return 0;
}

void heapsort()
{
    ///Taking the size of vector, thus the number of elements to be sorted
    int len=vec.size()-1;

    ///Initially making the whole vector follow heap property
    build_max_heap(len);

    for (int i=len;i>0;i--)
    {
        ///Swap the first element with the last element
        ///So, the element at 'len' is right now highest
        ///among elements in consideration
        swap(vec[0],vec[i]);

        ///Removing last element from consideration
        len--;

        ///Again making the elements follow heap property
        ///as in some cases it got violated, due to swap
        max_heapify(0,len);
    }
}

///The function builds the full vector following heap property
void build_max_heap(int l)
{
    for(int i=(l-1)/2;i>=0;i--)
        max_heapify(i,l);
}

void max_heapify(int i,int len)
{
    int largest;

    ///Finding left and right child node number
    ///for the parent whose node is 'i'
    int l = 2*i+1;
    int r = 2*i+2;

    ///Finding the node having highest element among
    ///parent 'i', left child 'l' & right child 'r'
    if(l<=len && vec[l]>vec[i])
        largest=l;
    else
        largest=i;
    if(r<=len && vec[r]>vec[largest])
        largest=r;

    ///If parent has the largest element then
    ///heap property is not violated, so move on
    ///If not, then this condition will become true
    ///And the following shall be executed
    if(largest!=i)
    {
        ///Making the largest element the new parent
        swap(vec[i],vec[largest]);
        ///Ensuring follow of heap property for the
        ///children of new parent
        max_heapify(largest,len);
    }
}
