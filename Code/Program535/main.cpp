/*
Created by  : Vaisakh Dileep
Date        : 27, February, 2022
Description : This program displays a binary tree using vertical order traversal.
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

// In order to get an understanding on how vertical-order traversal works refer "" pg no:15.

void compute_min_max_width_from_root(Node *root, int &min_width, int &max_width, int current_width)
{
    if(root == nullptr)
    {
        return ;
    }

    if(current_width < min_width)
    {
        min_width = current_width;
    }
    else if(current_width > max_width)
    {
        max_width = current_width;
    }

    compute_min_max_width_from_root(root->left_child, min_width, max_width, current_width - 1);

    compute_min_max_width_from_root(root->right_child, min_width, max_width, current_width + 1);
}

void display_vertical_nodes(Node *node, int target_width, int current_width)
{
    if(node == nullptr)
    {
        return ;
    }

    if(target_width == current_width)
    {
        cout<<node->data<<" ";
    }

    display_vertical_nodes(node->left_child, target_width, current_width - 1);

    display_vertical_nodes(node->right_child, target_width, current_width + 1);
}

void display_binary_tree(Binary_Tree *T) // vertical-order traversal
{
    if(T == nullptr)
    {
        return ;
    }

    int min_width {0}, max_width {0};

    compute_min_max_width_from_root(T->root, min_width, max_width, 0);

    cout<<"[ ";
    for(int i {min_width}; i <= max_width; i++)
    {
        cout<<"[ ";

        display_vertical_nodes(T->root, i, 0);

        cout<<"]";
    }
    cout<<"]";
}

int main()
{
    Binary_Tree T {};

    handle_create_binary_tree(&T, new int[15] {1, 2, 3, 4, 5, 6, 7, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, 8, 9}, 15);

    cout<<"T[vertical-order]: ";
    display_binary_tree(&T);
    cout<<"\n";

    return 0;
}