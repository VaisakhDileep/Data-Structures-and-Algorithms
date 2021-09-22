/*
Created by  : Vaisakh Dileep
Date		: 23, September, 2021
Description : This program inserts an element recursively to a binary search tree.
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


Node* insert_binary_search_tree(Node *node, int value)
{
	if(node == nullptr)
	{
		return new Node {nullptr, value, nullptr};
	}

	if(value < node->data)
	{
		node->left_child = insert_binary_search_tree(node->left_child, value);
	}
	else if(value > node->data)
	{
		node->right_child = insert_binary_search_tree(node->right_child, value);
	}
	else if(value == node->data)
	{
		throw string {"ERROR - Invalid operation, value already present in the binary search tree ....."};
	}

	return node;
}

void handle_insert_binary_search_tree(Binary_Tree *T, int value)
{
	if(T == nullptr)
	{
		cout<<"ERROR - Invalid operation, binary search tree is not valid .....";
	}

	try
	{
		T->root = insert_binary_search_tree(T->root, value);
	}
	catch(string &ex)
	{
		cout<<ex;
	}
}

int main()
{
	Binary_Tree T1 {};

	handle_insert_binary_search_tree(&T1, 1); // We can create a binary search tree from scratch like this.
	handle_insert_binary_search_tree(&T1, 4);
	handle_insert_binary_search_tree(&T1, 5);
	handle_insert_binary_search_tree(&T1, 3);

	handle_insert_binary_search_tree(&T1, 4);
	cout<<"\n";

	return 0;
}