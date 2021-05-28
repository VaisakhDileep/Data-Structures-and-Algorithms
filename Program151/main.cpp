/*
Created by  : Vaisakh Dileep
Date		: 28, May, 2021
Description : This program creates a doubly linked list from an array.
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

int main()
{
	Linked_list L1 {}, L2 {};

	create_doubly_linked_list(&L1, new int[4] {1, 2, 3, 4}, 4);

	int A[6] {1, 2, 3, 4, 5, 6};

	create_doubly_linked_list(&L2, A, 6);

	return 0;
}