/*
Created by  : Vaisakh Dileep
Date        : 30, May, 2021
Description : This program displays a stack.
*/

#include<iostream>

using namespace std;

struct Stack
{
    int *A {nullptr};

    int top {-1};

    int size {0};
};

void display_stack(Stack *stk) // We display from the top.
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

int main()
{
    Stack stk {new int[2] {1, 2}, 1, 2};

    cout<<"stk: ";
    display_stack(&stk);
    cout<<"\n";

    return 0;
}