/*
Created by  : Vaisakh Dileep
Date		: 25, September, 2021
Description : This program finds the inorder predecessor of a node in a binary search tree.
*/

#include<iostream>

using namespace std;

struct Node
{
	Node *left_child;

	int data;

	Node *right_child;
};

struct Binary_Search_Tree
{
	Node *root;
};

void insert_binary_search_tree(Binary_Search_Tree *T, int value)
{
	if(T == nullptr)
	{
		throw string {"ERROR - Invalid operation, binary search tree is not valid ....."};
	}

	if(T->root == nullptr)
	{
		T->root = new Node {nullptr, value, nullptr};

		return ;
	}

	Node *node {T->root}, *previous_node {};

	while(node != nullptr)
	{
		previous_node = node;

		if(value == node->data)
		{
			throw string {"ERROR - Invalid operation, value already present in the binary search tree ....."};
		}
		else if(value > node->data)
		{
			node = node->right_child;
		}
		else if(value < node->data)
		{
			node = node->left_child;
		}
	}

	if(value < previous_node->data)
	{
		previous_node->left_child = new Node {nullptr, value, nullptr};
	}
	else
	{
		previous_node->right_child = new Node {nullptr, value, nullptr};
	}
}


void create_binary_search_tree(Binary_Search_Tree *T, int *A, int size)
{
	for(int i {0}; i < size; i++)
	{
		try
		{
			insert_binary_search_tree(T, A[i]);
		}
		catch(string &ex)
		{
			if(ex == "ERROR - Invalid operation, value already present in the binary search tree .....")
			{
				cout<<"ERROR - Invalid operation, "<<A[i]<<" cannot be inserted in the binary search tree .....\n";
			}
			else if(ex == "ERROR - Invalid operation, binary search tree is not valid .....")
			{
				cout<<ex;

				return ;
			}
		}
	}
}

Node* search_binary_search_tree(Node *node, int key)
{
	if(node == nullptr)
	{
		return nullptr;
	}

	if(key == node->data)
	{
		return node;
	}
	else if(key < node->data)
	{
		return search_binary_search_tree(node->left_child, key);
	}
	else if(key > node->data)
	{
		return search_binary_search_tree(node->right_child, key);
	}
}

Node* inorder_predecessor_binary_search_tree(Node *node)
{
	Node *inorder_predecessor {node->left_child};

	while(inorder_predecessor->right_child != nullptr)
	{
		inorder_predecessor = inorder_predecessor->right_child;
	}

	return inorder_predecessor;
}

Node* handle_inorder_predecessor_binary_search_tree(Binary_Search_Tree *T, int node)
{
	if(T == nullptr)
	{
		cout<<"ERROR - Invalid operation, binary search tree is not valid .....";

		return nullptr;
	}
	else if(T->root == nullptr)
	{
		cout<<"ERROR - Invalid operation, binary search tree is empty .....";

		return nullptr;
	}

	Node *node_ptr {search_binary_search_tree(T->root, node)};

	if(node_ptr == nullptr)
	{
		cout<<"ERROR - Invalid operation, node is not present in the binary search tree .....";

		return nullptr;
	}

	if(node_ptr->left_child == nullptr)
	{
		cout<<"ERROR - Invalid operation, given binary search tree node does not contain inorder predecessor .....";

		return nullptr;
	}

	Node *inorder_predecessor {inorder_predecessor_binary_search_tree(node_ptr)};

	return inorder_predecessor;
}

int main()
{
	Binary_Search_Tree T {};

	// create_binary_search_tree(&T, new int[1] {1}, 1);

	// create_binary_search_tree(&T, new int [2] {5, 2}, 2);

	create_binary_search_tree(&T, new int[6] {10, 5, 6, 15, 20, 12}, 6);

	cout<<"handle_inorder_predecessor_binary_tree(&T, 10): "<<handle_inorder_predecessor_binary_search_tree(&T, 10)->data<<"\n";

	return 0;
}