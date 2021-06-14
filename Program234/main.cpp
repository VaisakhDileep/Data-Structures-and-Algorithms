/*
Created by  : Vaisakh Dileep
Date		: 13, June, 2021
Description : This program demonstrates selection sort.
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

void swap(int &a, int &b)
{
	int temp {a};

	a = b;
	b = temp;
}

void selection_sort(Array *A)
{
	if(A == nullptr)
	{
		throw string {"ERROR - Invalid operation, array is not valid ....."};
	}

	for(int i {0}; i < (A->size - 1); i++)
	{
		int k {i};

		for(int j {i}; j < A->size; j++)
		{
			if(A->A[j] < A->A[k])
			{
				k = j;
			}
		}

		swap(A->A[i], A->A[k]);
	}
}

void handle_selection_sort(Array *A)
{
	try
	{
		selection_sort(A);
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

	handle_selection_sort(&A);

	cout<<"A: ";
	display_array(&A);
	cout<<"\n";

	return 0;
}