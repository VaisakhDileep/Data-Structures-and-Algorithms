/*
Created by  : Vaisakh Dileep
Date        : 27, May, 2021
Description : This program deletes an element in a circular linked list.
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

void display_circular_linked_list(Linked_list *L)
{
    if(L->head == nullptr)
    {
        return ;
    }

    Node *last {L->head};

    do
    {
        cout<<last->data<<(last->next == L->head ? "" : "->");

        last = last->next;

    } while(last != L->head);
}

int delete_circular_linked_list(Linked_list *L, int index)
{
    if(L == nullptr)
    {
        throw string {"ERROR - Invalid operation, circular linked list is not valid ....."};
    }

    if(L->head == nullptr)
    {
        throw string {"ERROR - Invalid operation, circular linked list is empty ....."};
    }

    if(index < 0)
    {
        throw string {"ERROR - Invalid index, index cannot be a negative number ....."};
    }

    int deleted_value {};

    if(index == 0)
    {
        Node *last {L->head};

        while(last->next != L->head)
        {
            last = last->next;
        }

        if(last == L->head)
        {
            delete L->head;

            L->head = nullptr;
        }
        else
        {
            last->next = L->head->next;

            deleted_value = L->head->data;

            delete L->head;

            L->head = last->next;
        }
    }
    else
    {
        Node *target {L->head};

        for(int i {0}; (i < index - 1) and (target->next != L->head); i++)
        {
            target = target->next;
        }

        if(target->next == L->head)
        {
            throw string {"ERROR - Invalid index, index exceeds the size of the circular linked list ....."};
        }

        Node *temp {target->next}; // For deleting the dynamically created memory.

        target->next = target->next->next;

        deleted_value = target->next->data;

        delete temp;
    }

    return deleted_value;
}

int handle_delete_circular_linked_list(Linked_list *L, int index)
{
    try
    {
        return delete_circular_linked_list(L, index);
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

    create_circular_linked_list(&L1, new int[6] {1, 2, 3, 4, 5, 6}, 6);

    handle_delete_circular_linked_list(&L1, 0);
    handle_delete_circular_linked_list(&L1, 4);


    cout<<"L1: ";
    display_circular_linked_list(&L1);
    cout<<"\n";

    handle_delete_circular_linked_list(&L1, 4);
    cout<<"\n";

    handle_delete_circular_linked_list(&L1, -1);
    cout<<"\n";

    handle_delete_circular_linked_list(nullptr, 2);
    cout<<"\n";

    handle_delete_circular_linked_list(&L2, 1);
    cout<<"\n";

    return 0;
}