/*
Created by  : Vaisakh Dileep
Date        : 22, January, 2022
Description : This program displays a binary tree using level-order traversal maintaining the level details
*/

#include<iostream>

#include<vector>

#include<queue>

#include<math.h>

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

bool contains_non_null_node(vector<Node*> vec_nodes)
{
    for(int i {0}; i < vec_nodes.size(); i++)
    {
        if(vec_nodes[i] != nullptr)
        {
            return true;
        }
    }

    return false;
}

void display_binary_tree(Binary_Tree *T) // level-order traversal maintaining the level details.
{
    if((T == nullptr) or (T->root == nullptr))
    {
        cout<<"[ ]";

        return ;
    }

    vector<vector<Node*>> nodes_in_level {};

    vector<Node*> nodes_in_current_level {};

    queue<Node*> Q {};

    int node_counter {0}, current_level {0};

    Q.push(T->root);

    nodes_in_current_level.push_back(T->root);

    node_counter++;

    while(Q.empty() == false)
    {
        if(node_counter == pow(2, current_level))
        {
            if(contains_non_null_node(nodes_in_current_level) == false)
            {
                break;
            }

            node_counter = 0;

            nodes_in_level.push_back(nodes_in_current_level);

            nodes_in_current_level = vector<Node*> {};

            current_level++;
        }

        Node *current_node {Q.front()};

        Q.pop();

        if(current_node == nullptr)
        {
            Q.push(nullptr);
            Q.push(nullptr);

            nodes_in_current_level.push_back(nullptr);
            nodes_in_current_level.push_back(nullptr);
        }
        else
        {
            Q.push(current_node->left_child);
            Q.push(current_node->right_child);

            nodes_in_current_level.push_back(current_node->left_child);
            nodes_in_current_level.push_back(current_node->right_child);
        }

        node_counter += 2;
    }

    cout<<"[ ";
    for(int i {0}; i < nodes_in_level.size(); i++)
    {
        cout<<"[ ";
        for(int j {0}; j < nodes_in_level[i].size(); j++)
        {
            if(nodes_in_level[i][j] == nullptr)
            {
                cout<<"null ";

                continue ;
            }

            cout<<nodes_in_level[i][j]->data<<" ";
        }
        cout<<"] ";
    }
    cout<<"]";
}

int main()
{
    Binary_Tree T {};

    handle_create_binary_tree(&T, new int[15] {1, 2, INT_MIN, INT_MIN, 3, INT_MIN, INT_MIN, INT_MIN, INT_MIN, 4, 5, INT_MIN, INT_MIN, INT_MIN, INT_MIN}, 15);

    cout<<"T[level-order]: ";
    display_binary_tree(&T);
    cout<<"\n";

    return 0;
}