/*
Created by  : Vaisakh Dileep
Date        : 28, May, 2021
Description : This program deletes an element in a doubly linked list.
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

void display_doubly_linked_list(Linked_list *L)
{
    if((L == nullptr) or (L->head == nullptr))
    {
        return ;
    }

    Node *last {L->head};

    while(last != nullptr)
    {
        cout<<last->data<<(last->next == nullptr ? "" : " <-> ");

        last = last->next;
    }
}

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

int delete_doubly_linked_list(Linked_list *L, int index)
{
    if(L == nullptr)
    {
        throw string {"ERROR - Invalid operation, doubly linked list is not valid ....."};
    }

    if(L->head == nullptr)
    {
        throw string {"ERROR - Invalid operation, doubly linked list is emtpy ....."};
    }

    if(index < 0)
    {
        throw string {"ERROR - Invalid index, index cannot be a negative number ....."};
    }

    int deleted_value {};

    if(index == 0)
    {
        Node *last {L->head};

        deleted_value = last->data;

        L->head = L->head->next;

        if(L->head != nullptr)
        {
            L->head->previous = nullptr;
        }

        delete last;
    }
    else
    {
        Node *target {L->head};

        for(int i {0}; (i < index) and (target != nullptr); i++)
        {
            target = target->next;
        }

        if(target == nullptr)
        {
            throw string {"ERROR - Invalid index, index exceeds the size of the doubly linked list ....."};
        }
        else
        {
            target->previous->next = target->next;

            if(target->next != nullptr)
            {
                target->next->previous = target->previous;
            }

            deleted_value = target->data;
        }
    }

    return deleted_value;
}

int handle_delete_doubly_linked_list(Linked_list *L, int index)
{
    try
    {
        return delete_doubly_linked_list(L, index);
    }
    catch(string &ex)
    {
        cout<<ex;

        return -1;
    }
}

int main()
{
    Linked_list L1 {}, L2 {};

    create_doubly_linked_list(&L1, new int[6] {1, 2, 3, 4, 5, 6}, 6);

    handle_delete_doubly_linked_list(&L1, 0);
    handle_delete_doubly_linked_list(&L1, 4);
    handle_delete_doubly_linked_list(&L1, 2);

    cout<<"L1: ";
    display_doubly_linked_list(&L1);
    cout<<"\n";

    handle_delete_doubly_linked_list(&L2, 0);
    cout<<"\n";

    handle_delete_doubly_linked_list(nullptr, 1);
    cout<<"\n";

    return 0;
}