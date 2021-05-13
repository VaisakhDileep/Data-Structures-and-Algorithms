/*
Created by  : Vaisakh Dileep
Date		: 29, April, 2021
Description :  This program finds the sum of all the elements in an array.
*/

#include<iostream>

using namespace std;

struct Array
{
	int *A;

	int size;

	int length;
};

namespace recursion
{
	int sum_array(Array *A, int n)
	{
		if(A->A == nullptr)
		{
			throw string {"ERROR - Invalid operation, array is empty ....."};
		}

		if(n < 0)
		{
			return 0;
		}
		else
		{
			return sum_array(A, n - 1) + A->A[n];
		}
	}

	int handle_sum_array(Array *A)
	{
		try
		{
			return sum_array(A, A->length - 1);
		}
		catch(string &ex)
		{
			cout<<ex;

			return -1;
		}
		
	}
}

namespace iteration
{
	int sum_array(Array *A)
	{
		if((A->A == nullptr) or (A->length == 0))
		{
			throw string {"ERROR - Invalid operation, array is empty ....."};
		}

		int sum {0};

		for(int i {0}; i < A->length; i++)
		{
			sum += A->A[i];
		}

		return sum;
	}

	int handle_sum_array(Array *A)
	{
		try
		{
			return sum_array(A);
		}
		catch(string &ex)
		{
			cout<<ex;

			return -1;
		}
	}
}

int main()
{
	Array A {nullptr, 0, 0};

	Array B {new int[10] {-1, 2, 3, 4, 5, 6, 10, -12, 15, 19}, 10, 10};
	
	cout<<"sum_array(A) [recursion]: "<<recursion::handle_sum_array(&A)<<"\n";
	cout<<"sum_array(B) [recursion]: "<<recursion::handle_sum_array(&B)<<"\n";

	cout<<"sum_array(A) [iteration]: "<<iteration::handle_sum_array(&A)<<"\n";
	cout<<"sum_array(B) [iteration]: "<<iteration::handle_sum_array(&B)<<"\n";

	return 0;
}