/*
Created by  : Vaisakh Dileep
Date        : 29, April, 2021
Description : This program reverses an array(using swap function).
*/

#include<iostream>

using namespace std;

void swap(int &x, int &y)
{
    int temp {y};

    y = x;
    x = temp;
}

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

void reverse_array(Array *A)
{
    if((A->A == nullptr) or (A->length == 0))
    {
        throw string {"ERROR - Invalid operation, array is empty ....."};
    }

    for(int i {0}, j {A->length - 1}; i < j; i++, j--)
    {
        swap(A->A[i], A->A[j]);
    }
}

void handle_reverse_array(Array *A)
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