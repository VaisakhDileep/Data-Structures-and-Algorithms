/*
Created by  : Vaisakh Dileep
Date		: 24, August, 2021
Description : This program demonstrates quick sort.
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

void swap(int &a, int &b)
{
	int temp {a};

	a = b;
	b = temp;
}

int partition_array(vector<int> *vec, int left, int right)
{
	int pivot {vec->at(left)}, l {left}, r {right};

	while(l < r)
	{
		do
		{
			l++;
		}while(vec->at(l) <= pivot);

		do
		{
			r--;
		}while(vec->at(r) > pivot);

		if(l < r)
		{
			swap(vec->at(l), vec->at(r));
		}
	}

	swap(vec->at(r), vec->at(left));

	return r;
}

void quick_sort(vector<int> *vec, int left, int right)
{
	if(left < right)
	{
		int pivot_location {partition_array(vec, left, right)};

		quick_sort(vec, left, pivot_location); // pivot_location acts as extreme upper bound.
		quick_sort(vec, pivot_location + 1, right);
	}
}

void handle_quick_sort(vector<int> *vec)
{
	if(vec == nullptr)
	{
		cout<<"ERROR - Invalid operation, input array is not valid .....";

		return ;
	}

	vec->push_back(INT_MAX);

	quick_sort(vec, 0, vec->size() - 1);

	vec->pop_back();
}

int main()
{
	vector<int> vec {9, 8, 1, 2, 3, 7, 2, 8};

	cout<<"vec: ";
	display_array(&vec);
	cout<<"\n";

	handle_quick_sort(&vec);

	cout<<"vec: ";
	display_array(&vec);
	cout<<"\n";

	return 0;
}