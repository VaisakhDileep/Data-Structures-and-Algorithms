/*
Created by  : Vaisakh Dileep
Date        : 26, February, 2022
Description : This program checks if the given binary tree is a binary search tree(in-order traversal).
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

bool is_binary_search_tree(Node *current_node, Node **previous_node)
{
    if(current_node == nullptr)
    {
        return true;
    }

    if(previous_node == nullptr) // if "previous_node" is "nullptr" then we create a new pointer that will point to the previous Node in the inorder traversal.
    {
        previous_node = new Node* {nullptr}; // This line of code will only be executed once.
    }

    if(is_binary_search_tree(current_node->left_child, previous_node) == false)
    {
        return false;
    }

    if((*previous_node) != nullptr)
    {
        if(current_node->data <= (*previous_node)->data) // BST shouldn't contain duplicate elements as well.
        {
            return false;
        }
    }

    *previous_node = current_node;

    if(is_binary_search_tree(current_node->right_child, previous_node) == false)
    {
        return false;
    }

    return true;
}

bool handle_is_binary_search_tree(Binary_Tree *T)
{
    if(T == nullptr)
    {
        cout<<"ERROR - Invalid operation, binary tree is not valid .....";

        return false;
    }

    return is_binary_search_tree(T->root, nullptr);
}

int main()
{
    Binary_Tree T1 {}, T2 {};

    handle_create_binary_tree(&T1, new int[6] {10, 6, 15, 2, 8, 12}, 6);

    cout<<"is_binary_search_tree(T1): "<<handle_is_binary_search_tree(&T1)<<"\n";

    handle_create_binary_tree(&T2, new int[6] {10, 6, 15, 2, 11, 12}, 6);

    cout<<"is_binary_search_tree(T2): "<<handle_is_binary_search_tree(&T2)<<"\n";

    return 0;
}