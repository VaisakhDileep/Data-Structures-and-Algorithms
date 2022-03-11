/*
Created by  : Vaisakh Dileep
Date        : 9, June, 2021
Description : This program creates a binary tree from user using queue.
*/

#include<iostream>

#include<queue>

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

void create_binary_tree(Binary_Tree *T)
{
    if(T == nullptr)
    {
        throw string {"ERROR - Invalid operation, binary tree is not valid ....."};
    }

    int value {};

    queue<Node *> Q {};

    cout<<"Enter root value: ";

    cin>>value;

    T->root = new Node {nullptr, value, nullptr};

    Q.push(T->root);

    Node *popped_node {};

    while(!Q.empty())
    {
        popped_node = Q.front();

        Q.pop();

        cout<<"Enter left child for "<<popped_node->data<<": ";

        cin>>value;

// Enter "-2147483648" for empty node.

        if(value != -2147483648)
        {
            Node *temp {new Node {nullptr, value, nullptr}};

            popped_node->left_child = temp;

            Q.push(temp);
        }

        cout<<"Enter right child for "<<popped_node->data<<": ";

        cin>>value;

        if(value != -2147483648)
        {
            Node *temp {new Node {nullptr, value, nullptr}};

            popped_node->right_child = temp;

            Q.push(temp);
        }
    }
}

void handle_create_binary_tree(Binary_Tree *T)
{
    try
    {
        create_binary_tree(T);
    }
    catch(string &ex)
    {
        cout<<ex;
    }
}

int main()
{
    Binary_Tree T {};

    handle_create_binary_tree(&T);

    return 0;
}