/*
Created by  : Vaisakh Dileep
Date        : 1, June, 2021
Description : This program inserts an element to a queue.
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

bool is_full_queue(Queue *Q)
{
    Node *temp = new Node {0, nullptr};

    if(temp == NULL)
    {
        return true;
    }
    else
    {
        delete temp;

        return false;
    }
}

void enqueue(Queue *Q, int value)
{
    if(Q == nullptr)
    {
        throw string {"ERROR - Invalid operation, queue is not valid ....."};
    }

    if(is_full_queue(Q))
    {
        throw string {"ERROR - Invalid operation, queue is full ....."};
    }

    if(Q->front == nullptr)
    {
        Q->front = Q->rear = new Node {value, nullptr};
    }
    else
    {
        Q->rear = Q->rear->next = new Node {value, nullptr};
    }
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

    handle_enqueue(&Q, 1);
    handle_enqueue(&Q, 2);
    handle_enqueue(&Q, 3);
    handle_enqueue(&Q, 4);

    cout<<"Q: ";
    display_queue(&Q);
    cout<<"\n";

    return 0;
}