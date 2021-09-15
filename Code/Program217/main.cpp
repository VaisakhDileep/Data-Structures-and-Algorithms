/*
Created by  : Vaisakh Dileep
Date		: 9, June, 2021
Description : This program displays a binary tree using level-order traversal using queue.
*/

#include<iostream>

#include<queue>

using namespace std;

struct Node;

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

void display_binary_tree(Binary_Tree *T) // level-order traversal
{
	if((T == nullptr) or (T->root == nullptr))
	{
		return ;
	}

	queue<Node*> Q {};

	Node *node {T->root};

	cout<<node->data<<" ";

	Q.push(node);

	while(!Q.empty())
	{
		node = Q.front();

		Q.pop();

		if(node->left_child != nullptr)
		{
			cout<<node->left_child->data<<" ";

			Q.push(node->left_child);
		}

		if(node->right_child != nullptr)
		{
			cout<<node->right_child->data<<" ";

			Q.push(node->right_child);
		}
	}
}

int main()
{
	Binary_Tree T {};

	handle_create_binary_tree(&T, new int[6] {1, 2, 3, INT_MIN, 4, 5}, 6);

	cout<<"T[level-order]: ";
	display_binary_tree(&T);
	cout<<"\n";

	return 0;
}