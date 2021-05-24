/*
Created by  : Vaisakh Dileep
Date		: 22, May, 2021
Description : This program finds the max element in a linked list.
*/

#include<iostream>

#include<climits>

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
	int max_linked_list(Linked_list *L)
	{
		if((L == nullptr) or (L->head == nullptr)) // Short circuting works here.
		{
			throw string {"ERROR - Invalid operation, linked list is empty ....."};
		}

		Node *last = L->head;

		int max_element {last->data};

		last = last->next;

		while(last != nullptr)
		{
			max_element = max(max_element, last->data);

			last = last->next;
		}

		return max_element;
	}

	int handle_max_linked_list(Linked_list *L)
	{
		try
		{
			return max_linked_list(L);
		}
		catch(string &ex)
		{
			cout<<ex;
		}
	}
}

namespace recursion
{
	int max_linked_list(Node *node)
	{
		if(node == nullptr)
		{
			return INT_MIN;
		}

		return (max_linked_list(node->next) > node->data) ? max_linked_list(node->next) : node->data;
	}

	int handle_max_linked_list(Linked_list *L)
	{
		if((L == nullptr) or (max_linked_list(L->head) == INT_MIN)) // Short circuiting works here.
		{
			cout<<"ERROR - Invalid operation, linked list is empty .....";
		}
		else
		{
			return max_linked_list(L->head);
		}
	}
}

int main()
{
	Linked_list L1 {};

	create_linked_list(&L1, new int[6] {1, 2, 9, 4, 5, 6}, 6);

	cout<<"max_linked_list(L1) [iteration]: "<<iteration::handle_max_linked_list(&L1)<<"\n";

	cout<<"handle_max_linked_list(L1) [recursion]: "<<recursion::handle_max_linked_list(&L1)<<"\n";

	return 0;
}