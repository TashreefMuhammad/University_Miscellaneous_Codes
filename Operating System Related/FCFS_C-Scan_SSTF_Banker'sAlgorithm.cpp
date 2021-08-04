/****
    * Name        : Tashreef Muhammad
    * ID No.      : 170104014
    * Lab Group   : A1
    * Assignment  : Disk-Arm Scheduling [Even Set -> FCFS Scheduling, C-SCAN Algorithm, Extra: SSTF Scheduling]
                    Deadlock Avoidance [Banker's Algorithm]
****/

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

/// Functions Calling for Actions
void disk_arm_scheduling();
void deadlock_avoidance();
/// Functions Calling required Algorithms
void FCFS(int cnt_head, int cur_head, vector <int> cyl_req);
void SSTF(int cnt_head, int cur_head, vector <int> cyl_req);
void CSCN(int cnt_head, int cur_head, vector <int> cyl_req);
void banker(int no_proc, int no_res, vector <int> tot_res, vector <int> stat_proc[]);
/// Complimentary Function for Custom Use
int b_search(int val, vector <int> vec);

/**
=========Copy the following lines for sequenced sample input=========
----For Disk-Arm Management----
200
98,183,37,122,14,124,65,67
53

----For Deadlock Avoidance----
4
3
3
2
2
1
0
0
6
1
3
5
1
1
3
1
4
2
1
1
4
2
2
0
0
2
9
3
6

=========================End of Sample Input=========================
**/

int main(void)
{
    /// Following functions control which type of action are going to be performed
    disk_arm_scheduling();
    deadlock_avoidance();

    return 0;
}

/// Taking inputs and distributing those to the required functions for Disk-Arm Scheduling
void disk_arm_scheduling()
{
    cout << "\n\n===============================";
    cout << "\n||||  Disk-Arm Scheduling  ||||\n";
    cout << "===============================\n";

    int cnt_head, cur_head, take;
    vector <int> cyl_req;
    string req_str;

    cout << "Number of heads: ";
    cin >> cnt_head;

    cout << "Cylinder Requests: ";
    cin >> req_str;

    stringstream str(req_str);

    while(str >> take)
    {
        cyl_req.push_back(take);

        if(str.peek() == ',')
            str.ignore();
    }

    cout << "Current head position: ";
    cin >> cur_head;

    FCFS(cnt_head, cur_head, cyl_req);
    SSTF(cnt_head, cur_head, cyl_req);
    CSCN(cnt_head, cur_head, cyl_req);
}

/// Handling inputs to be later passed on to the Banker's Algorithm
void deadlock_avoidance()
{
    cout << "\n\n==============================";
    cout << "\n||||  Deadlock Avoidance  ||||\n";
    cout << "==============================\n";

    int no_proc, no_res, i, j, val;

    cout << "Enter the no. processes: ";
    cin >> no_proc;

    cout << "\nEnter the no. of resources: ";
    cin >> no_res;

    vector <int> tot_res, stat_proc[no_proc];

    /**
    * Description about stat_proc variable
        - It is a 2D vector
        - 1st dimension holds the process number and it can be 0-no_proc
        - 2nd dimension has a total of 2*no_res indices
            # from 0 to no_res-1 it stores "Maximum value for resource" for the process in Dimension 1
            # from no_res to 2*no_res-1 it stores "Allocated from resource" for the process in Dimension 1
    **/

    for(i = 0; i < no_proc; ++i)
    {
        cout << "\nProcess " << i + 1 << "\n";

        for(j = 0; j < no_res; ++j)
        {
            cout << "Maximum value for resource " << j + 1 << ": ";
            cin >> val;
            stat_proc[i].push_back(val);
        }

        for(j = 0; j < no_res; ++j)
        {
            cout << "Allocated from resource " << j + 1 << ": ";
            cin >> val;
            stat_proc[i].push_back(val);
        }
    }

    cout << "\n";
    for(i = 0; i < no_res; ++i)
    {
        cout << "Enter total value of resource " << i + 1 << ": ";
        cin >> val;
        tot_res.push_back(val);
    }

    banker(no_proc, no_res, tot_res, stat_proc);
}

void FCFS(int cnt_head, int cur_head, vector <int> cyl_req)
{
    cout << "\nFCFS (First Come First Serve) Scheduling\n";
    cout << "----------------------------------------\n";

    cout << "Cylinder Serving Order: " << cur_head << " ";

    int i, movement = 0, l = cyl_req.size();

    for(i = 0; i < l; ++i)
    {
        movement += abs(cur_head - cyl_req[i]);
        cur_head = cyl_req[i];
        cout << "-> " << cur_head <<" ";
    }

    cout << "\nTotal Cylinder movement: " << movement << "\n";
}

