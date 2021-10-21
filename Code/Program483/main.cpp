/*
Created by  : Vaisakh Dileep
Date        : 20, October, 2021
Description : This program performs LR rotation in a binary tree.
*/

// Note: All rotations are designed to work with binary-search tree as well, I used binary tree only to demonstrate.

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

// Inorder to understand how LR rotation works check "Program483/whiteboard_6.pdf".

Node* LR_rotation(Node *root, Node *p)
{
    if(root == nullptr)
    {
        throw string {"ERROR - Invalid operation, 'root' node cannot be null ....."};
    }

    if(p == nullptr)
    {
        throw string {"ERROR - Invalid operation, 'p' node cannot be null ....."};
    }

    if(p->left_child == nullptr)
    {
        throw string {"ERROR - Invalid operation, 'p' should have a left child ....."};
    }

    if(p->left_child->right_child == nullptr)
    {
        throw string {"ERROR - Invalid opeartion, left child of 'p' should have a right child ....."};
    }

    Node *p_left {p->left_child};

    Node *p_left_right {p_left->right_child};

    p_left->right_child = p_left_right->left_child;

    p->left_child = p_left_right->right_child;

    p_left_right->left_child = p_left;

    p_left_right->right_child = p;

    if(root == p)
    {
        root = p_left_right;
    }

    return p_left_right; // We will return the new root of the subtree.
}

Node* handle_LR_rotation(Node *root, Node *p)
{
    try
    {
        return LR_rotation(root, p);
    }
    catch(string &ex)
    {
        cout<<ex;

        return nullptr;
    }
}

int main()
{
    Binary_Tree T {};

/*
T[before rotation]:
        '1'
        /
       /
     '2'
       \
        \
        '3'
*/

    T.root = new Node {nullptr, 1, nullptr};

    T.root->left_child = new Node {nullptr, 2, nullptr};

    T.root->left_child->right_child = new Node {nullptr, 3, nullptr};

    T.root = handle_LR_rotation(T.root, T.root);

/*
T[after rotation]:
        '3'
        / \
       /   \
     '2'   '1'
*/

    return 0;
}