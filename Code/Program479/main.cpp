/*
Created by  : Vaisakh Dileep
Date        : 17, October, 2021
Description : This program constructs the minimax tree.
*/

#include<iostream>

#include<vector>

#include<math.h>

using namespace std;

struct Binary_Tree
{
    int *A;

    int size {0};

    int alloted_size {0};
};

void display_binary_tree(Binary_Tree *T)
{
    if(T == nullptr)
    {
        return ;
    }

    for(int i {0}; i < T->size; i++)
    {
        if(T->A[i] == INT_MIN)
        {
            cout<<"- ";
        }
        else
        {
            cout<<T->A[i]<<" ";
        }
    }
}

bool is_power_of_2(int num)
{
    if(num == 0)
    {
        return false;
    }

    return (ceil(log2(num)) == floor(log2(num)));
}

int minimax_tree_calculator(Binary_Tree *minimax_tree, vector<int> *leaf_nodes, int minimax_tree_index, int leaf_node_index, bool max_level, int tree_level, const int depth)
{
    if(depth == tree_level)
    {
        minimax_tree->A[minimax_tree_index] = leaf_nodes->at(leaf_node_index);

        return minimax_tree->A[minimax_tree_index];
    }

    if(max_level == true)
    {
        minimax_tree->A[minimax_tree_index] = max(minimax_tree_calculator(minimax_tree, leaf_nodes, 2 * minimax_tree_index + 1, 2 * leaf_node_index, false, tree_level + 1, depth), minimax_tree_calculator(minimax_tree, leaf_nodes, 2 * minimax_tree_index + 2, 2 * leaf_node_index + 1, false, tree_level + 1, depth));
    }
    else
    {
        minimax_tree->A[minimax_tree_index] = min(minimax_tree_calculator(minimax_tree, leaf_nodes, 2 * minimax_tree_index + 1, 2 * leaf_node_index, true, tree_level + 1, depth), minimax_tree_calculator(minimax_tree, leaf_nodes, 2 * minimax_tree_index + 2, 2 * leaf_node_index + 1, true, tree_level + 1, depth));
    }

    return minimax_tree->A[minimax_tree_index];
}

Binary_Tree* handle_minimax_tree_calculator(vector<int> *leaf_nodes)
{
    if(leaf_nodes == nullptr)
    {
        cout<<"ERROR - Invalid operation, input leaf_nodes array is not valid .....";

        return nullptr;
    }

    if(leaf_nodes->size() == 0)
    {
        cout<<"ERROR - Invalid operation, input leaf_nodes array is empty .....";

        return nullptr;
    }

    if(is_power_of_2(leaf_nodes->size()) == false)
    {
        cout<<"ERROR - Invalid operation, for the algorithm to work the tree should be complete(all the leaf nodes in the last level should be filled) .....";

        return nullptr;
    }

    int size_minimax_tree {leaf_nodes->size() * 2 - 1};

    Binary_Tree *minimax_tree {new Binary_Tree {new int[size_minimax_tree] {}, size_minimax_tree, size_minimax_tree}};

    minimax_tree_calculator(minimax_tree, leaf_nodes, 0, 0, true, 0, log2(leaf_nodes->size()));

    return minimax_tree;
}

int main()
{
    vector<int> static_evaluation {1, 2, 3, 4, 5, 6, 7, 8}; // "static_evaluation" corresponds to the leaf nodes in the last level of the minimax tree.

    Binary_Tree *minimax_tree {handle_minimax_tree_calculator(&static_evaluation)};

    cout<<"minimax_tree: \n";
    display_binary_tree(minimax_tree);
    cout<<"\n";

    return 0;
}