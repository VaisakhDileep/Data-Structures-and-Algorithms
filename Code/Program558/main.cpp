/*
Created by  : Vaisakh Dileep
Date        : 5, March, 2022
Description : This program checks if two nodes in a binary tree are siblings.
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

// Inorder to to understand siblings in binary tree refer "Data Structures and Algorithms Manual 1" pg no:16.

bool check_nodes_are_siblings_in_binary_tree(Node *current_node, Node *node_1, Node *node_2)
{
    if(current_node == nullptr)
    {
        return false;
    }

    if((current_node->left_child != nullptr) and (current_node->right_child != nullptr))
    {
        if((current_node->left_child == node_1) and (current_node->right_child == node_2))
        {
            return true;
        }

        if((current_node->left_child == node_2) and (current_node->right_child == node_1))
        {
            return true;
        }
    }

    if(current_node->left_child != nullptr)
    {
        if(check_nodes_are_siblings_in_binary_tree(current_node->left_child, node_1, node_2) == true)
        {
            return true;
        }
    }

    if(current_node->right_child != nullptr)
    {
        if(check_nodes_are_siblings_in_binary_tree(current_node->right_child, node_1, node_2) == true)
        {
            return true;
        }
    }

    return false;
}

bool handle_check_nodes_are_siblings_in_binary_tree(Binary_Tree *T, Node *node_1, Node *node_2)
{
    if(T == nullptr)
    {
        cout<<"ERROR - Invalid operation, binary tree is not valid .....";

        return false;
    }

    if(T->root == nullptr)
    {
        cout<<"ERROR - Invalid operation, binary tree is empty .....";

        return false;
    }

    if((node_1 == nullptr) or (node_2 == nullptr))
    {
        cout<<"ERROR - Invalid operation, one of the given nodes is not valid .....";

        return false;
    }

    return check_nodes_are_siblings_in_binary_tree(T->root, node_1, node_2);
}

int main()
{
    Binary_Tree T {};

    T.root = new Node {new Node {new Node {nullptr, 4, nullptr}, 2, new Node {new Node {new Node {nullptr, 7, nullptr}, 6, new Node {nullptr, 8, nullptr}}, 5, nullptr}}, 1, new Node {nullptr, 3, nullptr}};

    Node *node_1 {T.root->left_child->right_child->left_child->left_child}, *node_2 {T.root->left_child->right_child->left_child->right_child};

    cout<<"check_nodes_are_siblings_in_binary_tree([the test case contains valid siblings]): "<<handle_check_nodes_are_siblings_in_binary_tree(&T, node_1, node_2)<<"\n";

    node_1 = T.root->left_child->left_child;

    node_2 = T.root->right_child;

    cout<<"check_nodes_are_siblings_in_binary_tree([the test case contains invalid siblings]): "<<handle_check_nodes_are_siblings_in_binary_tree(&T, node_1, node_2)<<"\n";

    return 0;
}