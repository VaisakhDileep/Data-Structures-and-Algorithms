/*
Created by  : Vaisakh Dileep
Date        : 29, May, 2021
Description : This program creates a circular doubly linked list.
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
    Linked_list L {};

    L.head = new Node {nullptr, 0, nullptr};

    L.head->previous = L.head;

    L.head->next = L.head;

    L.head->next = new Node {L.head, 1, L.head};

    L.head->previous = L.head->next;

    L.head->next->next = new Node {L.head->next, 2, L.head};

    L.head->previous = L.head->next->next;

    return 0;
}