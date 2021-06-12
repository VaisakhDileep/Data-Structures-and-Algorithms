/*
Created by  : Vaisakh Dileep
Date		: 12, June, 2021
Description : This program finds the first 'n' largest elements in an array using bubble sort.
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

Array* first_n_largest_elements(Array *A, int n)
{
	if(A == nullptr)
	{
		throw string {"ERROR - Invalid operation, array is not valid ....."};
	}

	if(n > A->size)
	{
		throw string {"ERROR - Invalid operation, value of 'n' increased the size of the array ....."};
	}

	Array *result {new Array {new int[A->size] {}, A->size, n}};

	for(int i {0}; i < n; i++)
	{
		for(int j {0}; j < (A->size - 1- i); j++)
		{
			if(A->A[j] > A->A[j + 1])
			{
				swap(A->A[j], A->A[j + 1]);
			}
		}

		result->A[i] = A->A[A->size - 1 - i];
	}

	return result;
}

Array* handle_first_n_largest_elements(Array *A, int n)
{
	try
	{
		return first_n_largest_elements(A, n);
	}
	catch(string &ex)
	{
		cout<<ex;

		return nullptr;
	}
}

int main()
{
	Array A {new int[6] {9, 4, 3, 10, 7, 2}, 6, 6};

	cout<<"A: ";
	display_array(&A);
	cout<<"\n";

	Array *result {handle_first_n_largest_elements(&A, 3)};

	cout<<"result: ";
	display_array(result);
	cout<<"\n";

	result = handle_first_n_largest_elements(&A, 7);
	cout<<"\n";

	return 0;
}