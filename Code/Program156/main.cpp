/*
Created by  : Vaisakh Dileep
Date		: 28, May, 2021
Description : This program reverses a doubly linked list.
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

void create_doubly_linked_list(Linked_list *L, int *A, int size)
{
	if(size == 0)
	{
		return ;
	}

	L->head = new Node {nullptr, A[0], nullptr};

	Node *last {L->head};

	for(int i {1}; i < size; i++)
	{
		last->next = new Node {last, A[i], nullptr};

		last = last->next;
	}
}

void reverse_doubly_linked_list(Linked_list *L)
{
	if(L == nullptr)
	{
		throw string {"ERROR - Invalid operation, doubly linked list is not valid ....."};
	}

	if(L->head == nullptr)
	{
		throw string {"ERROR - Invalid operation, doubly linked list is empty ....."};
	}

	Node *last {L->head};

	while(last != nullptr)
	{
		Node *temp {last->next};

		last->next = last->previous;

		last->previous = temp;

		if(last->previous == nullptr) // remember we swapped the links.
		{
			L->head = last;
		}

		last = last->previous;
	}
}

void handle_reverse_doubly_linked_list(Linked_list *L)
{
	try
	{
		reverse_doubly_linked_list(L);
	}
	catch(string &ex)
	{
		cout<<ex;
	}
}

int main()
{
	Linked_list L1 {}, L2 {};

	create_doubly_linked_list(&L1, new int[6] {1, 2, 3, 4, 5, 6}, 6);

	cout<<"L1: ";
	display_doubly_linked_list(&L1);
	cout<<"\n";

	handle_reverse_doubly_linked_list(&L1);

	cout<<"L1 [reversed]: ";
	display_doubly_linked_list(&L1);
	cout<<"\n";

	handle_reverse_doubly_linked_list(&L2);
	cout<<"\n";

	handle_reverse_doubly_linked_list(nullptr);
	cout<<"\n";

	return 0;
}