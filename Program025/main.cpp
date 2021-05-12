/*
Created by  : Vaisakh Dileep
Date		: 27, April, 2021
Description : This program finds the 'n'th element of the fibonacci series(memoization).
*/

#include<iostream>

using namespace std;

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

int fibonacci(int n, int *F = nullptr) // 'F' contains the first 'n' elements in the fibonacci series.
{
	if(F == nullptr)
	{
		F = create_dynamic_array(n, -1);
	}

	if(n <= 1)
	{
		F[n] = n;

		return n;
	}
	else
	{
		if(F[n - 2] == -1)
		{
			F[n - 2] = fibonacci(n - 2, F);
		}

		if(F[n - 1] == -1)
		{
			F[n - 1] = fibonacci(n - 1, F);
		}

		return F[n - 2] + F[n - 1];
	}
}

int main()
{
	cout<<"fibonacci(10) [memoization]: "<<fibonacci(10)<<"\n";

	return 0;
}