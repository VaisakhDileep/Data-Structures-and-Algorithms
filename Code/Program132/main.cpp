/*
Created by  : Vaisakh Dileep
Date        : 22, May, 2021
Description : This program appends an element at the end of a linked list.
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

void display_linked_list(Linked_list *L)
{
    Node *last = L->head;

    while(last != nullptr)
    {
        cout<<last->data<<(last->next != nullptr ? "->" : "");

        last = last->next;
    }
}

void append_linked_list(Linked_list *L, int data)
{
    if(L == nullptr)
    {
        throw string {"ERROR - Invalid operation, linked list is not valid ....."};
    }

    if(L->head == nullptr)
    {
        L->head = new Node {data, nullptr};
    }
    else
    {
        Node *last {L->head};

        while(last->next != nullptr)
        {
            last = last->next;
        }

        last->next = new Node {data, nullptr};
    }
}

void handle_append_linked_list(Linked_list *L, int data)
{
    try
    {
        append_linked_list(L, data);
    }
    catch(string &ex)
    {
        cout<<ex;
    }
}

int main()
{
    handle_append_linked_list(nullptr, 0); // Here "Linked_list" is a "nullptr". Make sure to create a "Linked_List" object before passing it to the function.

    cout<<"\n";

    Linked_list L {};

    handle_append_linked_list(&L, 0); // We can create a linked list from scratch using "append_linked_list()".
    handle_append_linked_list(&L, 1);
    handle_append_linked_list(&L, 2);

    cout<<"L: ";
    display_linked_list(&L);
    cout<<"\n";

    return 0;
}