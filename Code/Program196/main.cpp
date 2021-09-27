/*
Created by  : Vaisakh Dileep
Date        : 4, June, 2021
Description : This program creates a circular queue.
*/

#include<iostream>

using namespace std;

struct Circular_Queue
{
    int *A {nullptr}; // dynamically created array.

    int front {0}; // index of the front of the circular queue, front should not contain any number.

    int rear {0}; // index of the rear of the circular queue.

    int size {0}; // size of the circular queue.
};

int main()
{
    Circular_Queue Q {new int[6] {}, 0, 0, 6};

    Q.A[++Q.rear] = 1;
    Q.A[++Q.rear] = 2;
    Q.A[++Q.rear] = 3; // Inserting in a circular queue.

    Q.front++;
    Q.front++; // deleting in a circular queue.

    return 0;
}