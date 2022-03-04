/*
Created by  : Vaisakh Dileep
Date        : 4, March, 2022
Description : This program finds the k-th smallest element in a binary search tree(O(n) space O(n) time solution).
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

void create_binary_search_tree(Binary_Search_Tree *T, int *A, int size)
{
    for(int i {0}; i < size; i++)
    {
        try
        {
            insert_binary_search_tree(T, A[i]);
        }
        catch(string &ex)
        {
            if(ex == "ERROR - Invalid operation, value already present in the binary search tree .....")
            {
                cout<<"ERROR - Invalid operation, "<<A[i]<<" cannot be inserted in the binary search tree .....\n";
            }
            else if(ex == "ERROR - Invalid operation, binary search tree is not valid .....")
            {
                cout<<ex;

                return ;
            }
        }
    }
}

int main()
{
    return 0;
}