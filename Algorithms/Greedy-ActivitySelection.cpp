/****
    * Name          : Tashreef Muhammad
    * ID No.        : 17 01 04 014
    * Assignment No.: 09 (i)
    * Assignment On : Activity Selection
****/

#include <stdio.h>
#include <algorithm>

using namespace std;

typedef struct activity_time activity_time;

struct activity_time
{
    int activity,start,over;
};

int compareSort(activity_time t1,activity_time t2)
{
    if(t1.over==t2.over)
        return t1.start<t2.start;
    else
        return t1.over<t2.over;

}

int main(void)
{
    int n,i,j;

    printf("Enter the number of entries: ");
    scanf("%d",&n);

    activity_time cur,st[n];

    for(i=0;i<n;i++)
    {
        st[i].activity=i+1;

        printf("Start time of activity %d: ",i+1);
        scanf("%d",&st[i].start);

        printf("Over  time of activity %d: ",i+1);
        scanf("%d",&st[i].over);

        printf("\n");
    }

    sort(st,st+n,compareSort);

    cur=st[0];

    printf("The number of activities that can be completed serially are:\n");
    printf("1.\tActivity %d\tStart : %d\tEnd : %d\n",cur.activity,cur.start,cur.over);

    for(i=1,j=1;i<n;i++)
        if(cur.over<=st[i].start)
        {
            cur=st[i];
            printf("%d.\tActivity %d\tStart : %d\tEnd : %d\n",++j,cur.activity,cur.start,cur.over);
        }

    return 0;
}
