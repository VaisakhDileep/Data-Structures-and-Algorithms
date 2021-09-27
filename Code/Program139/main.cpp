/*
Created by  : Vaisakh Dileep
Date        : 25, May, 2021
Description : This program reverses a linked list by reversing the links.
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

namespace iteration
{
    void reverse_linked_list(Linked_list *L)
    {
        if(L == nullptr)
        {
            throw string {"ERROR - Invalid operation, linked list is not valid ....."};
        }

        if(L->head == nullptr)
        {
            throw string {"ERROR - Invalid operation, linked list is empty ....."};
        }

        Node *current_node {L->head};

        Node *prev_node {};

        Node *prev_prev_node {};

        while(current_node != nullptr)
        {
            prev_prev_node = prev_node;

            prev_node = current_node;

            current_node = current_node->next;

            prev_node->next = prev_prev_node;
        }

        L->head = prev_node;
    }

    void handle_reverse_linked_list(Linked_list *L)
    {
        try
        {
            reverse_linked_list(L);
        }
        catch(string &ex)
        {
            cout<<ex;
        }
    }
}

namespace recursion
{
    void reverse_linked_list(Linked_list *L, Node *current_node, Node *prev_node = nullptr)
    {
        if(current_node != nullptr)
        {
            reverse_linked_list(L, current_node->next, current_node);

            current_node->next = prev_node; // Executed in the returning phase.
        }
        else
        {
            L->head = prev_node;
        }
    }

    void handle_reverse_linked_list(Linked_list *L)
    {
        if(L == nullptr)
        {
            cout<<"ERROR - Invalid operation, linked list is not valid .....";
        }

        if(L->head == nullptr)
        {
            cout<<"ERROR - Invalid operation, linked list is empty .....";
        }

        reverse_linked_list(L, L->head);
    }
}

int main()
{
    Linked_list L1 {}, L2 {};

    create_linked_list(&L1, new int[6] {1, 2, 3, 4, 5, 6}, 6);

    cout<<"L1: ";
    display_linked_list(&L1);
    cout<<"\n";

    iteration::handle_reverse_linked_list(&L1);

    cout<<"L1: ";
    display_linked_list(&L1);
    cout<<"\n";

    iteration::handle_reverse_linked_list(&L2);
    cout<<"\n";

    iteration::handle_reverse_linked_list(nullptr);
    cout<<"\n";

    cout<<"Using recursion: \n";

    cout<<"L1: ";
    display_linked_list(&L1);
    cout<<"\n";

    recursion::handle_reverse_linked_list(&L1);

    cout<<"L1: ";
    display_linked_list(&L1);
    cout<<"\n";

    recursion::handle_reverse_linked_list(&L2);
    cout<<"\n";

    recursion::handle_reverse_linked_list(nullptr);
    cout<<"\n";

    return 0;
}