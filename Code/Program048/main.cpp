/*
Created by  : Vaisakh Dileep
Date        : 30, April, 2021
Description : This program right rotates an array.
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

void right_rotate_array(Array *A)
{
    if((A->length == 0) or (A->A == nullptr))
    {
        throw string {"ERROR - Invalid operation, array is empty ....."};
    }
    else
    {
        int temp {A->A[A->length - 1]};

        for(int i {A->length - 1}; i >= 0; i--)
        {
            A->A[i + 1] = A->A[i];
        }

        A->A[0] = temp;
    }
}

void handle_right_rotate_array(Array *A)
{
    try
    {
        right_rotate_array(A);
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

    handle_right_rotate_array(&A);
    cout<<"\n";

    cout<<"B: ";
    display_array(&B);
    cout<<"\n";

    handle_right_rotate_array(&B);

    cout<<"B: ";
    display_array(&B);
    cout<<"\n";

    cout<<"C: ";
    display_array(&C);
    cout<<"\n";

    handle_right_rotate_array(&C);

    cout<<"C: ";
    display_array(&C);
    cout<<"\n";

    return 0;
}