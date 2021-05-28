/*
Created by  : Vaisakh Dileep
Date		: 28, May, 2021
Description : This program displays a doubly linked list.
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

void display_doubly_linked_list(Linked_list *L)
{
	if((L == nullptr) or (L->head == nullptr))
	{
		return ;
	}

	Node *last {L->head};

	while(last != nullptr)
	{
		cout<<last->data<<(last->next == nullptr ? "" : " <=> ");

		last = last->next;
	}
}

int main()
{
	Linked_list L1 {}, L2 {};

	create_doubly_linked_list(&L1, new int[4] {1, 2, 3, 4}, 4);

	cout<<"L1: ";
	display_doubly_linked_list(&L1);
	cout<<"\n";

	cout<<"L2: ";
	display_doubly_linked_list(&L2);
	cout<<"\n";

	return 0;
}