/*
Created by  : Vaisakh Dileep
Date        : 27, May, 2021
Description : This program counts the number of nodes in a circular linked list.
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

void create_circular_linked_list(Linked_list *L, int *A, int size)
{
    if(size == 0)
    {
        return ;
    }

    L->head = new Node {A[0], L->head};

    Node *last {L->head};

    for(int i {1}; i < size; i++)
    {
        last->next = new Node {A[i], L->head};

        last = last->next;
    }
}

int count_nodes_circular_linked_list(Linked_list *L)
{
    if((L == nullptr) or (L->head == nullptr))
    {
        return 0;
    }

    int count {0};

    Node *last {L->head};

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

    create_circular_linked_list(&L1, new int[6] {1, 2, 3, 4, 5, 6}, 6);

    cout<<"count_nodes_circular_linked_list(L1): "<<count_nodes_circular_linked_list(&L1)<<"\n";
    cout<<"count_nodes_circular_linked_list(L2): "<<count_nodes_circular_linked_list(&L2)<<"\n";
    cout<<"count_nodes_circular_linked_list(nullptr): "<<count_nodes_circular_linked_list(nullptr)<<"\n";

    return 0;
}