/****
    * Name        : Tashreef Muhammad
    * ID No.      : 170104014
    * Lab Group   : A1
    * Assignment  : Page Replacement Techniques of Operating System [Even Set -> FIFO Page Replacement, Optimal Page Replacement]
***/

#include <iostream>
#include <iomanip>
#include <cstring>
#include <sstream>
#include <vector>
#include <queue>

using namespace std;

void fifo_page_replacement(int page_no, int page_frame, int ref_no, vector <int> ref_seq);
void optimal_page_replacement(int page_no, int page_frame, int ref_no, vector <int> ref_seq);

int main(void)
{
    int page_no, ref_no, page_frame, take;
    vector <int> ref_seq;
    string ref_str;

    cout << "Number of pages: ";
    cin >> page_no;

    cout << "Number of Page References: ";
    cin >> ref_no;

    cout << "Reference String: ";
    cin >> ref_str;

    stringstream str(ref_str);

    while(str >> take)
    {
        ref_seq.push_back(take);

        if(str.peek() == ',' || str.peek() == '|')
            str.ignore();
    }

    cout << "Number of Memory Page Frame: ";
    cin >> page_frame;

    fifo_page_replacement(page_no, page_frame, ref_no, ref_seq);
    optimal_page_replacement(page_no, page_frame, ref_no, ref_seq);

    return 0;
}

void fifo_page_replacement(int page_no, int page_frame, int ref_no, vector <int> ref_seq)
{
    cout << "\n\n================================";
    cout << "\nFIFO Page Replacement Algorithm:\n";
    cout << "================================\n";
    int i, inside[page_no] = {0}, page_faults = 0;
    queue <int> container;

    for(i = 0; i < ref_no; ++i)
        if(inside[ref_seq[i]] == 0)
        {
            ++page_faults;
            container.push(ref_seq[i]);
            inside[ref_seq[i]] = 1;

            if(container.size() > page_frame)
            {
                inside[container.front()] = 0;
                container.pop();
            }
        }

    cout << "Number of page fault using FIFO Page replacement Algorithm: " << page_faults << "\nPage Fault Rate: " << fixed << setprecision(0) << ((double)page_faults / (double)ref_no) * 100.0 << "%\n";
}

void optimal_page_replacement(int page_no, int page_frame, int ref_no, vector <int> ref_seq)
{
    cout << "\n\n===================================";
    cout << "\nOptimal Page Replacement Algorithm:\n";
    cout << "===================================\n";
    int i, j, k, index, distance, container[page_frame], occupy[page_frame] = {0}, inside[page_no] = {0}, page_faults = 0;

    for(i = 0; i < ref_no; ++i)
        if(inside[ref_seq[i]] == 0)
        {
            ++page_faults;

            index = i;
            if(i >= page_frame)
            {
                index = distance = 0;
                for(j = 0; j < page_frame; ++j)
                {
                    for(k = i + 1; k < ref_no; ++k)
                        if(ref_seq[k] == container[j])
                            break;

                    if(distance < k)
                    {
                        distance = k;
                        index = j;
                    }
                    else if(distance == k && occupy[index] > occupy[j])
                    {
                        distance = k;
                        index = j;
                    }
                }
                inside[container[index]] = 0;
            }

            container[index] = ref_seq[i];
            inside[ref_seq[i]] = 1;

            for(j = 0; j < page_frame; ++j)
                occupy[j]++;
        }

    cout << "Number of page fault using Optimal Page replacement Algorithm: " << page_faults << "\nPage Fault Rate: " << fixed << setprecision(0) << ((double)page_faults / (double)ref_no) * 100.0 << "%\n";
}
/*
7,0,3,5,2,2,3,2,6,18,7,6,2,1,5,15,5,1,4,18,0,7,2
*/
