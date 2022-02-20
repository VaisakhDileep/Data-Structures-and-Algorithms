/*
Created by  : Vaisakh Dileep
Date        : 20, February, 2022
Description : This program creates an n-ary tree from an array.
*/

#include<iostream>

#include<vector>

#include<queue>

using namespace std;

struct Node
{
    int data;

    vector<Node *> children;
};

struct N_ary_Tree
{
    Node *root;
};

// Inorder to understand the different types of n-ary trees refer "Data Structures and Algorithms" pg:14.

void create_n_ary_tree(N_ary_Tree *T, int *A, int size, int n) // Note this will only work if the tree is a complete tree and we know the value of 'n'.
{
    if(T == nullptr)
    {
        throw string {"ERROR - Invalid operation, given n-ary tree is not valid ....."};
    }

    if(n < 0)
    {
        throw string {"ERROR - Invalid operation, value of 'n' cannot be negative ....."};
    }

    if(A == nullptr)
    {
        throw string {"ERROR - Invalid operation, given array is not valid ....."};
    }

    T->root = new Node {A[0], vector<Node *> {}};

    Node *current_node = nullptr;

    Node *current_parent = T->root;

    int child_count = 0;

    queue<Node *> Q {};

    for(int i {1}; i < size; i++)
    {
        current_node = new Node {A[i], vector<Node *> {}};

        Q.push(current_node);

        current_parent->children.push_back(current_node);

        child_count++;

        if(child_count == n)
        {
            current_parent = Q.front();

            Q.pop();

            child_count = 0;
        }
    }
}

void handle_create_n_ary_tree(N_ary_Tree *T, int *A, int size, int n)
{
    try
    {
        create_n_ary_tree(T, A, size, n);
    }
    catch(string &ex)
    {
        cout<<ex;
    }
}

int main()
{
    N_ary_Tree T {};

    handle_create_n_ary_tree(&T, new int[8] {1, 2, 3, 4, 5, 6, 7, 8}, 8, 3);

    return 0;
}