/*
Created by  : Vaisakh Dileep
Date		: 26, April, 2021
Description : This program helps to understand how to allocate memory dynamically in the heap.
*/

#include<iostream>

using namespace std;

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
	int *p {nullptr}; // Declaration + Iteration

	int size {5};

	p = new int {5};

	cout<<"*p: "<<*p<<"\n";

	p = new int[5] {1, 2, 3, 4, 5};

	cout<<"p: ";
	display_array(p, size);
	cout<<"\n";

	delete[] p;

	return 0;
}