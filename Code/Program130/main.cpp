/*
Created by  : Vaisakh Dileep
Date        : 22, May, 2021
Description : This program finds the average of all the elements in a linked list.
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

void create_linked_list(Linked_list *L, int *A, int size)
{
    if(size == 0)
    {
        return ;
    }

    L->head = new Node {A[0], nullptr};

    Node *last {L->head};

    for(int i {1}; i < size; i++)
    {
        last->next = new Node {A[i], nullptr};

        last = last->next;
    }
}

int sum_linked_list(Linked_list *L)
{
    if(L == nullptr)
    {
        return 0;
    }

    int sum {0};

    Node *last {L->head};

    while(last != nullptr)
    {
        sum += last->data;

        last = last->next;
    }

    return sum;
}

int count_nodes_linked_list(Linked_list *L)
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

double average_linked_list(Linked_list *L)
{
    if(count_nodes_linked_list(L) == 0)
    {
        return 0;
    }

    return static_cast<double>(sum_linked_list(L)) / count_nodes_linked_list(L);
}

int main()
{
    Linked_list L1 {};

    create_linked_list(&L1, new int[6] {1, 2, 9, 4, -1, 6}, 6);

    cout<<"average_linked_list(L1): "<<average_linked_list(&L1)<<"\n";

    return 0;
}