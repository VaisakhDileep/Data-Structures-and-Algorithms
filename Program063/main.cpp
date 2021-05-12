/*
Created by  : Vaisakh Dileep
Date		: 2, May, 2021
Description : This program finds all the missing elements in an array.
*/

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

int max_element_array(Array *A)
{
	if((A->length == 0) or (A->A == nullptr))
	{
		throw string {"ERROR - Invalid operation, array is empty ....."};
	}
	else
	{
		int max {A->A[0]};

		for(int i {1}; i < A->length; i++)
		{
			if(A->A[i] > max)
			{
				max = A->A[i];
			}
		}

		return max;
	}
}

int min_element_array(Array *A)
{
	if((A->length == 0) or (A->A == nullptr))
	{
		throw string {"ERROR - Invalid operation, array is empty ....."};
	}
	else
	{
		int min {A->A[0]};

		for(int i {1}; i < A->length; i++)
		{
			if(A->A[i] < min)
			{
				min = A->A[i];
			}
		}

		return min;
	}
}

Array missing_elements_array(Array *A) // 'A' shouldn't contain any negative elements.
{
	if((A->length == 0) or (A->A == nullptr))
	{
		throw string {"ERROR - Invalid operation, array is empty ....."};
	}

	int l {min_element_array(A)};
	
	int h {max_element_array(A)};

	Array H {create_dynamic_array(h + 1), (h + 1), (h + 1)};

	Array missing_elements {create_dynamic_array(MAX_SIZE), MAX_SIZE, 0};

	for(int i {0}; i < A->length; i++)
	{
		H.A[A->A[i]]++;
	}

	for(int i {l}; i <= h; i++)
	{
		if(H.A[i] == 0)
		{
			append_array(&missing_elements, i);
		}
	}

	if(missing_elements.length != 0)
	{
		return missing_elements;
	}
	else
	{
		throw string {"ERROR - Invalid operation, no missing elements in array  ....."};
	}
}

Array handle_missing_elements_array(Array *A)
{
	try
	{
		return missing_elements_array(A);
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

	Array C {new int[5] {10, 3, 1, 0, 1}, 5, 5};

	handle_missing_elements_array(&A);
	cout<<"\n";

	handle_missing_elements_array(&B);
	cout<<"\n";

	Array temp {handle_missing_elements_array(&C)};

	cout<<"missing_elements_array(C): ";
	display_array(&temp);
	cout<<"\n";

	return 0;
}