/*
Created by  : Vaisakh Dileep
Date        : 30, May, 2021
Description : This program creates a stack.
*/

#include<iostream>

using namespace std;

struct Stack
{
    int *A {nullptr}; // dynamically created array.

    int top {-1}; // index of the top-most element in the stack.

    int size {0}; // max size of the stack.
};

void create_stack(Stack *stk, int size)
{
    stk->A = new int[size] {};

    stk->top = -1;

    stk->size = size;
}

int main()
{
    Stack stk;

    create_stack(&stk, 100);

    return 0;
}