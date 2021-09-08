/*
Created by  : Vaisakh Dileep
Date		: 12, May, 2021
Description : This program displays a matrix.
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

int main()
{
	Matrix M1 {nullptr, 0, 0, 0};

	cout<<"M1: \n";
	display_matrix(&M1);
	cout<<"\n";

	Matrix M2 {new int*[2] {new int[3] {1, 2, 3}, new int[3] {4, 5, 6}}, 2 * 3, 2, 3};

	cout<<"M2: \n";
	display_matrix(&M2);
	cout<<"\n";

	Matrix M3 {created_dynamic_matrix(2, 3), 2 * 3, 2, 3};

	cout<<"M3: \n";
	display_matrix(&M3);
	cout<<"\n";

	return 0;
}