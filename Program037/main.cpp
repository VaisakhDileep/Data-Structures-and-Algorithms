/*
Created by  : Vaisakh Dileep
Date		: 29, April, 2021
Description : This program gets an element from an array.
*/

#include<iostream>

using namespace std;

struct Array
{
	int *A;

	int size;

	int length;
};

int get_element_array(const Array *A, int index)
{
	if((A->A == nullptr) or (A->length == 0))
	{
		throw string {"ERROR - Invalid operation, array is empty ....."};
	}

	if(index < 0)
	{
		throw string {"ERROR - Invalid index, index cannot be negative ....."};
	}
	else if(index >= A->length)
	{
		throw string {"ERROR - Invalid index, index cannot be greater than the length of the array ....."};
	}
	else
	{
		return A->A[index];
	}
}

int handle_get_element_array(const Array *A, int index)
{
	try
	{
		return get_element_array(A, index);
	}
	catch(string &ex)
	{
		cout<<ex;
	}
}

int main()
{
	Array A {new int[10] {-1, 2, 3, 4, 5, 6, 10, 12, 15, 19}, 10, 10};

	cout<<"A.A[-1]: "<<handle_get_element_array(&A, -1)<<"\n"; // Negative index exception.

	cout<<"A.A[10]: "<<handle_get_element_array(&A, 10)<<"\n"; // Index exceeds array length.

	cout<<"A.A[9]: "<<handle_get_element_array(&A, 9)<<"\n";

	return 0;
}