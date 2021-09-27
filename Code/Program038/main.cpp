/*
Created by  : Vaisakh Dileep
Date        : 29, April, 2021
Description : This program sets an element in an array.
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

void set_element_array(Array *A, int index, int value)
{
    if((A->A == nullptr) or (A->length == 0))
    {
        throw string {"ERROR - Invalid operation, array is empty ....."};
    }

    if(index < 0)
    {
        throw string {"ERROR - Invalid index, index cannot be negative ....."};
    }
    else if(index >= A->length)
    {
        throw string {"ERROR - Invalid index, index cannot be greater than the length of the array ....."};
    }
    else
    {
        A->A[index] = value;
    }
}

void handle_set_element_array(Array *A, int index, int value)
{
    try
    {
        set_element_array(A, index, value);
    }
    catch(string &ex)
    {
        cout<<ex;
    }
}

int main()
{
    Array A {new int[10] {-1, 2, 3, 4, 5, 6, 10, 12, 15, 19}, 10, 10};

    cout<<"A: ";
    display_array(&A);
    cout<<"\n";

    handle_set_element_array(&A, 0, -5);
    handle_set_element_array(&A, 9, 25);

    handle_set_element_array(&A, -1, 10); // Negative index exception.
    cout<<"\n";

    handle_set_element_array(&A, 10, 99); // Index exceeds array length.
    cout<<"\n";

    cout<<"A: ";
    display_array(&A);
    cout<<"\n";
    
    return 0;
}