/*
Created by  : Vaisakh Dileep
Date		: 22, May, 2021
Description : This program performs linear search in a linked list.
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

void display_linked_list(Linked_list *L)
{
	Node *last = L->head;

	while(last != nullptr)
	{
		cout<<last->data<<(last->next != nullptr ? "->" : "");

		last = last->next;
	}
}

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
	Node *linear_search_linked_list(Linked_list *L, int key) // Note: Binary search is not useful in linked list.
	{
		if((L == nullptr) or (L->head == nullptr))
		{
			throw string {"ERROR - Invalid operation, linked list is empty ....."};
		}

		Node *last {L->head};

		while(last != nullptr)
		{
			if(key == last->data)
			{
				return last;
			}

			last = last->next;
		}

		throw string {"ERROR - Invalid key, key not present in the linked list ....."};
	}

	Node *handle_linear_search_linked_list(Linked_list *L, int key)
	{
		try
		{
			return linear_search_linked_list(L, key);
		}
		catch(string &ex)
		{
			cout<<ex;

			return nullptr;
		}
	}
}

namespace recursion
{
	Node *linear_search_linked_list(Node *node, int key)
	{
		if(node == nullptr)
		{
			return nullptr;
		}

		if(node->data == key)
		{
			return node;
		}

		return linear_search_linked_list(node->next, key);
	}

	Node *handle_linear_search_linked_list(Linked_list *L, int key)
	{
		if((L == nullptr) or (L->head == nullptr))
		{
			cout<<"ERROR - Invalid operation, linked list is empty .....";

			return nullptr;
		}

		Node *element {linear_search_linked_list(L->head, key)};

		if(element == nullptr)
		{
			cout<<"ERROR - Invalid key, key not present in the linked list .....";
		}

		return element;
	}
}

int main()
{
	Linked_list L1 {};

	create_linked_list(&L1, new int[6] {1, 2, 9, 4, -1, 6}, 6);

	Node *element = iteration::handle_linear_search_linked_list(&L1, -1);

	element->data = 10; // Since we are returning by address we can change the original element in the linked list.

	cout<<"L1: ";
	display_linked_list(&L1);
	cout<<"\n";

	element = iteration::handle_linear_search_linked_list(&L1, 90); // '90' is not present in the linked list, so it will throw an exception.

	element = recursion::handle_linear_search_linked_list(&L1, 6);

	cout<<"\n";

	element->data = 20;

	cout<<"L1: ";
	display_linked_list(&L1);
	cout<<"\n";

	element = recursion::handle_linear_search_linked_list(&L1, 90);

	return 0;
}