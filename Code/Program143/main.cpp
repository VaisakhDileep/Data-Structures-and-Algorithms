/*
Created by  : Vaisakh Dileep
Date        : 26, May, 2021
Description : This program finds the middle node in a linked list.
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

Node *handle_middle_node_linked_list(Linked_list *L)
{
    try
    {
        return middle_node_linked_list(L);
    }
    catch(string &ex)
    {
        cout<<ex;

        return nullptr;
    }
}

int main()
{
    Linked_list L1 {}, L2 {};

    create_linked_list(&L1, new int[5] {1, 2, 3, 4, 5}, 5);

    Node* result {handle_middle_node_linked_list(&L1)};

    cout<<"result: "<<result->data<<"\n";

    result = handle_middle_node_linked_list(&L2);
    cout<<"\n";

    result = handle_middle_node_linked_list(nullptr);
    cout<<"\n";

    return 0;
}