/*
Created by  : Vaisakh Dileep
Date		: 29, August, 2021
Description : This program performs iterative binary search on a sorted array.
*/

// Binary search will only work for sorted arrays.

#include<iostream>

#include<vector>

using namespace std;

int binary_search(vector<int> *input_array, int target)
{
	if(input_array == nullptr)
	{
		throw string {"ERRRO - Invalid operation, input array is not valid ....."};
	}

	if(input_array->size() == 0)
	{
		throw string {"ERROR - Invalid operation, input array is empty ....."};
	}

	int left {0}, right {input_array->size() - 1};

	while(left <= right)
	{
		int mid {left + (right - left) / 2};

		if(input_array->at(mid) == target)
		{
			return mid;
		}
		else if(input_array->at(mid) > target)
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}

	throw string {"ERROR - Invalid operation, target element not present in the input array ....."};
}

int handle_binary_search(vector<int> *input_array, int target)
{
	try
	{
		return binary_search(input_array, target);
	}
	catch(string &ex)
	{
		cout<<ex;

		return INT_MIN; // "INT_MIN" is returned in the case of an unsuccessful search.
	}
}

int main()
{
	vector<int> vec {3, 4, 8, 9, 10, 11, 12, 15};

	cout<<"handle_binary_search(vec, 4): "<<handle_binary_search(&vec, 4)<<"\n";

	return 0;
}