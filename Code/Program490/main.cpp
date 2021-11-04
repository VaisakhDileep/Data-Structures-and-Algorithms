/*
Created by  : Vaisakh Dileep
Date        : 2, November, 2021
Description : This program creates a indexed binary min heap.
*/

#include<iostream>

#include<vector>

#include<math.h>

using namespace std;

struct Indexed_Binary_Min_Heap // binary indexed min heap should be a perfect tree.
{
    vector<int> *values; // stores the value of the key element(not for the index of the node).

    vector<int> *position_map; // stores the node index in the heap for the give key value.

    vector<int> *inverse_map; // stores the key value for node index in the heap.

    vector<int> *parent_node_index; // stores the parent of the given node.

    vector<int> *left_most_child_index; // stores the left-most child of the given node.

    int size {0};

    int alloted_size {0};
};

int height_indexed_binary_min_heap(Indexed_Binary_Min_Heap *heap)
{
    if(heap == nullptr)
    {
        throw string {"ERROR - Invalid operation, indexed binary min heap is not valid ....."};
    }

    if(heap->size == 0)
    {
        return 0;
    }

    int height {0};

    int total_nodes {0};

    while(total_nodes < heap->size)
    {
        total_nodes += pow(2, height);

        height++;
    }

    return height - 1; // We are only counting the edges for height.
}

Indexed_Binary_Min_Heap* create_indexed_binary_min_heap(int size = 10'000) // Make sure to create the indexed binary min heap with a very large size.
{
    if(size < 0)
    {
        throw string {"ERROR - Invalid operation, size of the indexed binary min heap cannot be negative ....."};
    }

    Indexed_Binary_Min_Heap *idx_bin_min_heap {new Indexed_Binary_Min_Heap {}};

    int max_height {height_indexed_binary_min_heap(new Indexed_Binary_Min_Heap {nullptr, nullptr, nullptr, nullptr, nullptr, size, 0})};

    size = static_cast<int>(pow(2, max_height + 1)) - 1; // We update "size" so that it will represent a perfect binary tree.

    idx_bin_min_heap->values = new vector<int>(size, INT_MIN); // "INT_MIN" means that the value of the key has not been added yet(key has not been added yet).

    idx_bin_min_heap->position_map = new vector<int>(size, INT_MIN); // "INT_MIN" means that the position map value has not been added yet(key has not been added yet).

    idx_bin_min_heap->inverse_map = new vector<int>(size, INT_MIN); // "INT_MIN" means that the inverse map value has not been added yet(node index in the heap has not been updated yet).

    idx_bin_min_heap->parent_node_index = new vector<int>(size, 0);

    idx_bin_min_heap->left_most_child_index = new vector<int>(size, 0);

    idx_bin_min_heap->size = 0;

    idx_bin_min_heap->alloted_size = size;

    idx_bin_min_heap->parent_node_index->at(0) = INT_MIN; // "INT_MIN" acts as a flag to denote that there is no parent for the given node.

    for(int i {1}; i < size; i++)
    {
        idx_bin_min_heap->parent_node_index->at(i) = ((i + 1) / 2) - 1; // Equation for finding the index of the parent of the node.
    }

    int left_child_index {};

    for(int i {0}; i < size; i++)
    {
        left_child_index = (2 * (i + 1)) - 1; // Equation for finding the index of the left child of the node.

        if(left_child_index >= size)
        {
            idx_bin_min_heap->left_most_child_index->at(i) = INT_MIN; // "INT_MIN" acts as a flag to denote that there is no left child for the given node.
        }
        else
        {
            idx_bin_min_heap->left_most_child_index->at(i) = left_child_index;
        }
    }

    return idx_bin_min_heap;
}

int main()
{
    Indexed_Binary_Min_Heap *idx_bin_min_heap {create_indexed_binary_min_heap(100)};

    return 0;
}