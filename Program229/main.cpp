/*
Created by  : Vaisakh Dileep
Date		: 12, June, 2021
Description : This program demonstrates bubble sort.
*/

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

void bubble_sort(Array *A)
{
	if(A == nullptr)
	{
		throw string {"ERROR - Invalid operation, array is not valid ....."};
	}

	for(int i {0}; i < A->size - 1; i++)
	{
		for(int j {0}; j < (A->size - 1 - i); j++)
		{
			if(A->A[j] > A->A[j + 1])
			{
				swap(A->A[j], A->A[j + 1]); // C++ has a built in swap function.
			}
		}
	}
}

void handle_bubble_sort(Array *A)
{
	try
	{
		bubble_sort(A);
	}
	catch(string &ex)
	{
		cout<<ex;
	}
}

int main()
{
	Array A {new int[6] {9, 1, 3, 8, 5, 10}, 6, 6};

	cout<<"A: ";
	display_array(&A);
	cout<<"\n";

	handle_bubble_sort(&A);

	cout<<"A: ";
	display_array(&A);
	cout<<"\n";

	return 0;
}