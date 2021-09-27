/*
Created by  : Vaisakh Dileep
Date        : 12, June, 2021
Description : This program searches for an element iteratively in a binary search tree.
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

Node* search_binary_search_tree(Binary_Search_Tree *T, int key)
{
    if(T == nullptr)
    {
        throw string {"ERROR - Invalid opeartion, binary search tree is not valid ....."};
    }

    Node *node {T->root};

    while(node != nullptr)
    {
        if(key == node->data)
        {
            return node;
        }
        else if(key < node->data)
        {
            node = node->left_child;
        }
        else if(key > node->data)
        {
            node = node->right_child;
        }
    }

    throw string {"ERROR - Invalid operation, key not present in the binary search tree ....."};
}

Node* handle_search_binary_search_tree(Binary_Search_Tree *T, int key)
{
    try
    {
        return search_binary_search_tree(T, key);
    }
    catch(string &ex)
    {
        cout<<ex;

        return nullptr;
    }
}

int main()
{
    Binary_Search_Tree T {};

    create_binary_search_tree(&T, new int[6] {7, 4, 6, 8, 9, 2}, 6);

    cout<<"handle_search_binary_search_tree(&T, 7): "<<handle_search_binary_search_tree(&T, 7)->data<<"\n";
    cout<<"handle_search_binary_search_tree(&T, 4): "<<handle_search_binary_search_tree(&T, 4)->data<<"\n";
    cout<<"handle_search_binary_search_tree(&T, 2): "<<handle_search_binary_search_tree(&T, 2)->data<<"\n";
    cout<<"handle_search_binary_search_tree(&T, 9): "<<handle_search_binary_search_tree(&T, 9)->data<<"\n";

    cout<<"handle_search_binary_search_tree(&T, 10): "<<handle_search_binary_search_tree(&T, 10)<<"\n\n";

    return 0;
}