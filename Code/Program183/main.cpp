/*
Created by  : Vaisakh Dileep
Date        : 1, June, 2021
Description : This program creates a queue from an array.
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
    Node *front {nullptr};

    Node *rear {nullptr};
};

void create_queue(Queue *Q, int *A, int size)
{
    if(size == 0)
    {
        return ;
    }

    Q->front = Q->rear = new Node {A[0], nullptr};

    for(int i {1}; i < size; i++)
    {
        Q->rear = Q->rear->next = new Node {A[i], nullptr};
    }
}

int main()
{
    Queue Q {};

    create_queue(&Q, new int[6] {1, 2, 3, 4, 5, 6}, 6);

    int A[8] {1, 2, 3, 4, 5, 6, 7, 8};

    create_queue(&Q, A, 8);

    return 0;
}