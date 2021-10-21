/*
Created by  : Vaisakh Dileep
Date        : 21, October, 2021
Description : This program demonstrates shell sort on an array.
*/

#include<iostream>

#include<vector>

using namespace std;

void display_array(vector<int> *vec)
{
    if(vec == nullptr)
    {
        cout<<"[ ]";

        return ;
    }

    cout<<"[ ";
    for(int i {0}; i < vec->size(); i++)
    {
        cout<<vec->at(i)<<" ";
    }
    cout<<"]";
}

void shell_sort(vector<int> *vec)
{
// Insertion sort is adaptive, this means that if the array is partially sorted then we can sort faster. In each iteration of the shell sort we will perform insertion sort with a certain gap, so that the heavier elements can pushed to the right and the lighter elements can be pushed to the left. In our final iteration we get insertion sort(gap = 1) with a partially sorted array.

// Time complexity of shell sort varies with the gap size that we select.

    if(vec == nullptr)
    {
        throw string {"ERROR - Invalid operation, input array is not valid ....."};
    }

    if(vec->size() == 0)
    {
        throw string {"ERROR - Invalid operation, input array is empty ....."};
    }

    for(int gap {vec->size() / 2}; gap >= 1; gap /= 2) // "gap" gets divided in half after each iteration. "gap" starts with half the size of the matrix.
    {
        for(int i {gap}; i < vec->size(); i++)
        {
            int temp {vec->at(i)};

            int j {i - gap};

            while((j >= 0) and (vec->at(j) > temp))
            {
                vec->at(j + gap) = vec->at(j);

                j -= gap;
            }

            vec->at(j + gap) = temp;
        }
    }
}

void handle_shell_sort(vector<int> *vec)
{
    try
    {
        shell_sort(vec);
    }
    catch(string &ex)
    {
        cout<<ex;
    }
}

int main()
{
    vector<int> vec {10, 8, 2, 1, 7, 9, 19, 10};

    shell_sort(&vec);

    cout<<"vec: ";
    display_array(&vec);
    cout<<"\n";

    return 0;
}