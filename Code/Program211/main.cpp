/*
Created by  : Vaisakh Dileep
Date        : 7, June, 2021
Description : This program displays a binary tree using pre-order traversal.
*/

#include<iostream>

#include<climits>

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

void display_binary_tree(Node *node) // pre-order traversal
{
    if(node != nullptr)
    {
        cout<<node->data<<" ";

        display_binary_tree(node->left_child);

        display_binary_tree(node->right_child);
    }
}

void handle_display_binary_tree(Binary_Tree *T)
{
    display_binary_tree(T->root);
}

int main()
{
    Binary_Tree T {};

    handle_create_binary_tree(&T, new int[6] {1, 2, 3, INT_MIN, 4, 5}, 6);

    cout<<"T[pre-order]: ";
    handle_display_binary_tree(&T);
    cout<<"\n";

    return 0;
}