/*
Created by  : Vaisakh Dileep
Date        : 28, April, 2021
Description : This program performs binary search on a sorted array.
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

namespace recursion
{
    int binary_search_array(Array *A, int l, int h, int key) // binary search only works with sorted arrays.
    {
        if((A->A == nullptr) or (A->length == 0))
        {
            throw string {"ERROR - Invalid operation, array is empty ....."};
        }

        if(l <= h)
        {
            int mid {(l + h) / 2};

            if(key == A->A[mid])
            {
                return mid;
            }
            else if(key < A->A[mid])
            {
                return binary_search_array(A, l, mid - 1, key);
            }
            else
            {
                return binary_search_array(A, mid + 1, h, key);
            }
        }
        else
        {
            throw string {"ERROR - Invalid key, key not present in the array ....."};
        }
    }

    int handle_binary_search_array(Array *A, int key)
    {
        try
        {
            return binary_search_array(A, 0, A->length - 1, key);
        }
        catch(string &ex)
        {
            cout<<ex;

            return -1;
        }
    }
}

namespace iteration
{
    int binary_search_array(const Array *A, int key)
    {

        if((A->A == nullptr) or (A->length == 0))
        {
            throw string {"ERROR - Invalid operation, array is empty ....."};
        }
        
        int l {0};

        int h {A->length - 1};

        while(l <= h)
        {
            int mid {(l + h) / 2};

            if(key == A->A[mid])
            {
                return mid;
            }
            else if(key < A->A[mid])
            {
                h = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        throw string {"ERROR - Invalid key, key not present in the array ....."};
    }

    int handle_binary_search_array(const Array *A, int key)
    {
        try
        {
            return binary_search_array(A, key);
        }
        catch(string &ex)
        {
            cout<<ex;

            return -1;
        }
    }
}

int main()
{
    Array A {new int[10] {-1, 2, 3, 4, 5, 6, 10, 12, 15, 19}, 10, 10};

    cout<<"binary_search_array(&A, -1) [recursion]: "<<recursion::handle_binary_search_array(&A, -1)<<"\n";
    cout<<"binary_search_array(&A, 12) [recursion]: "<<recursion::handle_binary_search_array(&A, 12)<<"\n";
    cout<<"binary_search_array(&A, 99) [recursion]: "<<recursion::handle_binary_search_array(&A, 99)<<"\n";

    cout<<"binary_search_array(&A, -1) [iteration]: "<<iteration::handle_binary_search_array(&A, -1)<<"\n";
    cout<<"binary_search_array(&A, 12) [iteration]: "<<iteration::handle_binary_search_array(&A, 12)<<"\n";
    cout<<"binary_search_array(&A, 99) [iteration]: "<<iteration::handle_binary_search_array(&A, 99)<<"\n";

    return 0;
}