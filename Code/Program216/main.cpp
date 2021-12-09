/*
Created by  : Vaisakh Dileep
Date        : 9, June, 2021
Description : This program displays a binary tree using post-order traversal using stack.
*/

#include<iostream>

#include<stack>

using namespace std;

struct Node
{
    Node *left_child;

    int data;

    int count {0}; // This will check if the node is visited or not.

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
        *node = new Node {nullptr, A[i], 0, nullptr};

        create_binary_tree(&((*node)->left_child), (2 * (i + 1)) - 1, A, size);

        create_binary_tree(&((*node)->right_child), 2 * (i + 1), A, size);
    }
}

void handle_create_binary_tree(Binary_Tree *T, int *A, int size)
{
    create_binary_tree(&(T->root), 0, A, size);
}

void display_binary_tree(Binary_Tree *T) // post-order traversal
{
    if(T == nullptr)
    {
        return ;
    }

    stack<Node *> stk {};

    Node *node {T->root};

    while((node != nullptr) or (!stk.empty()))
    {
        if(node != nullptr)
        {
            stk.push(node); // 1st time in stack(for checking left sub-tree).

            node = node->left_child;
        }
        else
        {
            Node *temp {stk.top()};

            stk.pop();

            if(temp->count == 0) // if the node is unvisited(2nd time in stack(for checking right sub-tree)), then we will push it into the stack and mark it as visited.
            {
                temp->count++;

                stk.push(temp);

                node = temp->right_child;
            }
            else // if the node is already visited(finished checking left sub-tree and right sub-tree), then we print it.
            {
                cout<<temp->data<<" ";

                temp->count = 0;
            }
        }
    }
}

int main()
{
    Binary_Tree T {};

    handle_create_binary_tree(&T, new int[6] {1, 2, 3, INT_MIN, 4, 5}, 6);

    cout<<"T[post-order]: ";
    display_binary_tree(&T);
    cout<<"\n";

    return 0;
}