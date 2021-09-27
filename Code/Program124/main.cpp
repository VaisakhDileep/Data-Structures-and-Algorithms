/*
Created by  : Vaisakh Dileep
Date        : 21, May, 2021
Description : This program displays a linked list.
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

namespace iteration
{
    void display_linked_list(Linked_list *L)
    {
        Node *last = L->head;

        while(last != nullptr)
        {
            cout<<last->data<<(last->next != nullptr ? "->" : "");

            last = last->next;
        }
    }
}

namespace recursion
{
    void display_linked_list(Node *node)
    {
        if(node != nullptr)
        {
            cout<<node->data<<(node->next != nullptr ? "->": "");

            display_linked_list(node->next);
        }
    }

    void handle_display_linked_list(Linked_list *L)
    {
        display_linked_list(L->head);
    }
}

int main()
{
    Linked_list L1 {};

    create_linked_list(&L1, new int[4] {1, 2, 3, 4}, 4);

    cout<<"L1: ";
    iteration::display_linked_list(&L1);
    cout<<"\n";

    cout<<"L2: ";
    recursion::handle_display_linked_list(&L1);
    cout<<"\n";

    return 0;
}