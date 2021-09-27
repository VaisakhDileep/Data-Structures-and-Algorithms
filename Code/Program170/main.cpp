/*
Created by  : Vaisakh Dileep
Date        : 30, May, 2021
Description : This program pops an element from a stack.
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

void display_stack(Stack *stk)
{
    if(stk == nullptr)
    {
        return ;
    }

    for(int i {stk->top}; i >= 0; i--)
    {
        cout<<stk->A[i]<<" ";
    }
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

int pop_stack(Stack *stk)
{
    if(stk == nullptr)
    {
        throw string {"ERROR - Invalid operation, stack is not valid ....."};
    }

    int popped_element {};

    if(is_empty_stack(stk))
    {
        throw string {"ERROR - Invalid operatoin, stack underflow ....."};
    }
    else
    {
        popped_element = stk->A[stk->top];

        stk->top--;
    }

    return popped_element;
}

int handle_pop_stack(Stack *stk)
{
    try
    {
        return pop_stack(stk);
    }
    catch(string &ex)
    {
        cout<<ex;

        return -1;
    }
}

int main()
{
    Stack stk {new int[5] {1, 2, 3, 4, 5}, 4, 5};

    handle_pop_stack(&stk);
    handle_pop_stack(&stk);
    handle_pop_stack(&stk);

    cout<<"stk: ";
    display_stack(&stk);
    cout<<"\n";

    return 0;
}