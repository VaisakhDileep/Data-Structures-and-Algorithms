/*
Created by  : Vaisakh Dileep
Date        : 28, September, 2021
Description : This program finds the determinant of a 2*2 matrix.
*/

#include<iostream>

using namespace std;

struct Square_Matrix
{
    int **M;

    int size;

    int n;
};

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

int handle_determinant_2x2_matrix(Square_Matrix *M)
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
    Square_Matrix M1 {new int*[2] {new int[2] {1, 12}, new int[2] {13, 4}}, 2 * 2, 2};

    cout<<"M1: \n";
    display_square_matrix(&M1);
    cout<<"\n\n";

    cout<<"determinant_2x2_matrix(M1): "<<determinant_2x2_matrix(&M1);

    return 0;
}