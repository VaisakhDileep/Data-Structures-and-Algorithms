/*
Created by  : Vaisakh Dileep
Date		: 27, April, 2021
Description : This program finds the n'th element of the fibonacci series.
*/

// Indexing of the fibonacci series starts from '0'.

#include<iostream>

using namespace std;

namespace recursion
{
	int fibonacci(int n)
	{
		if(n <= 1)
		{
			return n;
		}

		return fibonacci(n - 1) + fibonacci(n - 2);
	}
}

namespace iteration
{
	int fibonacci(int n)
	{
		int term_0 {0}, term_1 {1};

		int sum {0};

		if(n <= 1)
		{
			return n;
		}

		for(int i {2}; i <= n; i++)
		{
			sum = term_0 + term_1;

			term_0 = term_1;
			term_1 = sum;
		}

		return sum;
	}
}

int main()
{
	cout<<"fibonacci(10) [recursion]: "<<recursion::fibonacci(10)<<"\n";

	cout<<"fibonacci(10) [iteration]: "<<iteration::fibonacci(10)<<"\n";
	
	return 0;
}