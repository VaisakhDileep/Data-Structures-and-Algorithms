/*
Created by  : Vaisakh Dileep
Date        : 9, December, 2021
Description : This program displays a binary tree using Morris pre-order traversal.
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

void display_binary_tree(Binary_Tree *T) // Morris pre-order traversal
{
// Morris pre-order traversal will allow use to traverse the binary tree without using stack or recursion(recursion internally uses stack).

    if(T == nullptr)
    {
        return ;
    }

    Node *current_node {T->root};

    while(current_node != nullptr)
    {
        if(current_node->left_child == nullptr) // If "current_node" does not have a left child, then we can print it's value and proceed exploring it's right sub-tree.
        {
            cout<<current_node->data<<" ";

            current_node = current_node->right_child;
        }
        else
        {
            Node *inorder_predecessor {current_node->left_child};

            while((inorder_predecessor->right_child != nullptr) and (inorder_predecessor->right_child != current_node))
            {
                inorder_predecessor = inorder_predecessor->right_child;
            }

            if(inorder_predecessor->right_child == nullptr) // "inorder_predecessor" is valid. We print the current_node's value and proceed exploring it's left sub-tree.
            {
                cout<<current_node->data<<" ";

                inorder_predecessor->right_child = current_node; // This way we can come back to "current_node" later to explore it's right sub-tree.

                current_node = current_node->left_child;
            }
            else // "inorder_predecessor" is not valid.
            {
                inorder_predecessor->right_child = nullptr; // This will remove the thread that was assigned earlier.

                current_node = current_node->right_child;
            }
        }
    }
}

int main()
{
    Binary_Tree T {};

    handle_create_binary_tree(&T, new int[6] {1, 2, 3, INT_MIN, 4, 5}, 6);

    cout<<"T[pre-order]: ";
    display_binary_tree(&T);
    cout<<"\n";

    return 0;
}