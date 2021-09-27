/*
Created by  : Vaisakh Dileep
Date        : 28, April, 2021
Description : This program performs linear search on an array.
*/

#include<iostream>

using namespace std;

struct Array
{
    int *A;

    int size;

    int length;
};

int linear_search_array(const Array *A, int key)
{
    if((A->A == nullptr) or (A->length == 0))
    {
        throw string {"ERROR - Invalid operation, array is empty ....."};
    }

    for(int i {0}; i < A->length; i++)
    {
        if(A->A[i] == key)
        {
            return i;
        }
    }

    throw string {"ERROR - Invalid key, key not present in the arrray ....."};
}

void handle_linear_search_array(const Array *A, int key)
{
    try
    {
        int index = {linear_search_array(A, key)};

        cout<<key<<" found at index "<<index<<".";
    }
    catch(string &ex)
    {
        cout<<ex;
    }
}

int main()
{
    Array A {new int[10] {4, 1, 3, 2, 0, 6, 5, 7, 9, 8}, 10, 10};

    handle_linear_search_array(&A, 8);
    cout<<"\n\n";

    handle_linear_search_array(&A, 4);
    cout<<"\n\n";
    
    handle_linear_search_array(&A, 32);
    cout<<"\n";

    return 0;
}