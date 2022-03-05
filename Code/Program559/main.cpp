/*
Created by  : Vaisakh Dileep
Date        : 5, March, 2022
Description : This program finds all the nodes in a binary tree that do not have a sibling.
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

void create_binary_tree(Node **node, int i, int *A, int size)
{
    if((i < size) and (A[i] != INT_MIN))
    {
        *node = new Node {nullptr, A[i], nullptr};

        create_binary_tree(&((*node)->left_child), (2 * (i + 1)) - 1, A, size);

        create_binary_tree(&((*node)->right_child), 2 * (i + 1), A, size);
    }
}

void handle_create_binary_tree(Binary_Tree *T, int *A, int size)
{
    create_binary_tree(&(T->root), 0, A, size);
}

void extract_nodes_without_siblings(Node *current_node, vector<Node *> &nodes_without_siblings)
{
    if((current_node->left_child != nullptr) and (current_node->right_child != nullptr))
    {
        extract_nodes_without_siblings(current_node->left_child, nodes_without_siblings);

        extract_nodes_without_siblings(current_node->right_child, nodes_without_siblings);

        return ;
    }

    if(current_node->left_child != nullptr)
    {
        nodes_without_siblings.push_back(current_node->left_child);

        extract_nodes_without_siblings(current_node->left_child, nodes_without_siblings);
    }

    if(current_node->right_child != nullptr)
    {
        nodes_without_siblings.push_back(current_node->right_child);

        extract_nodes_without_siblings(current_node->right_child, nodes_without_siblings);
    }
}

vector<Node *> handle_extract_nodes_without_siblings(Binary_Tree *T)
{
    if(T == nullptr)
    {
        cout<<"ERROR - Invalid operation, binary tree is not valid .....";

        return vector<Node *> {};
    }

    if(T->root == nullptr)
    {
        cout<<"ERROR - Invalid operation, binary tree is empty .....";

        return vector<Node *> {};
    }

    vector<Node *> nodes_without_siblings {};

    extract_nodes_without_siblings(T->root, nodes_without_siblings);

    return nodes_without_siblings;
}

void display_nodes_without_siblings(vector<Node *> &nodes_without_siblings)
{
    for(int i {0}; i < nodes_without_siblings.size(); i++)
    {
        cout<<nodes_without_siblings[i]->data<<" ";
    }
}

int main()
{
    Binary_Tree T1 {};

    T1.root = new Node {new Node {new Node {nullptr, 4, nullptr}, 2, new Node {new Node {new Node {nullptr, 7, nullptr}, 6, new Node {nullptr, 8, nullptr}}, 5, nullptr}}, 1, new Node {nullptr, 3, nullptr}};

    vector<Node *> nodes_without_siblings {};

    nodes_without_siblings = handle_extract_nodes_without_siblings(&T1);

    cout<<"extract_nodes_without_siblings([the test case has nodes that does not contain siblings]): ";
    display_nodes_without_siblings(nodes_without_siblings);
    cout<<"\n";

    Binary_Tree T2 {};

    T2.root = new Node {new Node {new Node {nullptr, 4, nullptr}, 2, new Node {new Node {nullptr, 6, nullptr}, 5, new Node {nullptr, 7, nullptr}}}, 1, new Node {nullptr, 3, nullptr}};

    nodes_without_siblings = handle_extract_nodes_without_siblings(&T2);

    cout<<"extract_nodes_without_siblings([all the nodes in the test case has a sibling]): ";
    display_nodes_without_siblings(nodes_without_siblings);
    cout<<"\n";

    return 0;
}