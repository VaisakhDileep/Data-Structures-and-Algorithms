/*
Created by  : Vaisakh Dileep
Date        : 6, March, 2022
Description : This program checks if two nodes in a binary tree are cousins.
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

bool check_nodes_are_siblings_in_binary_tree(Node *current_node, Node *node_1, Node *node_2)
{
    if(current_node == nullptr)
    {
        return false;
    }

    if((current_node->left_child != nullptr) and (current_node->right_child != nullptr))
    {
        if((current_node->left_child == node_1) and (current_node->right_child == node_2))
        {
            return true;
        }

        if((current_node->left_child == node_2) and (current_node->right_child == node_1))
        {
            return true;
        }
    }

    if(current_node->left_child != nullptr)
    {
        if(check_nodes_are_siblings_in_binary_tree(current_node->left_child, node_1, node_2) == true)
        {
            return true;
        }
    }

    if(current_node->right_child != nullptr)
    {
        if(check_nodes_are_siblings_in_binary_tree(current_node->right_child, node_1, node_2) == true)
        {
            return true;
        }
    }

    return false;
}

bool check_nodes_are_cousins_in_binary_tree(Binary_Tree *T, Node *node_1, Node *node_2)
{
    if(T == nullptr)
    {
        throw string {"ERROR - Invalid operation, binary tree is not valid ....."};
    }

    if(T->root == nullptr)
    {
        throw string {"ERROR - Invalid operation, binary tree is empty ....."};
    }

    if((node_1 == nullptr) or (node_2 == nullptr))
    {
        throw string {"ERROR - Invalid operation, one of the given nodes is not valid ....."};
    }

    int node_1_level {level_of_node_in_binary_tree(T->root, node_1)}, node_2_level {level_of_node_in_binary_tree(T->root, node_2)};

    if((node_1_level == INT_MIN) or (node_2_level == INT_MIN))
    {
        throw string {"ERROR - Invalid operation, one of the given nodes is not present in the binary tree ....."};
    }

    bool is_valid_sibling {check_nodes_are_siblings_in_binary_tree(T->root, node_1, node_2)};

    if((node_1_level == node_2_level) and (is_valid_sibling == false))
    {
        return true;
    }

    return false;
}

bool handle_check_nodes_are_cousins_in_binary_tree(Binary_Tree *T, Node *node_1, Node *node_2)
{
    try
    {
        return check_nodes_are_cousins_in_binary_tree(T, node_1, node_2);
    }
    catch(string &ex)
    {
        cout<<ex;

        return false;
    }
}

int main()
{
    Binary_Tree T {};

    T.root = new Node {new Node {new Node {nullptr, 4, nullptr}, 2, new Node {nullptr, 5, nullptr}}, 1, new Node {new Node {nullptr, 6, nullptr}, 3, new Node {nullptr, 7, nullptr}}};

    cout<<"check_nodes_are_cousins_in_binary_tree([the test case contains valid cousins]): "<<handle_check_nodes_are_cousins_in_binary_tree(&T, T.root->left_child->left_child, T.root->right_child->left_child)<<"\n";
    cout<<"check_nodes_are_cousins_in_binary_tree([the test case contains valid cousins]): "<<handle_check_nodes_are_cousins_in_binary_tree(&T, T.root->left_child->left_child, T.root->right_child->right_child)<<"\n";
    cout<<"check_nodes_are_cousins_in_binary_tree([the test case contains valid cousins]): "<<handle_check_nodes_are_cousins_in_binary_tree(&T, T.root->left_child->right_child, T.root->right_child->left_child)<<"\n";
    cout<<"check_nodes_are_cousins_in_binary_tree([the test case contains valid cousins]): "<<handle_check_nodes_are_cousins_in_binary_tree(&T, T.root->left_child->right_child, T.root->right_child->right_child)<<"\n\n";

    cout<<"check_nodes_are_cousins_in_binary_tree([the test case contains invalid cousins]): "<<handle_check_nodes_are_cousins_in_binary_tree(&T, T.root->left_child->left_child, T.root->left_child->right_child)<<"\n";
    cout<<"check_nodes_are_cousins_in_binary_tree([the test case contains invalid cousins]): "<<handle_check_nodes_are_cousins_in_binary_tree(&T, T.root->left_child, T.root->right_child)<<"\n";
    cout<<"check_nodes_are_cousins_in_binary_tree([the test case contains invalid cousins]): "<<handle_check_nodes_are_cousins_in_binary_tree(&T, T.root->left_child, T.root->right_child->left_child)<<"\n";

    return 0;
}