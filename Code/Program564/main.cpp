/*
Created by  : Vaisakh Dileep
Date        : 7, March, 2022
Description : This program extracts all the nodes that are at 'k' distance from the root.
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

// Note: Distance from the root is calculated by counting the number of edges from the root.

void extract_nodes_k_distance_from_root_binary_tree(Node *current_node, int current_level, vector<Node *> &nodes_array)
{
    if(current_node == nullptr)
    {
        return ;
    }

    if(current_level < 0) // If we go deeper than 'k'.
    {
        return ;
    }

    if(current_level == 0)
    {
        nodes_array.push_back(current_node);

        return ;
    }

    extract_nodes_k_distance_from_root_binary_tree(current_node->left_child, current_level - 1, nodes_array);

    extract_nodes_k_distance_from_root_binary_tree(current_node->right_child, current_level - 1, nodes_array);
}

vector<Node *> handle_extract_nodes_k_distance_from_root_binary_tree(Binary_Tree *T, int k)
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

    vector<Node *> nodes_array {};

    extract_nodes_k_distance_from_root_binary_tree(T->root, k, nodes_array);

    return nodes_array;
}

void display_nodes_array(vector<Node *> &nodes_array)
{
    for(int i {0}; i < nodes_array.size(); i++)
    {
        cout<<nodes_array[i]->data<<" ";
    }
}

int main()
{
    Binary_Tree T {};

    handle_create_binary_tree(&T, new int[15] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}, 15);

    vector<Node *> nodes_array {};

    nodes_array = handle_extract_nodes_k_distance_from_root_binary_tree(&T, 3);

    cout<<"handle_extract_nodes_k_distance_from_root_binary_tree(T, 3): ";
    display_nodes_array(nodes_array);
    cout<<"\n";

    nodes_array = handle_extract_nodes_k_distance_from_root_binary_tree(&T, 2);

    cout<<"handle_extract_nodes_k_distance_from_root_binary_tree(T, 2): ";
    display_nodes_array(nodes_array);
    cout<<"\n";

    nodes_array = handle_extract_nodes_k_distance_from_root_binary_tree(&T, 1);

    cout<<"handle_extract_nodes_k_distance_from_root_binary_tree(T, 1): ";
    display_nodes_array(nodes_array);
    cout<<"\n";

    nodes_array = handle_extract_nodes_k_distance_from_root_binary_tree(&T, 0);

    cout<<"handle_extract_nodes_k_distance_from_root_binary_tree(T, 0): ";
    display_nodes_array(nodes_array);
    cout<<"\n";

    return 0;
}