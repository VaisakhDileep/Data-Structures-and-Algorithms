/*
Created by  : Vaisakh Dileep
Date        : 13, June, 2021
Description : This program demonstrates insertion sort on a linked list.
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

void delete_linked_list(Linked_list *L)
{
    Node *last {L->head};

    while(last != nullptr)
    {
        Node *temp {last->next};

        delete last;

        last = temp;
    }

    L->head = nullptr;
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

void insertion_sort(Linked_list *L) // Insertion sort is preferrable for linked list as we dont have to shift unlike the case for arrays.
{
    Linked_list *sorted_list {new Linked_list {}};

    Node *current_node {L->head};

    while(current_node != nullptr)
    {
        insert_sorted_linked_list(sorted_list, current_node->data);

        current_node = current_node->next;
    }

    delete_linked_list(L);

    L->head = sorted_list->head;
}

int main()
{
    Linked_list L {};

    create_linked_list(&L, new int[6] {8, 9, 2, 1, 3, 4}, 6);

    cout<<"L: ";
    display_linked_list(&L);
    cout<<"\n";

    insertion_sort(&L);

    cout<<"L: ";
    display_linked_list(&L);
    cout<<"\n";

    return 0;
}