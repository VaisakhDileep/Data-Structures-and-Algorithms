/*
Created by  : Vaisakh Dileep
Date		: 27, April, 2021
Description : This program finds the sum of the first 'n' natural numbers.
*/

#include<iostream>

using namespace std;

namespace formula
{
	int sum_n_natural_numbers(int n) // Formula used: (n * (n + 1)) / 2
	{
			return (n * (n + 1)) / 2;
	}
}

namespace recursion
{
	int sum_n_natural_numbers(int n)
	{
		if(n == 0)
		{
			return 0;
		}
		else
		{
			return sum_n_natural_numbers(n - 1) + n;
		}
	}
}

namespace iteration
{
	int sum_n_natural_numbers(int n)
	{
		int sum {0};

		for(int i {0}; i <= n; i++)
		{
			sum += i;
		}

		return sum;
	}
}

int main()
{
	cout<<"sum_n_natural_numbers(10) [formula]: "<<formula::sum_n_natural_numbers(10)<<"\n";

	cout<<"sum_n_natural_numbers(10) [recursion]: "<<recursion::sum_n_natural_numbers(10)<<"\n";

	cout<<"sum_n_natural_numbers(10) [iteration]: "<<iteration::sum_n_natural_numbers(10)<<"\n";

	return 0;
}