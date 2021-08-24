/*
Created by  : Vaisakh Dileep
Date		: 14, June, 2021
Description : This program finds the first 'n' smallest elements in an array using selection sort.
*/

#include<iostream>

#include<vector>

using namespace std;

void display_array(const vector<int> *vec)
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

vector<int>* first_n_smallest_elements(vector<int> *vec, int n)
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
		int k {i};

		for(int j {i}; j < vec->size(); j++)
		{
			if(vec->at(j) < vec->at(k))
			{
				k = j;
			}
		}

		swap(vec->at(i), vec->at(k));

		result->at(i) = vec->at(i);
	}

	return result;
}

vector<int>* handle_first_n_smallest_elements(vector<int> *vec, int n)
{
	try
	{
		return first_n_smallest_elements(vec, n);
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

	vector<int> *result {handle_first_n_smallest_elements(&vec, 3)};

	cout<<"result: ";
	display_array(result);
	cout<<"\n";

	result = handle_first_n_smallest_elements(&vec, 7);
	cout<<"\n";

	return 0;
}