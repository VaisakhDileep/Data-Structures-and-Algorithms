/*
Created by  : Vaisakh Dileep
Date        : 12, July, 2021
Description : This program implements grid_traveller(row, column) using recursion.
*/

// grid_traveller(row, column) finds the number of ways a traveller can move from the top-left corner to the bottom-right corner provided the traveller can only move down or right.

// The dimension of the 2-D grid is "row * column".

// Indexing of the grid starts from '0'.

#include<iostream>

using namespace std;

long long grid_traveller(long long row, long long column)
{
    if((row == 0) and (column == 0))
    {
        return 1;
    }

    if((row == -1) or (column == -1))
    {
        return 0;
    }

    return grid_traveller(row - 1, column) + grid_traveller(row, column - 1);
}

int main()
{
    cout<<"grid_traveller(10, 10): "<<grid_traveller(10, 10)<<"\n";

    cout<<"gird_traveller(100, 100): "<<grid_traveller(100, 100)<<"\n"; // This will take forever.

    return 0;
}