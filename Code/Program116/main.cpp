/*
Created by  : Vaisakh Dileep
Date        : 21, May, 2021
Description : This program adds two sparse matrices using 3-column representation.
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
    int i;

    int j;

    int value;
};

struct Sparse_Coordinate_List
{
    int rows;

    int columns;

    int non_zero_count;

    Sparse_Coordinate_List_Element *element;
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

Sparse_Coordinate_List add_optimized_sparse_matrices(Sparse_Coordinate_List *X1, Sparse_Coordinate_List *X2)
{
    if((X1 == nullptr) or (X2 == nullptr))
    {
        throw string {"ERROR - Invalid operation, one of the matrix is empty ....."};
    }

    if((X1->rows != X2->rows) or (X1->columns != X2->columns))
    {
        throw string {"ERROR - Invalid operation, dimension of the matrices do not match ....."};
    }

    Sparse_Coordinate_List S {X1->rows, X1->columns, 0, new Sparse_Coordinate_List_Element[X1->non_zero_count + X2->non_zero_count]};

    int i {0}, j {0}, k {0};

    while((i < X1->non_zero_count) and (j < X2->non_zero_count))
    {
        if(X1->element[i].i < X2->element[j].i)
        {
            S.element[k++] = X1->element[i++];
        }
        else if(X1->element[i].i > X2->element[j].i)
        {
            S.element[k++] = X2->element[j++];
        }
        else
        {
            if(X1->element[i].j < X2->element[j].j)
            {
                S.element[k++] = X1->element[i++];
            }
            else if(X1->element[i].j > X2->element[j].j)
            {
                S.element[k++] = X2->element[j++];
            }
            else
            {
                S.element[k] = X1->element[i++];

                S.element[k++].value += X2->element[j++].value;
            }
        }
    }

    for(; i < X1->non_zero_count; i++)
    {
        S.element[k++] = X1->element[i];
    }

    for(; j < X2->non_zero_count; j++)
    {
        S.element[k++] = X2->element[j];
    }

    S.non_zero_count = k;

    return S;
}

Sparse_Coordinate_List handle_add_optimized_sparse_matrices(Sparse_Coordinate_List *X1, Sparse_Coordinate_List *X2)
{
    try
    {
        return add_optimized_sparse_matrices(X1, X2);
    }
    catch(string &ex)
    {
        cout<<ex;

        return Sparse_Coordinate_List {};
    }
}

int main()
{
    Matrix M1 {new int*[4] {new int[5] {1, 0, 0, 0, 0}, new int[5] {0, 3, 0, 0, 0}, new int[5] {0, 2, 3, 0, 0}, new int[5] {1, 0, 0, 0, 0}}, (4 * 5), 4, 5};
    Matrix M2 {new int*[4] {new int[5] {0, 8, 0, 0, 0}, new int[5] {0, 0, 0, 0, 0}, new int[5] {0, 0, 1, 0, 3}, new int[5] {1, 0, 6, 0, 0}}, (4 * 5), 4, 5};

    cout<<"M1: \n";
    display_matrix(&M1);
    cout<<"\n";

    Sparse_Coordinate_List X1 {handle_create_sparse_coordinate_list(&M1)};
    Sparse_Coordinate_List X2 {handle_create_sparse_coordinate_list(&M2)};

    cout<<"X1[Coordinate List]: \n";
    display_sparse_coordinate_list(&X1);
    cout<<"\n";

    cout<<"X2[Coordinate List]: \n";
    display_sparse_coordinate_list(&X2);
    cout<<"\n";

    cout<<"X1: ";
    display_optimized_sparse_matrix(&X1);
    cout<<"\n";

    cout<<"X2: ";
    display_optimized_sparse_matrix(&X2);
    cout<<"\n\n";

    Sparse_Coordinate_List SX {handle_add_optimized_sparse_matrices(&X1, &X2)};

    cout<<"SX = X1 + X2\n\n";

    cout<<"SX[Coordinate List]: \n";
    display_sparse_coordinate_list(&SX);
    cout<<"\n";

    cout<<"SX: \n";
    display_optimized_sparse_matrix(&SX);
    cout<<"\n";

    return 0;
}