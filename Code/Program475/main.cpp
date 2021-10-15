/*
Created by  : Vaisakh Dileep
Date        : 15, October, 2021
Description : This program converts a square matrix representation to a matrix representation.
*/

// Since I have different representations for Matrix and Square Matrix, when performing some operations it is required to convert from one form to another(Square Matrix can always be converted to Matrix but not vice-versa).

#include<iostream>

using namespace std;

struct Matrix
{
    int **M;

    int size;

    int rows;

    int columns;
};

struct Square_Matrix
{
    int **M;

    int size;

    int n;
};

Matrix* convert_square_matrix_to_matrix(Square_Matrix *sq_M)
{
    if(sq_M == nullptr)
    {
        return nullptr;
    }

    Matrix *M {new Matrix {new int*[sq_M->n] {}, sq_M->size, sq_M->n, sq_M->n}};

    for(int i {0}; i < sq_M->n; i++)
    {
        M->M[i] = new int[sq_M->n] {};
    }

    for(int i {0}; i < sq_M->n; i++)
    {
        for(int j {0}; j < sq_M->n; j++)
        {
            M->M[i][j] = sq_M->M[i][j];
        }
    }

    return M;
}

int main()
{
    return 0;
}