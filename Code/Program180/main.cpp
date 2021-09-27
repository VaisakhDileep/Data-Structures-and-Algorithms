/*
Created by  : Vaisakh Dileep
Date        : 31, May, 2021
Description : This program finds the transpose of a matrix.
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

int ** created_dynamic_matrix(int rows, int columns, int initial_value = 0)
{
    int **p;

    p = new int*[rows];

    for(int i {0}; i < rows; i++)
    {
        p[i] = new int[columns];
    }

    for(int i {0}; i < rows; i++)
    {
        for(int j {0}; j < columns; j++)
        {
            p[i][j] = initial_value;
        }
    }

    return p;
}

Matrix* transpose_matrix(Matrix *M)
{
    if(M == nullptr)
    {
        throw string {"ERROR - Invalid operation, matrix is empty ....."};
    }

    Matrix *T {new Matrix {created_dynamic_matrix(M->columns, M->rows), (M->rows * M->columns), M->columns, M->rows}};

    for(int i {0}; i < M->rows; i++)
    {
        for(int j {0}; j < M->columns; j++)
        {
            T->M[j][i] = M->M[i][j];
        }
    }

    return T;
}

Matrix* handle_transpose_matrix(Matrix *M)
{
    try
    {
        return transpose_matrix(M);
    }
    catch(string &ex)
    {
        cout<<ex;

        return nullptr;
    }
}

int main()
{
    Matrix M {new int*[2] {new int[3] {1, 2, 3}, new int[3] {4, 5, 6}}, 2 * 3, 2, 3};

    cout<<"M:\n";
    display_matrix(&M);
    cout<<"\n\n";

    Matrix *T {handle_transpose_matrix(&M)};

    cout<<"T:\n";
    display_matrix(T);
    cout<<"\n";

    return 0;
}