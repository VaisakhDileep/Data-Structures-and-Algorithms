/*
Created by  : Vaisakh Dileep
Date        : 1, June, 2021
Description : This program creates a stack.
*/

#include<iostream>

struct Node
{
    int data;

    Node *next;
};

struct Stack
{
    Node *top; // "top" is the head of the linked list, since insertion and deletion at the head takes O(1) time.
};

int main()
{
    Stack S {};

    S.top = new Node {1, nullptr};

    S.top = new Node {2, S.top};
    S.top = new Node {3, S.top};

    return 0;
}