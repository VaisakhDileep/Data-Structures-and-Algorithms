/*
Created by  : Vaisakh Dileep
Date        : 30, May, 2021
Description : This program checks if a stack is empty.
*/

#include<iostream>

using namespace std;

struct Stack
{
    int *A {nullptr};

    int top {-1};

    int size {0};
};

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

bool handle_is_empty_stack(Stack *stk)
{
    try
    {
        return is_empty_stack(stk);
    }
    catch(string &ex)
    {
        cout<<ex;

        return false;
    }
}

int main()
{
    Stack stk {};

    cout<<"handle_is_empty_stack(stk): "<<handle_is_empty_stack(&stk)<<"\n";

    return 0;
}