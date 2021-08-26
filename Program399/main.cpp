/*
Created by  : Vaisakh Dileep
Date		: 25, August, 2021
Description : This program demonstrates radix sort.
*/

// Here I am implementing radix sort using bucket sort technique.

#include<iostream>

#include<vector>

#include<math.h>

using namespace std;

struct Node
{
	int data;

	Node *next;
};

struct Linked_list
{
	Node *head;
};

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

int digits_counter(int num)
{
	int digit_count {0};

	while(num != 0)
	{
		num = num / 10;

		digit_count++;
	}

	return digit_count;
}

void radix_sort(vector<int> *vec)
{
	if(vec == nullptr)
	{
		throw string {"ERROR - Invalid operation, input array is not valid ....."};
	}

	if(vec->size() == 0)
	{
		throw string {"ERROR - Invalid operation, input array is empty ....."};
	}

	int max_element {vec->at(0)};

	for(int i {0}; i < vec->size(); i++)
	{
		if(vec->at(i) < 0)
		{
			throw string {"ERROR - Invalid operation, radix sort fails for input arrays with negative elements ....."};
		}

		max_element = max(max_element, vec->at(i));
	}

	int digit_count {digits_counter(max_element)};

	for(int i {0}; i < digit_count; i++)
	{
		vector<Node *> bin(10, nullptr);

		int power_of_ten {pow(10, i)};

		for(int j {0}; j < vec->size(); j++)
		{
			if(bin[(vec->at(j) / power_of_ten) % 10] == nullptr)
			{
				bin[(vec->at(j) / power_of_ten) % 10] = new Node {vec->at(j), nullptr};

				continue;
			}

			Node *last {bin[((vec->at(j)) / power_of_ten) % 10]};

			while(last->next != nullptr)
			{
				last = last->next;
			}

			last->next = new Node {vec->at(j), nullptr};
		}

		int j {0};

		for(int i {0}; i < bin.size();)
		{
			if(bin[i] == nullptr)
			{
				i++;
			}
			else
			{
				Node *last {bin[i]};

				while(last != nullptr)
				{
					vec->at(j++) = last->data;

					last = last->next;
				}

				i++;
			}
		}
	}
}

void handle_radix_sort(vector<int> *vec)
{
	try
	{
		radix_sort(vec);
	}
	catch(string &ex)
	{
		cout<<ex;
	}
}

int main()
{
	vector<int> vec {123, 345, 567, 122, 101, 34, 1000, 342, 345};

	cout<<"vec: ";
	display_array(&vec);
	cout<<"\n";

	handle_radix_sort(&vec);

	cout<<"vec: ";
	display_array(&vec);
	cout<<"\n";

	return 0;
}