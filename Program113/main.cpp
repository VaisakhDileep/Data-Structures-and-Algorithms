/*
Created by  : Vaisakh Dileep
Date		: 19, May, 2021
Description : This program optimizes a tridiagonal matrix.
*/

#include<iostream>

using namespace std;

struct Square_Matrix // All tridiagonal matrices are square matrix.
{
	int **M;

	int size;

	int n;
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

void set_optimized_tridiagonal_matrix(Array_with_dimension *A, int i, int j, int value)
{
	if((i < A->rows) and ((i - j) == 1))
	{
		A->A[j] = value;
	}
	else if((i < A->rows) and ((i - j) == 0))
	{
		A->A[(A->rows - 1) + i] = value;
	}
	else if((i < A->rows) and ((j - i) == 1))
	{
		A->A[((2 * A->rows) - 1) + i] = value;
	}
	else if((i >= A->rows) or (j >= A->columns))
	{
		throw string {"ERROR - Cannot set value, invalid index ....."};
	}
	else if(value != 0)
	{
		throw string {"ERROR - Cannot set value, not a tridiagonal element ....."};
	}
}

void handle_set_optimized_tridiagonal_matrix(Array_with_dimension *A, int i, int j, int value)
{
	try
	{
		set_optimized_tridiagonal_matrix(A, i, j, value);
	}
	catch(string &ex)
	{
		cout<<ex;
	}
}

int get_optimized_tridiagonal_matrix(Array_with_dimension *A, int i, int j)
{
	if((i < A->rows) and ((i - j) == 1))
	{
		return A->A[j];
	}
	else if((i < A->rows) and ((i - j) == 0))
	{
		return A->A[(A->rows - 1) + i];
	}
	else if((i < A->rows) and ((j - i) == 1))
	{
		return A->A[((2 * A->rows) - 1) + i];
	}
	else if((i < A->rows) and (j < A->columns))
	{
		return 0;
	}
	else
	{
		throw string {"ERROR - Cannot retrieve data, invalid index ....."};
	}
}

int handle_get_optimized_tridiagonal_matrix(Array_with_dimension *A, int i, int j)
{
	try
	{
		return get_optimized_tridiagonal_matrix(A, i, j);
	}
	catch(string &ex)
	{
		cout<<ex;

		return -1;
	}
}

Array_with_dimension create_optimized_tridiagonal_matrix(Square_Matrix *M)
{
	if(M->M == nullptr)
	{
		throw string {"ERROR - Invalid operation, matrix is empty ....."};
	}

	Array_with_dimension A {create_dynamic_array((3 * M->n) - 2), ((3 * M->n) - 2), ((3 * M->n) - 2), M->n, M->n};

	for(int i {0}; i < M->n; i++)
	{
		for(int j {0}; j < M->n; j++)
		{
			try
			{
				set_optimized_tridiagonal_matrix(&A, i, j, M->M[i][j]);
			}
			catch(string &ex)
			{
				throw string {"ERROR - Invalid operation, matrix is not tridiagonal ....."};
			}
		}
	}

	return A;
}

Array_with_dimension handle_create_optimized_tridiagonal_matrix(Square_Matrix *M)
{
	try
	{
		return create_optimized_tridiagonal_matrix(M);
	}
	catch(string &ex)
	{
		cout<<ex;

		return Array_with_dimension {};
	}
}

void display_optimized_tridiagonal_matrix(Array_with_dimension *A)
{
	if(A->A == nullptr)
	{
		cout<<"[\n]";

		return ;
	}

	if(A->rows != A->columns)
	{
		cout<<"ERROR - Invalid operation, optimized matrix is not a tridiagonal matrix .....";
	}

	cout<<"[\n";
	for(int i {0}; i < A->rows; i++)
	{
		cout<<" [ ";
		for(int j {0}; j < A->columns; j++)
		{
			cout<<get_optimized_tridiagonal_matrix(A, i, j)<<" ";
		}
		cout<<"]\n";
	}
	cout<<"]";
}


int main()
{
	Square_Matrix M {new int*[5] {new int[5] {1, 2, 0, 0, 0}, new int[5] {1, 2, 3, 0, 0}, new int[5] {0, 1, 2, 3, 0}, new int[5] {0, 0, 1, 2, 3}, new int[5] {0, 0, 0, 1, 2}}, 5 * 5, 5};

	cout<<"M: \n";
	display_square_matrix(&M);
	cout<<"\n";

	Array_with_dimension A {handle_create_optimized_tridiagonal_matrix(&M)};

	cout<<"A: ";
	display_array_with_dimension(&A);
	cout<<"\n";

	cout<<"A: \n";
	display_optimized_tridiagonal_matrix(&A);
	cout<<"\n";

	cout<<"handle_get_optimized_tridiagonal_matrix(&A, 0, 1): "<<handle_get_optimized_tridiagonal_matrix(&A, 0, 1)<<"\n";
	cout<<"handle_get_optimized_tridiagonal_matrix(&A, 5, 0): "<<handle_get_optimized_tridiagonal_matrix(&A, 5, 0)<<"\n\n";

	handle_set_optimized_tridiagonal_matrix(&A, 0, 0, 9);
	handle_set_optimized_tridiagonal_matrix(&A, 3, 1, 7);

	cout<<"\n";

	cout<<"A: \n";
	display_optimized_tridiagonal_matrix(&A);
	cout<<"\n";

	return 0;
}