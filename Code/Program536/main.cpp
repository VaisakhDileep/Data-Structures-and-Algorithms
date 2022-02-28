/*
Created by  : Vaisakh Dileep
Date        : 27, February, 2022
Description : This program displays a binary tree using vertical order traversal(level-order traversal + map approach).
*/

#include<iostream>

#include<map>

#include<vector>

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

// In order to get an understanding on how vertical-order traversal works refer "Data Structures and Algorithms Manual 1" pg no:15.

void display_binary_tree(Binary_Tree *T) // vertical-order traversal
{
    if((T == nullptr) or (T->root == nullptr))
    {
        cout<<"[ ]";

        return ;
    }

    map<int, vector<int>> vertical_nodes {}; // "int" part will be the width from the root.

    queue<pair<Node *, int>> Q {}; // "int" part will be the width from the root.

    Q.push(pair<Node *, int>(T->root, 0));

    while(Q.empty() == false)
    {
        pair<Node *, int> top_element {Q.front()};

        Q.pop();

        vertical_nodes[top_element.second].push_back(top_element.first->data);

        if(top_element.first->left_child != nullptr)
        {
            Q.push(pair<Node *, int> {top_element.first->left_child, top_element.second - 1});
        }

        if(top_element.first->right_child != nullptr)
        {
            Q.push(pair<Node *, int> {top_element.first->right_child, top_element.second + 1});
        }
    }

    cout<<"[ ";
    for(auto itr {vertical_nodes.begin()}; itr != vertical_nodes.end(); itr++)
    {
        cout<<"[ ";
        for(int i {0}; i < itr->second.size(); i++)
        {
            cout<<itr->second[i]<<" ";
        }
        cout<<"] ";
    }
    cout<<"]";
}

int main()
{
    Binary_Tree T {};

    handle_create_binary_tree(&T, new int[15] {1, 2, 3, 4, 5, 6, 7, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, 8, 9}, 15);

    cout<<"T[vertical-order]: ";
    display_binary_tree(&T);
    cout<<"\n";

    return 0;
}