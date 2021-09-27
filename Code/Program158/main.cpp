/*
Created by  : Vaisakh Dileep
Date        : 29, May, 2021
Description : This program creates a circular doubly linked list from an array.
*/

#include<iostream>

using namespace std;

struct Node
{
    Node *previous;

    int data;

    Node *next;
};

struct Linked_list
{
    Node *head;
};

void create_circular_doubly_linked_list(Linked_list *L, int *A, int size)
{
    if(size == 0)
    {
        return ;
    }

    L->head = new Node {nullptr, A[0], nullptr};

    L->head->previous = L->head;

    L->head->next = L->head;

    Node *last {L->head};

    for(int i {1}; i < size; i++)
    {
        Node *temp {new Node {nullptr, A[i], nullptr}};

        last->next = temp;

        temp->previous = last;

        temp->next = L->head;

        L->head->previous = temp;

        last = temp;
    }
}

int main()
{
    Linked_list L {};

    create_circular_doubly_linked_list(&L, new int[6] {1, 2, 3, 4, 5, 6}, 6);

    int A[4] {1, 2, 3, 4};

    create_circular_doubly_linked_list(&L, A, 4);

    return 0;
}