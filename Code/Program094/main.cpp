/*
Created by  : Vaisakh Dileep
Date		: 6, May, 2021
Description : This program helps to understand masking.
*/

#include<iostream>

using namespace std;

void print_binary(int num)
{
	if(num > 1)
	{
		print_binary(num / 2);
	}

	cout<<(num % 2);
}

bool check_bit(int num, int pos) // Here masking is used. It is used to check if the bit at the position("pos") is set or not. "pos" should be indexed from LSB(0).
{
	int H {1};

	H = H << pos;

	if(num & H)
	{
		return true; // bit is set.
	}
	else
	{
		return false; // bit is not set.
	}
}

int main()
{
	int num {2};

	cout<<"num: ";
	print_binary(num);
	cout<<"\n";

	cout<<"check_bit(num, 1): "<<check_bit(num, 1)<<"\n";
	cout<<"check_bit(num, 0): "<<check_bit(num, 0)<<"\n";

	return 0;
}