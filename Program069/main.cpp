/*
Created by  : Vaisakh Dileep
Date		: 3, May, 2021
Description : This program removes all the duplicate elements in an array.
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

void append_array(Array *A, int value)
{
	if(A->A == nullptr)
	{
		A->A = new int {0};
	}

	if(A->length < A->size)
	{
		A->A[A->length] = value;

		A->length++;
	}
	else
	{
		throw string {"ERROR - Cannot append, overflow detected ....."};
	}
}

void remove_duplicate_elements_array(Array *A)
{
	if((A->length == 0) or (A->A == nullptr))
	{
		throw string {"ERROR - Invalid operation, array is empty ....."};
	}

	Array result_array {create_dynamic_array(A->size), A->size, 0};

	for(int i {0}; i < A->length; i++)
	{
		if(A->A[i] == 0)
		{
			append_array(&result_array, 0);

			break;
		}
	}

	for(int i {0}; i < A->length; i++)
	{
		if(A->A[i] != 0)
		{
			append_array(&result_array, A->A[i]);

			for(int j {i + 1}; j < A->length; j++)
			{
				if(A->A[i] == A->A[j])
				{
					A->A[j] = 0;
				}
			}
		}
	}

	delete[] A->A;

	A->A = result_array.A;

	A->size = result_array.size;

	A->length = result_array.length;
}

void handle_remove_duplicate_elements_array(Array *A)
{
	try
	{
		remove_duplicate_elements_array(A);
	}
	catch(string &ex)
	{
		cout<<ex;
	}
}

int main()
{
	Array A {nullptr, 0, 0};

	Array B {new int[5] {1, 3, 2, 5, 4}, 5, 5};

	Array C {new int[10] {0, 1, 3, 1, 0, 4, 6, 5, 4, 4}, 10, 10};

	handle_remove_duplicate_elements_array(&A);
	cout<<"\n";

	handle_remove_duplicate_elements_array(&B);

	cout<<"B: ";
	display_array(&B);
	cout<<"\n";

	handle_remove_duplicate_elements_array(&C);

	cout<<"C: ";
	display_array(&C);
	cout<<"\n";

	return 0;
}