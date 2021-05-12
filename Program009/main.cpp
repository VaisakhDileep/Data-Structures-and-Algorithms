/*
Created by  : Vaisakh Dileep
Date		: 26, April, 2021
Description : This program helps to understand how to return an array as return-type.
*/

#include<iostream>

using namespace std;

int* create_dynamic_array(int size, int initial_value = 0)
{
	int *p;

	p = new int[size];

	for(int i {0}; i < size; i++)
	{
		p[i] = initial_value;
	}

	return p;
}

void display_array(int A[], int size)
{
	cout<<"[ ";
	for(int i {0}; i < size; i++)
	{
		cout<<A[i]<<" ";
	}
	cout<<"]";
}

int main()
{
	int size {10};

	int *p = create_dynamic_array(size, 5);

	cout<<"p: ";
	display_array(p, size);
	cout<<"\n";

	return 0;
}