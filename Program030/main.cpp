/*
Created by  : Vaisakh Dileep
Date		: 28, April, 2021
Description : This program displays an array.
*/

#include<iostream>

using namespace std;

struct Array
{
	int *A;

	int size;

	int length;
};

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

void display_array(const Array *A)
{
	if(A->A == nullptr)
	{
		cout<<"[ ]";

		return ;
	}

	cout<<"[ ";
	for(int i {0}; i < A->length; i++)
	{
		cout<<A->A[i]<<" ";
	}
	cout<<"]";
}

int main()
{
	Array A {create_dynamic_array(10), 10, 0};

	cout<<"A: ";
	display_array(&A);
	cout<<"\n";

	return 0;
}