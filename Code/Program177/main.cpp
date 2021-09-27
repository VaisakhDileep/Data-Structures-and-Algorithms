/*
Created by  : Vaisakh Dileep
Date        : 31, May, 2021
Description : This program inserts an element to a queue.
*/

#include<iostream>

using namespace std;

struct Queue
{
    int *A {nullptr};

    int front {-1};

    int rear {-1};

    int size {0};
};

void create_queue(Queue *Q, int size)
{
    Q->A = new int[size] {};

    Q->front = -1;

    Q->rear = -1;

    Q->size = size;
}

void display_queue(Queue *Q)
{
    if(Q == nullptr)
    {
        return ;
    }

    for(int i {Q->front + 1}; i <= Q->rear; i++)
    {
        cout<<Q->A[i]<<" ";
    }
}

bool is_full_queue(Queue *Q)
{
    if(Q == nullptr)
    {
        throw string {"ERROR - Invalid operation, queue is not valid ....."};
    }

    if(Q->rear == (Q->size - 1))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void enqueue(Queue *Q, int value) // Insertion happens from the front.
{
    if(Q == nullptr)
    {
        throw string {"ERROR - Invalid operation, queue is not valid ....."};
    }

    if(is_full_queue(Q))
    {
        throw string {"ERROR - Invalid operation, queue is full ....."};
    }

    Q->rear++;

    Q->A[Q->rear] = value;
}

void handle_enqueue(Queue *Q, int value)
{
    try
    {
        enqueue(Q, value);
    }
    catch(string &ex)
    {
        cout<<ex;
    }
}

int main()
{
    Queue Q {};

    create_queue(&Q, 10);

    handle_enqueue(&Q, 1);
    handle_enqueue(&Q, 2);
    handle_enqueue(&Q, 3);

    cout<<"Q: ";
    display_queue(&Q);
    cout<<"\n";

    return 0;
}