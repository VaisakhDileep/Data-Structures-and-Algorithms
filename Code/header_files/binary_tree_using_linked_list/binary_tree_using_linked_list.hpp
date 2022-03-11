/*
Created by  : Vaisakh Dileep
Date        : 11, March, 2022
Description : Declaration file for binary_tree_using_linked_list.
*/

#ifndef _BINARY_TREE_USING_LINKED_LIST_HPP_
#define _BINARY_TREE_USING_LINKED_LIST_HPP_

namespace binary_tree_using_linked_list
{

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

    void create_binary_tree(Node **node, int i, int *A, int size);

    void handle_create_binary_tree(Binary_Tree *T, int *A, int size);

    Node* search_binary_tree(Node *node, int target);

    Node* handle_search_binary_tree(Binary_Tree *T, int target);
};

namespace BTLL = binary_tree_using_linked_list;

#endif