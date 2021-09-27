/*
Created by  : Vaisakh Dileep
Date        : 29, April, 2021
Description : This program reverses an array(using auxiliary array).
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

void reverse_array(const Array *A)
{
    if((A->A == nullptr) or (A->length == 0))
    {
        throw string {"ERROR - Invalid operation, array is empty ....."};
    }

    int *auxiliary_array = create_dynamic_array(A->length);

    for(int i {A->length - 1}, j {0}; i >= 0;  i--, j++)
    {
        auxiliary_array[j] = A->A[i];
    }

    for(int i {0}; i < A->length; i++)
    {
        A->A[i] = auxiliary_array[i];
    }
}

void handle_reverse_array(const Array *A)
{
    try
    {
        reverse_array(A);
    }
    catch(string &ex)
    {
        cout<<ex;
    }
}

int main()
{
    Array A {new int[10] {-1, 2, 3, 4, 5, 6, 10, -12, 15, 19}, 10, 10};

    cout<<"A: ";
    display_array(&A);
    cout<<"\n";

    handle_reverse_array(&A);

    cout<<"A: ";
    display_array(&A);
    cout<<"\n";

    return 0;
}