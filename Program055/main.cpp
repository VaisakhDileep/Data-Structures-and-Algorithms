/*
Created by  : Vaisakh Dileep
Date		: 1, May, 2021
Description : This program performs union operation on two arrays.
*/

// union operation comes under set operations and no duplicate elements are allowed when passing the arrays.

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

bool check_element_array(const Array *A, int value)
{
	if((A->length == 0) or (A->A == nullptr))
	{
		throw string {"ERROR - Invalid operation, array is empty ....."};
	}

	for(int i {0}; i < A->length; i++)
	{
		if(value == A->A[i])
		{
			return true;
		}
	}

	return false;
}

Array union_array(const Array *A, const Array *B)
{
	if(((A->length == 0) or (A->A == nullptr)) and ((B->length == 0) or (B->A == nullptr)))
	{
		throw string {"ERROR - Invalid operation, both the arrays are empty ....."};
	}

	Array result_array {create_dynamic_array(A->length + B->length), (A->length + B->length), 0};

	if((A->length == 0) or (A->A == nullptr))
	{
		result_array.length = B->length;

		for(int i {0}; i < B->length; i++)
		{
			result_array.A[i] = B->A[i];
		}
	}
	else if((B->length == 0) or (B->A == nullptr))
	{
		result_array.length = A->length;
		
		for(int i {0}; i < A->length; i++)
		{
			result_array.A[i] = A->A[i];
		}
	}
	else
	{
		for(int i {0}; i < A->length; i++)
		{
			result_array.A[result_array.length++] = A->A[i];
		}

		for(int i {0}; i < B->length; i++)
		{
			if(check_element_array(A, B->A[i]))
			{
				continue;
			}
			else
			{
				result_array.A[result_array.length++] = B->A[i];
			}
		}
	}

	return result_array;
}

Array handle_union_array(const Array *A, const Array *B)
{
	try
	{
		return union_array(A, B);
	}
	catch(string &ex)
	{
		cout<<ex;
	}
}

int main()
{
	Array A {nullptr, 0, 0};
	Array B {nullptr, 0, 0};

	Array C {new int[5] {1, 7, 5, 3, 9}, 5, 5};
	Array D {new int[5] {5, 2, 0, 8, 7}, 5, 5};

	handle_union_array(&A, &B);
	cout<<"\n";

	Array temp {handle_union_array(&A, &C)};

	cout<<"union_array(A, C): ";
	display_array(&temp);
	cout<<"\n";

	temp = handle_union_array(&C, &A);

	cout<<"union_array(C, A): ";
	display_array(&temp);
	cout<<"\n";

	temp = handle_union_array(&C, &D);

	cout<<"union_array(C, D): ";
	display_array(&temp);
	cout<<"\n";

	return 0;
}