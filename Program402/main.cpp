/*
Created by  : Vaisakh Dileep
Date		: 28, August, 2021
Description : This program performs recursive binary search on an array.
*/

// Binary search will only work for sorted arrays.

#include<iostream>

#include<vector>

using namespace std;

int binary_search(vector<int> *input_array, int left, int right, int target)
{
	if(left <= right)
	{
		int mid {left + (right - left) / 2};

		if(input_array->at(mid) == target)
		{
			return mid;
		}

		if(input_array->at(mid) > target)
		{
			return binary_search(input_array, left, mid - 1, target);
		}

		if(input_array->at(mid) < target)
		{
			return binary_search(input_array, mid + 1, right, target);
		}
	}
	else
	{
		throw string {"ERROR - Invalid operation, target element is not present in the input array ....."};
	}
}

int handle_binary_search(vector<int> *input_array, int target)
{
	if(input_array == nullptr)
	{
		cout<<"ERROR - Invlaid operation, input array is not valid .....";

		return INT_MIN; // "INT_MIN" is returned in the case of an unsuccessful search.
	}

	if(input_array->size() == 0)
	{
		cout<<"ERROR - Invalid operation, input array is not valid .....";

		return INT_MIN;
	}

	try
	{
		return binary_search(input_array, 0, input_array->size() - 1, target);
	}
	catch(string &ex)
	{
		cout<<ex;

		return INT_MIN;
	}
}

int main()
{
	vector<int> vec {0, 2, 3, 4, 8, 9, 10, 11};

	cout<<"handle_binary_search(vec, 3): "<<handle_binary_search(&vec, 3);

	return 0;
}