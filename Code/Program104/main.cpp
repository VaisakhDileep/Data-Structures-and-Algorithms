/*
Created by  : Vaisakh Dileep
Date        : 13, May, 2021
Description : This program represents a matrix in column-major form.
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

struct Array_with_dimension
{
    int *A;

    int size;

    int length;

    int rows;

    int columns;
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

void display_array_with_dimension(const Array_with_dimension *A)
{
    if(A->A == nullptr)
    {
        cout<<"[ ]";

        return ;
    }

    cout<<"[ ";
    for(int i {0}; i < A->length; i++)
    {
        cout<<A->A[i]<<" ";
    }
    cout<<"]";
}

void set_column_major_matrix(Array_with_dimension *A, int i, int j, int value)
{
    if((i < A->rows) and (j < A->columns))
    {
        A->A[((A->rows) * j) + i] = value; // Formulae for inserting in column-major form.
    }
    else
    {
        throw string {"ERROR - Cannot set value, invalid index ....."};
    }
}

void handle_set_column_major_matrix(Array_with_dimension *A, int i, int j, int value)
{
    try
    {
        set_column_major_matrix(A, i, j, value);
    }
    catch(string &ex)
    {
        cout<<ex;
    }
}

int get_column_major_matrix(Array_with_dimension *A, int i, int j)
{
    if((i < A->rows) and (j < A->columns))
    {
        return A->A[((A->rows) * j) + i]; // Formulae for retrieving data in column-major form.
    }
    else
    {
        throw string {"ERROR - Cannot retrieve data, invalid index ....."};
    }
}

int handle_get_column_major_matrix(Array_with_dimension *A, int i, int j)
{
    try
    {
        return get_column_major_matrix(A, i, j);
    }
    catch(string &ex)
    {
        cout<<ex;

        return -1;
    }
}

Array_with_dimension create_column_major_matrix(Matrix *M)
{
    if(M->M == nullptr)
    {
        throw string {"ERROR - Invalid operation, matrix is empty ....."};
    }

    Array_with_dimension A {create_dynamic_array(M->rows * M->columns), (M->rows * M->columns), (M->rows * M->columns), M->rows, M->columns};

    for(int i {0}; i < M->rows; i++)
    {
        for(int j {0}; j < M->columns; j++)
        {
            set_column_major_matrix(&A, i, j, M->M[i][j]);
        }
    }

    return A;
}

Array_with_dimension handle_create_column_major_matrix(Matrix *M)
{
    try
    {
        return create_column_major_matrix(M);
    }
    catch(string &ex)
    {
        cout<<ex;

        return Array_with_dimension {};
    }
}

void display_column_major_matrix(Array_with_dimension *A)
{
    if(A->A == nullptr)
    {
        cout<<"[\n]";

        return ;
    }

    cout<<"[\n";
    for(int i {0}; i < A->rows; i++)
    {
        cout<<"[ ";
        for(int j {0}; j < A->columns; j++)
        {
            cout<<get_column_major_matrix(A, i, j)<<" ";
        }
        cout<<"]\n";
    }
    cout<<"]";
}

int main()
{
    Matrix M {new int*[3] {new int[2] {1, 2}, new int[2] {3, 4}, new int[2] {5, 6}}, 3 * 2, 3, 2};

    cout<<"M: \n";
    display_matrix(&M);
    cout<<"\n";

    Array_with_dimension A {handle_create_column_major_matrix(&M)};

    cout<<"A: ";
    display_array_with_dimension(&A);
    cout<<"\n";

    cout<<"A: \n";
    display_column_major_matrix(&A);
    cout<<"\n";

    cout<<"handle_get_column_major_matrix(&A, 0, 1): "<<handle_get_column_major_matrix(&A, 0, 1)<<"\n";
    cout<<"handle_get_column_major_matrix(&A, 2, 2): "<<handle_get_column_major_matrix(&A, 2, 2)<<"\n\n";

    handle_set_column_major_matrix(&A, 0, 0, 9);
    handle_set_column_major_matrix(&A, 0, 2, 7);

    cout<<"\n";

    cout<<"A: \n";
    display_column_major_matrix(&A);
    cout<<"\n";

    return 0;
}