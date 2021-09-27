/*
Created by  : Vaisakh Dileep
Date        : 5, August, 2021
Description : This program implements 0-1 knapsack problem using tabulation.
*/

// Given weights and profits of 'n' items, we have to put these items in a knapsack of capacity 'W' to get the maximum total profit.

#include<iostream>

#include<vector>

using namespace std;

int zero_one_knap_sack(int *weights, int *profits, int W, int size) // Time Complexity: O(n * W)
{
    if(weights == nullptr)
    {
        throw string {"ERROR - Invalid operation, weights array is not valid ....."};
    }

    if(profits == nullptr)
    {
        throw string {"ERROR - Invalid operation, profits array is not valid ....."};
    }

    if(size < 0)
    {
        throw string {"ERROR - Invalid operation, size cannot be negative ....."};
    }

    vector<vector<int>> table(size + 1, vector<int>(W + 1, 0)); // result will be stored at "table[size - 1][W]".

    for(int i {0}; i <= size; i++)
    {
        for(int j {0}; j <= W; j++)
        {
            if((i == 0) or (j == 0))
            {
                table.at(i).at(j) = 0;
            }
            else if(weights[i - 1] > j)
            {
                table.at(i).at(j) = table.at(i - 1).at(j);
            }
            else
            {
                table.at(i).at(j) = max((profits[i - 1] + table.at(i - 1).at(j - weights[i - 1])), table.at(i - 1).at(j));
            }
        }
    }
    return table.at(size).at(W);
}

int handle_zero_one_knap_sack(int *weights, int *profits, int W, int size)
{
    try
    {
        return zero_one_knap_sack(weights, profits, W, size);
    }
    catch(string &ex)
    {
        cout<<ex;
    }
}

int main()
{
    int *weights {new int[3] {10, 20, 30}};

    int *profits {new int[3] {60, 100, 120}};

    cout<<"handle_zero_one_knap_sack(weights, profits, 50, 3): "<<handle_zero_one_knap_sack(weights, profits, 50, 3)<<"\n";

    return 0;
}