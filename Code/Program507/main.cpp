/*
Created by  : Vaisakh Dileep
Date        : 17, November, 2021
Description : This program merges two sorted linked lists(in-place).
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

Linked_list *merge_sorted_linked_list(Linked_list *L1, Linked_list *L2) // in-place merging.
{
    if((L1 == nullptr) or (L2 == nullptr))
    {
        throw string {"ERROR - Invalid operation, one of the linked list is not valid ....."};
    }

    Linked_list *result {new Linked_list {new Node {0, nullptr}}};

    Node *result_previous {result->head};

    Node *first {L1->head}, *second {L2->head};

    while((first != nullptr) and (second != nullptr))
    {
        if(first->data < second->data)
        {
            result_previous->next = first;

            result_previous = result_previous->next;

            first = first->next;
        }
        else if(second->data < first->data)
        {
            result_previous->next = second;

            result_previous = result_previous->next;

            second = second->next;
        }
        else
        {
            result_previous->next = first;

            result_previous = result_previous->next;

            first = first->next;

            result_previous->next = second;

            result_previous = result_previous->next;

            second = second->next;
        }
    }

    while(first != nullptr)
    {
        result_previous->next = first;

        result_previous = result_previous->next;

        first = first->next;
    }
    while(second != nullptr)
    {
        result_previous->next = second;

        result_previous = result_previous->next;

        second = second->next;
    }

    L1->head = nullptr;

    L2->head = nullptr; // 'L1' and 'L2' are obsolete now.
 
    result->head = result->head->next;

    return result;
}

Linked_list *handle_merge_sorted_linked_list(Linked_list *L1, Linked_list *L2)
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

    create_linked_list(&L2, new int[6] {1, 2, 11, 23, 25, 35}, 6);

    Linked_list *result {handle_merge_sorted_linked_list(&L1, &L2)}; // 'L1' and 'L2' are null after merging.

    cout<<"result: ";
    display_linked_list(result);
    cout<<"\n";

    result = handle_merge_sorted_linked_list(nullptr, &L3);
    cout<<"\n";

    return 0;
}