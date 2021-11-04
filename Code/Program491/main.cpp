/*
Created by  : Vaisakh Dileep
Date        : 4, November, 2021
Description : This program finds the height of the indexed binary min heap.
*/

#include<iostream>

#include<vector>

#include<math.h>

using namespace std;

struct Indexed_Binary_Min_Heap
{
    vector<int> *values;

    vector<int> *position_map;

    vector<int> *inverse_map;

    vector<int> *parent_node_index;

    vector<int> *left_most_child_index;

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

int handle_height_indexed_binary_min_heap(Indexed_Binary_Min_Heap *heap)
{
    try
    {
        return height_indexed_binary_min_heap(heap);
    }
    catch(string &ex)
    {
        cout<<ex;

        return -1;
    }
}

int main()
{
    return 0;
}