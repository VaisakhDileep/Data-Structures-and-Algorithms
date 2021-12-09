/*
Created by  : Vaisakh Dileep
Date        : 4, September, 2021
Description : This program constructs a binary tree from the in-order + pre-order traversals.
*/

#include<iostream>

#include<vector>

#include<algorithm>

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

namespace Binary_Tree_In_Order_Display
{
    void display_binary_tree(Node *node) // in-order traversal
    {
        if(node != nullptr)
        {
            display_binary_tree(node->left_child);

            cout<<node->data<<" ";

            display_binary_tree(node->right_child);
        }
    }

    void handle_display_binary_tree(Binary_Tree *T)
    {
        if(T == nullptr)
        {
            return ;
        }

        display_binary_tree(T->root);
    }
}

namespace Binary_Tree_Pre_Order_Display
{
    void display_binary_tree(Node *node) // pre-order traversal
    {
        if(node != nullptr)
        {
            cout<<node->data<<" ";

            display_binary_tree(node->left_child);

            display_binary_tree(node->right_child);
        }
    }

    void handle_display_binary_tree(Binary_Tree *T)
    {
        if(T == nullptr)
        {
            return ;
        }

        display_binary_tree(T->root);
    }
}

void construct_binary_tree(Node **node, vector<int> *in_order, vector<int> *pre_order, int &pre_order_index, int start, int end) // Construct tree from in-order + pre-order traversal.
{
    if(start > end)
    {
        *node = nullptr;

        return ;
    }

    int current_node {pre_order->at(pre_order_index++)};

    if(start == end)
    {
        *node = new Node {nullptr, current_node, nullptr};

        return ;
    }

    int root {0};

    for(int i {start}; i <= end; i++)
    {
        if(in_order->at(i) == current_node)
        {
            root = i;

            break;
        }
    }

    *node = new Node {nullptr, current_node, nullptr};

    construct_binary_tree(&((*node)->left_child), in_order, pre_order, pre_order_index, start, root - 1); // Make sure to traverse left sub tree first.

    construct_binary_tree(&((*node)->right_child), in_order, pre_order, pre_order_index, root + 1, end);
}

Binary_Tree* handle_construct_binary_tree(vector<int> *in_order, vector<int> *pre_order)
{
    if(in_order == nullptr)
    {
        cout<<"ERROR - Invalid operation, in-order traversal is not valid .....";

        return nullptr;
    }

    if(pre_order == nullptr)
    {
        cout<<"ERROR - Invalid operation, pre-order traversal is not valid .....";

        return nullptr;
    }

    vector<int> in_order_temp {*in_order}, pre_order_temp {*pre_order};

    sort(in_order_temp.begin(), in_order_temp.end());

    sort(pre_order_temp.begin(), pre_order_temp.end());

    if((in_order->size() != pre_order->size()) or (in_order_temp != pre_order_temp))
    {
        cout<<"ERROR - Invalid operation, in-order traversal and pre-order traversal do not match .....";

        return nullptr;
    }

    Binary_Tree *binary_tree {new Binary_Tree {}};

    int pre_order_index {0}; // Since we are passing by reference.

    construct_binary_tree(&binary_tree->root, in_order, pre_order, pre_order_index, 0, pre_order->size() - 1);

    return binary_tree;
}

int main()
{
    Binary_Tree *T {};

    vector<int> *in_order {new vector<int> {1, 0, 4, 3, 5, 2}}, *pre_order {new vector<int> {0, 1, 2, 3, 4, 5}};

    T = handle_construct_binary_tree(in_order, pre_order);

    cout<<"inorder_display(T): "; // in-order traversal to verify.
    Binary_Tree_In_Order_Display::handle_display_binary_tree(T);
    cout<<"\n";

    cout<<"preorder_display(T): "; // post-order traversal to verify.
    Binary_Tree_Pre_Order_Display::handle_display_binary_tree(T);
    cout<<"\n";

    return 0;
}