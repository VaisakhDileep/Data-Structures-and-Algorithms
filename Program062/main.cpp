/*
Created by  : Vaisakh Dileep
Date		: 2, May, 2021
Description : This program finds multiple missing elements in a sorted array.
*/

// sorted here means ascending order.

#include<iostream>

#define MAX_SIZE 10'000

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

Array multiple_missing_elements_sorted_array(Array *A) // 'A' shouldn't contain duplicate elements.
{
	if((A->length == 0) or (A->A == nullptr))
	{
		throw string {"ERROR - Invalid operation, array is empty ....."};
	}

	int l {A->A[0]};

	int diff {l};

	Array missing_elements {create_dynamic_array(MAX_SIZE), MAX_SIZE, 0};

	for(int i {0}; i < A->length; i++)
	{
		if((A->A[i] - i) != diff)
		{
			while(diff < (A->A[i] - i))
			{
				append_array(&missing_elements, diff + i);

				diff++;
			}
		}
	}

	if(missing_elements.length != 0)
	{
		return missing_elements;
	}
	else
	{
		throw string {"ERROR - Invalid operation, array is continuous ....."};
	}
}

Array handle_multiple_missing_elements_sorted_array(Array *A)
{
	try
	{
		return multiple_missing_elements_sorted_array(A);
	}
	catch(string &ex)
	{
		cout<<ex;
	}
}

int main()
{
	Array A {nullptr, 0, 0};

	Array B {new int[5] {1, 2, 3, 4, 5}, 5, 5};

	Array C {new int[5] {1, 2, 4, 6, 9}, 5, 5};

	handle_multiple_missing_elements_sorted_array(&A);
	cout<<"\n";

	handle_multiple_missing_elements_sorted_array(&B);
	cout<<"\n";

	Array temp {handle_multiple_missing_elements_sorted_array(&C)};

	cout<<"multiple_missing_elements_sorted_array(C): ";
	display_array(&temp);
	cout<<"\n";

	return 0;
}