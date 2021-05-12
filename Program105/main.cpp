/*
Created by  : Vaisakh Dileep
Date		: 12, May, 2021
Description : This program optimizes a diagonal matrix.
*/

#include<iostream>

using namespace std;

struct Square_Matrix
{
	int **M;

	int size;

	int n;
};

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
	return 0;
}