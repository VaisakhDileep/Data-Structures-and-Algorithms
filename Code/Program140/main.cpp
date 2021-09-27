/*
Created by  : Vaisakh Dileep
Date        : 26, May, 2021
Description : This program concatenates two linked lists.
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

Node *concatenate_linked_list(Linked_list *L1, Linked_list *L2)
{
    if((L1 == nullptr) or (L2 == nullptr))
    {
        throw string {"ERROR - Invalid operation, one of the linked list is not valid ....."};
    }

    Linked_list *result {new Linked_list {new Node {0, nullptr}}};

    Node *temp {};

    Node *result_previous {result->head};

    Node *last {L1->head};

    while(last != nullptr)
    {
        temp = new Node {last->data, nullptr};

        result_previous->next = temp;

        result_previous = result_previous->next;

        last = last->next;
    }

    last = L2->head;

    while(last != nullptr)
    {
        temp = new Node {last->data, nullptr};

        result_previous->next = temp;

        result_previous = result_previous->next;

        last = last->next;
    }

    result->head = result->head->next;

    return result->head;
}

Node *handle_concatenate_linked_list(Linked_list *L1, Linked_list *L2)
{
    try
    {
        return concatenate_linked_list(L1, L2);
    }
    catch(string &ex)
    {
        cout<<ex;

        return nullptr;
    }
}

int main()
{
    Linked_list L1 {}, L2 {}, L3 {};

    create_linked_list(&L1, new int[6] {5, 2, 3, 4, 1, 6}, 6);

    create_linked_list(&L2, new int[5] {9, 7, 2, 1, 5}, 5);

    Linked_list result {handle_concatenate_linked_list(&L1, &L2)};

    cout<<"result: ";
    display_linked_list(&result);
    cout<<"\n";

    result.head = handle_concatenate_linked_list(&L1, &L3);

    cout<<"result: ";
    display_linked_list(&result);
    cout<<"\n";

    result.head = handle_concatenate_linked_list(&L3, &L1);

    cout<<"result: ";
    display_linked_list(&result);
    cout<<"\n";

    result.head = handle_concatenate_linked_list(&L3, &L3);

    cout<<"result: ";
    display_linked_list(&result);
    cout<<"\n";

    result.head = handle_concatenate_linked_list(nullptr, &L3);
    cout<<"\n";

    return 0;
}