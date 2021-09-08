/*
Created by  : Vaisakh Dileep
Date		: 26, April, 2021
Description : This program helps to understand how to declare a structure.
*/

#include<iostream>

using namespace std;

struct Rectangle // Structure definition.
{
	int length;
	int breadth;
};

void display_rectangle(Rectangle temp)
{
	cout<<"Length : "<<temp.length<<"\n";
	cout<<"Breadth: "<<temp.breadth;
}

int main()
{
	Rectangle r1; // Declaration

	Rectangle r2 {2, 4}; // Declaration + Initialization

	cout<<"r1: \n";
	display_rectangle(r1);
	cout<<"\n";

	cout<<"r2: \n";
	display_rectangle(r2);
	cout<<"\n";

	return 0;
}