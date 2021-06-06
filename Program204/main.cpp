/*
Created by  : Vaisakh Dileep
Date		: 6, June, 2021
Description : This program creates a binary tree from an array.
*/

#include<iostream>

#include<climits>

#include<math.h>

using namespace std;

struct Binary_Tree
{
	int *A;

	int size;
};

int height_binary_tree(Binary_Tree *T)
{
	if(T == nullptr)
	{
		throw string {"ERROR - Invalid operation, binary tree is not valid ....."};
	}

	if(T->size == 0)
	{
		return 0;
	}

	int height {0};

	int total_nodes {0};

	while(total_nodes < T->size)
	{
		total_nodes += pow(2, height);

		height++;
	}

	return (height - 1);
}

void create_binary_tree(Binary_Tree *T, int *A, int size)
{
	if(T == nullptr)
	{
		throw string {"ERROR - Invalid operation, binary tree is not valid ....."};
	}

	T->size = size;

	T->A = A;

	int height {height_binary_tree(T)};

	int number_nodes {static_cast<int>(pow(2, height + 1)) - 1}; // Number of nodes to safely hold the tree.

	T->size = number_nodes;

	for(int i {size -1}; i < T->size; i++)
	{
		T->A[i] = INT_MIN;
	}
}

void handle_create_binary_tree(Binary_Tree *T, int *A, int size)
{
	try
	{
		create_binary_tree(T, A, size);
	}
	catch(string &ex)
	{
		cout<<ex;
	}
}

int main()
{
	Binary_Tree T {};

	handle_create_binary_tree(&T, new int[4] {1, 2, 3, INT_MIN}, 4);

	return 0;
}