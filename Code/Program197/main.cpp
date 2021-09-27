/*
Created by  : Vaisakh Dileep
Date        : 4, June, 2021
Description : This program checks if a circular queue is empty.
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

bool handle_is_empty_circular_queue(Circular_Queue *Q)
{
    try
    {
        return is_empty_circular_queue(Q);
    }
    catch(string &ex)
    {
        cout<<ex;

        return false;
    }
}

int main()
{
    Circular_Queue Q {};

    cout<<"handle_is_empty_circular_queue(Q): "<<handle_is_empty_circular_queue(&Q)<<"\n";

    Q.A = new int[4] {0, 1, 0, 0};

    Q.size = 4;

    Q.front = 0;

    Q.rear = 1;

    cout<<"handle_is_empty_circular_queue(Q): "<<handle_is_empty_circular_queue(&Q)<<"\n";

    return 0;
}