/*
Created by  : Vaisakh Dileep
Date        : 4, May, 2021
Description : This program finds min and max element of an array simultaneously.
*/

#include<iostream>

using namespace std;

struct Array
{
    int *A;

    int size;

    int length;
};

int *min_max_array(Array *A)
{
    if((A->length == 0) or (A->A == nullptr))
    {
        throw string {"ERROR - Invalid operation, array is empty ....."};
    }

    int static min_max[2] {}; // This is static so we can return by address(even though it is a local variable).

    min_max[0] = min_max[1] = A->A[0];

    for(int i {1}; i < A->length; i++)
    {
        if(min_max[0] > A->A[i])
        {
            min_max[0] = A->A[i];
        }
        else if(min_max[1] < A->A[i])
        {
            min_max[1] = A->A[i];
        }
    }

    return min_max;
}

void handle_min_max_array(Array *A)
{
    try
    {
        int *min_max {min_max_array(A)};

        cout<<"MIN: "<<min_max[0]<<"\n";

        cout<<"MAX: "<<min_max[1]<<"\n";
    }
    catch(string &ex)
    {
        cout<<ex;
    }
}

int main()
{
    Array A {nullptr, 0, 0};

    Array B {new int[5] {-5, -4, -3, -2, -1}, 5, 5};

    handle_min_max_array(&A);
    cout<<"\n";

    handle_min_max_array(&B);

    return 0;
}