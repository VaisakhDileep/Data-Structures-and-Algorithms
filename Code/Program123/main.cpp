/*
Created by  : Vaisakh Dileep
Date        : 21, May, 2021
Description : This program creates a linked list from an array.
*/

#include<iostream>

using namespace std;

struct Node
{
    int data;

    Node *next;
};

struct Linked_list
{
    Node *head;
};

void create_linked_list(Linked_list *L, int *A, int size) // We could use the Array structure which we created earlier.
{
    if(size == 0)
    {
        return ;
    }

    L->head = new Node {A[0], nullptr};

    Node *last {L->head}; // "last" is the iterator.

    for(int i {1}; i < size; i++)
    {
        last->next = new Node {A[i], nullptr};

        last = last->next;
    }
}

int main()
{
    Linked_list L1 {}, L2 {};

    create_linked_list(&L1, new int[4] {1, 2, 3, 4}, 4);

    int A[4] {5, 6, 7, 8};

    create_linked_list(&L2, A, 4);

    return 0;
}