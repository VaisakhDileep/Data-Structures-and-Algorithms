/*
Created by  : Vaisakh Dileep
Date        : 2, March, 2022
Description : This program finds the path of a node if it exists in a binary tree.
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

vector<Node *> handle_extract_path_binary_tree(Binary_Tree *T, Node *target)
{
    if(T == nullptr)
    {
        cout<<"ERROR - Invalid operation, binary tree is not valid .....";

        return vector<Node *> {};
    }

    vector<Node *> path {};

    if(extract_path_binary_tree(T->root, path, target) == true)
    {
        return path;
    }
    else
    {
        cout<<"ERROR - Invalid operation, target node not present in the binary tree .....";

        return vector<Node *> {};
    }
}

void display_path_binary_tree(vector<Node *> &path)
{
    for(int i {0}; i < path.size(); i++)
    {
        cout<<path[i]->data<<" ";
    }
}

int main()
{
    Binary_Tree T {};

    T.root = new Node {new Node {new Node {nullptr, 4, new Node {new Node {nullptr, 6, nullptr}, 5, new Node {nullptr, 7, nullptr}}}, 2, nullptr}, 1, new Node {nullptr, 3, nullptr}};

    Node *target {T.root->left_child->left_child->right_child->right_child};

    vector<Node *> path {handle_extract_path_binary_tree(&T, target)};

    cout<<"path(trying to find a valid path): ";
    display_path_binary_tree(path);
    cout<<"\n";

    cout<<"path(trying to find an invalid path): ";

    path = handle_extract_path_binary_tree(&T, new Node {nullptr, 10, nullptr}); // This will give an exception since the node does not exist in the binary tree.

    return 0;
}