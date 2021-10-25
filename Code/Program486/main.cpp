/*
Created by  : Vaisakh Dileep
Date        : 25, October, 2021
Description : This program inserts an element to a xor linked list.
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
    uintptr_t node_1_memory_address {reinterpret_cast<uintptr_t>(node_1)}; // "uintptr_t" will safely hold the memory address.

    uintptr_t node_2_memory_address {reinterpret_cast<uintptr_t>(node_2)};

    uintptr_t xor_value {node_1_memory_address ^ node_2_memory_address};

    Node *result_node {reinterpret_cast<Node*>(xor_value)}; // reinterpret it back to the node pointer.

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

    Node *new_node = new Node {data, nullptr}; // We are going to insert this node before the head and make this the new head.

    new_node->xor_link = xor_node_ptrs(xor_linked_list->head, nullptr); // Since there are no previous nodes, we have to xor with nullptr(0). The node after "new_node" is the current head node.

    xor_linked_list->head->xor_link = xor_node_ptrs(xor_linked_list->head->xor_link, new_node); // Since current head now has a previous node("new_node"), we have to xor it with the current head node.

    xor_linked_list->head = new_node; // Update the head node to "new_node".
}

void handle_insert_node_xor_linked_list(XOR_Linked_List *xor_linked_list, int data)
{
    try
    {
        insert_node_xor_linked_list(xor_linked_list, data);
    }
    catch(string &ex)
    {
        cout<<ex;
    }
}

int main()
{
    XOR_Linked_List *xor_linked_list {new XOR_Linked_List {nullptr}};

    handle_insert_node_xor_linked_list(xor_linked_list, 1);
    handle_insert_node_xor_linked_list(xor_linked_list, 2);
    handle_insert_node_xor_linked_list(xor_linked_list, 3);

    return 0;
}