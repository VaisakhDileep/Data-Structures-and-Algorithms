/*
Created by  : Vaisakh Dileep
Date		: 25, August, 2021
Description : This program demonstrates merge sort.
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
	
}

void merge_sort(vector<int> *vec, int left, int right)
{
	if(left < right)
	{
		int mid {left + (right - left) / 2};

		merge_sort(vec, left, mid);
		merge_sort(vec, mid + 1, right);

		merge_sorted_array();
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
	return 0;
}