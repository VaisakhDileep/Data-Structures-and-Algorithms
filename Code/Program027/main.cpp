/*
Created by  : Vaisakh Dileep
Date		: 28, April, 2021
Description : This program finds the number of combinations(pascal's triangle).
*/

#include<iostream>

using namespace std;

int combination(int n, int r)
{
	if(n == r || r == 0)
	{
		return 1;
	}
	else
	{
		return combination(n - 1, r - 1) + combination(n - 1, r);
	}
}

int main()
{
	cout<<"combination(5, 2): "<<combination(5, 2)<<"\n";

	return 0;
}