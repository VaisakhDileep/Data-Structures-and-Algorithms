/*
Created by  : Vaisakh Dileep
Date        : 12, May, 2021
Description : This program creates a square matrix.
*/

#include<iostream>

using namespace std;

struct Square_Matrix
{
    int **M; // pointer to a dynamically created matrix.

    int size; // maximum number of elements supported by the matrix.

    int n; // number of rows or columns.
};

int ** created_dynamic_square_matrix(int n, int initial_value = 0)
{
    int **p;

    p = new int*[n];

    for(int i {0}; i < n; i++)
    {
        p[i] = new int[n];
    }

    for(int i {0}; i < n; i++)
    {
        for(int j {0}; j < n; j++)
        {
            p[i][j] = initial_value;
        }
    }

    return p;
}

int main()
{
    Square_Matrix M {created_dynamic_square_matrix(2, 3), 3 * 3, 3};

    return 0;
}