/*
Created by  : Vaisakh Dileep
Date		: 
Description : This program finds the n'th element of the fibonacci series using memoization.
*/

// Indexing of the fibonacci series starts from '0'.

#include<iostream>

#include<unordered_map>

using namespace std;

long long fibonacci(long long num, unordered_map<long long, long long> &memo)
{
	if(num <= 1)
	{
		return num;
	}

	if(memo.find(num) == memo.end())
	{
		memo[num] = fibonacci(num - 1, memo) + fibonacci(num - 2, memo);
	}
	else
	{
		return memo[num];
	}
	return memo[num];
}

long long handle_fibonacci(long long num)
{
	unordered_map<long long, long long> memo;

	return fibonacci(num, memo);
}

int main()
{
	cout<<"fibonacci(10): "<<handle_fibonacci(10)<<"\n";

	cout<<"fibonacci(50): "<<handle_fibonacci(50)<<"\n";

	cout<<"fibonacci(100): "<<handle_fibonacci(100)<<"\n"; // Notice here we get the result without any delay.

	cout<<"fibonacci(1000): "<<handle_fibonacci(1000)<<"\n";

	return 0;
}