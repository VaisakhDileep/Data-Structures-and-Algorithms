/*
Created by  : Vaisakh Dileep
Date        : 1, June, 2021
Description : This program deletes an element from a queue.
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

void display_queue(Queue *Q)
{
    if(Q == nullptr)
    {
        return ;
    }

    Node *last {Q->front};

    while(last != nullptr)
    {
        cout<<last->data<<" ";

        last = last->next;
    }
}

bool is_empty_queue(Queue *Q)
{
    if(Q == nullptr)
    {
        throw string {"ERROR - Invalid operation, queue is not valid ....."};
    }

    if(Q->front == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int dequeue(Queue *Q) // Deletion happens from the rear.
{
    if(Q == nullptr)
    {
        throw string {"ERROR - Invalid operation, queue is not valid ....."};
    }

    if(is_empty_queue(Q))
    {
        throw string {"ERROR - Invalid operation, queue is empty ....."};
    }
    else
    {
        int deleted_value {Q->front->data};

        Node *temp {Q->front}; // To delete the dynamically allocated memory.

        Q->front = Q->front->next;

        if(Q->front == nullptr)
        {
            Q->rear = nullptr;
        }

        delete temp;

        return deleted_value;
    }
}

int handle_dequeue(Queue *Q)
{
    try
    {
        return dequeue(Q);
    }
    catch(string &ex)
    {
        cout<<ex;

        return -1;
    }
}

int main()
{
    Queue Q {};

    create_queue(&Q, new int[4] {1, 2, 3, 4}, 4);

    cout<<"Q: ";
    display_queue(&Q);
    cout<<"\n";

    handle_dequeue(&Q);
    handle_dequeue(&Q);

    cout<<"Q: ";
    display_queue(&Q);
    cout<<"\n";

    return 0;
}