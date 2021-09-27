/*
Created by  : Vaisakh Dileep
Date        : 13, July, 2021
Description : This program implements how_sum(target_sum, array) using memoization.
*/

// how_sum(target_sum, array) returns an array containing any combination of numbers in the array(numbers in the array can be used as many times as needed) that add up to exactly the "target_sum". If there are multiple combinations possible, only one such combination will be returned.

// All the input numbers are non-negative.

#include<iostream>

#include<vector>

#include<unordered_map>

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

vector<long long>* how_sum(long long target_sum, long long *A, long long size, unordered_map<long long, vector<long long>*> &memo)
{
    if(memo.find(target_sum) != memo.end())
    {
        return memo[target_sum];
    }

    if(target_sum == 0) // Create an empty vector, elements will be added at the return phase.
    {
        return new vector<long long> {};
    }

    if(target_sum < 0) // Return "nullptr" to denote that we cannot create any combinations for the array of numbers.
    {
        return nullptr;
    }

    for(long long i {0}; i < size; i++)
    {
        long long remainder {target_sum - A[i]};

        vector<long long> *result {how_sum(remainder, A, size, memo)};

        if(result != nullptr)
        {
            result->push_back(A[i]);

            memo[target_sum] = result;

            return result;
        }
    }

    memo[target_sum] = nullptr;

    return nullptr; // If the for loop fails(all the branches result in "nullptr").
}

vector<long long>* handle_how_sum(long long target_sum, long long *A, long long size)
{
    unordered_map<long long, vector<long long>*> memo {};

    return how_sum(target_sum, A, size, memo);
}

int main()
{
    vector<long long> *result {};

    cout<<"how_sum(30, new long long[4] {8, 4, 2, 1}, 4): ";

    result = handle_how_sum(30, new long long[4] {8, 4, 2, 1}, 4);

    display_vector(result);
    cout<<"\n";

    cout<<"how_sum(1000, new long long[2] {7, 14}, 2): ";

    result = handle_how_sum(1000, new long long[2] {7, 14}, 2); // Notice here we get the result without any delay.

    display_vector(result);
    cout<<"\n";

    return 0;
}