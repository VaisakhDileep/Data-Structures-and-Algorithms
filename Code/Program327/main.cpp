/*
Created by  : Vaisakh Dileep
Date        : 13, July, 2021
Description : This program implements can_sum(target_sum, array) using recursion.
*/

// can_sum(target_sum, array) returns a boolean indicating whether or not it is possible to generate the "target_sum" using the numbers in the array(numbers in the array can be used as many times as needed).

// All the input numbers are non-negative.

#include<iostream>

using namespace std;

bool can_sum(long long target_sum, long long *A, long long size)
{
    if(target_sum == 0) // Just don't select any number in the array.
    {
        return true;
    }

    if(target_sum < 0)
    {
        return false;
    }

    for(long long i {0}; i < size; i++)
    {
        long long remainder {target_sum - A[i]};

        if(can_sum(remainder, A, size) == true)
        {
            return true;
        }
    }

    return false; // If the for loop fails(all the branches result in false).
}

int main()
{
    cout<<"can_sum(10, new long long[2] {7, 14}, 2): "<<can_sum(10, new long long[2] {7, 14}, 2)<<"\n";

    cout<<"can_sum(100, new long long[2] {7, 14}, 2): "<<can_sum(100, new long long[2] {7, 14}, 2)<<"\n";

    cout<<"can_sum(1000, new long long[2] {7, 14}, 2): "<<can_sum(1000, new long long[2] {7, 14}, 2)<<"\n"; // This will take forever.

    return 0;
}