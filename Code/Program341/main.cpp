/*
Created by  : Vaisakh Dileep
Date        : 15, July, 2021
Description : This program implements can_sum(target_sum, array) using tabulation.
*/

// can_sum(target_sum, array) returns a boolean indicating whether or not it is possible to generate the "target_sum" using the numbers in the array(numbers in the array can be used as many times as needed).

// All the input numbers are non-negative.

#include<iostream>

#include<vector>

using namespace std;

bool can_sum(long long target_sum, long long *A, long long size)
{
    vector<bool> table(target_sum + 1, false);

    table.at(0) = true;

    for(unsigned long long i {0}; i < table.size(); i++)
    {
        if(table.at(i) == true)
        {
            for(long long j {0}; j < size; j++)
            {
                unsigned long long propogate_index {i + A[j]};

                if(propogate_index < table.size())
                {
                    table.at(propogate_index) = true;
                }
            }
        }
    }

    return table.at(target_sum);
}

int main()
{
    cout<<"can_sum(10, new long long[2] {7, 14}, 2): "<<can_sum(10, new long long[2] {7, 14}, 2)<<"\n";

    cout<<"can_sum(100, new long long[2] {7, 14}, 2): "<<can_sum(100, new long long[2] {7, 14}, 2)<<"\n";

    cout<<"can_sum(1000, new long long[2] {7, 14}, 2): "<<can_sum(1001, new long long[2] {7, 14}, 2)<<"\n"; // Notice here we get the result without any delay.

    return 0;
}