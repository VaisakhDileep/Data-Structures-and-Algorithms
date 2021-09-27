/*
Created by  : Vaisakh Dileep
Date        : 2, May, 2021
Description : This program counts the number of duplicate elements in a sorted array(using hash table).
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

void count_duplicate_elements_sorted_array(Array *A) // 'A' shouldn't contain any negative elements.
{
    if((A->length == 0) or (A->A == nullptr))
    {
        throw string {"ERROR - Invalid operation, array is empty ....."};
    }

    int l {A->A[0]};

    int h {A->A[A->length - 1]};

    Array H {create_dynamic_array(h + 1), (h + 1), (h + 1)};

    for(int i {0}; i < A->length; i++)
    {
        H.A[A->A[i]]++;
    }

    int flag {0};

    for(int i {l}; i <= h; i++)
    {
        if(H.A[i] > 1)
        {
            flag = 1;

            cout<<i<<" appeared "<<H.A[i]<<" times.\n";
        }
    }

    if(flag == 0)
    {
        throw string {"ERROR - Invalid operation, no duplicate elements in array ....."};
    }
}

void handle_count_duplicate_elements_sorted_array(Array *A)
{
    try
    {
        count_duplicate_elements_sorted_array(A);
    }
    catch(string &ex)
    {
        cout<<ex;
    }
}

int main()
{
    Array A {nullptr, 0, 0};

    Array B {new int[5] {1, 2, 3, 4, 5}, 5, 5};

    Array C {new int[10] {1, 2, 2, 3, 3, 3, 3, 4, 5, 6}, 10, 10};

    cout<<"count_duplicate_elements_sorted_array(A):\n";
    handle_count_duplicate_elements_sorted_array(&A);
    cout<<"\n\n";

    cout<<"count_duplicate_elements_sorted_array(B):\n";
    handle_count_duplicate_elements_sorted_array(&B);
    cout<<"\n\n";

    cout<<"count_duplicate_elements_sorted_array(C):\n";
    handle_count_duplicate_elements_sorted_array(&C);
    cout<<"\n";

    return 0;
}