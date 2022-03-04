/*
Created by  : Vaisakh Dileep
Date        : 4, March, 2022
Description : This program performs reversed in-order traversal on a binary search tree.
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

void display_binary_search_tree(Node *node) // reversed in-order traversal
{
    if(node != nullptr)
    {
        display_binary_search_tree(node->right_child);

        cout<<node->data<<" ";

        display_binary_search_tree(node->left_child);
    }
}

void handle_display_binary_search_tree(Binary_Search_Tree *T)
{
    if(T == nullptr)
    {
        return ;
    }

    display_binary_search_tree(T->root);
}

int main()
{
    Binary_Search_Tree T {};

    create_binary_search_tree(&T, new int[8] {9, 7, 10, 3, 8, 1, 15, 11}, 8);

    cout<<"T[reversed in-order traversal]: ";
    handle_display_binary_search_tree(&T);
    cout<<"\n";

    return 0;
}