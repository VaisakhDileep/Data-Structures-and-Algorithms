/*
Created by  : Vaisakh Dileep
Date        : 28, April, 2021
Description : This program extends the size of an array.
*/

#include<iostream>

using namespace std;

struct Array
{
    int *A;

    int size;

    int length;
};

int* create_dynamic_array(int size, int initial_value = 0)
{
    int *p;

    p = new int[size];

    for(int i {0}; i < size; i++)
    {
        p[i] = initial_value;
    }

    return p;
}

void display_array(const Array *A)
{
    if(A->A == nullptr)
    {
        cout<<"[ ]";

        return ;
    }

    cout<<"[ ";
    for(int i {0}; i < A->length; i++)
    {
        cout<<A->A[i]<<" ";
    }
    cout<<"]";
}

void increase_array_size(Array *A, int size, int initial_value = 0)
{
    if(A->A == nullptr)
    {
        A->A = create_dynamic_array(size, initial_value);

        A->size = size;

        return ;
    }

    int *temp;

    temp = new int[size];

    int i {0};

    for(; i < A->size; i++)
    {
        temp[i] = A->A[i];
    }

    for(; i < size; i++)
    {
        temp[i] = initial_value;
    }

    delete[] A->A;

    A->A = temp;

    A->size = size;
}

int main()
{
    Array A {nullptr, 0, 0};

    cout<<"A: ";
    display_array(&A);
    cout<<"\n";

    increase_array_size(&A, 10);

    A.length = 10;

    cout<<"A: ";
    display_array(&A);
    cout<<"\n";
}