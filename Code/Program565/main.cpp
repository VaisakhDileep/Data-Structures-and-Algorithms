/*
Created by  : Vaisakh Dileep
Date        : 9, March, 2022
Description : This program finds the diameter of a binary tree(brute-force(O(n*n)) approach).
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

int height_binary_tree(Node *node) // In this recursive function, height is found by counting the number of nodes.
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

// Inorder to understand diameter of a binary tree refer "Data Structures and Algorithms Manual 1" pg no:16.

int diameter_of_binary_tree(Node *current_node) // In this recursive function, diameter is found by counting the number of nodes.
{
    if(current_node == nullptr)
    {
        return 0;
    }

    int left_tree_height {height_binary_tree(current_node->left_child)};

    int right_tree_height {height_binary_tree(current_node->right_child)};

    int max_diameter_left_tree = diameter_of_binary_tree(current_node->left_child);

    int max_diameter_right_tree = diameter_of_binary_tree(current_node->right_child);

    return max(left_tree_height + right_tree_height + 1, max(max_diameter_left_tree, max_diameter_right_tree));
}

int handle_diameter_of_binary_tree(Binary_Tree *T)
{
    if(T == nullptr)
    {
        cout<<"ERROR - Invalid operation, binary tree is not valid .....";

        return 0;
    }

    if(T->root == nullptr)
    {
        cout<<"ERROR - Invalid operation, binary tree is empty .....";

        return 0;
    }

    return diameter_of_binary_tree(T->root) - 1; // Diameter of the tree is found by counting the number of edges.
}

int main()
{
    Binary_Tree T {};

    T.root = new Node {new Node {nullptr, 2, new Node {new Node {new Node {new Node {nullptr, 8, nullptr}, 7, nullptr}, 5, nullptr}, 4, new Node {nullptr, 6, new Node {nullptr, 8, new Node {nullptr, 10, nullptr}}}}}, 1, new Node {nullptr, 3, nullptr}};

    cout<<"diameter_of_binary_tree(T): "<<handle_diameter_of_binary_tree(&T)<<"\n";

    return 0;
}