/*
Created by  : Vaisakh Dileep
Date        : 31, May, 2021
Description : This program deletes an element from a queue.
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

bool is_empty_queue(Queue *Q)
{
    if(Q == nullptr)
    {
        throw string {"ERROR - Invalid operation, queue is not valid ....."};
    }

    if(Q->front == Q->rear)
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

    Q->front++;

    int deleted_value {Q->A[Q->front]};

    return deleted_value;
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
    Queue Q {new int[4] {1, 2, 3, 4}, -1, 3, 4};

    cout<<"Q: ";
    display_queue(&Q);
    cout<<"\n";

    handle_dequeue(&Q);
    handle_dequeue(&Q);
    handle_dequeue(&Q);

    cout<<"Q: ";
    display_queue(&Q);
    cout<<"\n";

    return 0;
}