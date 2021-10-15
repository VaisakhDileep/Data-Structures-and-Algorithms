/*
Created by  : Vaisakh Dileep
Date        : 15, October, 2021
Description : This program finds the n'th element in the fibonacci series(binary matrix exponentiation).
*/

// For proof check "Program474/whiteboard_1.pdf".

// Note: Indexing of the fibonacci series starts from 1.

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

int fibonacci_series(int n)
{
    if(n < 0)
    {
        throw string {"ERROR - Invalid operation, 'n' cannot be a negative number ....."};
    }

    if(n == 0)
    {
        throw string {"ERROR - Invalid operation, 'n' cannot be 0 since indexing starts from 1 ....."};
    }

    if((n == 1) or (n == 2))
    {
        return 1;
    }

    Square_Matrix transition_matrix {new int*[2] {new int[2] {0, 1}, new int[2] {1, 1}}, 2 * 2, 2};

    matrix_exponentiation(&transition_matrix, n - 1);

    Matrix initial_state {new int*[1] {new int[2] {1, 1}}, 1 * 2, 1, 2}; // [F1 F2], since indexing starts from '1'.

    Matrix *final_state {multiply_matrices(&initial_state, convert_square_matrix_to_matrix(&transition_matrix))}; // [Fn, Fn+1] will be the final state matrix.

    return final_state->M[0][0];
}

int handle_fibonacci_series(int n)
{
    try
    {
        return fibonacci_series(n);
    }
    catch(string &ex)
    {
        cout<<ex;

        return INT_MIN;
    }
}

int main()
{
    cout<<"fibonacci_series(5): "<<fibonacci_series(10)<<"\n";

    return 0;
}