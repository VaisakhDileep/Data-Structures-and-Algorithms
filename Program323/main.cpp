/*
Created by  : Vaisakh Dileep
Date		: 11, July, 2021
Description : This program finds the n'th element of the fibonacci series using recursion.
*/

// Indexing of the fibonacci series starts from '0'.

#include<iostream>

using namespace std;

long long fibonacci(long long num)
{
	if(num <= 1)
	{
		return num;
	}

	return fibonacci(num - 1) + fibonacci(num - 2);
}

int main()
{
	cout<<"fibonacci(10): "<<fibonacci(10)<<"\n";

	cout<<"fibonacci(50): "<<fibonacci(50)<<"\n"; // Notice here it will take a couple of minutes.

	cout<<"fibonacci(100): "<<fibonacci(100)<<"\n"; // This will take forever.

	return 0;
}