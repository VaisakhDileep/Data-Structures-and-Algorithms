/*
Created by  : Vaisakh Dileep
Date        : 9, October, 2021
Description : This program multiplies two matrices(brute force approach).
*/

#include<iostream>

using namespace std;

struct Matrix
{
    int **M;

    int size;

    int rows;

    int columns;
};

Matrix* multiply_matrices(Matrix *A, Matrix *B)
{
    if(A == nullptr)
    {
        throw string {"ERROR - Invalid operation, matrix 'A' is not valid ....."};
    }

    if(B == nullptr)
    {
        throw string {"ERROR - Invalid operation, matrix 'B' is not valid ....."};
    }

    if(A->M == nullptr)
    {
        throw string {"ERROR - Invalid operation, matrix 'A' is empty ....."};
    }

    if(B->M == nullptr)
    {
        throw string {"ERROR - Invalid operation, matrix 'B' is empty ....."};
    }

    if(A->columns != B->rows)
    {
        throw string {"ERROR - Invalid operation, number of columns in matrix 'A' is not equal to the number of rows in matrix 'B' ....."};
    }

    Matrix *product {new Matrix {new int*[A->rows] {}, A->rows * B->columns, A->rows, B->columns}};

    for(int i {0}; i < A->rows; i++)
    {
        product->M[i] = new int[B->columns] {};
    }

    for(int i {0}; i < A->rows; i++)
    {
        for(int j {0}; j < B->columns; j++)
        {
            int sum {0};

            for(int k {0}; k < A->columns; k++)
            {
                sum += A->M[i][k] * B->M[k][j];
            }

            product->M[i][j] = sum;
        }
    }

    return product;
}

Matrix* handle_multiply_matrices(Matrix *A, Matrix *B)
{
    try
    {
        return multiply_matrices(A, B);
    }
    catch(string &ex)
    {
        cout<<ex;

        return nullptr;
    }
}

void display_matrix(Matrix *M)
{
    if(M->M == nullptr)
    {
        cout<<"[\n]";

        return ;
    }

    cout<<"[\n";
    for(int i {0}; i < M->rows; i++)
    {
        cout<<" [ ";
        for(int j {0}; j < M->columns; j++)
        {
            cout<<M->M[i][j]<<" ";
        }
        cout<<"]\n";
    }
    cout<<"]";
}

int main()
{
    Matrix M1 {new int*[2] {new int[3] {1, 2, 3}, new int[3] {4, 5, 6}}, 2 * 3, 2, 3};

    cout<<"M1: \n";
    display_matrix(&M1);
    cout<<"\n\n";

    Matrix M2 {new int*[3] {new int[4] {1, 2, 3, 4}, new int[4] {5, 6, 7, 8}, new int[4] {9, 10, 11, 12}}, 3 * 4, 3, 4};

    cout<<"M2: \n";
    display_matrix(&M2);
    cout<<"\n\n";

    Matrix *product {handle_multiply_matrices(&M1, &M2)};

    cout<<"multiply_matrices(M1, M2): \n";
    display_matrix(product);
    cout<<"\n";

    return 0;
}