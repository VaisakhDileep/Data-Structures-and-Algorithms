/*
Created by  : Vaisakh Dileep
Date        : 31, May, 2021
Description : This program checks if a queue is full.
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

bool handle_is_full_queue(Queue *Q)
{
    try
    {
        return is_full_queue(Q);
    }
    catch(string &ex)
    {
        cout<<ex;

        return false;
    }
}

int main()
{
    Queue Q {new int[4] {1, 2, 3}, -1, 3, 4};

    cout<<"handle_is_full(Q): "<<handle_is_full_queue(&Q)<<"\n";

    cout<<"handle_is_full(nullptr): "<<handle_is_full_queue(nullptr)<<"\n";

    return 0;
}