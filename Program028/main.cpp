/*
Created by  : Vaisakh Dileep
Date		: 28, April, 2021
Description : This program finds the solution for the Tower of Hanoi problem.
*/

#include<iostream>

using namespace std;

void tower_of_hanoi(int n, char A, char B, char C) // 'n' is the number of disks, 'A' is the source location, 'B' is the intermediate location, 'C' is the final location.
{
	if(n > 0)
	{
		tower_of_hanoi(n - 1, A, C, B);

		cout<<"Move disk from "<<A<<" to "<<C<<"\n";

		tower_of_hanoi(n - 1, B, A, C);
	}
}

int main()
{
	cout<<"Instructions for 3 disks : \n";
	tower_of_hanoi(3, 'A', 'B', 'C');
	cout<<"\n";
	
	return 0;
}