/*
Created by  : Vaisakh Dileep
Date        : 10, October, 2021
Description : This program performs matrix exponentiation(binary exponentiation).
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

void matrix_exponentiation(Square_Matrix *base, int power)
{
    if(base == nullptr)
    {
        throw string {"ERROR - Invalid operation, matrix is not valid ....."};
    }

    if(power < 0)
    {
        throw string {"ERROR - Invalid operation, power should be greater than 0 ....."};
    }

    Square_Matrix *result {new Square_Matrix {new int*[base->n] {}, base->n * base->n, base->n}}; // Result matrix(initialized with identity matrix)

    for(int i {0}; i < base->n; i++)
    {
        result->M[i] = new int[base->n] {};
    }

    for(int i {0}; i < base->n; i++)
    {
        result->M[i][i] = 1;
    }

    Square_Matrix *temp_base {base};

    while(power)
    {
        if((power % 2) == 1)
        {
            result = multiply_square_matrices(result, temp_base);

            power--;
        }
        else
        {
            temp_base = multiply_square_matrices(temp_base, temp_base);

            power /= 2;
        }
    }

    for(int i {0}; i < base->n; i++)
    {
        for(int j {0}; j < base->n; j++)
        {
            base->M[i][j] = result->M[i][j];
        }
    }
}

void handle_matrix_exponentiation(Square_Matrix *base, int power)
{
    try
    {
        matrix_exponentiation(base, power);
    }
    catch(string &ex)
    {
        cout<<ex;
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

    handle_matrix_exponentiation(&M1, 4);

    cout<<"matrix_exponentiation(M1, 4): \n";
    display_square_matrix(&M1);
    cout<<"\n";

    return 0;
}