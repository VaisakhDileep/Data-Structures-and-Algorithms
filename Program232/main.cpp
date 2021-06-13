/*
Created by  : Vaisakh Dileep
Date		: 13, June, 2021
Description : This program demonstrates insertions sort in an array.
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

void insertion_sort(Array *A)
{
	if(A == nullptr)
	{
		throw string {"ERROR - Invalid operation, array is not valid ....."};
	}

	for(int i {1}; i < A->size; i++)
	{
		int j {i - 1};

		int temp {A->A[i]};

		while((j >= 0) and (A->A[j] > temp))
		{
			A->A[j + 1] = A->A[j];

			j--;
		}

		A->A[j + 1] = temp;
	}
}

void handle_insertion_sort(Array *A)
{
	try
	{
		insertion_sort(A);
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

	handle_insertion_sort(&A);

	cout<<"A: ";
	display_array(&A);
	cout<<"\n";

	return 0;
}