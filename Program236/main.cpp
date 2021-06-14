/*
Created by  : Vaisakh Dileep
Date		: 14, June, 2021
Description : This program finds the first 'n' smallest elements in an array using selection sort.
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

Array* first_n_smallest_elements(Array *A, int n)
{
	if(A == nullptr)
	{
		throw string {"ERROR - Invalid operation, array is not valid ....."};
	}

	if(n > A->size)
	{
		throw string {"ERROR - Invalid operation, value of 'n' exceeds the size of the array ....."};
	}

	Array *result_array {new Array {new int[n] {}, A->size, n}};

	for(int i {0}; i < n; i++)
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

		result_array->A[i] = A->A[i];
	}

	return result_array;
}

Array* handle_first_n_smallest_elements(Array *A, int n)
{
	try
	{
		return first_n_smallest_elements(A, n);
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

	Array *result {handle_first_n_smallest_elements(&A, 3)};

	cout<<"result: ";
	display_array(result);
	cout<<"\n";

	result = handle_first_n_smallest_elements(&A, 7);
	cout<<"\n";

	return 0;
}