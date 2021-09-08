/*
Created by  : Vaisakh Dileep
Date		: 2, June, 2021
Description : This program checks if a stack is empty.
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

bool handle_is_empty_stack(Stack *stk)
{
	try
	{
		is_empty_stack(stk);
	}
	catch(string &ex)
	{
		cout<<ex;

		return false;
	}
}

int main()
{
	Stack S {};

	cout<<"handle_is_empty_stack(S): "<<handle_is_empty_stack(&S)<<"\n";

	S.top = new Node {1, nullptr};

	cout<<"handle_is_empty_stack(S): "<<handle_is_empty_stack(&S)<<"\n";

	return 0;
}