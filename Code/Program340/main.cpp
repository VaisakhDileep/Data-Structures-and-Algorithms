/*
Created by  : Vaisakh Dileep
Date		: 15, July, 2021
Description : This program implements grid_traveller(row, column) using tabulation.
*/

// grid_traveller(row, column) finds the number of ways a traveller can move from the top-left corner to the bottom-right corner provided the traveller can only move down or right.

// The dimension of the 2-D grid is "row * column".

// Indexing of the grid starts from '0'.

#include<iostream>

#include<vector>

using namespace std;

long long grid_traveller(int row, int column)
{
	vector<vector<long long>> table(row + 1);

	for(unsigned long long i {0}; i < table.size(); i++)
	{
		table.at(i) = vector<long long>(column + 1);
	}

	table.at(0).at(0) = 1;

	for(long long i {0}; i < table.size(); i++)
	{
		for(long long j {0}; j < table.at(i).size(); j++)
		{
			long long previous_row_index {i - 1}, previous_column_index {j - 1};

			if(previous_row_index >= 0)
			{
				table.at(i).at(j) += table.at(previous_row_index).at(j);
			}

			if(previous_column_index >= 0)
			{
				table.at(i).at(j) += table.at(i).at(previous_column_index);
			}
		}
	}

	return table.at(row).at(column);
}

int main()
{
	cout<<"grid_traveller(10, 10): "<<grid_traveller(10, 10)<<"\n";

	cout<<"gird_traveller(100, 100): "<<grid_traveller(100, 100)<<"\n"; // Notice here we get the result without any delay.

	return 0;
}