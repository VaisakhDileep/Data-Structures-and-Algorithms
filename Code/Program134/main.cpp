/*
Created by  : Vaisakh Dileep
Date        : 23, May, 2021
Description : This program inserts an element to a sorted linked list.
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

void display_linked_list(Linked_list *L)
{
    Node *last = L->head;

    while(last != nullptr)
    {
        cout<<last->data<<(last->next != nullptr ? "->" : "");

        last = last->next;
    }
}

void insert_sorted_linked_list(Linked_list *L, int value)
{
    if(L == nullptr)
    {
        throw string {"ERROR - Invalid operation, linked list is not valid ....."};
    }

    if(L->head == nullptr)
    {
        L->head = new Node {value, nullptr};

        return ;
    }

    Node *target {L->head};

    Node *previous {};

    while((target != nullptr) and (target->data < value))
    {
        previous = target;

        target = target->next;
    }

    if(target == L->head)
    {
        Node* temp {new Node {value, nullptr}};

        temp->next = L->head;

        L->head = temp;
    }
    else
    {
        Node *temp {new Node {value, nullptr}};

        temp->next = target;

        previous->next = temp;
    }
}

void handle_insert_sorted_linked_list(Linked_list *L, int value)
{
    try
    {
        insert_sorted_linked_list(L, value);
    }
    catch(string &ex)
    {
        cout<<ex;
    }
}

int main()
{
    Linked_list L {};

    handle_insert_sorted_linked_list(&L, 1); // We can create a linked list(sorted) from scratch using "insert_sorted_linked_list()".
    handle_insert_sorted_linked_list(&L, 0);
    handle_insert_sorted_linked_list(&L, 2);
    handle_insert_sorted_linked_list(&L, 4);
    handle_insert_sorted_linked_list(&L, 3);

    cout<<"L: ";
    display_linked_list(&L);
    cout<<"\n";

    handle_insert_sorted_linked_list(nullptr, 0);

    return 0;
}