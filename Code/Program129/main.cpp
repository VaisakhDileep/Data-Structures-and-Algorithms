/*
Created by  : Vaisakh Dileep
Date		: 22, May, 2021
Description : This program finds the min element in a linked list.
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

namespace iteration
{
	int min_linked_list(Linked_list *L)
	{
		if((L == nullptr) or (L->head == nullptr)) // Short circuiting works here.
		{
			throw string {"ERROR - Invalid operation, linked list is empty ....."};
		}

		Node *last = L->head;

		int min_element {last->data};

		last = last->next;

		while(last != nullptr)
		{
			min_element = min(min_element, last->data);

			last = last->next;
		}

		return min_element;
	}
}

namespace recursion
{
	int min_linked_list(Node *node)
	{
		if(node == nullptr)
		{
			return INT_MAX;
		}

		return (min_linked_list(node->next) < node->data) ? min_linked_list(node->next) : node->data;
	}

	int handle_min_linked_list(Linked_list *L)
	{
		if((L == nullptr) or (min_linked_list(L->head) == INT_MAX)) // Short circuiting works here.
		{
			cout<<"ERROR - Invalid operation, linked list is empty .....";
		}
		else
		{
			return min_linked_list(L->head);
		}
	}
}

int main()
{
	Linked_list L1 {};

	create_linked_list(&L1, new int[6] {1, 2, 9, 4, -1, 6}, 6);

	cout<<"min_linked_list(L1) [iteration]: "<<iteration::min_linked_list(&L1)<<"\n";

	cout<<"handle_min_linked_list(L1) [recursion]: "<<recursion::handle_min_linked_list(&L1)<<"\n";

	return 0;
}