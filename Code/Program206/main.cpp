/*
Created by  : Vaisakh Dileep
Date        : 6, June, 2021
Description : This program finds the left child of a node in a binary tree.
*/

#include<iostream>

#include<climits>

#include<math.h>

using namespace std;

struct Binary_Tree
{
    int *A;

    int size {0};

    int alloted_size {0};
};

int height_binary_tree(Binary_Tree *T)
{
    if(T == nullptr)
    {
        throw string {"ERROR - Invalid operation, binary tree is not valid ....."};
    }

    if(T->size == 0)
    {
        return 0;
    }

    int height {0};

    int total_nodes {0};

    while(total_nodes < T->size)
    {
        total_nodes += pow(2, height);

        height++;
    }

    return height - 1;
}

void create_binary_tree(Binary_Tree *T, int *A, int size)
{
    if(T == nullptr)
    {
        throw string {"ERROR - Invalid operation, binary tree is not valid ....."};
    }

    T->size = size;

    int height {height_binary_tree(T)};

    int number_nodes {static_cast<int>(pow(2, height + 1)) - 1};

    T->size = size;

    T->alloted_size = number_nodes;

    T->A = new int[number_nodes] {};

    for(int i {0}; i < size; i++)
    {
        T->A[i] = A[i];
    }

    for(int i {size}; i < T->alloted_size; i++)
    {
        T->A[i] = INT_MIN;
    }
}

void handle_create_binary_tree(Binary_Tree *T, int *A, int size)
{
    try
    {
        create_binary_tree(T, A, size);
    }
    catch(string &ex)
    {
        cout<<ex;
    }
}

int left_child_binary_tree(Binary_Tree *T, int node)
{
    if(T == nullptr)
    {
        throw string {"ERROR - Invalid operation, binary tree is not valid ....."};
    }

    if(T->A == nullptr)
    {
        throw string {"ERROR - Invalid operation, binary tree is empty ....."};
    }

    int i {0};

    for(; i < T->size; i++)
    {
        if(T->A[i] == node)
        {
            break;
        }
    }

    if(i == T->size)
    {
        throw string {"ERROR - Invalid operation, node not present in the binary tree ....."};
    }
    else
    {
        i = (2 * (i + 1)) - 1; // Equation for finding the index of the left child of the node.
    }

    if((i >= T->size) or (T->A[i] == INT_MIN))
    {
        throw string {"ERROR - Invalid operation, no left child present for the node ....."};
    }
    else
    {
        return T->A[i];
    }
}

int handle_left_child_binary_tree(Binary_Tree *T, int node)
{
    try
    {
        return left_child_binary_tree(T, node);
    }
    catch(string &ex)
    {
        cout<<ex;

        return INT_MIN;
    }
}

int main()
{
    Binary_Tree T {};

    handle_create_binary_tree(&T, new int [4] {1, 2, 3, 4}, 4);

    cout<<"handle_left_child_binary_tree(T, 2): "<<handle_left_child_binary_tree(&T, 2)<<"\n";
    cout<<"handle_left_child_binary_tree(T, 1): "<<handle_left_child_binary_tree(&T, 1)<<"\n";
    cout<<"handle_left_child_binary_tree(T, 3): "<<handle_left_child_binary_tree(&T, 3)<<"\n";
    cout<<"handle_left_child_binary_tree(T, 5): "<<handle_left_child_binary_tree(&T, 5)<<"\n";

    return 0;
}