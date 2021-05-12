/*
Created by  : Vaisakh Dileep
Date		: 1, May, 2021
Description : This program performs difference operation on two arrays.
*/

// difference operation comes under set operations and no duplicate elements are allowed when passing the arrays.

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

Array difference_array(const Array *A, const Array *B) // A - B
{
	if(((A->length == 0) or (A->A == nullptr)) and ((B->length == 0) or (B->A == nullptr)))
	{
		throw string {"ERROR - Invalid operation, both the arrays are empty ....."};
	}

	if((A->length == 0) or (A->A == nullptr))
	{
		throw string {"ERROR - Invalid operation, first argument cannot be an empty array ....."};
	}

	if((B->length == 0) or (B->A == nullptr))
	{
		Array result_array {*A};

		result_array.size = result_array.length;

		return result_array;
	}

	Array result_array {create_dynamic_array(A->length), A->length, 0};

	for(int i {0}; i < A->length; i++)
	{
		if(check_element_array(B, A->A[i]))
		{
			continue;
		}
		else
		{
			result_array.A[result_array.length++] = A->A[i];
		}
	}

	return result_array;
}

Array handle_difference_array(const Array *A, const Array *B)
{
	try
	{
		return difference_array(A, B);
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

	Array C {new int[5] {1, 5, 3, 9, 7}, 5, 5};
	Array D {new int[5] {2, 0, 8, 7, 5}, 5, 5};

	handle_difference_array(&A, &B);
	cout<<"\n";

	handle_difference_array(&A, &C);
	cout<<"\n";

	Array temp {handle_difference_array(&C, &A)};

	cout<<"difference_array(C, A): ";
	display_array(&temp);
	cout<<"\n";

	temp = handle_difference_array(&C, &D);

	cout<<"difference_array(C, D): ";
	display_array(&temp);
	cout<<"\n";

	temp = handle_difference_array(&D, &C);

	cout<<"difference_array(D, C): ";
	display_array(&temp);
	cout<<"\n";

	return 0;
}