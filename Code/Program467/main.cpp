/*
Created by  : Vaisakh Dileep
Date        : 7, October, 2021
Description : This program rotates a square matrix by 180 deg(O(1) space solution).
*/

#include<iostream>

using namespace std;

struct Square_Matrix
{
    int **M;

    int size;

    int n;
};

struct index
{
    int r;

    int c;
};

void rotate_matrix_180_deg(Square_Matrix *M)
{
    if(M == nullptr)
    {
        throw string {"ERROR - Invalid operation, square matrix is not valid ....."};
    }

    if(M->M == nullptr)
    {
        throw string {"ERROR - Invalid operation, square matrix is empty ....."};
    }

    for(int i {0}; i < M->n / 2; i++)
    {
        for(int j {0}; j < M->n - 1 - (2 * i); j++)
        {
            index row_up {i, j + i}, column_right {j + i, M->n - 1 - i}, row_down {M->n - 1 - i, M->n - 1 - i - j}, column_left {M->n - 1 - i - j, i};

            swap(M->M[row_up.r][row_up.c], M->M[row_down.r][row_down.c]);

            swap(M->M[column_right.r][column_right.c], M->M[column_left.r][column_left.c]);
        }
    }
}

void handle_rotate_matrix_180_deg(Square_Matrix *M)
{
    try
    {
        rotate_matrix_180_deg(M);
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
    cout<<"\n";

    handle_rotate_matrix_180_deg(&M1);

    cout<<"M1[after rotating 180 deg]: \n";
    display_square_matrix(&M1);
    cout<<"\n";

    return 0;
}