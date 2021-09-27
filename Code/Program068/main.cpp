/*
Created by  : Vaisakh Dileep
Date        : 3, May, 2021
Description : This program counts the number of duplicate elements in an array(using hash table).
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

int max_element_array(Array *A)
{
    if((A->length == 0) or (A->A == nullptr))
    {
        throw string {"ERROR - Invalid operation, array is empty ....."};
    }
    else
    {
        int max {A->A[0]};

        for(int i {1}; i < A->length; i++)
        {
            if(A->A[i] > max)
            {
                max = A->A[i];
            }
        }

        return max;
    }
}

int min_element_array(Array *A)
{
    if((A->length == 0) or (A->A == nullptr))
    {
        throw string {"ERROR - Invalid operation, array is empty ....."};
    }
    else
    {
        int min {A->A[0]};

        for(int i {1}; i < A->length; i++)
        {
            if(A->A[i] < min)
            {
                min = A->A[i];
            }
        }

        return min;
    }
}

void count_duplicate_elements_array(Array *A) // 'A' shouldn't contain any negative elements.
{
    if((A->length == 0) or (A->A == nullptr))
    {
        throw string {"ERROR - Invalid operation, array is empty ....."};
    }

    int l {min_element_array(A)};

    int h {max_element_array(A)};

    int flag {0};

    Array H {create_dynamic_array(h + 1), (h + 1), (h + 1)};

    for(int i {0}; i < A->length; i++)
    {
        H.A[A->A[i]]++;
    }

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

void handle_count_duplicate_elements_array(Array *A)
{
    try
    {
        count_duplicate_elements_array(A);
    }
    catch(string &ex)
    {
        cout<<ex;
    }
}

int main()
{
    Array A {nullptr, 0, 0};

    Array B {new int[5] {1, 3, 2, 5, 4}, 5, 5};

    Array C {new int[10] {0, 1, 3, 1, 0, 4, 6, 5, 4, 4}, 10, 10};

    cout<<"count_duplicate_elements_array(A):\n";
    handle_count_duplicate_elements_array(&A);
    cout<<"\n\n";

    cout<<"count_duplicate_elements_array(B):\n";
    handle_count_duplicate_elements_array(&B);
    cout<<"\n\n";

    cout<<"count_duplicate_elements_array(C):\n";
    handle_count_duplicate_elements_array(&C);
    cout<<"\n";

    return 0;
}