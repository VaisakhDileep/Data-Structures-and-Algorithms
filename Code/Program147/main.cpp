/*
Created by  : Vaisakh Dileep
Date        : 27, May, 2021
Description : This program inserts an element to a circular linked list.
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

void insert_circular_linked_list(Linked_list *L, int index, int value)
{
    if(L == nullptr)
    {
        throw string {"ERROR - Invalid operation, circular linked list is not valid ....."};
    }

    if(index < 0)
    {
        throw string {"ERROR - Invalid index, index cannot be a negative number ....."};
    }

    if(index == 0)
    {
        Node *temp {new Node {value, nullptr}};

        if(L->head == nullptr)
        {
            L->head = temp;

            L->head->next = L->head;
        }
        else
        {
            Node *last {L->head};

            while(last->next != L->head)
            {
                last = last->next;
            }

            last->next = temp;

            temp->next = L->head;

            L->head = temp;
        }
    }
    else
    {
        if(L->head == nullptr)
        {
            throw string {"ERROR - Invalid index, index exceeds the size of the circular linked list ....."};
        }

        Node *target {L->head};

        int i {0};

        for(; (i < index - 1) and ((target != L->head) or (i == 0)); i++)
        {
            target = target->next;
        }

        if((target == L->head) and (i != 0))
        {
            throw string {"ERROR - Invalid index, index exceeds the size of the circular linked list ....."};
        }
        else
        {
            Node *temp {new Node {value, target->next}};

            target->next = temp;
        }
    }
}

void handle_insert_circular_linked_list(Linked_list *L, int index, int value)
{
    try
    {
        insert_circular_linked_list(L, index, value);
    }
    catch(string &ex)
    {
        cout<<ex;
    }
}

int main()
{
    Linked_list L {};

    handle_insert_circular_linked_list(&L, 0, 1); // We can create a circular linked list from scratch using "insert_circular_linked_list()".
    handle_insert_circular_linked_list(&L, 0, 2);
    handle_insert_circular_linked_list(&L, 1, 3);
    handle_insert_circular_linked_list(&L, 2, 4);
    handle_insert_circular_linked_list(&L, 3, 5);
    handle_insert_circular_linked_list(&L, 5, 6);

    cout<<"L: ";
    display_circular_linked_list(&L);
    cout<<"\n";

    handle_insert_circular_linked_list(&L, 7, -1);
    cout<<"\n";

    handle_insert_circular_linked_list(&L, -1, 2);
    cout<<"\n";

    handle_insert_circular_linked_list(nullptr, 6, 2);
    cout<<"\n";

    return 0;
}