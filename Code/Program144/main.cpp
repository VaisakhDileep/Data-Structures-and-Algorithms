/*
Created by  : Vaisakh Dileep
Date		: 26, May, 2021
Description : This program creates a circular linked list.
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

int main()
{
	Linked_list L {};

	L.head = new Node {1, nullptr};

	L.head->next = L.head;

	L.head->next = new Node {2, L.head};

	L.head->next->next = new Node {3 , L.head};

	return 0;
}