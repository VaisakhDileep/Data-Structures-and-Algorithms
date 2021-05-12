/*
Created by  : Vaisakh Dileep
Date		: 12, May, 2021
Description : This program creates a matrix.
*/

#include<iostream>

using namespace std;

struct Matrix
{
	int **A; // pointer to a dynamically created matrix.

	int size; // maximum number of elements supported by the matrix.

	int rows; // number of rows.

	int columns; // number of columns.
};

int ** created_dynamic_matrix(int rows, int columns, int initial_value = 0)
{
	int **p;

	p = new int*[rows];

	for(int i {0}; i < rows; i++)
	{
		p[i] = new int[columns];
	}

	return p;
}

int main()
{
	Matrix M {created_dynamic_matrix(2, 3), 2 * 3, 2, 3};

	return 0;
}