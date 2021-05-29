/*
Created by  : Vaisakh Dileep
Date		: 29, May, 2021
Description : This program inserts an element to a circular doubly linked list.
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

void create_circular_doubly_linked_list(Linked_list *L, int *A, int size)
{
	if(size == 0)
	{
		return ;
	}

	L->head = new Node {nullptr, A[0], nullptr};

	L->head->previous = L->head;

	L->head->next = L->head;

	Node *last {L->head};

	for(int i {1}; i < size; i++)
	{
		Node *temp {new Node {nullptr, A[i], nullptr}};

		last->next = temp;

		temp->previous = last;

		temp->next = L->head;

		L->head->previous = temp;

		last = temp;
	}
}

void insert_circular_doubly_linked_list(Linked_list *L)
{
	if(L == nullptr)
	{
		throw string {""};
	}
}

int main()
{
	return 0;
}