/*
Created by  : Vaisakh Dileep
Date		: 12, June, 2021
Description : This program makes bubble sort adaptive.
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

void bubble_sort(vector<int> *vec)
{
	if(vec == nullptr)
	{
		throw string {"ERROR - Invalid operation, input array is not valid ....."};
	}

	bool flag {};

	for(int i {0}; i < vec->size() - 1; i++)
	{
		flag = false;

		for(int j {0}; j < vec->size() - 1 - i; j++)
		{
			if(vec->at(j) > vec->at(j + 1))
			{
				swap(vec->at(j), vec->at(j + 1));

				flag = true;
			}
		}

		if(flag == false)
		{
			break;
		}
	}
}

void handle_bubble_sort(vector<int> *vec)
{
	try
	{
		bubble_sort(vec);
	}
	catch(string &ex)
	{
		cout<<ex;
	}
}

int main()
{
	vector<int> vec {9, 2, 4, 10, 7, 5};

	cout<<"vec: ";
	display_array(&vec);
	cout<<"\n";

	handle_bubble_sort(&vec);

	cout<<"vec: ";
	display_array(&vec);
	cout<<"\n";

	return 0;
}