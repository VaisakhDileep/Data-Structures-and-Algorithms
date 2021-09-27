/*
Created by  : Vaisakh Dileep
Date        : 30, May, 2021
Description : This program pushes an element into a stack.
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

bool is_full_stack(Stack *stk)
{
    if(stk == nullptr)
    {
        throw string {"ERROR - Invalid operation, stack is not valid ....."};
    }

    if(stk->top == ((stk->size) - 1))
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
        throw string {"ERROR - Invalid operation, stack overflow ....."};
    }
    else
    {
        stk->top++;

        stk->A[stk->top] = value;
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
    Stack stk {};

    create_stack(&stk, 10);

    handle_push_stack(&stk, 1);
    handle_push_stack(&stk, 2);
    handle_push_stack(&stk, 3);

    cout<<"stk: ";
    display_stack(&stk);
    cout<<"\n";

    return 0;
}