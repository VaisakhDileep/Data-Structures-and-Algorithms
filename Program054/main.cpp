/*
Created by  : Vaisakh Dileep
Date		: 1, May, 2021
Description : This program checks if an element is present in an array.
*/

#include<iostream>

using namespace std;

struct Array
{
	int *A;

	int size;

	int length;
};

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

bool handle_check_element_array(const Array *A, int value)
{
	try
	{
		return check_element_array(A, value);
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

	handle_check_element_array(&A, 1);
	cout<<"\n";

	cout<<"check_element_array(B, 1): "<<handle_check_element_array(&B, 1)<<"\n";

	cout<<"check_element_array(B, -1): "<<handle_check_element_array(&B, -1)<<"\n";

	return 0;
}