/*
Created by  : Vaisakh Dileep
Date		: 1, May, 2021
Description : This program performs intersection operation on two sorted arrays.
*/

// sorted here means ascending order.

// intersection operation comes under set operations and no duplicate elements are allowed when passing the arrays.

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

Array intersection_sorted_array(const Array *A, const Array *B)
{
	if(((A->length == 0) or (A->A == nullptr)) and ((B->length == 0) or (B->A == nullptr)))
	{
		throw string {"ERROR - Invalid operation, both the arrays are empty ....."};
	}

	if(((A->length == 0) or (A->A == nullptr)) or ((B->length == 0) or (B->A == nullptr)))
	{
		throw string {"ERROR - Invalid operation, one of the array is empty ....."};
	}

	Array result_array {create_dynamic_array(A->length), A->length, 0};

	int i {0}, j {0};

	while((i < A->length) and (j < B->length))
	{
		if(A->A[i] < B->A[j])
		{
			i++;
		}
		else if(A->A[i] > B->A[j])
		{
			j++;
		}
		else
		{
			result_array.A[result_array.length++] = A->A[i++];

			j++;
		}
	}

	return result_array;
}

Array handle_intersection_sorted_array(const Array *A, const Array *B)
{
	try
	{
		return intersection_sorted_array(A, B);
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
	Array D {new int[5] {0, 2, 5, 7, 8}, 5, 5};

	handle_intersection_sorted_array(&A, &B);
	cout<<"\n";

	handle_intersection_sorted_array(&A, &C);
	cout<<"\n";

	handle_intersection_sorted_array(&C, &A);
	cout<<"\n";

	Array temp {handle_intersection_sorted_array(&C, &D)};

	cout<<"intersection_sorted_array(C, D): ";
	display_array(&temp);
	cout<<"\n";

	return 0;
}