/*
Created by  : Vaisakh Dileep
Date		: 20, August, 2021
Description : This program performs linear search in an array.
*/

#include<iostream>

#include<vector>

using namespace std;

void linear_search(vector<int> *A)
{
	if(A == nullptr)
	{
		throw string {"ERROR - Invalid operation, array is not valid ....."};
	}

	if(A->size() == 0)
	{
		throw string {"ERROR - Invalid operation, array is empty ....."};
	}

	
}

int main()
{
	return 0;
}