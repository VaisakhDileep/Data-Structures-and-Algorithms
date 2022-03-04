/*
Created by  : Vaisakh Dileep
Date        : 4, March, 2022
Description : This program displays a binary tree using reversed level-order traversal.
*/

#include<iostream>

#include<queue>

#include<stack>

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

// Inorder to understand how reversed level-order traversal works refer "Data Structures and Algorithms Manual 1" pg no:15.

void display_binary_tree(Binary_Tree *T) // reversed level-order traversal
{
    if((T == nullptr) or (T->root == nullptr))
    {
        return ;
    }

    queue<Node *> Q {};

    stack<int> stk {};

    stk.push(T->root->data);

    Q.push(T->root);

    Node *node {};

    while(Q.empty() == false)
    {
        node = Q.front();

        Q.pop();

        if(node->right_child != nullptr) // Inorder to preserve the ordering from left to right in each level, we input the right child first in the stack.
        {
            stk.push(node->right_child->data);

            Q.push(node->right_child);
        }

        if(node->left_child != nullptr)
        {
            stk.push(node->left_child->data);

            Q.push(node->left_child);
        }
    }

    while(stk.empty() == false)
    {
        cout<<stk.top()<<" ";

        stk.pop();
    }
}

int main()
{
    Binary_Tree T {};

    handle_create_binary_tree(&T, new int[6] {1, 2, 3, INT_MIN, 4, 5}, 6);

    cout<<"T[level-order]: ";
    display_binary_tree(&T);
    cout<<"\n";

    return 0;
}