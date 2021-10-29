/*
Created by  : Vaisakh Dileep
Date        : 25, October, 2021
Description : This program displays(traverses) the xor linked list in the backward direction.
*/

#include<iostream>

using namespace std;

struct Node
{
    int data;

    Node *xor_link;
};

struct XOR_Linked_List
{
    Node *head;
};

Node* xor_node_ptrs(Node *node_1, Node *node_2)
{
    uintptr_t node_1_memory_address {reinterpret_cast<uintptr_t>(node_1)};

    uintptr_t node_2_memory_address {reinterpret_cast<uintptr_t>(node_2)};

    uintptr_t xor_value {node_1_memory_address ^ node_2_memory_address};

    Node *result_node {reinterpret_cast<Node*>(xor_value)};

    return result_node;
}

void insert_node_xor_linked_list(XOR_Linked_List *xor_linked_list, int data)
{
    if(xor_linked_list == nullptr)
    {
        throw string {"ERROR - Invalid operation, xor linked list is not valid ....."};
    }

    if(xor_linked_list->head == nullptr)
    {
        xor_linked_list->head = new Node {data, nullptr};

        return ;
    }

    Node *new_node = new Node {data, nullptr};

    new_node->xor_link = xor_node_ptrs(xor_linked_list->head, nullptr);

    xor_linked_list->head->xor_link = xor_node_ptrs(xor_linked_list->head->xor_link, new_node);

    xor_linked_list->head = new_node;
}

XOR_Linked_List* create_xor_linked_list(int *A, int size)
{
    if(A == nullptr)
    {
        throw string {"ERROR - Invalid operation, given array is not valid ....."};
    }

    XOR_Linked_List *xor_linked_list {new XOR_Linked_List {}};

    for(int i {0}; i < size; i++)
    {
        insert_node_xor_linked_list(xor_linked_list, A[i]);
    }

    return xor_linked_list;
}

XOR_Linked_List* handle_create_xor_linked_list(int *A, int size)
{
    try
    {
        return create_xor_linked_list(A, size);
    }
    catch(string &ex)
    {
        cout<<ex;

        return nullptr;
    }
}

void display_xor_linked_list_backward_direction(XOR_Linked_List *xor_linked_list)
{
    if(xor_linked_list == nullptr)
    {
        return ;
    }

    Node *current_node {xor_linked_list->head};

    Node *previous_node {nullptr};

    Node *next_node {nullptr};

    while(true)
    {
        next_node = xor_node_ptrs(current_node->xor_link, previous_node);

        if(next_node == nullptr)
        {
            break;
        }

        previous_node = current_node;

        current_node = next_node;
    }

    previous_node = nullptr;

    while(current_node != nullptr)
    {
        cout<<current_node->data<<" ";

        next_node = xor_node_ptrs(current_node->xor_link, previous_node);

        previous_node = current_node;

        current_node = next_node;
    }
}

int main()
{
    XOR_Linked_List *xor_linked_list {};

    xor_linked_list = handle_create_xor_linked_list(new int[6] {1, 2, 3, 4, 5, 6}, 6);

    cout<<"xor_linked_list: ";
    display_xor_linked_list_backward_direction(xor_linked_list);

    return 0;
}