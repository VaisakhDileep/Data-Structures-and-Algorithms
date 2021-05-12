/*
Created by  : Vaisakh Dileep
Date		: 27, April, 2021
Description : This program optimized power(m, n).
*/

#include<iostream>

using namespace std;

int power(int m, int n)
{
	if(n == 0) // Base condition
	{
		return 1;
	}
	else if((n % 2) == 0) // 'n' is even
	{
		return power(m * m, n / 2);
	}
	else // 'n' is odd
	{
		return m * power(m * m, (n - 1) / 2);
	}
}

int main()
{
	cout<<"power(2, 9): "<<power(2, 9)<<"\n";

	return 0;
}