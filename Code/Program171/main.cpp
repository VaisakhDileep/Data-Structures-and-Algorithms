/*
Created by  : Vaisakh Dileep
Date		: 30, May, 2021
Description : This program returns the top element of a stack.
*/

#include<iostream>

using namespace std;

struct Stack
{
	int *A {nullptr};

	int top {-1};

	int size {0};
};

void create_stack(Stack *stk, int size)
{
	stk->A = new int[size] {};

	stk->top = -1;

	stk->size = size;
}

bool is_empty_stack(Stack *stk)
{
	if(stk == nullptr)
	{
		throw string {"ERROR - Invaid operation, stack is not valid ....."};
	}

	if(stk->top == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int& top_stack(Stack *stk)
{
	if(stk == nullptr)
	{
		throw string {"ERROR - Invalid operation, stack is not valid ....."};
	}

	if(is_empty_stack(stk))
	{
		throw string {"ERROR - Invalid operation, stack is empty ....."};
	}

	return stk->A[stk->top];
}

int& handle_top_stack(Stack *stk)
{
	try
	{
		return top_stack(stk);
	}
	catch(string &ex)
	{
		cout<<ex;
	}
}

int main()
{
	Stack stk {};

	handle_top_stack(&stk);
	cout<<"\n";

	stk = {new int[4] {1, 2, 3, 4}, 3, 4};

	cout<<"handle_top_stack(stk): "<<handle_top_stack(&stk)<<"\n";

	handle_top_stack(&stk) = 10;

	cout<<"handle_top_stack(stk): "<<handle_top_stack(&stk)<<"\n";

	return 0;
}