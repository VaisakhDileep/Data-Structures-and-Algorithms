/*
Created by  : Vaisakh Dileep
Date        : 12, July, 2021
Description : This program implements grid_traveller(row, column) using memoization.
*/

// grid_traveller(row, column) finds the number of ways a traveller can move from the top-left corner to the bottom-right corner provided the traveller can only move down or right.

// The dimension of the 2-D grid is "row * column".

// Indexing of the grid starts from '0'.

#include<iostream>

#include<unordered_map>

using namespace std;

long long grid_traveller(long long row, long long column, unordered_map<string, long long> &memo)
{
    string key_1 {to_string(row) + "," + to_string(column)}, key_2 {to_string(column) + "," + to_string(row)};

    if(memo.find(key_1) != memo.end())
    {
        return memo[key_1];
    }

    if(memo.find(key_2) != memo.end()) // grid_traveller(a, b) == grid_traveller(b, a).
    {
        return memo[key_2];
    }

    if((row == 0) and (column == 0))
    {
        return 1;
    }

    if((row == -1) or (column == -1))
    {
        return 0;
    }
    memo[key_1] = grid_traveller(row - 1, column, memo) + grid_traveller(row, column - 1, memo);

    return memo[key_1];
}

long long handle_grid_traveller(long long row, long long column)
{
    unordered_map<string, long long> memo {};

    return grid_traveller(row, column, memo);
}

int main()
{
    cout<<"gird_traveller(10, 10): "<<handle_grid_traveller(10, 10)<<"\n";

    cout<<"grid_traveller(100, 100): "<<handle_grid_traveller(100, 100)<<"\n"; // Notice here we get the result without any delay.

    return 0;
}