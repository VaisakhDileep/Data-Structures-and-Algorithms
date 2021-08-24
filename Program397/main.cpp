/*
Created by  : Vaisakh Dileep
Date		: 24, August, 2021
Description : This program demonstrates count sort.
*/

#include<iostream>

#include<vector>

using namespace std;

void display_array(vector<int> *vec)
{
	if(vec == nullptr)
	{
		cout<<"[ ]";

		return ;
	}

	cout<<"[ ";
	for(int i {0}; i < vec->size(); i++)
	{
		cout<<vec->at(i)<<" ";
	}
	cout<<"]";
}

void count_sort(vector<int> *vec) // Count sort is preferred when the range of the input array is small.
{
	if(vec == nullptr)
	{
		throw string {"ERROR - Invalid operation, input array is not valid ....."};
	}

	if(vec->size() == 0)
	{
		throw string {"ERROR - Invalid operation, input array is empty ....."};
	}

	int max_element {vec->at(0)};

	for(int i {1}; i < vec->size(); i++)
	{
		max_element = max(max_element, vec->at(i));
	}

	vector<int> count_array(max_element + 1, 0);

	for(int i {0}; i < vec->size(); i++)
	{
		if(vec->at(i) < 0)
		{
			throw string {"ERROR - Invalid operation, count sort fails for input arrays with negative elements ....."};
		}

		count_array[vec->at(i)]++;
	}

	int j {};

	for(int i {0}; i < vec->size();)
	{
		if(count_array[i] > 0)
		{
			vec->at(j++) = i;

			count_array[i]--;
		}
		else
		{
			i++;
		}
	}
}

void handle_count_sort(vector<int> *vec)
{
	try
	{
		count_sort(vec);
	}
	catch(string &ex)
	{
		cout<<ex;
	}
}

int main()
{
	vector<int> vec {2, 2, 1, 3, 4, 4, 5, 8, -9, 0, 0};

	cout<<"vec: ";
	display_array(&vec);
	cout<<"\n";

	handle_count_sort(&vec);

	cout<<"vec: ";
	display_array(&vec);
	cout<<"\n";

	return 0;
}