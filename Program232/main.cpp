/*
Created by  : Vaisakh Dileep
Date		: 13, June, 2021
Description : This program demonstrates insertions sort in an array.
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

void insertion_sort(vector<int> *vec)
{
	if(vec == nullptr)
	{
		throw string {"ERROR - Invalid operation, input array is not valid ....."};
	}

	for(int i {1}; i < vec->size(); i++)
	{
		int j {i - 1};

		int temp {vec->at(i)};

		while((j >= 0) and (vec->at(j) > temp))
		{
			vec->at(j + 1) = vec->at(j);

			j--;
		}

		vec->at(j + 1) = temp;
	}
}

void handle_insertion_sort(vector<int> *vec)
{
	try
	{
		insertion_sort(vec);
	}
	catch(string &ex)
	{
		cout<<ex;
	}
}

int main()
{
	vector<int> vec {9, 1, 3, 8, 5, 10};

	cout<<"vec: ";
	display_array(&vec);
	cout<<"\n";

	handle_insertion_sort(&vec);

	cout<<"vec: ";
	display_array(&vec);
	cout<<"\n";

	return 0;
}