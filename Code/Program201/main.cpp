/*
Created by  : Vaisakh Dileep
Date        : 4, June, 2021
Description : This program deletes an element in a circular queue.
*/

#include<iostream>

using namespace std;

struct Circular_Queue
{
    int *A {nullptr};

    int front {0};

    int rear {0};

    int size {0};
};

bool is_empty_circular_queue(Circular_Queue *Q)
{
    if(Q == nullptr)
    {
        throw string {"ERROR - Invalid operation, circular queue is not valid ....."};
    }

    if((Q->A == nullptr) or (Q->front == Q->rear))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void display_circular_queue(Circular_Queue *Q)
{
    if((Q == nullptr) or (Q->A == nullptr))
    {
        return ;
    }
    else if(is_empty_circular_queue(Q))
    {
        return ;
    }
    else
    {
        int i {Q->front + 1};

        do
        {
            cout<<Q->A[i]<<" ";

            i = (i + 1) % Q->size;

        } while(i != (Q->rear + 1) % Q->size);
    }
}

int delete_circular_queue(Circular_Queue *Q)
{
    if(Q == nullptr)
    {
        throw string {"ERROR - Invalid operation, circular queue is not valid ....."};
    }

    if(is_empty_circular_queue(Q))
    {
        throw string {"ERROR - Invalid operation, circular queue is empty ....."};
    }

    Q->front = (Q->front + 1) % Q->size;

    return Q->A[Q->front];
}

int handle_delete_circular_queue(Circular_Queue *Q)
{
    try
    {
        return delete_circular_queue(Q);
    }
    catch(string &ex)
    {
        cout<<ex;

        return -1;
    }
}

int main()
{
    Circular_Queue Q {new int[4] {0, 1, 2, 3}, 0, 3, 4};

    handle_delete_circular_queue(&Q);
    handle_delete_circular_queue(&Q);

    cout<<"Q: ";
    display_circular_queue(&Q);
    cout<<"\n";

    handle_delete_circular_queue(&Q);

    handle_delete_circular_queue(&Q);
    cout<<"\n";

    return 0;
}