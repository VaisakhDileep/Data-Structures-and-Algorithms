/*
Created by  : Vaisakh Dileep
Date        : 31, May, 2021
Description : This program finds the transpose of a square matrix.
*/

#include<iostream>

using namespace std;

struct Square_Matrix
{
    int **M;

    int size;

    int n;
};

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

Square_Matrix* transpose_square_matrix(Square_Matrix *M)
{
    if(M == nullptr)
    {
        throw string {"ERROR - Invalid operation, matrix is empty ....."};
    }

    Square_Matrix *T {new Square_Matrix {create_dynamic_square_matrix(M->n), (M->n * M->n), M->n}};

    for(int i {0}; i < M->n; i++)
    {
        for(int j {0}; j < M->n; j++)
        {
            T->M[i][j] = M->M[i][j];
        }
    }

    for(int i {0}; i < M->n; i++)
    {
        for(int j {i}; j < M->n; j++)
        {
            int temp {T->M[i][j]};

            T->M[i][j] = T->M[j][i];

            T->M[j][i] = temp;
        }
    }

    return T;
}

Square_Matrix* handle_transpose_square_matrix(Square_Matrix *M)
{
    try
    {
        return transpose_square_matrix(M);
    }
    catch(string &ex)
    {
        cout<<ex;

        return nullptr;
    }
}

int main()
{
    Square_Matrix M {new int*[3] {new int[3] {1, 2, 3}, new int[3] {4, 5, 6}, new int[3] {7, 8, 9}}, 3 * 3, 3};

    cout<<"M:\n";
    display_square_matrix(&M);
    cout<<"\n\n";

    Square_Matrix *T {handle_transpose_square_matrix(&M)};

    cout<<"T:\n";
    display_square_matrix(T);
    cout<<"\n";

    return 0;
}