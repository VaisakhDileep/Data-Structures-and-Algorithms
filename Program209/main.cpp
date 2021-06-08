/*
Created by  : Vaisakh Dileep
Date		: 7, June, 2021
Description : This program creates a binary tree.
*/

#include<iostream>

using namespace std;

struct Node
{
	struct Node *left_child;

	int data;

	struct Node *right_child;
};

struct Binary_Tree
{
	Node *root;
};

int main()
{
	Binary_Tree B {};

	B.root = new Node {nullptr, 1, nullptr};

	B.root->left_child = new Node {nullptr, 2, nullptr};

	B.root->right_child = new Node {nullptr, 3, nullptr};

	B.root->left_child->left_child = new Node {nullptr, 4, nullptr};

	return 0;
}