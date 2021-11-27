/*
Created by  : Vaisakh Dileep
Date        : 27, November, 2021
Description : This program flattens a multi-level linked list depth-wise(using recursion).
*/

#include<iostream>

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

// Note: The head of each of the linked lists should be contained in any other linked list within the multi-level linked list(except the head of the multi-level linked list).

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

Node* flatten_multi_level_linked_list(Node *head)
{
    static Node *last_visited_node; // "last_visited_node" is the last visited node in the recursive call stack.

    last_visited_node = head;

    Node *right_node {head->right};

    if(head->down != nullptr)
    {
        head->right = flatten_multi_level_linked_list(head->down);
    }

    if(right_node != nullptr)
    {
        last_visited_node->right = flatten_multi_level_linked_list(right_node);
    }

    return head;
}

void handle_flatten_multi_level_linked_list(Multi_Level_Linked_list *L)
{
    if(L == nullptr)
    {
        cout<<"ERROR - Invalid operation, multi level linked list is not valid .....";

        return ;
    }

    if(L->head == nullptr)
    {
        cout<<"ERROR - Invalid operation, multi level linked list is empty .....";

        return ;
    }

    flatten_multi_level_linked_list(L->head);
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