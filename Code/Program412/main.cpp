/*
Created by  : Vaisakh Dileep
Date		: 3, September, 2021
Description : This program finds implements Brian Kernighan's algorithm to find the number of set bits in a number.
*/

// Indexing starts from the right hand side.

#include<iostream>

using namespace std;

int count_set_bits(int num)
{
	if(num < 0)
	{
		throw string {"ERROR - Invalid operation, number cannot be negative ....."};
	}

	int count {0};

	while(num)
	{
		num = num & (num - 1); // Subtracting '1' from the number flips all the bits until(including) the right-most set bit.

		count++;
	}

	return count;
}

int handle_count_set_bits(int num)
{
	try
	{
		return count_set_bits(num);
	}
	catch(string &ex)
	{
		cout<<ex;

		return -1;
	}
}

int main()
{
	cout<<"count_set_bits(9): "<<handle_count_set_bits(9)<<"\n";

	return 0;
}