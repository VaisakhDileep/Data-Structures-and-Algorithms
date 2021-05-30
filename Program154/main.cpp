/*
Created by  : Vaisakh Dileep
Date		: 28, May, 2021
Description : This program inserts an element to a doubly linked list.
*/

#include<iostream>

using namespace std;

struct Node
{
	Node *previous;

	int data;

	Node *next;
};

struct Linked_list
{
	Node *head;
};

void display_doubly_linked_list(Linked_list *L)
{
	if((L == nullptr) or (L->head == nullptr))
	{
		return ;
	}

	Node *last {L->head};

	while(last != nullptr)
	{
		cout<<last->data<<(last->next == nullptr ? "" : " <-> ");

		last = last->next;
	}
}

void insert_doubly_linked_list(Linked_list *L, int index, int value)
{
	if(L == nullptr)
	{
		throw string {"ERROR - Invalid operation, doubly linked list is not valid ....."};
	}

	if(index < 0)
	{
		throw string {"ERROR - Invalid index, index cannot be a negative number ....."};
	}

	if(index == 0)
	{
		Node *temp {new Node {nullptr, value, nullptr}};

		if(L->head == nullptr)
		{
			L->head = temp;
		}
		else
		{
			temp->next = L->head;

			L->head->previous = temp;

			L->head = temp;
		}
	}
	else
	{
		if(L->head == nullptr)
		{
			throw string {"ERROR - Invalid index, index exceeds the size of the doubly linked list ....."};
		}

		Node *target {L->head};

		for(int i {0}; (i < (index - 1)) and (target != nullptr); i++)
		{
			target = target->next;
		}

		if(target == nullptr)
		{
			throw string {"ERROR - Invalid index, index exceeds the size of the doubly linked list ....."};
		}
		else if(target->next == nullptr)
		{
			Node *temp {new Node {nullptr, value, nullptr}};

			target->next = temp;

			temp->previous = target;
		}
		else
		{
			Node *temp {new Node {nullptr, value, nullptr}};

			temp->next = target->next;

			temp->previous = target;

			target->next->previous = temp;

			target->next = temp;
		}
	}
}

void handle_insert_doubly_linked_list(Linked_list *L, int index, int value)
{
	try
	{
		insert_doubly_linked_list(L, index, value);
	}
	catch(string &ex)
	{
		cout<<ex;
	}
}

int main()
{
	Linked_list L {};

	handle_insert_doubly_linked_list(&L, 0, 1);
	handle_insert_doubly_linked_list(&L, 0, 2);
	handle_insert_doubly_linked_list(&L, 1, 3);
	handle_insert_doubly_linked_list(&L, 3, 4);

	cout<<"L: ";
	display_doubly_linked_list(&L);
	cout<<"\n";

	handle_insert_doubly_linked_list(&L, 5, 5);
	cout<<"\n";

	handle_insert_doubly_linked_list(&L, -1, 1);
	cout<<"\n";

	handle_insert_doubly_linked_list(nullptr, 1, 1);
	cout<<"\n";

	return 0;
}