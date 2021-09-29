/*
Created by  : Vaisakh Dileep
Date        : 28, September, 2021
Description : This program finds the determinant of a n*n matrix.
*/

#include<iostream>

using namespace std;

struct Square_Matrix
{
    int **M;

    int size;

    int n;
};

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

int** create_dynamic_square_matrix(int n, int initial_value = 0)
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

int determinant_2x2_matrix(Square_Matrix *M)
{
    if(M == nullptr)
    {
        throw string {"ERROR - Invalid operation, square matrix is not valid ....."};
    }

    if(M->M == nullptr)
    {
        throw string {"ERROR - Invalid operation, square matrix is empty ....."};
    }

    if(M->n != 2)
    {
        throw string {"ERROR - Invalid operation, given matrix is not 2X2 ....."};
    }

    int determinant {(M->M[0][0] * M->M[1][1]) - (M->M[0][1] * M->M[1][0])};

    return determinant;
}

Square_Matrix* sub_matrix_NXN_determinant(Square_Matrix *M, int row, int column) // sub-matrix after removing the corresponding row and column of the element.
{
    Square_Matrix *sub_M {new Square_Matrix {create_dynamic_square_matrix(M->n - 1), (M->n - 1) * (M->n - 1), M->n - 1}};

    int sub_M_row_count {0}, sub_M_column_count {0};

    for(int i {0}; i < M->n; i++) // Select row.
    {
        if(i == row)
        {
            continue;
        }

        sub_M_column_count = 0;

        for(int j {0}; j < M->n; j++) // Select column.
        {
            if(j == column)
            {
                continue;
            }

            sub_M->M[sub_M_row_count][sub_M_column_count] = M->M[i][j];

            sub_M_column_count++;
        }

        sub_M_row_count++;
    }

    return sub_M;
}

int determinant_NxN_matrix(Square_Matrix *M)
{
    if(M == nullptr)
    {
        throw string {"ERROR - Invalid operation, square matrix is not valid ....."};
    }

    if(M->M == nullptr)
    {
        throw string {"ERROR - Invalid operation, square matrix is empty ....."};
    }

    if(M->n == 1)
    {
        return M->M[0][0];
    }

    if(M->n == 2)
    {
        return determinant_2x2_matrix(M);
    }

    int determinant {0}, sign_flag {1};

    for(int i {0}; i < M->n; i++)
    {
        Square_Matrix* sub_M {sub_matrix_NXN_determinant(M, 0, i)};

        int determinant_sub_matrix {determinant_NxN_matrix(sub_M)};

        determinant += (sign_flag * M->M[0][i] * determinant_sub_matrix);

        sign_flag *= -1;
    }

    return determinant;
}

int handle_determinant_NXN_matrix(Square_Matrix *M)
{
    try
    {
        return determinant_2x2_matrix(M);
    }
    catch(string &ex)
    {
        cout<<ex;

        return INT_MIN;
    }
}

int main()
{
    Square_Matrix M1 {new int*[5] {new int[5] {3, 7, 0, 2, 1}, new int[5] {8, 9, 1, 3, 4}, new int[5] {9, 9, 1, 3, 1}, new int[5] {1, 1, 6, 6, 3}, new int[5] {1, 8, 9, 9, 9}}, 5 * 5, 5};

    cout<<"M1: \n";
    display_square_matrix(&M1);
    cout<<"\n\n";

    cout<<"determinant_NXN_matrix(M1): "<<determinant_NxN_matrix(&M1);

    return 0;
}