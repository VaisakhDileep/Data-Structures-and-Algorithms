/*
Created by  : Vaisakh Dileep
Date		: 28, April, 2021
Description : This program finds the number of combinations.
*/

#include<iostream>

using namespace std;

int factorial(int n)
{
	if(n == 0)
	{
		return 1;
	}
	else
	{
		return factorial(n - 1) * n;
	}
}

int combination(int n, int r) // nCr = n! / (r! * (n - r)!)
{
	int numerator {0}, denominator {0};

	numerator = factorial(n);

	denominator = factorial(r) * factorial(n - r);

	return numerator / denominator;
}

int main()
{
	cout<<"combination(5, 2): "<<combination(5, 2)<<"\n";

	return 0;
}