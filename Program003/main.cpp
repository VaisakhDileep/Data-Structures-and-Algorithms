/*
Created by  : Vaisakh Dileep
Date		: 26, April, 2021
Description : This program helps to understand how to declare a pointer.
*/

#include<iostream>

using namespace std;

int main()
{
	int ten {10};

	int *p1; // Declaration

	p1 = &ten; // Assigning

	cout<<"*p1: "<<*p1<<"\n";

	int *p2 {&ten}; // Declaration + Initialization

	cout<<"*p2: "<<*p2<<"\n";

	return 0;
}