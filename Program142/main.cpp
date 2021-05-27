/*
Created by  : Vaisakh Dileep
Date		: 26, May, 2021
Description : This program checks if a linked list contains loops.
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

bool check_loop_linked_list(Linked_list *L)
{
	if(L == nullptr)
	{
		throw string {"ERROR - Invalid operation, linked list is not valid ....."};
	}

	if(L->head == nullptr)
	{
		throw string {"ERROR - Invalid operation, linked list is empty ....."};
	}

	Node *racing_node_1 {L->head};

	Node *racing_node_2 {L->head};

	do
	{
		racing_node_1 = racing_node_1->next;

		racing_node_2 = racing_node_2->next;

		racing_node_2 = (racing_node_2 == nullptr) ? nullptr : racing_node_2->next;

	} while((racing_node_1 != nullptr) and (racing_node_2 != nullptr) and (racing_node_1 != racing_node_2));

	if((racing_node_1 == nullptr) or (racing_node_2 == nullptr))
	{
		return false;
	}
	else if(racing_node_1 == racing_node_2)
	{
		return true;
	}

	return false;
}

bool handle_check_loop_linked_list(Linked_list *L)
{
	try
	{
		return check_loop_linked_list(L);
	}
	catch(string &ex)
	{
		cout<<ex;

		return false;
	}
}

int main()
{
	Linked_list L1 {}, L2 {};

	create_linked_list(&L1, new int[6] {1, 2, 3, 4, 5 ,6}, 6);

	L1.head->next->next->next = L1.head->next; // Creating a cycle.

	cout<<"check_loop_linked_list(L1): "<<handle_check_loop_linked_list(&L1)<<"\n";

	cout<<"check_loop_linked_list(nullptr): "<<handle_check_loop_linked_list(nullptr)<<"\n";

	cout<<"check_loop_linked_list(L2): "<<handle_check_loop_linked_list(&L2)<<"\n";

	return 0;
}