/*
Created by  : Vaisakh Dileep
Date        : 4, August, 2021
Description : This program implements 0-1 knapsack problem using recursion.(brute force approach)
*/

// Given weights and profits of 'n' items, we have to put these items in a knapsack of capacity 'W' to get the maximum total profit.

#include<iostream>

using namespace std;

int zero_one_knap_sack(int *weights, int *profits, int W, int n) // Time Complexity: O(2^n)
{
    if((n == 0) or (W == 0)) // Base case.
    {
        return 0;
    }

    if(weights[n - 1] > W) // This item exceeds the capacity of the knapsack.
    {
        return zero_one_knap_sack(weights, profits, W, n - 1);
    }
    else
    {
        return max((profits[n - 1] + zero_one_knap_sack(weights, profits, W - weights[n - 1], n - 1)) , zero_one_knap_sack(weights, profits, W, n - 1)); // C++ has a built in "max()" function.
    }
}

int handle_zero_one_knap_sack(int *weights, int *profits, int W, int size)
{
    if(weights == nullptr)
    {
        cout<<"ERROR - Invalid operation, weights array is not valid .....";

        return 0;
    }

    if(profits == nullptr)
    {
        cout<<"ERROR - Invalid operation, profits array is not valid .....";

        return 0;
    }

    if(size < 0)
    {
        cout<<"ERROR - Invalid operation, size cannot be negative .....";

        return 0;
    }

    return zero_one_knap_sack(weights, profits, W, size);
}

int main()
{
    int *weights {new int[3] {10, 20, 30}};

    int *profits {new int[3] {70, 200, 100}};

    cout<<"handle_zero_one_knap_sack(weights, profits, 40, 3): "<<handle_zero_one_knap_sack(weights, profits, 40, 3)<<"\n";

    return 0;
}