/*
Created by  : Vaisakh Dileep
Date        : 2, June, 2021
Description : This program checks if a stack is full.
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

bool is_full_stack(Stack *stk) // The only case when the stack is full is when we run out of stack memory.
{
    Node *temp {new Node {0, nullptr}};

    if(temp == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    Stack S {};

    cout<<"is_full_stack(S): "<<is_full_stack(&S)<<"\n";

    return 0;
}