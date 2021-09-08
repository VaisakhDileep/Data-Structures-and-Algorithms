/*
Created by  : Vaisakh Dileep
Date		: 28, April, 2021
Description : This program inserts an element to an array.
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

void insert_array(Array *A, int index, int value)
{
	if(A->A == nullptr)
	{
		A->A = new int {0};
	}
	
	if(A->length >= A->size)
	{
		throw string {"ERROR - Cannot insert, overflow detected ....."};
	}
	else if(index < 0)
	{
		throw string {"ERROR - Invalid index, index cannot be negative ....."};
	}
	else if(index > A->length)
	{
		throw string {"ERROR - Invalid index, index cannot be greater than the length of the array ....."};
	}
	else
	{
		for(int i {A->length}; i > index; i--)
		{
			A->A[i] = A->A[i - 1];
		}

		A->A[index] = value;

		A->length++;

	}
}

void handle_insert_array(Array *A, int index, int value)
{
	try
	{
		insert_array(A, index, value);
	}
	catch(string &ex)
	{
		cout<<ex;
	}
}

int main()
{
	Array A {create_dynamic_array(5), 5, 0};

	handle_insert_array(&A, -1, 2); // Negative index exception.
	cout<<"\n";

	handle_insert_array(&A, 1, 2); // Index exceeds array length.
	cout<<"\n";

	handle_insert_array(&A, 0, 1);
	handle_insert_array(&A, 1, 2);
	handle_insert_array(&A, 2, 3);
	handle_insert_array(&A, 3, 4);
	handle_insert_array(&A, 4, 5);

	handle_insert_array(&A, 5, 6); // Overflow will happend here.
	cout<<"\n";
	
	cout<<"A: ";
	display_array(&A);
	cout<<"\n";

	return 0;
}