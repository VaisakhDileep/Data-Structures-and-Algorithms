/*
Created by  : Vaisakh Dileep
Date        : 27, May,2021
Description : This program creates a doubly linked list.
*/

#include<iostream>

using namespace std;

struct Node
{
    Node *previous;

    int data;

    Node *next;
};

struct Linked_list
{
    Node *head;
};

int main()
{
    Linked_list L {new Node {nullptr, 1, nullptr}};

    L.head->next = new Node {L.head, 2, nullptr};

    L.head->next->next  = new Node {L.head->next, 3, nullptr};

    return 0;
}