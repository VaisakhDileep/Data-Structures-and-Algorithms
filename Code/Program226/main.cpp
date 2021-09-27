/*
Created by  : Vaisakh Dileep
Date        : 11, June, 2021
Description : This program inserts an element iteratively to a binary search tree.
*/

#include<iostream>

using namespace std;

struct Node
{
    Node *left_child;

    int data;

    Node *right_child;
};

struct Binary_Search_Tree
{
    Node *root;
};

void insert_binary_search_tree(Binary_Search_Tree *T, int value)
{
    if(T == nullptr)
    {
        throw string {"ERROR - Invalid operation, binary search tree is not valid ....."};
    }

    if(T->root == nullptr)
    {
        T->root = new Node {nullptr, value, nullptr};

        return ;
    }

    Node *node {T->root}, *previous_node {};

    while(node != nullptr)
    {
        previous_node = node;

        if(value == node->data)
        {
            throw string {"ERROR - Invalid operation, value already present in the binary search tree ....."};
        }
        else if(value > node->data)
        {
            node = node->right_child;
        }
        else if(value < node->data)
        {
            node = node->left_child;
        }
    }

    if(value < previous_node->data)
    {
        previous_node->left_child = new Node {nullptr, value, nullptr};
    }
    else
    {
        previous_node->right_child = new Node {nullptr, value, nullptr};
    }
}

void handle_insert_binary_search_tree(Binary_Search_Tree *T, int value)
{
    try
    {
        insert_binary_search_tree(T, value);
    }
    catch(string &ex)
    {
        cout<<ex;
    }
}

int main()
{
    Binary_Search_Tree T1 {};

    handle_insert_binary_search_tree(&T1, 1); // We can create a binary search tree from scratch like this.
    handle_insert_binary_search_tree(&T1, 4);
    handle_insert_binary_search_tree(&T1, 5);
    handle_insert_binary_search_tree(&T1, 3);

    handle_insert_binary_search_tree(&T1, 4);
    cout<<"\n";

    return 0;
}