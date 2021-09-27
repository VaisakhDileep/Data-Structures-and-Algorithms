/*
Created by  : Vaisakh Dileep
Date        : 28, May, 2021
Description : This program counts the number of nodes in a doubly linked list.
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

void create_doubly_linked_list(Linked_list *L, int *A, int size)
{
    if(size == 0)
    {
        return ;
    }

    L->head = new Node {nullptr, A[0], nullptr};

    Node *last {L->head};

    for(int i {1}; i < size; i++)
    {
        last->next = new Node {last, A[i], nullptr};

        last = last->next;
    }
}

int count_doubly_linked_list(Linked_list *L)
{
    if(L == nullptr)
    {
        return 0;
    }

    int count {0};

    Node *last {L->head};

    while(last != nullptr)
    {
        count++;

        last = last->next;
    }

    return count;
}

int main()
{
    Linked_list L1 {}, L2 {};

    create_doubly_linked_list(&L1, new int[4] {1, 2, 3, 4}, 4);

    cout<<"count_doubly_linked_list(L1): "<<count_doubly_linked_list(&L1)<<"\n";
    cout<<"count_doubly_linked_list(L2): "<<count_doubly_linked_list(&L2)<<"\n";
    cout<<"count_doubly_linked_list(nullptr): "<<count_doubly_linked_list(nullptr)<<"\n";

    return 0;
}