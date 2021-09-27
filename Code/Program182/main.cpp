/*
Created by  : Vaisakh Dileep
Date        : 1, June, 2021
Description : This program creates a queue.
*/

#include<iostream>

using namespace std;

struct Node
{
    int data;

    Node *next;
};

struct Queue
{
    Node *front {nullptr}; // Pointer to the front of the queue.

    Node *rear {nullptr}; // Pointer to the rear of the queue.
};

int main()
{
    Queue Q {};

    Q.front = Q.rear = new Node {1, nullptr};

    Q.rear = Q.rear->next = new Node {2, nullptr};

    Q.rear = Q.rear->next = new Node {3, nullptr};

    return 0;
}