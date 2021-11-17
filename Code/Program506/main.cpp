/*
Created by  : Vaisakh Dileep
Date        : 16, November, 2021
Description : This program demonstrates merge sort on a linked list.
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

    Node *last {L->head}; // "last" is the iterator.

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

Node *middle_node_linked_list(Linked_list *L)
{
    if(L == nullptr)
    {
        throw string {"ERROR - Invalid operation, linked list is not valid ....."};
    }

    if(L->head == nullptr)
    {
        throw string {"ERROR - Invalid operation, linked list is emtpy ....."};
    }

    Node *mid_node {L->head};

    Node *last {L->head};

    while(last != nullptr)
    {
        last = last->next;

        last = (last == nullptr) ? nullptr : last->next;

        mid_node = (last == nullptr) ? mid_node : mid_node->next;
    }

    return mid_node;
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

            first = first->next; // Make sure to update "first" before updating "result_previous".

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

Node* merge_sort(Node *head_ll_1)
{
    if(head_ll_1->next == nullptr)
    {
        return head_ll_1; // If head is the only element in the linked list.
    }

    Node *mid {middle_node_linked_list(new Linked_list {head_ll_1})};

    Node *head_ll_2 {mid->next};

    mid->next = nullptr;

    head_ll_1 = merge_sort(head_ll_1);
    head_ll_2 = merge_sort(head_ll_2);

    Linked_list *sorted_linked_list {merge_sorted_linked_list(new Linked_list {head_ll_1}, new Linked_list {head_ll_2})};

    return sorted_linked_list->head;
}

Linked_list* handle_merge_sort(Linked_list *L)
{
    if(L == nullptr)
    {
        cout<<"ERROR - Invalid operation, linked list is not valid .....";
    }

    return new Linked_list {merge_sort(L->head)};
}

int main()
{
    Linked_list L {};

    create_linked_list(&L, new int[10] {1, -1, 7, 19, 8, 1, 2, 8, 0, -4}, 10);

    Linked_list *result {handle_merge_sort(&L)};

    cout<<"L [before sorting]:";
    display_linked_list(&L);
    cout<<"\n";

    cout<<"L [after sorting]:";
    display_linked_list(result);
    cout<<"\n";

    return 0;
}