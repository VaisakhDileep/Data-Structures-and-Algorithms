/*
Created by  : Vaisakh Dileep
Date		: 7, June, 2021
Description : This program finds the parent of a node in a binary tree.
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

	int height {height_binary_tree(T)};

	int number_nodes {static_cast<int>(pow(2, height + 1)) - 1};

	T->size = number_nodes;

	T->A = new int[number_nodes] {};

	for(int i {0}; i < size; i++)
	{
		T->A[i] = A[i];
	}

	for(int i {size}; i < T->size; i++)
	{
		T->A[i] = INT_MIN;
	}
}

int parent_binary_tree(Binary_Tree *T, int node)
{
	if(T == nullptr)
	{
		throw string {"ERROR - Invalid operation, binary tree is not valid ....."};
	}

	if(T->A == nullptr)
	{
		throw string {"ERROR - Invalid operation, binary tree is empty ....."};
	}

	int i {0};

	for(; i < T->size; i++)
	{
		if(T->A[i] == node)
		{
			break;
		}
	}

	if(i == T->size)
	{
		throw string {"ERROR - Invalid operation, node not present in the binary tree ....."};
	}
	else if(i == 0)
	{
		throw string {"ERROR - Invalid operation, given node is the root of the binary tree ....."};
	}
	else
	{
		i = ((i + 1) / 2) - 1; // Equation for finding the index of the parent of the node.
	}

	return T->A[i];
}

int handle_parent_binary_tree(Binary_Tree *T, int node)
{
	try
	{
		return parent_binary_tree(T, node);
	}
	catch(string &ex)
	{
		cout<<ex;

		return -1;
	}
}

int main()
{
	Binary_Tree T {};

	create_binary_tree(&T, new int[6] {1, 2, 3, 4, 5, 6}, 6);

	cout<<"handle_parent_binary_tree(T, 2): "<<handle_parent_binary_tree(&T, 2)<<"\n";
	cout<<"handle_parent_binary_tree(T, 4): "<<handle_parent_binary_tree(&T, 4)<<"\n";
	cout<<"handle_parent_binary_tree(T, 1): "<<handle_parent_binary_tree(&T, 1)<<"\n";
	cout<<"handle_parent_bianry_tree(T, 7): "<<handle_parent_binary_tree(&T, 7)<<"\n";

	return 0;
}