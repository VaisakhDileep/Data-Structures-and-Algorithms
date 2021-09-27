/*
Created by  : Vaisakh Dileep
Date        : 29, May, 2021
Description : This program counts the number of nodes in a circular doubly linked list.
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

int count_circular_doubly_linked_list(Linked_list *L)
{
    if((L == nullptr) or (L->head == nullptr))
    {
        return 0;
    }

    Node *last {L->head};

    int count {0};

    do
    {
        count++;

        last = last->next;

    } while(last != L->head);

    return count;
}

int main()
{
    Linked_list L1 {}, L2 {};

    create_circular_doubly_linked_list(&L1, new int[6] {1, 2, 3, 4, 5, 6}, 6);

    cout<<"count_circular_doubly_linked_list(L1): "<<count_circular_doubly_linked_list(&L1)<<"\n";
    cout<<"count_circular_doubly_linked_list(L2): "<<count_circular_doubly_linked_list(&L2)<<"\n";
    cout<<"count_circular_doubly_linked_list(nullptr): "<<count_circular_doubly_linked_list(nullptr)<<"\n";

    return 0;
}