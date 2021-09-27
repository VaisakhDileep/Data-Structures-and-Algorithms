/*
Created by  : Vaisakh Dileep
Date        : 29, April, 2021
Description : This program left shifts an array.
*/

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

void left_shift_array(Array *A)
{
    if((A->length == 0) or (A->A == nullptr))
    {
        throw string {"ERROR - Invalid operation, array is empty ....."};
    }
    else
    {
        for(int i {1}; i < A->length; i++)
        {
            A->A[i - 1] = A->A[i];
        }

        A->length--;
    }
}

void handle_left_shift_array(Array *A)
{
    try
    {
        left_shift_array(A);
    }
    catch(string &ex)
    {
        cout<<ex;
    }
}

int main()
{
    Array A {nullptr, 0, 0};

    Array B {new int[1] {3}, 1, 1};

    Array C {new int[10] {-1, 2, 3, 4, 5, 6, 10, -12, 15, 19}, 10, 10};

    cout<<"A: ";
    display_array(&A);
    cout<<"\n";

    handle_left_shift_array(&A);
    cout<<"\n";

    cout<<"B: ";
    display_array(&B);
    cout<<"\n";

    handle_left_shift_array(&B);

    cout<<"B: ";
    display_array(&B);
    cout<<"\n";

    cout<<"C: ";
    display_array(&C);
    cout<<"\n";

    handle_left_shift_array(&C);

    cout<<"C: ";
    display_array(&C);
    cout<<"\n";

    return 0;
}