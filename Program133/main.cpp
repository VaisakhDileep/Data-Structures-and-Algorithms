/*
Created by  : Vaisakh Dileep
Date		: 22, May, 2021
Description : This program inserts an element to a linked list.
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

void display_linked_list(Linked_list *L)
{
	Node *last = L->head;

	while(last != nullptr)
	{
		cout<<last->data<<(last->next != nullptr ? "->" : "");

		last = last->next;
	}
}

void insert_linked_list(Linked_list *L, int index, int value)
{
	if(L == nullptr)
	{
		throw string {"ERROR - Invalid operation, linked list is not valid ....."};
	}

	if(index < 0)
	{
		throw string {"ERROR - Invalid index, index cannot be a negative number ....."};
	}

	if(index == 0)
	{
		Node *temp {new Node {value, L->head}};

		L->head = temp;

		return ;
	}

	Node *target {L->head};

	for(int i {0}; (i < (index - 1)) and (target != nullptr); i++)
	{
		target = target->next;
	}

	if(target != nullptr)
	{
		Node *temp {new Node {value, target->next}};

		target->next = temp;
	}
	else
	{
		throw string {"ERROR - Invalid index, index exceeds the size of the linked list ....."};
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
	Linked_list L {};

	handle_insert_linked_list(&L, 0, 1); // We can create a linked list from scratch using "insert_linked_list()".
	handle_insert_linked_list(&L, 1, 2);
	handle_insert_linked_list(&L, 1, 3);
	handle_insert_linked_list(&L, 0, 4);
	handle_insert_linked_list(&L, 4, 5);

	cout<<"L: ";
	display_linked_list(&L);
	cout<<"\n";

	handle_insert_linked_list(&L, 6, 6);
	cout<<"\n";

	handle_insert_linked_list(&L, -1, 7);
	cout<<"\n";

	handle_insert_linked_list(nullptr, 0, 0);
	cout<<"\n";

	return 0;
}