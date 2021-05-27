/*
Created by  : Vaisakh Dileep
Date		: 27, May, 2021
Description : This program inserts an element to a circular linked list.
*/

#include<iostream>

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

void insert_linked_list(Linked_list *L, int index, int value)
{
	if(L == nullptr)
	{
		throw string {"ERROR - Invalid operation, circular linked list is not valid ....."};
	}

	if(index < 0)
	{
		throw string {"ERROR - Invalid index, index cannot be a negative number ....."};
	}
}

void handle_insert_linked_list(Linked_list *L, int index, int value)
{
	try
	{
		insert_linked_list(L, index, value);
	}
	catch(string &ex)
	{
		cout<<ex;
	}
}

int main()
{
	return 0;
}