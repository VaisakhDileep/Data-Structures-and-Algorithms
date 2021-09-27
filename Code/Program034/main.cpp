/*
Created by  : Vaisakh Dileep
Date        : 28, April, 2021
Description : This program deletes an element from an array.
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

int delete_array(Array *A, int index)
{
    if((A->A == nullptr) or (A->length == 0))
    {
        throw string {"ERROR - Invalid operation, array is empty ....."};
    }

    int deleted_element {-1};

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
        deleted_element = A->A[index];

        for(int i {index}; i < A->length - 1; i++)
        {
            A->A[i] = A->A[i + 1];
        }

        A->length--;

        return deleted_element;
    }
}

int handle_delete_array(Array *A, int index)
{
    try
    {
        return delete_array(A, index);
    }
    catch(string &ex)
    {
        cout<<ex;

        return -1;
    }
}

int main()
{
    Array A {new int[10] {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, 10, 10};

    handle_delete_array(&A, 9);
    handle_delete_array(&A, 3);

    handle_delete_array(&A, -1); // Negative index exception.
    cout<<"\n";

    handle_delete_array(&A, 10); // Index exceeds array length.
    cout<<"\n";

    cout<<"A: ";
    display_array(&A);
    cout<<"\n";

    return 0;
}