/*
Created by  : Vaisakh Dileep
Date        : 6, December, 2021
Description : This program checks if the given binary tree is a binary search tree(optimal approach).
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

bool is_binary_search_tree(Node *root, int min, int max)
{
    if(root == nullptr)
    {
        return true; // An empty node is also a binary search tree.
    }

    if((root->data < min) or (root->data > max))
    {
        return false;
    }

    return is_binary_search_tree(root->left_child, min, root->data - 1) and is_binary_search_tree(root->right_child, root->data + 1, max);
}

bool handle_is_binary_search_tree(Binary_Tree *T)
{
    if(T == nullptr)
    {
        cout<<"ERROR - Invalid operation, binary tree is not valid .....";

        return false;
    }

    return is_binary_search_tree(T->root, INT_MIN, INT_MAX);
}

int main()
{
    Binary_Tree T1 {}, T2 {}, T3 {};

    handle_create_binary_tree(&T1, new int[7] {5, 3, 7, 2, 4, 6, 8}, 7);

    cout<<"is_binary_search_tree(T1): "<<handle_is_binary_search_tree(&T1)<<"\n";

    handle_create_binary_tree(&T2, new int[7] {15, 3, 7, 2, 4, 6, 8}, 7);

    cout<<"is_binary_search_tree(T2): "<<handle_is_binary_search_tree(&T2)<<"\n";

    handle_create_binary_tree(&T3, new int[7] {5, 3, 7, 2, 4, 6, 7}, 7);

    cout<<"is_binary_search_tree(T3): "<<handle_is_binary_search_tree(&T3)<<"\n";

    return 0;
}