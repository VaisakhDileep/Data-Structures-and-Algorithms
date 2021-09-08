/*
Created by  : Vaisakh Dileep
Date		: 27, May, 2021
Description : This program displays a circular linked list.
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

	Node *last {L->head};

	for(int i {1}; i < size; i++)
	{
		last->next = new Node {A[i], L->head};

		last = last->next;
	}
}

namespace iteration
{
	void display_circular_linked_list(Linked_list *L)
	{
		if(L->head == nullptr)
		{
			return ;
		}

		Node *last {L->head};

		do
		{
			cout<<last->data<<(last->next == L->head ? "" : "->");

			last = last->next;

		} while(last != L->head);
	}
}

namespace recursion
{
	void display_circular_linked_list(Node *node, Node *head)
	{
		static int flag {0};

		if((node != head) or (flag == 0))
		{
			flag = 1;

			cout<<node->data<<(node->next == head ? "" : "->");

			display_circular_linked_list(node->next, head);
		}

		flag = 0;
	}

	void handle_display_circular_linked_list(Linked_list *L)
	{
		if(L == nullptr)
		{
			cout<<"ERROR - Invalid operation, circular linked list is not valid .....";

			return ;
		}

		if(L->head == nullptr)
		{
			return ;
		}

		display_circular_linked_list(L->head, L->head);
	}
}

int main()
{
	Linked_list L1 {}, L2 {};

	create_circular_linked_list(&L1, new int[4] {1, 2, 3, 4}, 4);

	cout<<"L1: ";
	iteration::display_circular_linked_list(&L1);
	cout<<"\n";

	cout<<"L2: ";
	iteration::display_circular_linked_list(&L2);
	cout<<"\n";

	cout<<"L1: ";
	recursion::handle_display_circular_linked_list(&L1);
	cout<<"\n";

	cout<<"L2: ";
	recursion::handle_display_circular_linked_list(&L2);
	cout<<"\n";

	return 0;
}