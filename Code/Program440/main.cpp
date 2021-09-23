/*
Created by  : Vaisakh Dileep
Date		: 23, September, 2021
Description : This program searches for an element recursively in a binary search tree.
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

Node* handle_search_binary_search_tree(Binary_Search_Tree *T, int key)
{
	if(T == nullptr)
	{
		cout<<"ERROR - Invalid operation, binary search tree is not valid .....";

		return nullptr;
	}

	Node *target {search_binary_search_tree(T->root, key)};

	if(target == nullptr)
	{
		cout<<"ERROR - Invalid operation, key not present in the binary search tree .....";

		return nullptr;
	}
	else
	{
		return target;
	}
}

int main()
{
	Binary_Search_Tree T {};

	create_binary_search_tree(&T, new int[6] {7, 4, 6, 8, 9, 2}, 6);

	cout<<"handle_search_binary_search_tree(&T, 7): "<<handle_search_binary_search_tree(&T, 7)->data<<"\n";
	cout<<"handle_search_binary_search_tree(&T, 4): "<<handle_search_binary_search_tree(&T, 4)->data<<"\n";
	cout<<"handle_search_binary_search_tree(&T, 2): "<<handle_search_binary_search_tree(&T, 2)->data<<"\n";
	cout<<"handle_search_binary_search_tree(&T, 9): "<<handle_search_binary_search_tree(&T, 9)->data<<"\n";

	cout<<"handle_search_binary_search_tree(&T, 10): "<<handle_search_binary_search_tree(&T, 10)<<"\n";

	return 0;
}