/*
Created by  : Vaisakh Dileep
Date        : 12, March, 2022
Description : This program finds the maximum path sum between any two nodes in a binary tree.
*/

// In my implementation, I assume that there is a path from a node to itself.

#include<iostream>

#include "../header_files/binary_tree_using_linked_list/binary_tree_using_linked_list.hpp"

using namespace std;

using namespace BTLL;

int maximum_path_sum_between_leaf_nodes_binary_tree(Node *current_node, int &maximum_path_sum_between_leaf_nodes)
{
    if(current_node == nullptr)
    {
        return INT_MIN;
    }

    int left_result {maximum_path_sum_between_leaf_nodes_binary_tree(current_node->left_child, maximum_path_sum_between_leaf_nodes)};

    int right_result {maximum_path_sum_between_leaf_nodes_binary_tree(current_node->right_child, maximum_path_sum_between_leaf_nodes)};

    if((left_result == INT_MIN) and (right_result == INT_MIN)) // "current_node" is the leaf node.
    {
        maximum_path_sum_between_leaf_nodes = max(maximum_path_sum_between_leaf_nodes, current_node->data);

        return current_node->data;
    }
    else if(left_result == INT_MIN) // "current_node" does not have a left child.
    {
        return right_result + current_node->data;
    }
    else if(right_result == INT_MIN) // "current_node" does not have a right child.
    {
        return left_result + current_node->data;
    }
    else
    {
        maximum_path_sum_between_leaf_nodes = max(maximum_path_sum_between_leaf_nodes, left_result + right_result + current_node->data);

        return (left_result > right_result) ? (left_result + current_node->data) : (right_result + current_node->data);
    }
}

int handle_maximum_path_sum_between_leaf_nodes_binary_tree(Binary_Tree *T)
{
    if(T == nullptr)
    {
        cout<<"ERROR - Invalid operation, binary tree is not valid .....";

        return INT_MIN;
    }

    if(T->root == nullptr)
    {
        cout<<"ERROR - Invalid operation, binary tree is empty .....";

        return INT_MIN;
    }

    int maximum_path_sum_between_leaf_nodes {INT_MIN};

    maximum_path_sum_between_leaf_nodes_binary_tree(T->root, maximum_path_sum_between_leaf_nodes);

    return maximum_path_sum_between_leaf_nodes;
}

int main()
{
    Binary_Tree T1 {};

    T1.root = new Node {new Node {new Node {nullptr, -4, nullptr}, 2, nullptr}, 10, new Node {nullptr, 3, new Node {nullptr, 10, nullptr}}};

    cout<<"maximum_path_sum_between_leaf_nodes_binary_tree(T1): "<<handle_maximum_path_sum_between_leaf_nodes_binary_tree(&T1)<<"\n";

    Binary_Tree T2 {};

    T2.root = new Node {new Node {new Node {nullptr, 5, nullptr}, 7, nullptr}, 10, nullptr};

    cout<<"maximum_path_sum_between_leaf_nodes_binary_tree(T2): "<<handle_maximum_path_sum_between_leaf_nodes_binary_tree(&T2)<<"\n";

    Binary_Tree T3 {};

    T3.root = new Node {new Node {new Node {nullptr, -1, nullptr}, 7, new Node {new Node {nullptr, -5, nullptr}, 20, nullptr}}, 10, new Node {new Node {new Node {nullptr, -1, nullptr}, 10, nullptr}, 8, new Node {nullptr, 1, nullptr}}};

    cout<<"maximum_path_sum_between_leaf_nodes_binary_tree(T3): "<<handle_maximum_path_sum_between_leaf_nodes_binary_tree(&T3)<<"\n";

    Binary_Tree T4 {};

    T4.root = new Node {nullptr, 10, nullptr};

    cout<<"maximum_path_sum_between_leaf_nodes_binary_tree(T4): "<<handle_maximum_path_sum_between_leaf_nodes_binary_tree(&T4)<<"\n";

    return 0;
}