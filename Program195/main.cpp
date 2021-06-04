/*
Created by  : Vaisakh Dileep
Date		: 4, June, 2021
Description : This program deletes an element from a queue.
*/

#include<iostream>

using namespace std;

struct Node
{
	int data;

	Node *next;
};

struct Stack
{
	Node *top;
};

void create_stack(Stack *stk, int *A, int size)
{
	if(size == 0)
	{
		return ;
	}

	stk->top = new Node {A[0], nullptr};

	for(int i {1}; i < size; i++)
	{
		stk->top = new Node {A[i], stk->top};
	}
}

void display_stack(Stack *stk)
{
	if(stk == nullptr)
	{
		return ;
	}

	if(stk->top == nullptr)
	{
		return ;
	}

	Node *last {stk->top};

	while(last != nullptr)
	{
		cout<<last->data<<" ";

		last = last->next;
	}
}

bool is_empty_stack(Stack *stk)
{
	if(stk == nullptr)
	{
		throw string {"ERROR - Invalid operation, stack is not valid ....."};
	}

	if(stk->top == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int delete_stack(Stack *stk)
{
	if(stk == nullptr)
	{
		throw string {"ERROR - Invalid operation, stack is not valid ....."};
	}

	if(stk->top == nullptr)
	{
		throw string {"ERROR - Invalid operation, stack is empty ....."};
	}

	int deleted_value {stk->top->data};

	Node *temp {stk->top};

	stk->top = stk->top->next;

	delete temp;

	return deleted_value;
}

int handle_delete_stack(Stack *stk)
{
	try
	{
		return delete_stack(stk);
	}
	catch(string &ex)
	{
		cout<<ex;

		return -1;
	}
}

int main()
{
	Stack S {};

	create_stack(&S, new int[5] {1, 2, 3, 4, 5}, 5);

	handle_delete_stack(&S);
	handle_delete_stack(&S);
	handle_delete_stack(&S);

	cout<<"S: ";
	display_stack(&S);
	cout<<"\n";

	return 0;
}