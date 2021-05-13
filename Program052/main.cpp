/*
Created by  : Vaisakh Dileep
Date		: 30, April, 2021
Description : This program merges two sorted arrays.
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

Array merge_sorted_array(const Array *A, const Array *B)
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
		int i {0}, j {0};

		while((i < A->length) and (j < B->length))
		{
			if(A->A[i] < B->A[j])
			{
				result_array.A[result_array.length++] = A->A[i++];
			}
			else
			{
				result_array.A[result_array.length++] = B->A[j++];
			}
		}

		for(; i < A->length; i++)
		{
			result_array.A[result_array.length++] = A->A[i];
		}

		for(; j < B->length; j++)
		{
			result_array.A[result_array.length++] = B->A[j];
		}
	}

	return result_array;
}

Array handle_merge_sorted_array(const Array *A, const Array *B)
{
	try
	{
		return merge_sorted_array(A, B);
	}
	catch(string &ex)
	{
		cout<<ex;

		return Array {};
	}
}

int main()
{
	Array A {nullptr, 0, 0};
	Array B {nullptr, 0, 0};

	Array C {new int[5] {1, 3, 5, 7, 9}, 5, 5};
	Array D {new int[5] {0, 2, 4, 6, 8}, 5, 5};

	handle_merge_sorted_array(&A, &B);
	cout<<"\n";

	Array temp {handle_merge_sorted_array(&A, &C)};

	cout<<"merge_sorted_array(A, C): ";
	display_array(&temp);
	cout<<"\n";

	temp = handle_merge_sorted_array(&C, &A);

	cout<<"merge_sorted_array(C, A): ";
	display_array(&temp);
	cout<<"\n";

	temp = handle_merge_sorted_array(&C, &D);

	cout<<"merge_sorted_array(C, D): ";
	display_array(&temp);
	cout<<"\n";

	return 0;
}