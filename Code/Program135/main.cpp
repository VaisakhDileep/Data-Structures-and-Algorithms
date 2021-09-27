/*
Created by  : Vaisakh Dileep
Date        : 24, May, 2021
Description : This program deletes an element from a linked list.
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

void display_linked_list(Linked_list *L)
{
    Node *last = L->head;

    while(last != nullptr)
    {
        cout<<last->data<<(last->next != nullptr ? "->" : "");

        last = last->next;
    }
}

int delete_linked_list(Linked_list *L, int index)
{
    if(L == nullptr)
    {
        throw string {"ERROR - Invalid operation, linked list is not valid ....."};
    }

    if(L->head == nullptr)
    {
        throw string {"ERROR - Invalid operation, linked list is empty ....."};
    }

    if(index < 0)
    {
        throw string {"ERROR - Invalid index, index cannot be a negative number ....."};
    }

    int deleted_value {};

    if(index == 0)
    {
        Node *temp {L->head};

        L->head = temp->next;

        deleted_value = temp->data;

        delete temp;

        return deleted_value;
    }

    Node *target {L->head};

    Node *previous {};

    for(int i {0}; (i < index) and (target != nullptr); i++)
    {
        previous = target;

        target = target->next;
    }

    if(target == nullptr)
    {
        throw string {"ERROR - Invalid index, index exceeds the size of the linked list ....."};
    }

    previous->next = target->next;

    deleted_value = target->data;

    delete target;

    return deleted_value;
}

int handle_delete_linked_list(Linked_list *L, int index)
{
    try
    {
        return delete_linked_list(L, index);
    }
    catch(string &ex)
    {
        cout<<ex;

        return -1;
    }
}

int main()
{
    Linked_list L {};

    create_linked_list(&L, new int[6] {1, 2, 3, 4, 5, 6}, 6);

    handle_delete_linked_list(&L, 0);

    cout<<"L: ";
    display_linked_list(&L);
    cout<<"\n";

    handle_delete_linked_list(&L, 4);

    cout<<"L: ";
    display_linked_list(&L);
    cout<<"\n";

    handle_delete_linked_list(nullptr, 1);
    cout<<"\n";

    handle_delete_linked_list(&L, 4);
    cout<<"\n";

    handle_delete_linked_list(&L, -1);
    cout<<"\n";

    return 0;
}