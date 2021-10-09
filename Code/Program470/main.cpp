/*
Created by  : Vaisakh Dileep
Date        : 9, October, 2021
Description : This program multiplies two square matrices(brute force approach).
*/

#include<iostream>

using namespace std;

struct Square_Matrix
{
    int **M;

    int size;

    int n;
};

Square_Matrix* multiply_square_matrices(Square_Matrix *A, Square_Matrix *B)
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

    if(A->n != B->n)
    {
        throw string {"ERROR - Invalid operation, matrices should have the same dimension ....."};
    }

    Square_Matrix *product {new Square_Matrix {new int*[A->n] {}, A->n * A->n, A->n}};

    for(int i {0}; i < A->n; i++)
    {
        product->M[i] = new int[A->n] {};
    }

    for(int i {0}; i < A->n; i++)
    {
        for(int j {0}; j < B->n; j++)
        {
            int sum {0};

            for(int k {0}; k < A->n; k++)
            {
                sum += A->M[i][k] * B->M[k][j];
            }

            product->M[i][j] = sum;
        }
    }

    return product;
}

Square_Matrix* handle_multiply_square_matrices(Square_Matrix *A, Square_Matrix *B)
{
    try
    {
        return multiply_square_matrices(A, B);
    }
    catch(string &ex)
    {
        cout<<ex;

        return nullptr;
    }
}

void display_square_matrix(Square_Matrix *M)
{
    if(M->M == nullptr)
    {
        cout<<"[\n]";

        return ;
    }

    cout<<"[\n";
    for(int i {0}; i < M->n; i++)
    {
        cout<<" [ ";
        for(int j {0}; j < M->n; j++)
        {
            cout<<M->M[i][j]<<" ";
        }
        cout<<"]\n";
    }
    cout<<"]";
}

int main()
{
    Square_Matrix M1 {new int*[3] {new int[3] {1, 2, 3}, new int[3] {4, 5, 6}, new int[3] {7, 8, 9}}, 3 * 3, 3};

    cout<<"M1: \n";
    display_square_matrix(&M1);
    cout<<"\n\n";

    Square_Matrix M2 {new int*[3] {new int[3] {9, 8, 7}, new int[3] {6, 5, 4}, new int[3] {3, 2, 1}}, 3 * 3, 3};

    cout<<"M2: \n";
    display_square_matrix(&M2);
    cout<<"\n\n";

    Square_Matrix *product {handle_multiply_square_matrices(&M1, &M2)};

    cout<<"multiply_square_matrices(M1, M2): \n";
    display_square_matrix(product);
    cout<<"\n";

    return 0;
}