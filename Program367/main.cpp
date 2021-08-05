/*
Created by  : Vaisakh Dileep
Date		: 4, August, 2021
Description : This program implements 0-1 knapsack problem using memoization.
*/

// Given weights and profits of 'n' items, we have to put these items in a knapsack of capacity 'W' to get the maximum total profit.

#include<iostream>

#include<vector>

using namespace std;

int zero_one_knap_sack(int *weights, int *profits, int W, int n, vector<vector<int>> &memo) // Time Complexity: O(n * w)
{
	if((n == 0) or (W == 0)) // Base case.
	{
		return 0;
	}

	if(memo.at(n - 1).at(W) != INT_MIN)
	{
		return memo.at(n - 1).at(W);
	}

	if(weights[n - 1] > W) // This item exceeds the capacity of the knapsack.
	{
		memo.at(n - 1).at(W) = zero_one_knap_sack(weights, profits, W, n - 1, memo);

		return memo.at(n - 1).at(W);
	}
	else
	{
		memo.at(n - 1).at(W) = max((profits[n - 1] + zero_one_knap_sack(weights, profits, W - weights[n - 1], n - 1, memo)), zero_one_knap_sack(weights, profits, W, n - 1, memo));

		return memo.at(n - 1).at(W);
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

	vector<vector<int>> memo(size, vector<int>(W + 1, INT_MIN)); // result will be stored at memo[size - 1][W].

	return zero_one_knap_sack(weights, profits, W, size, memo);
}

int main()
{
	int *weights {new int[3] {10, 20, 30}};

	int *profits {new int[3] {60, 100, 120}};

	cout<<"handle_zero_one_knap_sack(weights, profits, 50, 3): "<<handle_zero_one_knap_sack(weights, profits, 50, 3)<<"\n";

	return 0;
}