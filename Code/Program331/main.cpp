/*
Created by  : Vaisakh Dileep
Date        : 13, July, 2021
Description : This program implements best_sum(target_sum, array) using recursion.
*/

// best_sum(target_sum, array) returns an array containing the shortest combination of numbers in the array(numbers in the array can be used as many times as needed) that add up to exactly the "target_sum". If there are multiple such combinations possible, only one such combination will be returned.

// All the input numbers are non-negative.

#include<iostream>

#include<vector>

using namespace std;

void display_vector(vector<long long> *vec)
{
    if(vec == nullptr)
    {
        cout<<"[ ]";

        return ;
    }

    cout<<"[ ";
    for(unsigned long long i {0}; i < vec->size(); i++)
    {
        cout<<vec->at(i)<<" ";
    }
    cout<<"]";
}

vector<long long>* best_sum(long long target_sum, long long *A, long long size)
{
    if(target_sum == 0) // Create an empty vector, elements will be added at the return phase.
    {
        return new vector<long long> {};
    }

    if(target_sum < 0) // Return "nullptr" to denote that we cannot create any combinations for the array of numbers.
    {
        return nullptr;
    }

    vector<long long> *shortest_result {nullptr};

    for(long long i {0}; i < size; i++)
    {
        long long remainder {target_sum - A[i]};

        vector<long long> *result {best_sum(remainder, A, size)};

        if(result != nullptr)
        {
            result->push_back(A[i]);

            if((shortest_result == nullptr) or (result->size() < shortest_result->size())) // Short circuiting is used here.
            {
                shortest_result = result;
            }
        }
    }

    return shortest_result; // If the for loop fails(all the branches result in "nullptr"), "shortest_result" wouldn't be updated, it will default to "nullptr".
}

int main()
{
    vector<long long> *result {};

    cout<<"best_sum(8, new long long[3] {1, 4, 5}, 3): ";

    result = best_sum(8, new long long[3] {1, 4, 5}, 3);

    display_vector(result);
    cout<<"\n";

    cout<<"best_sum(1000, new long long[2] {7, 14}, 2): ";

    result = best_sum(1000, new long long[2] {7, 14}, 2); // This will take forever.

    display_vector(result);
    cout<<"\n";

    return 0;
}