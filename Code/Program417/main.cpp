/*
Created by  : Vaisakh Dileep
Date        : 7, September, 2021
Description : This program finds the n'th smallest element in an array using quick sort algorithm.
*/

#include<iostream>

#include<vector>

using namespace std;

int partition_array(vector<int> *input, int left, int right)
{
    int pivot {input->at(right)}; // We are selecting the last element as the pivot.

    int j {left};

    for(int i {left}; i <= right - 1; i++)
    {
        if(input->at(i) < pivot)
        {
            swap(input->at(i), input->at(j));

            j++;
        }
    }

    swap(input->at(j), input->at(right));

    return j;
}

int nth_smallest_element(vector<int> *input, int left, int right, int n)
{
    if((n > input->size() - 1) or (n < 0))
    {
        throw string {"ERROR - Invalid operation, index exceeds the bound constraints ....."};
    }

    int partition_index {partition_array(input, left, right)};

    if(partition_index == n)
    {
        return input->at(partition_index);
    }
    else if(partition_index > n)
    {
        return nth_smallest_element(input, left, partition_index - 1, n);
    }
    else if(partition_index < n)
    {
        return nth_smallest_element(input, partition_index + 1, right, n);
    }
}

int handle_nth_smallest_element(vector<int> *input, int n)
{
    try
    {
        return nth_smallest_element(input, 0, input->size() - 1, n - 1); // Make sure to subtract '1' from 'n'.
    }
    catch(string &ex)
    {
        cout<<ex;

        return INT_MAX;
    }
}

int main()
{
    vector<int> *input {new vector<int> {10, 2, 1, 4, 8, 8, 21}};

    cout<<"nth_smallest_element(input, 1): "<<handle_nth_smallest_element(input, 1)<<"\n";

    return 0;
}