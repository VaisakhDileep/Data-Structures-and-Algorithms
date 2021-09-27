/*
Created by  : Vaisakh Dileep
Date        : 30, April, 2021
Description : This program moves all the negative elements to the beginning of the array.
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

void segregate_negative_elements_array(Array *A)
{
    if((A->length == 0) and (A->A == nullptr))
    {
        throw string {"ERROR - Invalid operation, array is empty ....."};
    }

    int i {0};

    int j {A->length - 1};

    while(i < j)
    {
        while(A->A[i] < 0)
        {
            i++;
        }

        while(A->A[j] >= 0)
        {
            j--;
        }

        if(i < j)
        {
            swap(A->A[i], A->A[j]);
        }
    }
}

void handle_segregate_negative_elements(Array *A)
{
    try
    {
        segregate_negative_elements_array(A);
    }
    catch(string &ex)
    {
        cout<<ex;
    }
}

int main()
{
    Array A {nullptr, 0, 0};

    Array B {new int[10] {2, 3, 4, -9, -8, 0, -4, 0, -4, -2}, 10, 10};

    Array C {new int[1] {1}, 1, 1};

    cout<<"A: ";
    display_array(&A);
    cout<<"\n";

    handle_segregate_negative_elements(&A);
    cout<<"\n";

    cout<<"A: ";
    display_array(&A);
    cout<<"\n";

    cout<<"B: ";
    display_array(&B);
    cout<<"\n";

    handle_segregate_negative_elements(&B);

    cout<<"B: ";
    display_array(&B);
    cout<<"\n";

    cout<<"C: ";
    display_array(&C);
    cout<<"\n";

    handle_segregate_negative_elements(&C);

    cout<<"C: ";
    display_array(&C);
    cout<<"\n";

    return 0;
}