/*
Created by  : Vaisakh Dileep
Date		: 2, May, 2021
Description : This program finds the single missing element in a sorted array.
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

int single_missing_element_sorted_array(Array *A) // 'A' shouldn't contain duplicate elements.
{
	if((A->length == 0) or (A->A == nullptr))
	{
		throw string {"ERROR - Invalid operation, array is empty ....."};
	}

	int l {A->A[0]};

	const int diff {l};

	for(int i {1}; i < A->length; i++)
	{
		if((A->A[i] - i) != diff)
		{
			return i + diff;
		}
	}

	throw string {"ERROR - Invalid operation, array is continuous ....."};
}

int handle_single_missing_element_sorted_array(Array *A)
{
	try
	{
		return single_missing_element_sorted_array(A);
	}
	catch(string &ex)
	{
		cout<<ex;

		return -1;
	}
}

int main()
{
	Array A {nullptr, 0, 0};

	Array B {new int[5] {1, 2, 3, 4, 5}, 5, 5};

	Array C {new int[5] {1, 2, 3, 5, 6}, 5, 5};

	handle_single_missing_element_sorted_array(&A);
	cout<<"\n";

	handle_single_missing_element_sorted_array(&B);
	cout<<"\n";

	cout<<"single_missing_element_sorted_array(C): "<<handle_single_missing_element_sorted_array(&C);
	cout<<"\n";

	return 0;
}