void SSTF(int cnt_head, int cur_head, vector <int> cyl_req)
{
    cout << "\nSSTF (Shortest Seek time First) Scheduling\n";
    cout << "------------------------------------------\n";
    cout << "Cylinder Serving Order: " << cur_head << " ";

    int left, right, movement = 0, l = cyl_req.size();
    /// Creating a new vector vec, which along with head, will store the whole sequence
    /// It will be utilized to easily find required sequence after applying sort
    vector <int> vec;
    vec = cyl_req;
    vec.push_back(cur_head);
    sort(vec.begin(), vec.end());
    /// b_search() is a binary search that will return the index where after sorting the head is situated
    right = b_search(cur_head, vec) + 1;
    left = right - 2;

    while(l--)
    {
        if(left >= 0 && vec[right] - cur_head > cur_head - vec[left])
        {
            movement += cur_head - vec[left];
            cur_head = vec[left--];
        }
        else
        {
            movement += vec[right] - cur_head;
            cur_head = vec[right++];
        }
        cout << "-> " << cur_head <<" ";
    }
    cout << "\nTotal Cylinder movement: " << movement << "\n";
}

void CSCN(int cnt_head, int cur_head, vector <int> cyl_req)
{
    cout << "\nC-SCAN (Circular Scan) Algorithm\n";
    cout << "--------------------------------\n";
    cout << "Cylinder Serving Order: " << cur_head << " ";

    int i, ind, movement = 0, l = cyl_req.size();
    /// Creating a new vector vec, which along with head, will store the whole sequence
    /// It will be utilized to easily find required sequence after applying sort
    vector <int> vec;
    vec = cyl_req;
    vec.push_back(cur_head);
    sort(vec.begin(), vec.end());
    /// b_search() is a binary search that will return the index where after sorting the head is situated
    ind = b_search(cur_head, vec);

    for(i = ind + 1; i <= l; ++i)
    {
        movement += vec[i] - cur_head;
        cur_head = vec[i];
        cout << "-> " << cur_head <<" ";
    }

    movement += cnt_head;
    cur_head = vec[0];

    for(i = 0; i < ind; ++i)
    {
        movement += vec[i] - cur_head;
        cur_head = vec[i];
        cout << "-> " << cur_head <<" ";
    }
    cout << "\nTotal Cylinder movement: " << movement << "\n";
}

void banker(int no_proc, int no_res, vector <int> tot_res, vector <int> stat_proc[])
{
    int i, j, finished, rem_res[no_res], completed[no_proc] = {0}, cnt_complete = 0;
    vector <int> safe;

    /// Finding number of remaining slots of each resource
    for(i = 0; i < no_res; ++i)
    {
        rem_res[i] = tot_res[i];

        for(j = 0; j < no_proc; ++j)
            rem_res[i] -= stat_proc[j][no_res+i];
    }

    /// The loop shall continue until all processes are completed
    while(cnt_complete < no_proc)
    {
        finished = 0;
        for(i = 0; i < no_proc; ++i)
            if(completed[i] == 0)
            {
                for(j = 0; j < no_res; ++j)
                    if(rem_res[j] < stat_proc[i][j] - stat_proc[i][no_res+j])   /// If any of the required resources is insufficient,
                        break;                                                  /// the process cannot be completed for now

                if(j < no_res)                                                  /// Indicates ith process cannot be completed in current condition
                    continue;

                /// If  so far, the conditions are satisfied, it means we have a process that can be completed
                completed[i] = 1;
                safe.push_back(i+1);
                ++finished;

                /// Updating the remaining resources value
                for(j = 0; j < no_res; ++j)
                    rem_res[j] += stat_proc[i][no_res+j];

                /// If the following break is commented, the loop will continue to
                /// higher process number to see if more process can be found
                /// Uncommenting will mean after one process is completed, again a
                /// search will occur from process 1 in regard to find possibility of completion
                break;
            }

        /// If finished remained 0, it means, no process was able to be completed
        /// though cnt_complete < no_proc was evaluated true. So, we have a deadlock
        /// and continuing this loop will not bear any fruit
        if(finished == 0)
            break;

        /// Updating the number of completed process
        cnt_complete += finished;
    }

    /// Unable to solve deadlock
    if(cnt_complete < no_proc)
        cout << "\nResources are too limited to avoid Deadlock in this case.\n";
    else
    {
        cout << "\nThe System is currently in safe state and < ";
        for(i = 0; i < no_proc; ++i)
            cout << "P" << safe[i] << " ";
        cout << "> is the safe sequence.\n";
    }
}

/// Binary search function will be used for finding index of header at first shot
int b_search(int val, vector <int> vec)
{
    int lo, hi, mid;
    lo = 0;
    hi = vec.size()-1;

    while(lo <= hi)
    {
        mid = (lo + hi) >> 1;

        if(vec[mid] > val)
            hi = mid - 1;
        else if(vec[mid] < val)
            lo = mid + 1;
        else
            break;
    }

    return mid;
}
