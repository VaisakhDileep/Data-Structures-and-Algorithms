/*
Created by  : Vaisakh Dileep
Date        : 27, February, 2022
Description : This program displays the top-view of a binary tree from left to right.
*/

#include<iostream>

#include<map>

#include<queue>

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

void display_top_view_binary_tree(Binary_Tree *T)
{
    if((T == nullptr) or (T->root == nullptr))
    {
    
        return ;
    }

    map<int, int> top_most_vertical_node {}; // For every width value, it will store the top-most value(it will ignore the deeper values).

    queue<pair<Node *, int>> Q {}; // "int" part will be the width from the root.

    Q.push(pair<Node *, int> {T->root, 0});

    while(Q.empty() == false)
    {
        pair<Node *, int> top_element {Q.front()};

        Q.pop();

        if(top_most_vertical_node.find(top_element.second) == top_most_vertical_node.end())
        {
            top_most_vertical_node[top_element.second] = top_element.first->data;
        }

        if(top_element.first->left_child != nullptr)
        {
            Q.push(pair<Node *, int> {top_element.first->left_child, top_element.second - 1});
        }

        if(top_element.first->right_child != nullptr)
        {
            Q.push(pair<Node *, int> {top_element.first->right_child, top_element.second + 1});
        }
    }

    for(auto itr {top_most_vertical_node.begin()}; itr != top_most_vertical_node.end(); itr++)
    {
        cout<<itr->second<<" ";
    }
}

int main()
{
    Binary_Tree T {};

    handle_create_binary_tree(&T, new int[31] {1, 2, 3, INT_MIN, 4, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, 5, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN,INT_MIN, INT_MIN, INT_MIN, 6, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN}, 31);

    cout<<"T[top-view]: ";
    display_top_view_binary_tree(&T);
    cout<<"\n";

    return 0;
}