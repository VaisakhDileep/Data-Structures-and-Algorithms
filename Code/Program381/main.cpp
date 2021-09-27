/*
Created by  : Vaisakh Dileep
Date        : 10, August, 2021
Description : This program constructs a segment tree for range minimum query.
*/

#include<iostream>

#include<vector>

#include<math.h>

using namespace std;

struct Segment_Tree
{
    vector<int> *tree;
};

void insert_segment_tree(vector<int> *input_array, Segment_Tree *segment_tree, int start, int end, int root)
{
    if(start == end)
    {
        segment_tree->tree->at(root) = input_array->at(start);

        return ;
    }

    int mid {(start + end) / 2};

    insert_segment_tree(input_array, segment_tree, start, mid, 2 * root + 1); // left child.

    insert_segment_tree(input_array, segment_tree, mid + 1, end, 2 * root + 2); // right child.

    segment_tree->tree->at(root) = min(segment_tree->tree->at(2 * root + 1), segment_tree->tree->at(2 * root + 2));
}

Segment_Tree* construct_segment_tree(vector<int> *input_array)
{
    if(input_array == nullptr)
    {
        throw string {"ERROR - Invalid operation, input array is not valid ....."};
    }

    if(input_array->size() == 0)
    {
        throw string {"ERROR - Invalid operation, input array is empty ....."};
    }

    int num_leaf_nodes {pow(2, ceil(log2(input_array->size())))}; // Minimum number of leaf nodes required.

    int segment_tree_node_count {num_leaf_nodes + (num_leaf_nodes - 1)}; // For a complete binary tree, "num_leaf_nodes = num_internal_nodes + 1".

    Segment_Tree *segment_tree {new Segment_Tree {new vector<int>(segment_tree_node_count, 0)}};

    insert_segment_tree(input_array, segment_tree, 0, input_array->size() - 1, 0);

    return segment_tree;
}

Segment_Tree* handle_construct_segment_tree(vector<int> *input_array)
{
    try
    {
        return construct_segment_tree(input_array);
    }
    catch(string &ex)
    {
        cout<<ex;
    }
}

void display_segment_tree(Segment_Tree *segment_tree)
{
    if(segment_tree == nullptr)
    {
        return ;
    }

    for(int i {0}; i < segment_tree->tree->size(); i++)
    {
        cout<<segment_tree->tree->at(i)<<" ";
    }
}

int main()
{
    vector<int> *input_array {new vector<int> {-1, -2, -3, -4, 5}};

    Segment_Tree *segment_tree {handle_construct_segment_tree(input_array)};

    cout<<"segment_tree: ";
    display_segment_tree(segment_tree);
    cout<<"\n";

    return 0;
}