/*
Created by  : Vaisakh Dileep
Date        : 4, October, 2021
Description : This program rotates a square matrix 90 deg anti-clockwise(O(n*n) space solution).
*/

#include<iostream>

using namespace std;

struct Square_Matrix
{
    int **M;

    int size;

    int n;
};

void rotate_matrix_90_deg_anti_clockwise(Square_Matrix *M)
{
    if(M == nullptr)
    {
        throw string {"ERROR - Invalid operation, square matrix is not valid ....."};
    }

    if(M->M == nullptr)
    {
        throw string {"ERROR - Invalid operation, square matrix is empty ....."};
    }

    Square_Matrix temp {new int*[M->n] {}, M->n * M->n, M->n};

    for(int i {0}; i < M->n; i++)
    {
        temp.M[i] = new int[M->n] {};
    }

    int column_itr {0};

    for(int i {0}; i < M->n; i++)
    {
        for(int j {M->n - 1}; j >= 0; j--)
        {
            temp.M[M->n -1 - j][column_itr] = M->M[i][j];
        }

        column_itr++;
    }

    for(int i {0}; i < M->n; i++)
    {
        for(int j {0}; j < M->n; j++)
        {
            M->M[i][j] = temp.M[i][j];
        }
    }
}

void handle_rotate_matrix_90_deg_anti_clockwise(Square_Matrix *M)
{
    try
    {
        rotate_matrix_90_deg_anti_clockwise(M);
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

    handle_rotate_matrix_90_deg_anti_clockwise(&M1);

    cout<<"M1[after rotating 90 deg anti-clockwise]: \n";
    display_square_matrix(&M1);
    cout<<"\n";

    return 0;
}