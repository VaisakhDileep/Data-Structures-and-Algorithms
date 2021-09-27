/*
Created by  : Vaisakh Dileep
Date        : 26, May, 2021
Description : This program merges two sorted linked lists.
*/

// sorted here means ascending order.

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

Node *merge_sorted_linked_list(Linked_list *L1, Linked_list *L2)
{
    if((L1 == nullptr) or (L2 == nullptr))
    {
        throw string {"ERROR - Invalid operation, one of the linked list is not valid ....."};
    }

    Linked_list *result {new Linked_list {new Node {0, nullptr}}};

    Node *result_previous {result->head};

    Node *temp {};

    Node *first {L1->head}, *second {L2->head};

    while((first != nullptr) and (second != nullptr))
    {
        if(first->data < second->data)
        {
            temp = new Node {first->data, nullptr};

            result_previous->next = temp;

            result_previous = result_previous->next;

            first = first->next;
        }
        else if(second->data < first->data)
        {
            temp = new Node {second->data, nullptr};

            result_previous->next = temp;

            result_previous = result_previous->next;

            second = second->next;
        }
        else
        {
            temp = new Node {first->data, nullptr};

            result_previous->next = temp;

            result_previous = result_previous->next;

            second = second->next;

            first = first->next;
        }
    }

    if(first != nullptr)
    {
        result_previous->next = first;
    }
    else if(second != nullptr)
    {
        result_previous->next = second;
    }

    result->head = result->head->next;

    return result->head;
}

Node *handle_merge_sorted_linked_list(Linked_list *L1, Linked_list *L2)
{
    try
    {
        return merge_sorted_linked_list(L1, L2);
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

    create_linked_list(&L1, new int[6] {1, 3, 8, 9, 12, 34}, 6);

    create_linked_list(&L2, new int[5] {2, 11, 23, 25, 35}, 5);

    Linked_list result {handle_merge_sorted_linked_list(&L1, &L2)};

    cout<<"result: ";
    display_linked_list(&result);
    cout<<"\n";

    result.head = handle_merge_sorted_linked_list(&L1, &L3);

    cout<<"result: ";
    display_linked_list(&result);
    cout<<"\n";

    result.head = handle_merge_sorted_linked_list(&L3, &L1);

    cout<<"result: ";
    display_linked_list(&result);
    cout<<"\n";

    result.head = handle_merge_sorted_linked_list(&L3, &L3);

    cout<<"result: ";
    display_linked_list(&result);
    cout<<"\n";

    result.head = handle_merge_sorted_linked_list(nullptr, &L3);
    cout<<"\n";

    return 0;
}