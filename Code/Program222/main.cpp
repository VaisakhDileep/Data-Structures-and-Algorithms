/*
Created by  : Vaisakh Dileep
Date        : 9, June, 2021
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

int height_binary_tree(Node *node)
{
    int left_height {0}, right_height {0};

    if(node != nullptr)
    {
        left_height = height_binary_tree(node->left_child);

        right_height = height_binary_tree(node->right_child);

        if(left_height > right_height)
        {
            return left_height + 1;
        }
        else
        {
            return right_height + 1;
        }
    }

    return 0;
}

int handle_height_binary_tree(Binary_Tree *T)
{
    if(T == nullptr)
    {
        cout<<"ERROR - Invalid operation, binary tree is not valid .....";

        return -1;
    }
    else if(T->root == nullptr)
    {
        return 0;
    }

    return height_binary_tree(T->root) - 1; // We are only counting the edges for height.
}

int main()
{
    Binary_Tree T {};

    handle_create_binary_tree(&T, new int[4] {1, 2, 3, 4}, 4);

    cout<<"handle_height_binary_tree(T): "<<handle_height_binary_tree(&T)<<"\n";

    return 0;
}