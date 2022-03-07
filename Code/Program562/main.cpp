/*
Created by  : Vaisakh Dileep
Date        : 6, March, 2022
Description : This program finds all the cousins of a given node in a binary tree.
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

int level_of_node_in_binary_tree(Node *current_node, Node *node, int level = 0) // In this implementation "level" is found by counting the number of edges(level indexing starts from '0').
{
    if(current_node == nullptr)
    {
        return INT_MIN;
    }

    if(current_node == node)
    {
        return level;
    }

    int result_left_branch {level_of_node_in_binary_tree(current_node->left_child, node, level + 1)};

    if(result_left_branch != INT_MIN)
    {
        return result_left_branch;
    }

    int result_right_branch {level_of_node_in_binary_tree(current_node->right_child, node, level + 1)};

    if(result_right_branch != INT_MIN)
    {
        return result_right_branch;
    }

    return INT_MIN;
}

void extract_cousins_from_given_level_in_binary_tree(Node *node, Node *target_node, vector<Node *> &cousin_nodes, int current_level)
{
    if(node == nullptr)
    {
        return ;
    }

    if(current_level == 0) // "current_level == 0" happens when we reach the last level.
    {
        return ;
    }
    else if(current_level == 1) // "current_level == 1" happens when we have the reached the level just above the last level.
    {
        if((node->left_child == target_node) or (node->right_child == target_node))
        {
            return ;
        }
        else
        {
            cousin_nodes.push_back(node->left_child);

            cousin_nodes.push_back(node->right_child);
        }
    }
    else if(current_level > 1)
    {
        extract_cousins_from_given_level_in_binary_tree(node->left_child, target_node, cousin_nodes, current_level - 1);

        extract_cousins_from_given_level_in_binary_tree(node->right_child, target_node, cousin_nodes, current_level - 1);
    }
}

vector<Node *> extract_cousins_of_given_node_in_binary_tree(Binary_Tree *T, Node *node)
{
    if(T == nullptr)
    {
        throw string {"ERROR - Invalid operation, binary tree is not valid ....."};
    }

    if(T->root == nullptr)
    {
        throw string {"ERROR - Invalid operation, binary tree is empty ....."};
    }

    if(node == nullptr)
    {
        throw string {"ERROR - Invalid operation, given node is not valid ....."};
    }

    int node_level {level_of_node_in_binary_tree(T->root, node)};

    if(node_level == INT_MIN)
    {
        throw string {"ERROR - Invalid operation, given node is not present in the binary tree ....."};
    }

    vector<Node *> cousin_nodes {};

    extract_cousins_from_given_level_in_binary_tree(T->root, node, cousin_nodes, node_level);

    return cousin_nodes;
}

vector<Node *> handle_extract_cousins_of_given_node_in_binary_tree(Binary_Tree *T, Node *node)
{
    try
    {
        return extract_cousins_of_given_node_in_binary_tree(T, node);
    }
    catch(string &ex)
    {
        cout<<ex;

        return vector<Node *> {};
    }
}

void display_cousin_nodes_of_given_node(Node *target_node, vector<Node *> cousin_nodes)
{
    cout<<(target_node->data)<<" -> ";

    for(int i {0}; i < cousin_nodes.size(); i++)
    {
        cout<<cousin_nodes[i]->data<<" ";
    }
}

int main()
{
    Binary_Tree T {};

    handle_create_binary_tree(&T, new int[15] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}, 15);

    vector<Node *> cousin_nodes {};

    Node *target_node {T.root->left_child->left_child};

    cousin_nodes = handle_extract_cousins_of_given_node_in_binary_tree(&T, target_node);

    cout<<"extract_cousins_of_given_node_in_binary_tree([the test case node does contain cousins]): ";
    display_cousin_nodes_of_given_node(target_node, cousin_nodes);
    cout<<"\n";

    target_node = T.root->left_child->left_child->left_child;

    cousin_nodes = handle_extract_cousins_of_given_node_in_binary_tree(&T, target_node);

    cout<<"extract_cousins_of_given_node_in_binary_tree([the test case node does contain cousins]): ";
    display_cousin_nodes_of_given_node(target_node, cousin_nodes);
    cout<<"\n\n";

    target_node = T.root->left_child;

    cousin_nodes = handle_extract_cousins_of_given_node_in_binary_tree(&T, target_node);

    cout<<"extract_cousins_of_given_node_in_binary_tree([the test case node does not contain cousins]): ";
    display_cousin_nodes_of_given_node(target_node, cousin_nodes);
    cout<<"\n";

    target_node = new Node {nullptr, 9, nullptr};

    cout<<"extract_cousins_of_given_node_in_binary_tree([the test case node does not contain cousins]): ";

    cousin_nodes = handle_extract_cousins_of_given_node_in_binary_tree(&T, target_node);
    cout<<"\n";

    return 0;
}