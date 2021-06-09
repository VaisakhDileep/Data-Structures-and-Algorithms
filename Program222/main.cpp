/*
Created by  : Vaisakh Dileep
Date		: 9, June, 2021
Description : This program finds the height of a binary tree.
*/

#include<iostream>

using namespace std;

struct Node
{
	Node *left_child;

	int data;

	Node *right_child;
};

struct Binary_Tree
{
	Node *root;
};

void create_binary_tree(Node **node, int i, int *A, int size)
{
	if((i < size) and (A[i] != INT_MIN))
	{
		*node = new Node {nullptr, A[i], nullptr};

		create_binary_tree(&((*node)->left_child), (2 * (i + 1)) - 1, A, size);

		create_binary_tree(&((*node)->right_child), 2 * (i + 1), A, size);
	}
}

void handle_create_binary_tree(Binary_Tree *T, int *A, int size)
{
	create_binary_tree(&(T->root), 0, A, size);
}



int main()
{
	return 0;
}