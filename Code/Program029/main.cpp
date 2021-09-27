/*
Created by  : Vaisakh Dileep
Date        : 28, April, 2021
Description : This program creates an array.
*/

#include<iostream>

using namespace std;

struct Array
{
    int *A; // pointer to a dynamically created array.

    int size; // maximum number of elements the array can hold.
    
    int length; // current number of elements present in the array.
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

int main()
{
    Array A {create_dynamic_array(10), 10, 0};

    return 0;
}