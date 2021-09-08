/*
Created by  : Vaisakh Dileep
Date		: 29, August, 2021
Description : This program performs interpolation search on an array.
*/

// Interpolation search will only work for sorted arrays(preferably the array should be fairly uniform).

#include<iostream>

#include<vector>

using namespace std;

int interpolation_search(vector<int> *input_array, int low, int high, int target)
{
	if(input_array == nullptr)
	{
		throw string {"ERROR - Invalid operation, input array is not valid ....."};
	}

	if(input_array->size() == 0)
	{
		throw string {"ERROR - Invalid operation, input array is empty ....."};
	}

	if(low <= high)
	{
		int position {low + (static_cast<int>((static_cast<double>(target - input_array->at(low)) / static_cast<double>(input_array->at(high) - input_array->at(low)))) * (high - low))};

		if(input_array->at(position) == target)
		{
			return position;
		}

		if(input_array->at(position) > target)
		{
			return interpolation_search(input_array, low, position - 1, target);
		}

		if(input_array->at(position) < target)
		{
			return interpolation_search(input_array, position + 1, high, target);
		}
	}

	throw string {"ERROR - Invalid operation, target element is not present in the input array ....."};
}

int handle_interpolation_search(vector<int> *input_array, int target)
{
	if(input_array == nullptr)
	{
		cout<<"ERROR - Invalid operation, input array is not valid .....";

		return INT_MIN; // "INT_MIN" is returned in the case of an unsuccessful search.
	}

	if(input_array->size() == 0)
	{
		cout<<"ERROR - Invalid operation, input array is empty .....";

		return INT_MIN;
	}

	try
	{
		return interpolation_search(input_array, 0, input_array->size() - 1, target);
	}
	catch(string &ex)
	{
		cout<<ex;

		return INT_MIN;
	}
}

int main()
{
	vector<int> vec {1, 2, 3, 4, 5, 6};

	cout<<"handle_interpolation_search(vec): "<<handle_interpolation_search(&vec, 6)<<"\n";

	return 0;
}