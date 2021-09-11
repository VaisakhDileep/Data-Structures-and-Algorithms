/*
Created by  : Vaisakh Dileep
Date		: 11, September, 2021
Description : This program performs binary search on a sorted 2-D array.
*/

// Binary search will only work for sorted 2-D arrays.

#include<iostream>

#include<vector>

using namespace std;

pair<int, int> binary_search(vector<vector<int>*> *input_matrix, int left, int right, int target)
{
	int row_count {input_matrix->size()}, column_count {input_matrix->at(0)->size()};

	if(left <= right)
	{
		int mid {left + (right - left) / 2};

		int current_element {input_matrix->at(mid / column_count)->at(mid % column_count)};

		if(current_element == target)
		{
			return pair<int, int> {mid / column_count, mid % column_count};
		}

		if(current_element > target)
		{
			return binary_search(input_matrix, left, mid - 1, target);
		}

		if(current_element < target)
		{
			return binary_search(input_matrix, mid + 1, right, target);
		}
	}
	else
	{
		throw string {"ERROR - Invalid operation, target element is not present in the input matrix ....."};
	}
}

pair<int, int> handle_binary_search(vector<vector<int>*> *input_matrix, int target)
{
	if(input_matrix == nullptr)
	{
		cout<<"ERROR - Invalid operation, input matrix is not valid .....";

		return pair<int, int> {INT_MIN, INT_MIN}; // "INT_MIN" is returned in the case of an unsuccessful search.
	}

	if(input_matrix->size() == 0)
	{
		cout<<"ERROR - Invalid operation, input matrix is empty .....";

		return pair<int, int> {INT_MIN, INT_MIN};
	}

	int row_count {input_matrix->size()}, column_count {input_matrix->at(0)->size()};

	try
	{
		return binary_search(input_matrix, 0, row_count * column_count - 1, target);
	}
	catch(string &ex)
	{
		cout<<ex;

		return pair<int, int> {INT_MIN, INT_MIN};
	}
}

int main()
{
	vector<vector<int>*> *input_matrix {new vector<vector<int>*> {new vector<int> {4, 8, 10, 15}, new vector<int> {26, 37, 45, 50}, new vector<int> {60, 61, 67, 100}}};

	pair<int, int> index {handle_binary_search(input_matrix, 37)};

	cout<<"handle_binary_search(input_matrix, 37): {"<<index.first<<", "<<index.second<<"}\n";

	return 0;
}