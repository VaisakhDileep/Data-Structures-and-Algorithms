/*
Created by  : Vaisakh Dileep
Date		: 25, May, 2021
Description : This program reverses a linked list by reversing the data elements.
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

void create_linked_list(Linked_list *L, int *A, int size)
{
	if(size == 0)
	{
		return ;
	}

	L->head = new Node {A[0], nullptr};

	Node *last {L->head};

	for(int i {1}; i < size; i++)
	{
		last->next = new Node {A[i], nullptr};

		last = last->next;
	}
}

void display_linked_list(Linked_list *L)
{
	Node *last = L->head;

	while(last != nullptr)
	{
		cout<<last->data<<(last->next != nullptr ? "->" : "");

		last = last->next;
	}
}

int count_nodes_linked_list(Linked_list *L)
{
	if(L == nullptr)
	{
		return 0;
	}

	int count {0};

	Node *last {L->head};

	while(last != nullptr)
	{
		count++;

		last = last->next;
	}

	return count;
}

void reverse_linked_list(Linked_list *L)
{
	if(L == nullptr)
	{
		throw string {"ERROR - Invalid operation, linked list is not valid ....."};
	}

	if(L->head == nullptr)
	{
		throw string {"ERROR - Invalid operation, linked list is empty ....."};
	}

	Node *iterator {L->head};

	int * Auxillary_array {new int[count_nodes_linked_list(L)]};

	int i {0};

	while(iterator != nullptr)
	{
		Auxillary_array[i] = iterator->data;

		iterator = iterator->next;

		i++;
	}

	iterator = L->head;

	i--;

	while(iterator != nullptr)
	{
		iterator->data = Auxillary_array[i--];

		iterator = iterator->next;
	}
}

void handle_reverse_linked_list(Linked_list *L)
{
	try
	{
		reverse_linked_list(L);
	}
	catch(string &ex)
	{
		cout<<ex;
	}
}

int main()
{
	Linked_list L1 {}, L2 {};

	create_linked_list(&L1, new int[6] {1, 2, 3, 4, 5, 6}, 6);

	cout<<"L1: ";
	display_linked_list(&L1);
	cout<<"\n";

	reverse_linked_list(&L1);

	cout<<"L1: ";
	display_linked_list(&L1);
	cout<<"\n";

	handle_reverse_linked_list(&L2);
	cout<<"\n";

	handle_reverse_linked_list(nullptr);
	cout<<"\n";

	return 0;
}