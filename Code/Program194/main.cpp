/*
Created by  : Vaisakh Dileep
Date		: 4, June, 2021
Description : This program pushes an element into a stack.
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

bool is_full_stack(Stack *stk)
{
	Node *temp {new Node {0, nullptr}};

	if(temp == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void push_stack(Stack *stk, int value)
{
	if(stk == nullptr)
	{
		throw string {"ERROR - Invalid operation, stack is not valid ....."};
	}

	if(is_full_stack(stk))
	{
		throw string {"ERROR - Invalid operation, stack if full ....."};
	}

	if(stk->top == nullptr)
	{
		stk->top = new Node {value, nullptr};
	}
	else
	{
		Node *temp {new Node {value, nullptr}};

		temp->next = stk->top;

		stk->top = temp;
	}
}

void handle_push_stack(Stack *stk, int value)
{
	try
	{
		push_stack(stk, value);
	}
	catch(string &ex)
	{
		cout<<ex;
	}
}

int main()
{
	Stack S {};

	handle_push_stack(&S, 1);
	handle_push_stack(&S, 2);
	handle_push_stack(&S, 3);

	cout<<"S: ";
	display_stack(&S);
	cout<<"\n";

	return 0;
}