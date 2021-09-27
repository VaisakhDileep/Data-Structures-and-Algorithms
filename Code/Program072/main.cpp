/*
Created by  : Vaisakh Dileep
Date        : 3, May, 2021
Description : This program finds all the pairs whose sum is 'k'(A[i] + A[j] = k) in an array(using hash table).
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

void append_array(Array *A, int value)
{
    if(A->A == nullptr)
    {
        A->A = new int {0};
    }

    if(A->length < A->size)
    {
        A->A[A->length] = value;

        A->length++;
    }
    else
    {
        throw string {"ERROR - Cannot append, overflow detected ....."};
    }
}

Array copy_array(Array *A) // Returns a copy of 'A'.
{
    if((A->length == 0) or (A->A == nullptr))
    {
        throw string {"ERROR - Invalid operation, array is empty ....."};
    }

    Array copied_array {create_dynamic_array(A->size), A->size, A->length};

    for(int i {0}; i < A->length; i++)
    {
        copied_array.A[i] = A->A[i];
    }

    return copied_array;
}

void remove_duplicate_elements_array(Array *A)
{
    if((A->length == 0) or (A->A == nullptr))
    {
        throw string {"ERROR - Invalid operation, array is empty ....."};
    }

    Array result_array {create_dynamic_array(A->size), A->size, 0};

    for(int i {0}; i < A->length; i++)
    {
        if(A->A[i] == 0)
        {
            append_array(&result_array, 0);

            break;
        }
    }

    for(int i {0}; i < A->length; i++)
    {
        if(A->A[i] != 0)
        {
            append_array(&result_array, A->A[i]);

            for(int j {i + 1}; j < A->length; j++)
            {
                if(A->A[i] == A->A[j])
                {
                    A->A[j] = 0;
                }
            }
        }
    }

    delete[] A->A;

    A->A = result_array.A;

    A->size = result_array.size;

    A->length = result_array.length;
}

void sum_pair_array(Array *A, int sum) // 'A' shouldn't contain any negative values.
{
    if((A->length == 0) or (A->A == nullptr))
    {
        throw string {"ERROR - Invalid operation, array is empty ....."};
    }

    Array modified_array {copy_array(A)};

    remove_duplicate_elements_array(&modified_array); // Removes all the duplicate elements.

    int h {max_element_array(&modified_array)};

    int flag {0};

    Array H {create_dynamic_array(h + 1), (h + 1), (h + 1)};

    for(int i {0}; i < modified_array.length; i++)
    {
        if(((sum - modified_array.A[i]) >= 0) and (H.A[sum - modified_array.A[i]] != 0))
        {
            flag = 1;

            cout<<"("<<modified_array.A[i]<<" + "<<(sum - modified_array.A[i])<<") = "<<sum<<"\n";
        }

        H.A[modified_array.A[i]]++;
    }

    if(flag == 0)
    {
        throw string {"ERROR - Invalid operation, no such pairs were found ....."};
    }
}

void handle_sum_pair_array(Array *A, int sum)
{
    try
    {
        sum_pair_array(A, sum);
    }
    catch(string &ex)
    {
        cout<<ex;
    }
}

int main()
{
    Array A {nullptr, 0, 0};

    cout<<"sum_pair_array(&A, 2): ";
    handle_sum_pair_array(&A, 2);
    cout<<"\n";

    Array B {new int[5] {2, 3, 4, 5, 6}, 5, 5};

    cout<<"sum_pair_array(&B, 2): ";
    handle_sum_pair_array(&B, 2);
    cout<<"\n";

    Array C {new int[10] {1, 2, 3, 0, 0, 3, 0, 3, 2, 1}, 10, 10};

    cout<<"sum_pair_array(&C, 3): \n";
    handle_sum_pair_array(&C, 3);
    cout<<"\n";

    return 0;
}