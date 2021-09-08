/*
Created by  : Vaisakh Dileep
Date		: 21, May, 2021
Description : This program creates a linked list.
*/

#include<iostream>

using namespace std;

struct Node
{
	int data;

	Node *next; // self-referential structure.
};

struct Linked_list
{
	Node *head; // head of the linked list.
};

int main()
{
	Linked_list L {nullptr};

// The give below piece of code demonstrates some of the procedures to check if a Linked List is empty or not.
	if(L.head == nullptr) // Procedure 1
	{
		cout<<"The Linked List is empty.\n";
	}

	if(L.head == 0) // Procedure 2
	{
		cout<<"The Linked List is empty.\n";
	}

	if(!(L.head)) // Procedure 3
	{
		cout<<"The Linked List is empty.\n";
	}

	L.head = new Node {1, nullptr}; // Inserting the first element in the Linked List.

	L.head->next = new Node {2, nullptr}; // Inserting the second element in the Linked List.

	L.head->next->next = new Node {3, nullptr}; // Inserting the third element in the Linked List.

	return 0;
}