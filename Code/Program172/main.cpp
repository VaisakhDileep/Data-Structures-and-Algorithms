/*
Created by  : Vaisakh Dileep
Date        : 30, May, 2021
Description : This program peeks through a stack.
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

int peek_stack(Stack *stk, int index) // Indexing starts from the top of the stack.
{
    if(stk == nullptr)
    {
        throw string {"ERROR - Invalid operation, stack is not valid ....."};
    }

    if(index < 0)
    {
        throw string {"ERROR - Invalid index, index cannot be a negative number ....."};
    }

    if(stk->top - index < 0)
    {
        throw string {"ERROR - Invalid index, index exceeds the size of the stack ....."};
    }

    return stk->A[stk->top - index];
}

int handle_peek_stack(Stack *stk, int index)
{
    try
    {
        return peek_stack(stk, index);
    }
    catch(string &ex)
    {
        cout<<ex;

        return -1;
    }
}

int main()
{
    Stack stk {new int[6] {1, 2, 3, 4, 5, 6}, 5, 6};

    cout<<"peek_stack(stk, 5): "<<handle_peek_stack(&stk, 0)<<"\n";

    cout<<"peek_stack(stk, 0): "<<handle_peek_stack(&stk, 5)<<"\n";

    cout<<"peek_stack(stk, -1): "<<handle_peek_stack(&stk, -1)<<"\n";

    cout<<"peek_stack(stk, 6): "<<handle_peek_stack(&stk, 6)<<"\n";

    return 0;
}