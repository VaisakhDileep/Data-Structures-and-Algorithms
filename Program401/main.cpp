/*
Created by  : Vaisakh Dileep
Date		: 28, August, 2021
Description : This program demonstrates Boyer-Moore majority voting algorithm.
*/

// Boyer-Moore majority voting algorithm is used to find the majority element among the given elements('n' elements) that have more than n/2 occurrences.

#include<iostream>

#include<vector>

using namespace std;

int boyer_moore_majority_voting_algorithm(vector<int> *input_array)
{
	if(input_array == nullptr)
	{
		throw string {"ERROR - Invalid operation, input array is not valid ....."};
	}

	if(input_array->size() == 0)
	{
		throw string {"ERROR - Invalid operation, input array is empty ....."};
	}

	int counter {1}, majority_element {input_array->at(0)};

	for(int i {0}; i < input_array->size(); i++)
	{
		if(counter == 0)
		{
			majority_element = input_array->at(i);

			counter++;
		}
		else
		{
			if(majority_element == input_array->at(i))
			{
				counter++;
			}
			else
			{
				counter--;
			}
		}
	}

	counter = 0;

	for(int i {0}; i < input_array->size(); i++)
	{
		if(majority_element == input_array->at(i))
		{
			counter++;
		}
	}

	if(counter > input_array->size() / 2)
	{
		return majority_element;
	}
	else
	{
		throw string {"ERROR - Invalid operation, majority element is not present in the array ....."};
	}
}

int handle_boyer_moore_majority_voting_algorithm(vector<int>*input_array)
{
	try
	{
		return boyer_moore_majority_voting_algorithm(input_array);
	}
	catch(string &ex)
	{
		cout<<ex;

		return 0;
	}
}

int main()
{
	vector<int> vec {2, 1, 2, 2};

	cout<<"handle_boyer_moore_majority_voting_algorithm(vec): "<<handle_boyer_moore_majority_voting_algorithm(&vec)<<"\n";

	return 0;
}