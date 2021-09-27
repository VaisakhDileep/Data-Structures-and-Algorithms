/*
Created by  : Vaisakh Dileep
Date        : 29, May, 2021
Description : This program inserts an element to a circular doubly linked list.
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

void display_circular_doubly_linked_list(Linked_list *L)
{
    if((L == nullptr) or (L->head == nullptr))
    {
        return ;
    }

    Node *last {L->head};

    do
    {
        cout<<last->data<<(last->next != L->head ? " <-> " : "");

        last = last->next;

    } while(last != L->head);
}

void insert_circular_doubly_linked_list(Linked_list *L, int index, int value)
{
    if(L == nullptr)
    {
        throw string {"ERROR - Invalid operation, circular doubly linked list is not valid ....."};
    }

    if(index < 0)
    {
        throw string {"ERROR - Invalid index, index cannot be a negative number ....."};
    }

    if(index == 0)
    {
        if(L->head == nullptr)
        {
            L->head = new Node {nullptr, value, nullptr};

            L->head->next = L->head;

            L->head->previous = L->head;
        }
        else
        {
            Node *temp {new Node {nullptr, value, nullptr}};

            temp->next = L->head;

            temp->previous = L->head->previous;

            L->head->previous->next = temp;

            L->head->previous = temp;
        }
    }
    else
    {
        if(L->head == nullptr)
        {
            throw string {"ERROR - Invalid index, index exceeds the size of the circular doubly linked list ....."};
        }

        Node *target {L->head};

        int i {0};

        for(; (i < index - 1) and ((target != L->head) or (i == 0)); i++)
        {
            target = target->next;
        }

        if((target == L->head) and (i != 0))
        {
            throw string {"ERROR - Invalid index, index exceeds the size of the circular doubly linked list ....."};
        }
        else
        {
            Node *temp {new Node {nullptr, value, nullptr}};

            temp->next = target->next;

            temp->previous = target;

            target->next = temp;

            temp->next->previous = temp;
        }
    }
}

void handle_insert_circular_doubly_linked_list(Linked_list *L, int index, int value)
{
    try
    {
        insert_circular_doubly_linked_list(L, index, value);
    }
    catch(string &ex)
    {
        cout<<ex;
    }
}

int main()
{
    Linked_list L1 {}, L2 {};

    handle_insert_circular_doubly_linked_list(&L1, 0, 1);
    handle_insert_circular_doubly_linked_list(&L1, 0, 2);
    handle_insert_circular_doubly_linked_list(&L1, 2, 3);
    handle_insert_circular_doubly_linked_list(&L1, 2, 4);

    cout<<"L1: ";
    display_circular_doubly_linked_list(&L1);
    cout<<"\n";

    handle_insert_circular_doubly_linked_list(&L1, -1, 0);
    cout<<"\n";

    handle_insert_circular_doubly_linked_list(&L1, 5, 5);
    cout<<"\n";

    handle_insert_circular_doubly_linked_list(nullptr, 0, 0);
    cout<<"\n";

    return 0;
}