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

void count_sort(vector<int> *vec)
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

	}
}

int main()
{
	return 0;
}