/*
Created by  : Vaisakh Dileep
Date        : 11, March, 2022
Description : Defintion file for binary_tree_using_linked_list.
*/

#include "binary_tree_using_linked_list.hpp"

#include<iostream>

using namespace std;

void BTLL::create_binary_tree(Node **node, int i, int *A, int size)
{
    if((i < size) and (A[i] != INT_MIN))
    {
        *node = new Node {nullptr, A[i], nullptr};

        create_binary_tree(&((*node)->left_child), (2 * (i + 1)) - 1, A, size);

        create_binary_tree(&((*node)->right_child), 2 * (i + 1), A, size);
    }
}

void BTLL::handle_create_binary_tree(Binary_Tree *T, int *A, int size)
{
    create_binary_tree(&(T->root), 0, A, size);
}

BTLL::Node* BTLL::search_binary_tree(Node *node, int target)
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

BTLL::Node* BTLL::handle_search_binary_tree(Binary_Tree *T, int target)
{
    if(T == nullptr)
    {
        cout<<"ERROR - Invalid operation, binary tree is not valid .....";

        return nullptr;
    }
    else if(T->root == nullptr)
    {
        cout<<"ERROR - Invalid operation, binary tree is empty .....";

        return nullptr;
    }

    Node *result {search_binary_tree(T->root, target)};

    if(result != nullptr)
    {
        return result;
    }
    else
    {
        cout<<"ERROR - Invalid operation, key not present in the binary tree .....";

        return nullptr;
    }
}
