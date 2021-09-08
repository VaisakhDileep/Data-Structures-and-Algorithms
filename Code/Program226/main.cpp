/*
Created by  : Vaisakh Dileep
Date		: 11, June, 2021
Description : This program inserts an element to a binary search tree.
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

namespace iteration
{
	void insert_binary_search_tree(Binary_Tree *T, int value)
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

	void handle_insert_binary_search_tree(Binary_Tree *T, int value)
	{
		try
		{
			insert_binary_search_tree(T, value);
		}
		catch(string &ex)
		{
			cout<<ex;
		}
	}
}

namespace recursion
{
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
}

int main()
{
	Binary_Tree T1 {}, T2 {};

// Using iteration:
	iteration::handle_insert_binary_search_tree(&T1, 1);
	iteration::handle_insert_binary_search_tree(&T1, 4);
	iteration::handle_insert_binary_search_tree(&T1, 5);
	iteration::handle_insert_binary_search_tree(&T1, 3); // We can create a binary search tree from scratch like this.

	iteration::handle_insert_binary_search_tree(&T1, 4);
	cout<<"\n";

// Using recursion:
	recursion::handle_insert_binary_search_tree(&T2, 1); // We can create a binary search tree from scratch like this.
	recursion::handle_insert_binary_search_tree(&T2, 4);
	recursion::handle_insert_binary_search_tree(&T2, 5);
	recursion::handle_insert_binary_search_tree(&T2, 3);

	recursion::handle_insert_binary_search_tree(&T2, 4);
	cout<<"\n";

	return 0;
}