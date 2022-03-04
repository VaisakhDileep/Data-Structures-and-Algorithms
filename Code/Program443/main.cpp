/*
Created by  : Vaisakh Dileep
Date        : 24, September, 2021
Description : This program finds the inorder predecessor of a node in a binary tree.
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

Node* search_binary_tree(Node *node, int target)
{
    if(node == nullptr)
    {
        return nullptr;
    }
    else if(node->data == target)
    {
        return node; // Return the pointer to the node.
    }

    Node *result {search_binary_tree(node->left_child, target)};

    if(result != nullptr)
    {
        return result;
    }

    result = search_binary_tree(node->right_child, target);

    return result; // If "target" is not present in the left subtree or right subtree, then "result" will be equal to "nullptr".
}

Node* inorder_predecessor_binary_tree(Node *node)
{
    Node *inorder_predecessor {node->left_child};

    while(inorder_predecessor->right_child != nullptr)
    {
        inorder_predecessor = inorder_predecessor->right_child;
    }

    return inorder_predecessor;
}

Node* handle_inorder_predecessor_binary_tree(Binary_Tree *T, int node)
{
    if(T == nullptr)
    {
        cout<<"ERROR - Invalid operation, binary tree is not valid .....";

        return nullptr;
    }

    if(T->root == nullptr)
    {
        cout<<"ERROR - Invalid operation, binary tree is empty .....";

        return nullptr;
    }

    Node *node_ptr {search_binary_tree(T->root, node)};

    if(node_ptr == nullptr)
    {
        cout<<"ERROR - Invalid operation, node is not present in the binary tree .....";

        return nullptr;
    }

    if(node_ptr->left_child == nullptr)
    {
        cout<<"ERROR - Invalid operation, given binary tree node does not contain inorder predecessor .....";

        return nullptr;
    }

    Node *inorder_predecessor {inorder_predecessor_binary_tree(node_ptr)};

    return inorder_predecessor;
}

int main()
{
    Binary_Tree T {};

    handle_create_binary_tree(&T, new int[3] {1, 2, 3}, 3);

    // handle_create_binary_tree(&T, new int[3] {1, INT_MIN, 3}, 3);

    // handle_create_binary_tree(&T, new int[11] {1, 2, 3, 4, 5, INT_MIN, INT_MIN, INT_MIN, INT_MIN, 6, 7}, 11);

    cout<<"inorder_predecessor_binary_tree(&T, 1): "<<handle_inorder_predecessor_binary_tree(&T, 1)->data<<"\n";

    return 0;
}