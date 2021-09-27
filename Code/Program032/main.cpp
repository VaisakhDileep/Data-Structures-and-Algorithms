/*
Created by  : Vaisakh Dileep
Date        : 28, April, 2021
Description : This program appends an element at the end of an array.
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

void append_array(Array *A, int value)
{
    if(A->A == nullptr)
    {
        A->A = new int {0};
    }

    if(A->length < A->size)
    {
        A->A[A->length] = value;

        A->length++;
    }
    else
    {
        throw string {"ERROR - Cannot append, overflow detected ....."};
    }
}

void handle_append_array(Array *A, int value)
{
    try
    {
        append_array(A, value);
    }
    catch(string &ex)
    {
        cout<<ex;
    }
}

int main()
{
    Array A {create_dynamic_array(5), 5, 0};

    handle_append_array(&A, 1);
    handle_append_array(&A, 2);
    handle_append_array(&A, 3);
    handle_append_array(&A, 4);
    handle_append_array(&A, 5);

    handle_append_array(&A, 6); // Overflow will happen here.
    cout<<"\n";
    
    cout<<"A: ";
    display_array(&A);
    cout<<"\n";
    
    return 0;
}