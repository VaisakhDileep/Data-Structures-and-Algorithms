/*
Created by  : Vaisakh Dileep
Date        : 22, August, 2021
Description : This program performs Dutch national flag(DNF) sort.
*/

#include<iostream>

#include<vector>

using namespace std;

void dutch_national_flag_sort(vector<int> *input_array)
{
    if(input_array == nullptr)
    {
        throw string {"ERROR - Invalid operation, input array is not valid ....."};
    }
    if(input_array->size() == 0)
    {
        throw string {"ERROR - Invalid operation, input array is empty ....."};
    }

    int left {0}, mid {0}, right {input_array->size() - 1};

    while(mid <= right)
    {
        if(input_array->at(mid) == 0)
        {
            swap(input_array->at(left), input_array->at(mid));

            left++;
            mid++;
        }
        else if(input_array->at(mid) == 1)
        {
            mid++;
        }
        else if(input_array->at(mid) == 2)
        {
            swap(input_array->at(mid), input_array->at(right));

            right--; 
        }
        else
        {
            throw string {"ERROR - Invalid operation, DNF sort can only be performed for input arrays that contain only 0, 1 and 2 ....."};
        }
    }
}

void handle_dutch_national_flag_sort(vector<int> *input)
{
    try
    {
        dutch_national_flag_sort(input);
    }
    catch(string &ex)
    {
        cout<<ex;
    }
}

int main()
{
    vector<int> *input_array {new vector<int> {0, 0, 1, 2, 0, 2, 1, 1, 2}};

    handle_dutch_national_flag_sort(input_array);

    cout<<"input_array: ";
    for(int i {0}; i < input_array->size(); i++)
    {
        cout<<input_array->at(i)<<" ";
    }
    cout<<"\n";

    return 0;
}