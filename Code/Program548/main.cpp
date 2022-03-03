/*
Created by  : Vaisakh Dileep
Date        : 3, March, 2022
Description : This program finds the lowest common ancestor of two nodes in a binary tree(brute force approach).
*/

#include<iostream>

#include<vector>

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

bool extract_path_binary_tree(Node *current_node, vector<Node *> &path, Node *target)
{
    if(current_node == nullptr)
    {
        return false;
    }

    path.push_back(current_node);

    if(current_node == target)
    {
        return true;
    }

    if((extract_path_binary_tree(current_node->left_child, path, target) == true) or (extract_path_binary_tree(current_node->right_child, path, target) == true))
    {
        return true;
    }

    path.pop_back();

    return false;
}

Node* lowest_common_ancestor_binary_tree(Binary_Tree *T, Node *node_1, Node *node_2)
{
    if(T == nullptr)
    {
        throw string {"ERROR - Invalid operation, binary tree is not valid ....."};
    }

    if((node_1 == nullptr) or (node_2 == nullptr))
    {
        throw string {"ERROR - Invalid operation, one of the given nodes is not valid ....."};
    }

    vector<Node *> path_1 {}, path_2 {};

    if((extract_path_binary_tree(T->root, path_1, node_1) == false) or (extract_path_binary_tree(T->root, path_2, node_2) == false))
    {
        throw string {"ERROR - Invalid operation, one of the nodes is not present in the binary tree ....."};
    }

    int i {0};

    for(; i < path_1.size(); i++)
    {
        if(path_1[i] != path_2[i])
        {
            break;
        }
    }

    return path_1[i - 1];
}

Node* handle_lowest_common_ancestor_binary_tree(Binary_Tree *T, Node *node_1, Node *node_2)
{
    try
    {
        return lowest_common_ancestor_binary_tree(T, node_1, node_2);
    }
    catch(string &ex)
    {
        cout<<ex;

        return nullptr;
    }
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