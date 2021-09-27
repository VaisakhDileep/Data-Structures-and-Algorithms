/*
Created by  : Vaisakh Dileep
Date        : 4, September, 2021
Description : This program constructs a binary tree from the in-order + post-order traversals.
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
        display_binary_tree(T->root);
    }
};

namespace Binary_Tree_Post_Order_Display
{
    void display_binary_tree(Node *node) // post-order traversal
    {
        if(node != nullptr)
        {
            display_binary_tree(node->left_child);

            display_binary_tree(node->right_child);

            cout<<node->data<<" ";
        }
    }

    void handle_display_binary_tree(Binary_Tree *T)
    {
        display_binary_tree(T->root);
    }
};

void construct_binary_tree(Node **node, vector<int> *in_order, vector<int> *post_order, int &post_order_index, int start, int end) // Construct tree from in-order + post-order traversal.
{
    if(start > end)
    {
        *node = nullptr;

        return ;
    }

    int current_node {post_order->at(post_order_index--)};

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

    construct_binary_tree(&((*node)->right_child), in_order, post_order, post_order_index, root + 1, end); // Make sure to traverse right sub tree first.

    construct_binary_tree(&((*node)->left_child), in_order, post_order, post_order_index, start, root - 1);
}

Binary_Tree* handle_construct_binary_tree(vector<int> *in_order, vector<int> *post_order)
{
    if(in_order == nullptr)
    {
        cout<<"ERROR - Invalid operation, in-order traversal is not valid .....";

        return nullptr;
    }

    if(post_order == nullptr)
    {
        cout<<"ERROR - Invalid operation, post-order traversal is not valid .....";

        return nullptr;
    }

    vector<int> in_order_temp {*in_order}, post_order_temp {*post_order};

    sort(in_order_temp.begin(), in_order_temp.end());

    sort(post_order_temp.begin(), post_order_temp.end());

    if((in_order->size() != post_order->size()) or (in_order_temp != post_order_temp))
    {
        cout<<"ERROR - Invalid operation, in-order traversal and post-order traversal do not match .....";

        return nullptr;
    }

    Binary_Tree *binary_tree {new Binary_Tree {}};

    int post_order_index {post_order->size() - 1}; // Since we are passing by reference.

    construct_binary_tree(&binary_tree->root, in_order, post_order, post_order_index, 0, post_order->size() - 1);

    return binary_tree;
}

int main()
{
    Binary_Tree *T {};

    vector<int> *in_order {new vector<int> {3, 1, 0, 5, 6, 4, 2}}, *post_order {new vector<int> {3, 1, 6, 5, 4, 2, 0}};

    T = handle_construct_binary_tree(in_order, post_order);

    cout<<"inorder_display(T): "; // in-order traversal to verify.
    Binary_Tree_In_Order_Display::handle_display_binary_tree(T);
    cout<<"\n";

    cout<<"postorder_display(T: "; // post-order traversal to verify.
    Binary_Tree_Post_Order_Display::handle_display_binary_tree(T);
    cout<<"\n";

    return 0;
}