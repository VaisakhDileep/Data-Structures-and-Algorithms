/*
Created by  : Vaisakh Dileep
Date		: 29, August, 2021
Description : This program performs jump search on an array.
*/

// Jump search will only work for sorted arrays.

#include<iostream>

#include<math.h>

#include<vector>

using namespace std;

int jump_search(vector<int> *input_array, int target) // Time Complexity: O(n^1/2)
{
	if(input_array == nullptr)
	{
		throw string {"ERROR - Invalid operation, input array is not valid ....."};
	}

	if(input_array->size() == 0)
	{
		throw string {"ERROR - Invalid operation, input array is empty ....."};
	}

	int size {input_array->size()};

	int jump {sqrt(size)};

	int start {0}, end {jump - 1};

	if(target > input_array->at(size - 1))
	{
		throw string {"ERROR - Invalid operation, target element is not present in the array ....."};
	}

	while(input_array->at(end) < target)
	{
		start = end;

		end += jump;

		if(end >= size)
		{
			end = size - 1;

			break;
		}
	}

	while(input_array->at(start) < target)
	{
		start++;
	}

	if(input_array->at(start) == target)
	{
		return start;
	}

	throw string {"ERROR - Invalid operation, target element is not present in the array ....."};
}

int handle_jump_search(vector<int> *input_array, int target)
{
	try
	{
		return jump_search(input_array, target);
	}
	catch(string &ex)
	{
		cout<<ex;

		return INT_MIN; // "INT_MIN" is returned in the case of an unsuccessful search.
	}
}

int main()
{
	vector<int> vec {1, 3, 4, 5, 7, 8, 9, 10, 14};

	cout<<"handle_jump_search(vec, 3): "<<handle_jump_search(&vec, 3)<<"\n";

	return 0;
}