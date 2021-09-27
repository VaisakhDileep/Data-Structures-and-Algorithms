/*
Created by  : Vaisakh Dileep
Date        : 30, April, 2021
Description : This program inserts an element to a sorted array.
*/

// sorted here means ascending order.

#include<iostream>

using namespace std;

struct Array
{
    int *A;

    int size;

    int length;
};

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

void insert_sorted_array(Array *A, int value)
{
    if(A->A == nullptr)
    {
            A->A = new int {0};
    }

    if(A->length >= A->size)
    {
        throw string {"ERROR - cannot insert, overflow detected ....."};
    }
    else
    {
        int i {A->length - 1};

        A->length++;

        while((A->A[i] > value) and (i >= 0))
        {
            A->A[i + 1] = A->A[i];

            i--;
        }

        A->A[i + 1] = value;
    }
}

void handle_insert_sorted_array(Array *A, int value)
{
    try
    {
        insert_sorted_array(A, value);
    }
    catch(string &ex)
    {
        cout<<ex;
    }
}

int main()
{
    Array A {nullptr, 5, 0};

    handle_insert_sorted_array(&A, 2);
    handle_insert_sorted_array(&A, 5);
    handle_insert_sorted_array(&A, 3);
    handle_insert_sorted_array(&A, 4);
    handle_insert_sorted_array(&A, 1);
    handle_insert_sorted_array(&A, 0);

    cout<<"\n";

    cout<<"A: ";
    display_array(&A);
    cout<<"\n";

    return 0;
}