/*
Created by  : Vaisakh Dileep
Date		: 26, April, 2021
Description : This program helps to understand how to declare an array.
*/

#include<iostream>

using namespace std;

void display_array(int A[], const int size)
{
	cout<<"[ ";
	for(int i {0}; i < 5; i++)
	{
		cout<<A[i]<<" ";
	}
	cout<<"]";
}

int main()
{
	const int size {5};

	int A[size]; // Declaration

	int B[size] {1, 2, 3, 4, 5}; // Declaration + Initialization

	cout<<"A: ";
	display_array(A, size);
	cout<<"\n";

	cout<<"B: ";
	display_array(B, size);
	cout<<"\n";

	return 0;
}