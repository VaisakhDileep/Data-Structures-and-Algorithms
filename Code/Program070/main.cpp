/*
Created by  : Vaisakh Dileep
Date        : 3, May, 2021
Description : This program copies an array.
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

Array copy_array(Array *A) // Returns a copy of 'A'.
{
    if((A->length == 0) or (A->A == nullptr))
    {
        throw string {"ERROR - Invalid operation, array is empty ....."};
    }

    Array copied_array {create_dynamic_array(A->size), A->size, A->length};

    for(int i {0}; i < A->length; i++)
    {
        copied_array.A[i] = A->A[i];
    }

    return copied_array;
}

Array handle_copy_array(Array *A)
{
    try
    {
        return copy_array(A);
    }
    catch(string &ex)
    {
        cout<<ex;

        return Array {};
    }
}

int main()
{
    Array A {nullptr, 0, 0};

    Array B {new int[5] {1, 2, 3, 4, 5}, 5, 5};

    handle_copy_array(&A);
    cout<<"\n";

    Array B_copy {handle_copy_array(&B)};

    cout<<"B_copy: ";
    display_array(&B_copy);
    cout<<"\n";
}