/*
Created by  : Vaisakh Dileep
Date		: 25, August, 2021
Description : This program demonstrates merge sort on an array.
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

void merge_sorted_array(vector<int> *vec, int start_1, int end_1, int start_2, int end_2)
{
	vector<int> array_1(end_1 - start_1 + 1, 0), array_2(end_2 - start_2 + 1, 0);

	for(int i {0}; i < array_1.size(); i++)
	{
		array_1[i] = vec->at(start_1 + i);
	}

	for(int i {0}; i < array_2.size(); i++)
	{
		array_2[i] = vec->at(start_2 + i);
	}

	int array_1_i {0}, array_2_i {0}, vec_i {start_1};

	while((array_1_i < array_1.size()) and (array_2_i < array_2.size()))
	{
		if(array_1[array_1_i] < array_2[array_2_i])
		{
			vec->at(vec_i++) = array_1[array_1_i++];
		}
		else
		{
			vec->at(vec_i++) = array_2[array_2_i++];
		}
	}

	while(array_1_i < array_1.size())
	{
		vec->at(vec_i++) = array_1[array_1_i++];
	}

	while(array_2_i < array_2.size())
	{
		vec->at(vec_i++) = array_2[array_2_i++];
	}
}

void merge_sort(vector<int> *vec, int left, int right)
{
	if(left < right)
	{
		int mid {left + (right - left) / 2};

		merge_sort(vec, left, mid);
		merge_sort(vec, mid + 1, right);

		merge_sorted_array(vec, left, mid, mid + 1, right);
	}
}

void handle_merge_sort(vector<int> *vec)
{
	if(vec == nullptr)
	{
		cout<<"ERROR - Invalid operation, input array is not valid .....";

		return ;
	}

	if(vec->size() == 0)
	{
		cout<<"ERROR - Invalid operation, input array is empty .....";

		return ;
	}

	merge_sort(vec, 0, vec->size() - 1);
}

int main()
{
	vector<int> vec {3, 1, 2, 4, 1, 3, 8, 9, 10, 0};

	cout<<"vec: ";
	display_array(&vec);
	cout<<"\n";

	handle_merge_sort(&vec);

	cout<<"vec: ";
	display_array(&vec);
	cout<<"\n";

	return 0;
}