/*
Created by  : Vaisakh Dileep
Date		: 27, May, 2021
Description : This program creates a circular linked list from an array.
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

void create_circular_linked_list(Linked_list *L, int *A, int size)
{
	if(size == 0)
	{
		return ;
	}

	L->head = new Node {A[0], L->head};

	Node *last {L->head}; // "last" is the iterator.

	for(int i {1}; i < size; i++)
	{
		last->next = new Node {A[i], L->head};

		last = last->next;
	}
}

int main()
{
	Linked_list L1 {}, L2 {};

	create_circular_linked_list(&L1, new int[4] {1, 2, 3, 4}, 4);

	int A[6] {1, 2, 3, 4, 5, 6};

	create_circular_linked_list(&L2, A, 6);

	return 0;
}