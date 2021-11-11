/*
Created by  : Vaisakh Dileep
Date        : 21, October, 2021
Description : This program performs RL rotation in a binary tree.
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

// Inorder to understand how RL rotation works refer "Data Structures and Algorithms Manual 1" pg no:6.

Node* RL_rotation(Node *root, Node *p)
{
    if(root == nullptr)
    {
        throw string {"ERROR - Invalid operation, 'root' node cannot be null ....."};
    }

    if(p == nullptr)
    {
        throw string {"ERROR - Invalid operation, 'p' node cannot be null ....."};
    }

    if(p->right_child == nullptr)
    {
        throw string {"ERROR - Invalid operation, 'p' should have a right child ....."};
    }

    if(p->right_child->left_child == nullptr)
    {
        throw string {"ERROR - Invalid operation, right child of 'p' should have a left child ....."};
    }

    Node *p_right {p->right_child};

    Node *p_right_left {p_right->left_child};

    p_right->left_child = p_right_left->right_child;

    p->right_child = p_right_left->left_child;

    p_right_left->left_child = p;

    p_right_left->right_child = p_right;

    if(root == p)
    {
        root = p_right_left;
    }

    return p_right_left; // We will return the new root of the subtree.
}

Node* handle_RL_rotation(Node *root, Node *p)
{
    try
    {
        return RL_rotation(root, p);
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
    \
     \
     '2'
     /
    /
  '3'
*/

    T.root = new Node {nullptr, 1, nullptr};

    T.root->right_child = new Node {nullptr, 2, nullptr};

    T.root->right_child->left_child = new Node {nullptr,3, nullptr};

    T.root = handle_RL_rotation(T.root, T.root);

/*
T[after rotation]:
        '3'
        / \
       /   \
     '1'   '2'
*/

    return 0;
}