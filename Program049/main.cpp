/*
Created by  : Vaisakh Dileep
Date		: 30, April, 2021
Description : This program inserts an element to a sorted array.
*/

// sorted here means ascending order.

#include<iostream>

using namespace std;

struct Array
{
	int *A;

	int size;

	int length;
};

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

void insert_sorted_array(Array *A, int value)
{
	if(A->A == nullptr)
	{
			A->A = new int {0};
	}

	if(A->length >= A->size)
	{
		throw string {"ERROR - cannot insert, overflow detected ....."};
	}
	else
	{
		int i {A->length - 1};

		A->length++;

		while((A->A[i] > value) and (i >= 0))
		{
			A->A[i + 1] = A->A[i];

			i--;
		}

		A->A[i + 1] = value;
	}
}

int main()
{
	Array A {nullptr, 10, 0};

	insert_sorted_array(&A, 2);
	insert_sorted_array(&A, 5);
	insert_sorted_array(&A, 3);

	cout<<"A: ";
	display_array(&A);
	cout<<"\n";

	return 0;
}