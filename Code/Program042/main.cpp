/*
    Created by  : Vaisakh Dileep
    Date        : 29, April, 2021
    Description : This program finds the average of all the elements in an array.
*/

#include<iostream>

using namespace std;

struct Array
{
    int *A;

    int size;

    int length;
};

int sum_array(Array *A)
{
    int sum {0};

    for(int i {0}; i < A->length; i++)
    {
        sum += A->A[i];
    }

    return sum;
}

double average_array(Array *A)
{
    if((A->A == nullptr) or (A->length == 0))
    {
        throw string {"ERROR - Invalid operation, array is empty ....."};
    }

    int sum {sum_array(A)};

    if(A->length == 0)
    {
        return 0;
    }
    
    return static_cast<double>(sum) / A->length;
}

double handle_average_array(Array *A)
{
    try
    {
        average_array(A);
    }
    catch(string &ex)
    {
        cout<<ex;

        return -1;
    }
}

int main()
{
    Array A {nullptr, 0, 0};

    Array B {new int[10] {-1, 2, 3, 4, 5, 6, 10, -12, 15, 19}, 10, 10};
    
    cout<<"average_array(A): "<<handle_average_array(&A)<<"\n";
    cout<<"average_array(B): "<<handle_average_array(&B)<<"\n";
    
    return 0;
}