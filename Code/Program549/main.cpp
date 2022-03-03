/*
Created by  : Vaisakh Dileep
Date        : 3, March, 2022
Description : This program finds the lowest common ancestor of two nodes in a binary tree(one traversal no extra space approach).
*/

#include<iostream>

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

Node *lowest_common_ancestor_binary_tree(Node *current_node, Node *node_1, Node *node_2, bool &found_node_1, bool &found_node_2)
{
    if(current_node == nullptr)
    {
        return nullptr;
    }

    if(current_node == node_1)
    {
        found_node_1 = true;

        return current_node;
    }

    if(current_node == node_2)
    {
        found_node_2 = true;

        return current_node;
    }

    Node *left_result {}, *right_result {};

    left_result = lowest_common_ancestor_binary_tree(current_node->left_child, node_1, node_2, found_node_1, found_node_2);

    right_result = lowest_common_ancestor_binary_tree(current_node->right_child, node_1, node_2, found_node_1, found_node_2);

    if((left_result != nullptr) and (right_result != nullptr))
    {
        return current_node;
    }

    if(left_result != nullptr)
    {
        return left_result;
    }
    else if(right_result != nullptr)
    {
        return right_result;
    }

    return nullptr;
}

Node *handle_lowest_common_ancestor_binary_tree(Binary_Tree *T, Node *node_1, Node *node_2)
{
    if(T == nullptr)
    {
        cout<<"ERROR - Invalid operation, binary tree is not valid .....";

        return nullptr;
    }

    if((node_1 == nullptr) or (node_2 == nullptr))
    {
        cout<<"ERROR - Invalid operation, one of the given nodes in not valid .....";

        return nullptr;
    }

    bool found_node_1 {false}, found_node_2 {false};

    Node *LCA {lowest_common_ancestor_binary_tree(T->root, node_1, node_2, found_node_1, found_node_2)};

    if((found_node_1 == false) or (found_node_2 == false))
    {
        cout<<"ERROR - Invalid operation, one of the nodes is not present in the binary tree .....";

        return nullptr;
    }

    return LCA;
}

int main()
{
    Binary_Tree T {};

    T.root = new Node {new Node {new Node {nullptr, 4, new Node {new Node {nullptr, 6, nullptr}, 5, new Node {nullptr, 7, nullptr}}}, 2, new Node {new Node {nullptr, 9, nullptr}, 8, nullptr}}, 1, new Node {nullptr, 3, nullptr}};

    Node *node_1 {T.root->left_child->left_child->right_child->right_child};

    Node *node_2 {T.root->left_child->right_child->left_child};

    Node *LCA {handle_lowest_common_ancestor_binary_tree(&T, node_1, node_2)}; // "LCA" stands for "Lowest Common Ancestor"

    cout<<"LCA(trying to find a valid LCA): "<<LCA->data<<"\n";

    cout<<"LCA(trying to find an invalid LCA): ";

    LCA = handle_lowest_common_ancestor_binary_tree(&T, node_1, new Node {nullptr, 11, nullptr});

    cout<<"\n";
    cout<<"LCA(trying to find an invalid LCA): ";

    LCA = handle_lowest_common_ancestor_binary_tree(&T, node_1, nullptr);

    return 0;
}