/*
Created by  : Vaisakh Dileep
Date        : 23, September, 2021
Description : This program checks if the given binary search tree is height balanced(O(n) solution).
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

bool is_height_balanced_binary_search_tree(Node *root, int &height)
{
    if(root == nullptr)
    {
        return true;
    }

    int left_height {0}, right_height {0};

    if(is_height_balanced_binary_search_tree(root->left_child, left_height) == false)
    {
        return false;
    }

    if(is_height_balanced_binary_search_tree(root->right_child, right_height) == false)
    {
        return false;
    }

    height = max(left_height, right_height) + 1;

    if(abs(left_height - right_height) <= 1)
    {
        return true;
    }

    return false;
}

bool handle_is_height_balanced_binary_search_tree(Binary_Search_Tree *T)
{
    if(T == nullptr)
    {
        cout<<"ERROR - Invalid operation, binary search tree is not valid .....";

        return false;
    }
    else if(T->root == nullptr)
    {
        return true;
    }

    int height {};

    return is_height_balanced_binary_search_tree(T->root, height);
}

int main()
{
    Binary_Search_Tree T {};

    // create_binary_search_tree(&T, new int[4] {10, 7, 15, 11}, 4); // This test case is height-balanced.

    create_binary_search_tree(&T, new int[5] {10, 7, 15, 13, 12}, 5); // This test case is not height-balanced.

    cout<<"handle_is_height_balanced_binary_search_tree(T): "<<handle_is_height_balanced_binary_search_tree(&T)<<"\n";

    return 0;
}