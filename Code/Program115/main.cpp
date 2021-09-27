/*
Created by  : Vaisakh Dileep
Date        : 20, May, 2021
Description : This program optimizes a sparse matrix using 3-column representation.
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

struct Sparse_Coordinate_List_Element
{
    int i; // index of row.

    int j; // index of column.

    int value; // non-zero element.
};

struct Sparse_Coordinate_List
{
    int rows; // number of rows

    int columns; // number of columns.

    int non_zero_count; // number of non-zero elements.

    Sparse_Coordinate_List_Element *element; // dynamically created array of "Sparse_Coordinate_List_Elements".
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

int count_non_zero_elements_matrix(Matrix *M)
{
    if(M->M == nullptr)
    {
        throw string {"ERROR - Invalid operation, matrix is empty ....."};
    }

    int count {0};

    for(int i {0}; i < M->rows; i++)
    {
        for(int j {0}; j < M->columns; j++)
        {
            if(M->M[i][j] != 0)
            {
                count++;
            }
        }
    }

    return count;
}

int handle_count_non_zero_elements_matrix(Matrix *M)
{
    try
    {
        return count_non_zero_elements_matrix(M);
    }
    catch(string &ex)
    {
        cout<<ex;

        return -1;
    }
}

Sparse_Coordinate_List create_sparse_coordinate_list(Matrix *M)
{
    if(M->M == nullptr)
    {
        throw string {"ERROR - Invalid operation, matrix is empty ....."};
    }

    Sparse_Coordinate_List X {M->rows, M->columns, count_non_zero_elements_matrix(M), new Sparse_Coordinate_List_Element[count_non_zero_elements_matrix(M)]};

    int k {0};

    for(int i {0}; i < M->rows; i++)
    {
        for(int j {0}; j < M->columns; j++)
        {
            if(M->M[i][j] != 0)
            {
                X.element[k] = Sparse_Coordinate_List_Element {i, j, M->M[i][j]};

                k++;
            }
        }
    }

    return X;
}

Sparse_Coordinate_List handle_create_sparse_coordinate_list(Matrix *M)
{
    try
    {
        return create_sparse_coordinate_list(M);
    }
    catch(string &ex)
    {
        cout<<ex;

        return Sparse_Coordinate_List {};
    }
}

void display_sparse_coordinate_list(Sparse_Coordinate_List *X)
{
    if(X == nullptr)
    {
        cout<<"[\n] -- {i, j, value}";

        return ;
    }

    cout<<"[\n";

    for(int i {0}; i < X->non_zero_count; i++)
    {
        cout<<" { "<<X->element[i].i<<", "<<X->element[i].j<<", "<<X->element[i].value<<" }\n";
    }

    cout<<"] -- {i, j, value}";
}

int get_sparse_coordinate_list_element(Sparse_Coordinate_List *X, int i , int j)
{
    if((i < X->rows) and (j < X->columns))
    {
        for(int k {0}; k < X->non_zero_count; k++)
        {
            if( (i == X->element[k].i) and (j == X->element[k].j))
            {
                return X->element[k].value;
            }
        }

        return 0;
    }
    else
    {
        throw string {"ERROR - Cannot retrieve data, invalid index ....."};
    }
}

int handle_get_sparse_coordinate_list_element(Sparse_Coordinate_List *X, int i, int j)
{
    try
    {
        get_sparse_coordinate_list_element(X, i, j);
    }
    catch(string &ex)
    {
        cout<<ex;

        return -1;
    }
}

void display_optimized_sparse_matrix(Sparse_Coordinate_List *X)
{
    if(X == nullptr)
    {
        cout<<"[\n]";

        return ;
    }

    cout<<"[\n";
    for(int i {0}; i < X->rows; i++)
    {
        cout<<" [ ";
        for(int j {0}; j < X->columns; j++)
        {
            cout<<get_sparse_coordinate_list_element(X, i, j)<<" ";
        }
        cout<<"]\n";
    }
    cout<<"]";
}

int main()
{
    Matrix M {new int*[4] {new int[5] {1, 0, 0, 0, 0}, new int[5] {0, 3, 0, 0, 0}, new int[5] {0, 2, 3, 0, 0}, new int[5] {1, 0, 0, 0, 0}}, (4 * 5), 4, 5};

    cout<<"M: \n";
    display_matrix(&M);
    cout<<"\n";

    Sparse_Coordinate_List X {handle_create_sparse_coordinate_list(&M)};

    cout<<"X[Coordinate List]: \n";
    display_sparse_coordinate_list(&X);
    cout<<"\n";

    cout<<"X: \n";
    display_optimized_sparse_matrix(&X);
    cout<<"\n";

    return 0;
}