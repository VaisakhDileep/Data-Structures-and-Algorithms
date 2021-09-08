/*
Created by  : Vaisakh Dileep
Date		: 4, June, 2021
Description : This program displays a stack.
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

void display_stack(Stack *stk) // Displaying happens from the top of the stack.
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

int main()
{
	Stack S {};

	create_stack(&S, new int[6] {1, 2, 3, 4, 5, 6}, 6);

	cout<<"S: ";
	display_stack(&S);
	cout<<"\n";

	return 0;
}