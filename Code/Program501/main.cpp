/*
Created by  : Vaisakh Dileep
Date        : 7, November, 2021
Description : This program displays an indexed binary max heap.
*/

#include<iostream>

#include<vector>

#include<map>

using namespace std;

struct Indexed_Binary_Max_Heap
{
    vector<int> *values;

    vector<int> *position_map;

    vector<int> *inverse_map;

    vector<int> *parent_node_index;

    vector<int> *left_most_child_index;

    int size {0};

    int alloted_size {0};
};

void display_binary_max_heap(map<int, string> *key_member, Indexed_Binary_Max_Heap *heap)
{
    if(heap == nullptr)
    {
        return ;
    }

    for(int i {0}; i < heap->size; i++)
    {
        cout<<"{"<<(*key_member)[heap->inverse_map->at(i)]<<":"<<heap->values->at(heap->inverse_map->at(i))<<"} ";
    }
}

int main()
{
    return 0;
}