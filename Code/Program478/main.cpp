/*
Created by  : Vaisakh Dileep
Date        : 17, October, 2021
Description : This program demonstrates minimax algorithm without constructing the minimax tree.
*/

// Note: In my implementation I am considering root node as a maximizing node.

#include<iostream>

#include<vector>

#include<math.h>

using namespace std;

bool is_power_of_2(int num)
{
    if(num == 0)
    {
        return false;
    }

    return (ceil(log2(num))) == (floor(log2(num)));
}

// In order to get an understanding on how indexing gets propagated to the leaf node level check "Program478/whiteboard_3.pdf".

int minimax_calculator(vector<int> *leaf_nodes, int leaf_node_index, bool max_level, int tree_level, const int depth)
{
    if(depth == tree_level)
    {
        return leaf_nodes->at(leaf_node_index);
    }

    if(max_level == true)
    {
        return max(minimax_calculator(leaf_nodes, 2 * leaf_node_index, false, tree_level + 1, depth), minimax_calculator(leaf_nodes, 2 * leaf_node_index + 1, false, tree_level + 1, depth)); // Nodes in the max level will always try to maximize the outcome.
    }
    else
    {
        return min(minimax_calculator(leaf_nodes, 2 * leaf_node_index, true, tree_level + 1, depth), minimax_calculator(leaf_nodes, 2 * leaf_node_index + 1, true, tree_level + 1, depth)); // Nodes in the min level will always try to minimize the outcome.
    }
}

int handle_minimax_calculator(vector<int> *leaf_nodes)
{
    if(leaf_nodes == nullptr)
    {
        cout<<"ERROR - Invalid operation, input leaf_nodes array is not valid .....";

        return INT_MIN;
    }

    if(leaf_nodes->size() == 0)
    {
        cout<<"ERROR - Invalid operation, input leaf_nodes array is empty .....";

        return INT_MIN;
    }

    if(is_power_of_2(leaf_nodes->size()) == false)
    {
        cout<<"ERROR - Invalid operation, for the algorithm to work the tree should be complete(all the leaf nodes in the last level should be filled) .....";

        return INT_MIN;
    }

    return minimax_calculator(leaf_nodes, 0, true, 0, log2(leaf_nodes->size()));
}

int main()
{
    vector<int> static_evaluation {1, 2, 3, 4, 5, 6, 7, 8}; // "static_evaluation" corresponds to the leaf nodes in the last level of the minimax tree.

    cout<<"minimax_calculator(static_evaluation): "<<handle_minimax_calculator(&static_evaluation);

    return 0;
}