/*
Created by  : Vaisakh Dileep
Date        : 12, August, 2021
Description : This program performs the range sum query operation on a prefix sum array(1-D array).
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

    if(input_array->size() == 0)
    {
        throw string {"ERROR - Invalid operation, input array is empty ....."};
    }

    vector<int> *prefix_sum {new vector<int>(input_array->size(), 0)};

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

int range_sum_query_prefix_sum_array(int query_start, int query_end, vector<int> *prefix_sum) // Both "query_start" and "query_end" are inclusive. Formulae: sum(start, end) = sum(0, end) - sum(0, start - 1).
{
    if(prefix_sum == nullptr)
    {
        throw string {"ERROR - Invalid operation, prefix sum array is not valid ....."};
    }

    if((prefix_sum->size() == 0))
    {
        throw string {"ERROR - Invalid operation, prefix sum array is empty ....."};
    }

    if((query_start < 0) or (query_end < 0))
    {
        throw string {"ERROR - Invalid operation, index cannot be negative ....."};
    }

    if((query_start >= prefix_sum->size()) or (query_end >= prefix_sum->size()))
    {
        throw string {"ERROR - Invalid operation, index exceeds the size of the prefix sum array ....."};
    }

    if(query_start > query_end)
    {
        throw string {"ERROR - Invalid operation, start index cannot exceed the end index ....."};
    }

    if(query_start == 0)
    {
        return prefix_sum->at(query_end);
    }
    else
    {
        return (prefix_sum->at(query_end) - prefix_sum->at(query_start - 1));
    }
}

int handle_range_sum_query_prefix_sum_array(int start, int end, vector<int> *prefix_sum)
{
    try
    {
        return range_sum_query_prefix_sum_array(start, end, prefix_sum);
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

    cout<<"handle_range_sum_query_prefix_sum_array(0, 0, prefix_sum): "<<handle_range_sum_query_prefix_sum_array(0, 0, prefix_sum)<<"\n";

    cout<<"handle_range_sum_query_prefix_sum_array(2, 2, prefix_sum): "<<handle_range_sum_query_prefix_sum_array(2, 2, prefix_sum)<<"\n";

    cout<<"handle_range_sum_query_prefix_sum_array(0, 2, prefix_sum): "<<handle_range_sum_query_prefix_sum_array(0, 2, prefix_sum)<<"\n";

    cout<<"handle_range_sum_query_prefix_sum_array(0, 4, prefix_sum): "<<handle_range_sum_query_prefix_sum_array(0, 4, prefix_sum)<<"\n";

    return 0;
}