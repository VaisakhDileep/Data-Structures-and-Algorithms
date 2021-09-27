/*
Created by  : Vaisakh Dileep
Date        : 25, May, 2021
Description : This program removes all the duplicate elements in a sorted linked list.
*/

// sorted here means ascending order.

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

void display_linked_list(Linked_list *L)
{
    Node *last = L->head;

    while(last != nullptr)
    {
        cout<<last->data<<(last->next != nullptr ? "->" : "");

        last = last->next;
    }
}

void remove_duplicate_elements(Linked_list *L)
{
    if(L == nullptr)
    {
        throw string {"ERROR - Invalid operation, linked list is not valid ....."};
    }

    if(L->head == nullptr)
    {
        throw string {"ERROR - Invalid operation, linked list is empty ....."};
    }

    Node *target {L->head->next};

    Node *previous {L->head};

    while(target)
    {
        if(target->data != previous->data)
        {
            previous = target;

            target = target->next;
        }
        else
        {
            previous->next = target->next;

            delete target;

            target = previous->next;
        }
    }
}

void handle_remove_duplicate_elements(Linked_list *L)
{
    try
    {
        remove_duplicate_elements(L);
    }
    catch(string &ex)
    {
        cout<<ex;
    }
}

int main()
{
    Linked_list L {};

    create_linked_list(&L, new int[9] {1, 1, 1, 2, 2, 4, 5, 6, 6}, 9);

    handle_remove_duplicate_elements(&L);

    cout<<"L: ";
    display_linked_list(&L);
    cout<<"\n";

    return 0;
}