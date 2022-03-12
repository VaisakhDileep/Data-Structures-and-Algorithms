/*
Created by  : Vaisakh Dileep
Date        : 10, March, 2022
Description : This program finds the maximum path sum in a binary tree.
*/

#include<iostream>

#include<vector>

#include<algorithm>

#include "../header_files/binary_tree_using_linked_list/binary_tree_using_linked_list.hpp"

using namespace std;

using namespace BTLL;

int maximum_path_sum_binary_tree(Node *current_node, int &maximum_path_sum)
{
    if(current_node == nullptr)
    {
        return INT_MIN;
    }

    int left_linear_cost {maximum_path_sum_binary_tree(current_node->left_child, maximum_path_sum)}; // A path along the left sub-tree, that goes linearly down each level.

    int right_linear_cost {maximum_path_sum_binary_tree(current_node->right_child, maximum_path_sum)}; // A path along the right sub-tree, that goes linearly down each level.

    int max_left_right_linear_cost_with_update {}, sum_left_right_linear_cost_with_update {};

    if((left_linear_cost == INT_MIN) and (right_linear_cost == INT_MIN))
    {
        max_left_right_linear_cost_with_update = current_node->data;

        sum_left_right_linear_cost_with_update = current_node->data;
    }
    else if(left_linear_cost == INT_MIN)
    {
        max_left_right_linear_cost_with_update = max(right_linear_cost + current_node->data, current_node->data);

        sum_left_right_linear_cost_with_update = max(right_linear_cost + current_node->data, current_node->data);
    }
    else if(right_linear_cost == INT_MIN)
    {
        max_left_right_linear_cost_with_update = max(left_linear_cost + current_node->data, current_node->data);

        sum_left_right_linear_cost_with_update = max(left_linear_cost + current_node->data, current_node->data);
    }
    else
    {
        vector<int> arguments {(left_linear_cost + right_linear_cost + current_node->data), (left_linear_cost + current_node->data), (right_linear_cost + current_node->data), current_node->data};

        max_left_right_linear_cost_with_update = max(max(left_linear_cost, right_linear_cost) + current_node->data, current_node->data);

        sum_left_right_linear_cost_with_update = *max_element(arguments.begin(), arguments.end());
    }

    maximum_path_sum = max(maximum_path_sum, sum_left_right_linear_cost_with_update);

    return max_left_right_linear_cost_with_update;
}

int handle_maximum_path_sum_binary_tree(Binary_Tree *T)
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

    int maximum_path_sum {INT_MIN};

    maximum_path_sum_binary_tree(T->root, maximum_path_sum);

    return maximum_path_sum;
}

int main()
{
    Binary_Tree T1 {};

    T1.root = new Node {new Node {nullptr, 30, nullptr}, -9, new Node {new Node {new Node {nullptr, 7, nullptr}, 5, nullptr}, -4, new Node {nullptr, 6, new Node {nullptr, 100, nullptr}}}};

    cout<<"maximum_path_sum_binary_tree(T1): "<<handle_maximum_path_sum_binary_tree(&T1)<<"\n";

    Binary_Tree T2 {};

    T2.root = new Node {new Node {nullptr, 100, nullptr}, 15, new Node {nullptr, -10, nullptr}};

    cout<<"maximum_path_sum_binary_tree(T2): "<<handle_maximum_path_sum_binary_tree(&T2)<<"\n";

    Binary_Tree T3 {};

    handle_create_binary_tree(&T3, new int[15] {10, -10, 100, -20, -100, -90, -20, 100, 75, 10, 50, 100, -100, 100, 80}, 15);

    cout<<"maximum_path_sum_binary_tree(T3): "<<handle_maximum_path_sum_binary_tree(&T3)<<"\n";

    return 0;
}