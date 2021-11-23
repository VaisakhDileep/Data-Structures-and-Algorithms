/*
Created by  : Vaisakh Dileep
Date        : 18, November, 2021
Description : This program creates a multi-level linked list.
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

int main()
{
    Multi_Level_Linked_list L {new Node {0, nullptr, nullptr}};

    handle_insert_linked_list_right(L.head, new int[4] {1, 2, 3, 4}, 4);

    handle_insert_linked_list_down(L.head->right->right, new int[4] {9, 8, 7, 6}, 4);

    return 0;
}