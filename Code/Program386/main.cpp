/*
Created by  : Vaisakh Dileep
Date        : 12, August, 2021
Description : This program creates a prefix sum array for range sum query(1-D array).
*/

// This will only work for static arrays(array data cannot be changed).

#include<iostream>

#include<vector>

using namespace std;

vector<int>* create_prefix_sum_array(vector<int> *input_array)
{
    if(input_array == nullptr)
    {
        throw string {"ERROR - Invalid operation, input array is not valid ....."};
    }

    vector<int> *prefix_sum {new vector<int>(input_array->size(), 0)};

    if(input_array->size() == 0)
    {
        throw string {"ERROR - Invalid operation, input array is empty ....."};
    }

    prefix_sum->at(0) = input_array->at(0);

    for(int i {1}; i < input_array->size(); i++)
    {
        prefix_sum->at(i) = prefix_sum->at(i - 1) + input_array->at(i);
    }

    return prefix_sum;
}

vector<int>* handle_create_prefix_sum_array(vector<int> *input_array)
{
    try
    {
        return create_prefix_sum_array(input_array);
    }
    catch(string &ex)
    {
        cout<<ex;
    }
}

int main()
{
    vector<int> *input_array {new vector<int> {1, 2, 3, 4, 5}};

    vector<int> *prefix_sum {handle_create_prefix_sum_array(input_array)};

    return 0;
}