/*
Created by  : Vaisakh Dileep
Date		: 29, April, 2021
Description : This program finds the min element in an array.
*/

#include<iostream>

using namespace std;

struct Array
{
	int *A;

	int size;

	int length;
};

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

int handle_min_element_array(Array *A)
{
	try
	{
		return min_element_array(A);
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

	Array B {new int[10] {-1, 2, 3, 4, 5, 6, 10, -12, 15, 19}, 10, 10};

	cout<<"min_element_array(A): "<<handle_min_element_array(&A)<<"\n";
	cout<<"min_element_array(B): "<<handle_min_element_array(&B)<<"\n";

	return 0;
}