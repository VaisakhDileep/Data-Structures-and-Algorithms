/*
Created by  : Vaisakh Dileep
Date		: 20, August, 2021
Description : This program performs linear search on an array(O(n) time complexity).
*/

#include<iostream>

#include<vector>

using namespace std;

int linear_search(vector<int> *A, int target)
{
	if(A == nullptr)
	{
		throw string {"ERROR - Invalid operation, array is not valid ....."};
	}

	if(A->size() == 0)
	{
		throw string {"ERROR - Invalid operation, array is empty ....."};
	}

	for(int i {0}; i < static_cast<int>(A->size()); i++)
	{
		if(A->at(i) == target)
		{
			return i;
		}
	}

	throw string {"ERROR - Invalid operation, target element not present in the array ....."};
}

int handle_linear_search(vector<int> *A, int target)
{
	try
	{
		return linear_search(A, target);
	}
	catch(string &ex)
	{
		cout<<ex;

		return INT_MIN;
	}
}

int main()
{
	vector<int> *A {new vector<int> {1, 3, 4, 5, 7, 8, 9, 2}};

	cout<<"linear_search(A, 2): "<<handle_linear_search(A, 2)<<"\n";

	return 0;
}