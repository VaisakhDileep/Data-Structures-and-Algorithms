/*
Created by  : Vaisakh Dileep
Date        : 12, May, 2021
Description : This program displays a square matrix.
*/

#include<iostream>

using namespace std;

struct Square_Matrix
{
    int **M;

    int size;

    int n;
};

int ** created_dynamic_square_matrix(int n, int initial_value = 0)
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

int main()
{
    Square_Matrix M1 {nullptr, 0, 0};

    cout<<"M1: \n";
    display_square_matrix(&M1);
    cout<<"\n\n";

    Square_Matrix M2 {new int*[2] {new int[2] {1, 2}, new int[2] {3, 4}}, 2 * 2, 2};

    cout<<"M2: \n";
    display_square_matrix(&M2);
    cout<<"\n\n";

    Square_Matrix M3 {created_dynamic_square_matrix(2), 2 * 2, 2};

    cout<<"M3: \n";
    display_square_matrix(&M3);
    cout<<"\n";

    return 0;
}