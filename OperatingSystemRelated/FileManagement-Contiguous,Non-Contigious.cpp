/****
    * Name        : Tashreef Muhammad
    * ID No.      : 170104014
    * Lab Group   : A1
    * Assignment  : File Management of Operating System [Contiguous Allocation, Non-Contiguous Allocation]
****/

#include <iostream>
#include <map>

using namespace std;

void contiguous_allocation();
void noncontiguous_allocation();

int main(void)
{
    cout << "Contiguous Allocation\n";
    contiguous_allocation();
    cout << "\n\nNon-Contiguous Allocation\n";
    noncontiguous_allocation();

    return 0;
}

void contiguous_allocation()
{
    int n, sze, i, j, k, q = 3;
    char name;
    map <char, int> mp;
    cout << "Enter total number of blocks: ";
    cin >> n;
    cout << "\n";
    int blocks[n];

    for(i = 0; i < n; ++i)
        blocks[i] = -1;

    for(i = 0; i < q; ++i)
    {
        cout << "Enter Filename: ";
        cin >> name;

        cout << "Enter File-Size: ";
        cin >> sze;

        mp[name] = i;

        for(j = 0; j+sze < n; ++j)
            if(blocks[j] == -1)
            {
                for(k = 0; k < sze; ++k)
                    blocks[k+j] = i;
                break;
            }
        if(j+sze >= n)
            cout << "File " << name << " cannot be created (not enough free blocks)\n";
        else
            cout << "File " << name << " created\n";
        cout << "\n";
    }

    for(i = 0; i <= q; ++i)
    {
        cout << "Search Filename: ";
        cin >> name;

        for(j = 0; j < n; ++j)
        {
            if(mp.find(name) == mp.end())
                continue;
            if(blocks[j] == mp[name])
            {
                cout << "File Found in the blocks: " << j;
                k = j+1;
                for(k = j+1; k < n && blocks[j] == blocks[k]; ++k)
                    cout << ", " << k;
                j = n+1;
            }
        }

        if(j > n)
            cout << "\n";
        else
            cout << "File not Found.\n";
    }
}

void noncontiguous_allocation()
{
    int n, sze, i, j, k, q = 3;
    char name;
    map <char, int> mp;
    cout << "Enter total number of blocks: ";
    cin >> n;
    cout << "\n";
    int free = n, blocks[n];

    for(i = 0; i < n; ++i)
        blocks[i] = -1;

    for(i = 0; i < q; ++i)
    {
        cout << "Enter Filename: ";
        cin >> name;

        cout << "Enter File-Size: ";
        cin >> sze;

        mp[name] = i;

        if(sze > free)
            cout << "File " << name << " cannot be created (not enough free blocks)\n";
        else
        {
            if(free == n)
            {
                for(j = 0; j < n && sze > 0; j+= 2)
                {
                    blocks[j] = i;
                    --free;
                    --sze;
                }

                if(sze)
                {
                    for(j = 0; j < n && sze > 0; ++j)
                        if(blocks[j] == -1)
                        {
                            --sze;
                            --free;
                            blocks[j] = i;
                        }
                }
            }
            else
            {
                for(j = 0; j < n && sze > 0; ++j)
                    if(blocks[j] == -1)
                    {
                        --free;
                        --sze;
                        blocks[j] = i;
                    }
            }
            cout << "File " << name << " created\n";
        }

        cout << "\n";
    }

    for(i = 0; i <= q; ++i)
    {
        cout << "Search Filename: ";
        cin >> name;

        for(j = 0; j < n; ++j)
        {
            if(mp.find(name) == mp.end())
                continue;
            if(blocks[j] == mp[name])
            {
                cout << "File Found in the blocks: " << j;
                k = j+1;
                for(k = j+1; k < n; ++k)
                    if(blocks[k] == blocks[j])
                        cout << ", " << k;
                j = n+1;
            }
        }

        if(j > n)
            cout << "\n";
        else
            cout << "File not Found.\n";
    }
}
