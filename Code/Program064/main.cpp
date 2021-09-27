/*
Created by  : Vaisakh Dileep
Date        : 2, May, 2021
Description : This program finds all the duplicate elements in a sorted array.
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

Array duplicate_elements_sorted_array(Array *A)
{
    if((A->A == nullptr) or (A->length == 0))
    {
        throw string {"ERROR - Invalid operation, array is empty ....."};
    }

    int last_duplicate {A->A[0] - 1}; // Since this is ascending order first element will be the lowest.

    Array duplicate_elements {create_dynamic_array(A->length), A->length, 0};

    for(int i {0}; i < (A->length - 1); i++)
    {
        if((A->A[i] == A->A[i + 1]) and (A->A[i] != last_duplicate))
        {
            append_array(&duplicate_elements, A->A[i]);

            last_duplicate = A->A[i];
        }
    }

    if(duplicate_elements.length != 0)
    {
        return duplicate_elements;
    }
    else
    {
        throw string {"ERROR - Invalid operation, no duplicate elements in array ....."};
    }
}

Array handle_duplicate_elements_sorted_array(Array *A)
{
    try
    {
        return duplicate_elements_sorted_array(A);
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

    Array C {new int[10] {1, 2, 2, 3, 3, 3, 3, 4, 5, 6}, 10, 10};

    handle_duplicate_elements_sorted_array(&A);
    cout<<"\n";

    handle_duplicate_elements_sorted_array(&B);
    cout<<"\n";

    Array temp {handle_duplicate_elements_sorted_array(&C)};

    cout<<"duplicate_elements_sorted_array(C): ";
    display_array(&temp);
    cout<<"\n";

    return 0;
}