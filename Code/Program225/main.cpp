/*
Created by  : Vaisakh Dileep
Date		: 10, June, 2021
Description : This program counts the number of nodes with degree '1' in a binary tree.
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

int count_nodes_degree_one_binary_tree(Node *node)
{
	int left_count {}, right_count {};

	if(node != nullptr)
	{
		left_count = count_nodes_degree_one_binary_tree(node->left_child);

		right_count = count_nodes_degree_one_binary_tree(node->right_child);

		if(!(node->left_child) != !(node->right_child)) // xor operation
		{
			return left_count + right_count + 1;
		}
		else
		{
			return left_count + right_count;
		}
	}

	return 0;
}

int handle_count_nodes_degree_one_binary_tree(Binary_Tree *T)
{
	if(T == nullptr)
	{
		cout<<"ERROR - Invalid operation, binary tree is not valid .....";
	}
	else if(T->root == nullptr)
	{
		return 0;
	}

	return count_nodes_degree_one_binary_tree(T->root);
}

int main()
{
	Binary_Tree T {};

	handle_create_binary_tree(&T, new int[6] {1, 2, 3, 4, 5, 6}, 6);

	cout<<"handle_count_nodes_degree_one_binary_tree(T): "<<handle_count_nodes_degree_one_binary_tree(&T)<<"\n";

	return 0;
}