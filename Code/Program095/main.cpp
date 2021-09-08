/*
Created by  : Vaisakh Dileep
Date		: 5, May, 2021
Description : This program helps to understand merging.
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

void set_bit(int *num, int pos) // Here merging is used. It is used to set the bit at the position("pos"). "pos" should be indexed from LSB(0).
{
	int H {1};

	H = H << pos;

	*num = *num | H;
}

int main()
{
	int num {2};

	cout<<"num: ";
	print_binary(num);
	cout<<"\n";

	set_bit(&num, 0);

	cout<<"num: ";
	print_binary(num);
	cout<<"\n";

	set_bit(&num, 4);

	cout<<"num: ";
	print_binary(num);
	cout<<"\n";

	return 0;
}