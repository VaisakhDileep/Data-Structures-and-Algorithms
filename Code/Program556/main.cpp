/*
Created by  : Vaisakh Dileep
Date        : 4, March, 2022
Description : This program finds the k-th smallest element in a binary search tree(O(k) space O(k) time solution).
*/

#include<iostream>

using namespace std;

struct Node
{
    Node *left_child;

    int data;

    Node *right_child;
};

struct Binary_Search_Tree
{
    Node *root;
};

void insert_binary_search_tree(Binary_Search_Tree *T, int value)
{
    if(T == nullptr)
    {
        throw string {"ERROR - Invalid operation, binary search tree is not valid ....."};
    }

    if(T->root == nullptr)
    {
        T->root = new Node {nullptr, value, nullptr};

        return ;
    }

    Node *node {T->root}, *previous_node {};

    while(node != nullptr)
    {
        previous_node = node;

        if(value == node->data)
        {
            throw string {"ERROR - Invalid operation, value already present in the binary search tree ....."};
        }
        else if(value > node->data)
        {
            node = node->right_child;
        }
        else if(value < node->data)
        {
            node = node->left_child;
        }
    }

    if(value < previous_node->data)
    {
        previous_node->left_child = new Node {nullptr, value, nullptr};
    }
    else
    {
        previous_node->right_child = new Node {nullptr, value, nullptr};
    }
}

void create_binary_search_tree(Binary_Search_Tree *T, int *A, int size)
{
    for(int i {0}; i < size; i++)
    {
        try
        {
            insert_binary_search_tree(T, A[i]);
        }
        catch(string &ex)
        {
            if(ex == "ERROR - Invalid operation, value already present in the binary search tree .....")
            {
                cout<<"ERROR - Invalid operation, "<<A[i]<<" cannot be inserted in the binary search tree .....\n";
            }
            else if(ex == "ERROR - Invalid operation, binary search tree is not valid .....")
            {
                cout<<ex;

                return ;
            }
        }
    }
}

void k_th_smallest_element_binary_search_tree(Node *current_node, int &k, int &current_k, int &result)
{
    if(current_node != nullptr)
    {
        k_th_smallest_element_binary_search_tree(current_node->left_child, k, current_k, result);

        if(current_k == k)
        {
            result = current_node->data;

            throw string {"Done - Successfully found the value ....."};
        }

        current_k++;

        k_th_smallest_element_binary_search_tree(current_node->right_child, k, current_k, result);
    }
}

int handle_k_th_smallest_element_binary_search_tree(Binary_Search_Tree *T, int k)
{
    if(T == nullptr)
    {
        cout<<"ERROR - Invalid operation, binary search tree is not valid .....";

        return INT_MAX;
    }

    if(T->root == nullptr)
    {
        cout<<"ERROR - Invalid operation, binary search tree is empty .....";

        return INT_MAX;
    }

    if(k < 0)
    {
        cout<<"ERROR - Invalid operation, value of 'k' cannot be negative .....";

        return INT_MAX;
    }

    int current_k {1}, result {};

    try
    {
        k_th_smallest_element_binary_search_tree(T->root, k, current_k, result);

        cout<<"ERROR - Invalid operation, value of 'k' cannot exceed the size of the binary search tree .....";

        return INT_MAX;
    }
    catch(string &ex)
    {
        if(ex == "Done - Successfully found the value .....");
        {
            return result;
        }

        cout<<ex;

        return INT_MAX;
    }
}

int main()
{
    Binary_Search_Tree T {};

    create_binary_search_tree(&T, new int[8] {9, 7, 10, 3, 8, 1, 15, 11}, 8);

    cout<<"k_th_smallest_element_binary_search_tree(&T, 1): "<<handle_k_th_smallest_element_binary_search_tree(&T, 1)<<"\n";
    cout<<"k_th_smallest_element_binary_search_tree(&T, 3): "<<handle_k_th_smallest_element_binary_search_tree(&T, 3)<<"\n";
    cout<<"k_th_smallest_element_binary_search_tree(&T, 8): "<<handle_k_th_smallest_element_binary_search_tree(&T, 8)<<"\n\n";

    cout<<"k_th_smallest_element_binary_search_tree(&T, 9): "<<handle_k_th_smallest_element_binary_search_tree(&T, 9)<<"\n";
    cout<<"k_th_smallest_element_binary_search_tree(&T, -1): "<<handle_k_th_smallest_element_binary_search_tree(&T, -1)<<"\n";

    return 0;
}