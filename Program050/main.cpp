/*
Created by  : Vaisakh Dileep
Date		: 30, April, 2021
Description : This program checks if an array is sorted.
*/

#include<iostream>

using namespace std;

struct Array
{
	int *A;

	int size;

	int length;
};

bool is_sorted_array(const Array *A, int flag = 0) // flag = 0, for ascending order. flag = 1, for descending order.
{
	if((A->length == 0) or (A->A == nullptr))
	{
		throw string {"ERROR - Invalid operation, array is empty ....."};
	}

	if(flag == 0)
	{
		for(int i {0}; i < (A->length - 1); i++)
		{
			if(A->A[i] > A->A[i + 1])
			{
				return false;
			}
		}

		return true;
	}
	else if(flag == 1)
	{
		for(int i {0}; i < (A->length - 1); i++)
		{
			if(A->A[i] < A->A[i + 1])
			{
				return false;
			}
		}

		return true;
	}
	else
	{
		throw string {"ERROR - Invalid flag, flag should be either 0 or 1 ....."};
	}
}

bool handle_is_sorted_array(const Array *A, int flag = 0)
{
	try
	{
		return is_sorted_array(A, flag);
	}
	catch(string &ex)
	{
		cout<<ex;

		return false;
	}
}

int main()
{
	Array A {new int[10] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 10, 10};

	Array B {new int[10] {10, 9, 8, 7 ,6, 5, 4, 3, 2, 1}, 10, 10};

	Array C {nullptr, 0, 0};

	cout<<"is_sorted_array(&A): "<<handle_is_sorted_array(&A)<<"\n";
	cout<<"is_sorted_array(&B): "<<handle_is_sorted_array(&B)<<"\n";
	cout<<"is_sorted_array(&C): "<<handle_is_sorted_array(&C)<<"\n";

	cout<<"is_sorted_array(&A, 1): "<<handle_is_sorted_array(&A, 1)<<"\n";
	cout<<"is_sorted_array(&B, 1): "<<handle_is_sorted_array(&B, 1)<<"\n";
	cout<<"is_sorted_array(&C, 1): "<<handle_is_sorted_array(&C, 1)<<"\n";

	cout<<"is_sorted_array(&A, 2): "<<handle_is_sorted_array(&A, 2)<<"\n";

	return 0;
}