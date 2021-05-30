/*
Created by  : Vaisakh Dileep
Date		: 29, May, 2021
Description : This program deletes an element in a circular doubly linked list.
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

void display_circular_doubly_linked_list(Linked_list *L)
{
	if((L == nullptr) or (L->head == nullptr))
	{
		return ;
	}

	Node *last {L->head};

	do
	{
		cout<<last->data<<(last->next != L->head ? " <-> " : "");

		last = last->next;

	} while(last != L->head);
}

int delete_circular_doubly_linked_list(Linked_list *L, int index)
{
	if(L == nullptr)
	{
		throw string {"ERROR - Invalid operation, circular doubly linked list is not valid ....."};
	}

	if(L->head == nullptr)
	{
		throw string {"ERROR - Invalid operation, circular doubly linked list is empty ....."};
	}

	if(index < 0)
	{
		throw string {"ERROR - Invalid index, index cannot be a negative number ....."};
	}

	int deleted_value {};

	if(index == 0)
	{
		Node *last {L->head};

		deleted_value = last->data;

		if(L->head->next == L->head)
		{
			L->head = nullptr;

			delete last;
		}
		else
		{
			last->next->previous = last->previous;

			last->previous->next = last->next;

			L->head = last->next;

			delete last;
		}
	}
	else
	{
		Node *target {L->head};

		for(int i {0}; (i < index - 1) and (target->next != L->head); i++)
		{
			target = target->next;
		}

		if(target->next == L->head)
		{
			throw string {"ERROR - Invalid index, index exceeds the size of the circular doubly linked list ....."};
		}
		else
		{
			Node *temp {target->next}; // For deleting the dynamically created memory.

			deleted_value = temp->data;

			temp->next->previous = temp->previous;

			temp->previous->next = temp->next;

			delete temp;
		}
	}
}

int handle_delete_circular_doubly_linked_list(Linked_list *L, int index)
{
	try
	{
		return delete_circular_doubly_linked_list(L, index);
	}
	catch(string &ex)
	{
		cout<<ex;

		return -1;
	}
}

using namespace std;

int main()
{
	Linked_list L1 {}, L2 {};

	create_circular_doubly_linked_list(&L1, new int[6] {1, 2, 3, 4, 5, 6}, 6);

	handle_delete_circular_doubly_linked_list(&L1, 0);
	handle_delete_circular_doubly_linked_list(&L1, 4);

	cout<<"L1: ";
	display_circular_doubly_linked_list(&L1);
	cout<<"\n";

	handle_delete_circular_doubly_linked_list(&L1, 4);
	cout<<"\n";

	handle_delete_circular_doubly_linked_list(&L1, -1);
	cout<<"\n";

	handle_delete_circular_doubly_linked_list(&L2, 0);
	cout<<"\n";

	return 0;
}