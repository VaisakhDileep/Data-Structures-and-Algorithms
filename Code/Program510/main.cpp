/*
Created by  : Vaisakh Dileep
Date        : 28, November, 2021
Description : This program flattens a multi-level linked list depth-wise(using stack).
*/

#include<iostream>

#include<stack>

using namespace std;

struct Node
{
    int data;

    Node *right;

    Node *down;
};

struct Multi_Level_Linked_list
{
    Node *head;
};

// Note: The head of each of the linked lists should be contained in any other linked list within the multi-level linked list(except the head of the first linked list in the multi-level linked list).

void insert_linked_list_right(Node *head, int *A, int size)
{
    if(head == nullptr)
    {
        throw string {"ERROR - Invalid operation, head of the linked list is not valid ....."};
    }

    if(head->right != nullptr)
    {
        throw string {"ERROR - Invalid operation, right pointer of head is already occupied ....."};
    }

    if(size == 0)
    {
        return ;
    }

    Node *last {head};

    for(int i {0}; i < size; i++)
    {
        last->right = new Node {A[i], nullptr, nullptr};

        last = last->right;
    }
}

void handle_insert_linked_list_right(Node *head, int *A, int size)
{
    try
    {
        insert_linked_list_right(head, A, size);
    }
    catch(string &ex)
    {
        cout<<ex;
    }
}

void insert_linked_list_down(Node *head, int *A, int size)
{
    if(head == nullptr)
    {
        throw string {"ERROR - Invalid operation, head of the linked list is not valid ....."};
    }

    if(head->down != nullptr)
    {
        throw string {"ERROR - Invalid operation, down pointer of head is already occupied ....."};
    }

    if(size == 0)
    {
        return ;
    }

    Node *last {head};

    for(int i {0}; i < size; i++)
    {
        last->down = new Node {A[i], nullptr, nullptr};

        last = last->down;
    }
}

void handle_insert_linked_list_down(Node *head, int *A, int size)
{
    try
    {
        insert_linked_list_down(head, A, size);
    }
    catch(string &ex)
    {
        cout<<ex;
    }
}

void flatten_multi_level_linked_list(Multi_Level_Linked_list *L)
{
    if(L == nullptr)
    {
        throw string {"ERROR - Invalid operation, multi-level linked list is not valid ....."};
    }

    if(L->head == nullptr)
    {
        throw string {"ERROR - Invalid operation, multi-level linked list is empty ....."};
    }

    stack<Node *> next_node_to_process {};

    next_node_to_process.push(L->head);

    Node *previous_node {};

    while(next_node_to_process.empty() == false)
    {
        Node *temp {next_node_to_process.top()};

        next_node_to_process.pop();

        if(temp->right != nullptr)
        {
            next_node_to_process.push(temp->right);
        }

        if(temp->down != nullptr)
        {
            next_node_to_process.push(temp->down);
        }

        if(previous_node != nullptr)
        {
            previous_node->right = temp;
        }

        previous_node = temp;
    }
}

void handle_flatten_multi_level_linked_list(Multi_Level_Linked_list *L)
{
    try
    {
        flatten_multi_level_linked_list(L);
    }
    catch(string &ex)
    {
        cout<<ex;
    }
}

void display_flattened_multi_level_linked_list(Multi_Level_Linked_list *L)
{
    if(L == nullptr)
    {
        return ;
    }

    Node *current_node {L->head};

    while(current_node != nullptr)
    {
        cout<<current_node->data<<" ";

        current_node = current_node->right;
    }
}

int main()
{
    Multi_Level_Linked_list L {new Node {0, nullptr, nullptr}};

    handle_insert_linked_list_right(L.head, new int[4] {1, 2, 3, 4}, 4);

    handle_insert_linked_list_down(L.head->right, new int[4] {5, 6, 7, 8}, 4);

    handle_insert_linked_list_right(L.head->right->down->down, new int[5] {9, 10, 11, 12, 13}, 5);

    handle_flatten_multi_level_linked_list(&L);

    cout<<"L(flattened depth-wise): ";
    display_flattened_multi_level_linked_list(&L);
    cout<<"\n";

    return 0;
}