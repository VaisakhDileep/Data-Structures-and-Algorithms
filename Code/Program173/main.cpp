/*
Created by  : Vaisakh Dileep
Date        : 31, May, 2021
Description : This program creates a queue.
*/

#include<iostream>

using namespace std;

struct Queue
{
    int *A {nullptr}; // dynamically created array.

    int front {-1}; // index of the array element before the first element in the queue.

    int rear {-1}; // index of the last element in the queue.

    int size {0}; // size of the queue.
};

void create_queue(Queue *Q, int size)
{
    Q->A = new int[size] {};

    Q->front = -1;

    Q->rear = -1;

    Q->size = size;
}

int main()
{
    Queue Q {};

    create_queue(&Q, 10);

    return 0;
}