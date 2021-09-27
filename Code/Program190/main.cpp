/*
Created by  : Vaisakh Dileep
Date        : 2, June, 2021
Description : This program creates a stack from an array.
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

int main()
{
    Stack S {};

    create_stack(&S, new int[4] {1, 2, 3, 4}, 4);

    return 0;
}