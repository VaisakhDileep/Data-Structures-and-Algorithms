/*
Created by  : Vaisakh Dileep
Date		: 12, June, 2021
Description : This program finds the first 'n' largest elements in an array using bubble sort.
*/

#include<iostream>

#include<vector>

using namespace std;

void display_array(vector<int> *vec)
{
	if(vec == nullptr)
	{
		cout<<"[ ]";

		return ;
	}

	cout<<"[ ";
	for(int i {0}; i < vec->size(); i++)
	{
		cout<<vec->at(i)<<" ";
	}
	cout<<"]";
}

void swap(int &a, int &b)
{
	int temp {a};

	a = b;
	b = temp;
}

vector<int>* first_n_largest_elements(vector<int> *vec, int n)
{
	if(vec == nullptr)
	{
		throw string {"ERROR - Invalid operation, input array is not valid ....."};
	}

	if(n < 0)
	{
		throw string {"ERROR - Invalid operation, value of 'n' cannot be negative ....."};
	}

	if(n > vec->size())
	{
		throw string {"ERROR - Invalid operation, value of 'n' exceeds the size of the array ....."};
	}

	vector<int> *result {new vector<int>(n, 0)};

	for(int i {0}; i < n; i++)
	{
		for(int j {0}; j < (vec->size() - 1- i); j++)
		{
			if(vec->at(j) > vec->at(j + 1))
			{
				swap(vec->at(j), vec->at(j + 1));
			}
		}

		result->at(i) = vec->at(vec->size() - 1 - i);
	}

	return result;
}

vector<int>* handle_first_n_largest_elements(vector<int> *vec, int n)
{
	try
	{
		return first_n_largest_elements(vec, n);
	}
	catch(string &ex)
	{
		cout<<ex;

		return nullptr;
	}
}

int main()
{
	vector<int> vec {9, 4, 3, 10, 7, 2};

	cout<<"vec: ";
	display_array(&vec);
	cout<<"\n";

	vector<int> *result {handle_first_n_largest_elements(&vec, 6)};

	cout<<"result: ";
	display_array(result);
	cout<<"\n";

	result = handle_first_n_largest_elements(&vec, 7);
	cout<<"\n";

	return 0;
}