/*
Created by  : Vaisakh Dileep
Date        : 9, November, 2021
Description : This program pops the smallest element from the indexed binary max heap.
*/

#include<iostream>

#include<vector>

#include<math.h>

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

int height_indexed_binary_max_heap(Indexed_Binary_Max_Heap *heap)
{
    if(heap == nullptr)
    {
        throw string {"ERROR - Invalid operation, indexed binary max heap is not valid ....."};
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

Indexed_Binary_Max_Heap* create_indexed_binary_max_heap(int size = 10'000) // Make sure to create the indexed binary max heap with a very large size.
{
    if(size < 0)
    {
        throw string {"ERROR - Invalid operation, size of the indexed binary max heap cannot be negative ....."};
    }

    Indexed_Binary_Max_Heap *idx_bin_max_heap {new Indexed_Binary_Max_Heap {}};

    int max_height {height_indexed_binary_max_heap(new Indexed_Binary_Max_Heap {nullptr, nullptr, nullptr, nullptr, nullptr, size, 0})};

    size = static_cast<int>(pow(2, max_height + 1)) - 1; // We update "size" so that it will represent a perfect binary tree.

    idx_bin_max_heap->values = new vector<int>(size, INT_MIN); // "INT_MIN" means that the value of the key has not been added yet(key has not been added yet).

    idx_bin_max_heap->position_map = new vector<int>(size, INT_MIN); // "INT_MIN" means that the position map value has not been added yet(key has not been added yet).

    idx_bin_max_heap->inverse_map = new vector<int>(size, INT_MIN); // "INT_MIN" means that the inverse map value has not been added yet(node index in the heap has not been updated yet).

    idx_bin_max_heap->parent_node_index = new vector<int>(size, 0);

    idx_bin_max_heap->left_most_child_index = new vector<int>(size, 0);

    idx_bin_max_heap->size = 0;

    idx_bin_max_heap->alloted_size = size;

    idx_bin_max_heap->parent_node_index->at(0) = INT_MIN; // "INT_MIN" acts as a flag to denote that there is no parent for the given node.

    for(int i {1}; i < size; i++)
    {
        idx_bin_max_heap->parent_node_index->at(i) = ((i + 1) / 2) - 1; // Equation for finding the index of the parent of the node.
    }

    int left_child_index {};

    for(int i {0}; i < size; i++)
    {
        left_child_index = (2 * (i + 1)) - 1; // Equation for finding the index of the left child of the node.

        if(left_child_index >= size)
        {
            idx_bin_max_heap->left_most_child_index->at(i) = INT_MIN; // "INT_MIN" acts as a flag to denote that there is no left child for the given node.
        }
        else
        {
            idx_bin_max_heap->left_most_child_index->at(i) = left_child_index;
        }
    }

    return idx_bin_max_heap;
}

Indexed_Binary_Max_Heap* handle_create_indexed_binary_max_heap(int size = 10'000)
{
    try
    {
        return create_indexed_binary_max_heap(size);
    }
    catch(string &ex)
    {
        cout<<ex;

        return nullptr;
    }
}

void swap_node(Indexed_Binary_Max_Heap *heap, int index_1, int index_2)
{
    heap->position_map->at(heap->inverse_map->at(index_1)) = index_2;

    heap->position_map->at(heap->inverse_map->at(index_2)) = index_1;

    swap(heap->inverse_map->at(index_1), heap->inverse_map->at(index_2));
}

void swim(Indexed_Binary_Max_Heap *heap, int index) // target node will move up the indexed binary max heap till the heap condition is satisfied.
{
    if(index == 0)
    {
        return ;
    }

    int parent_index {heap->parent_node_index->at(index)};

    while(true)
    {
        if(index == 0)
        {
            break;
        }

        if(heap->values->at(heap->inverse_map->at(index)) <= heap->values->at(heap->inverse_map->at(parent_index)))
        {
            break;
        }

        swap_node(heap, index, parent_index);

        index = parent_index;

        parent_index = heap->parent_node_index->at(index);
    }
}

int select_max_child_index(Indexed_Binary_Max_Heap *heap, int parent)
{
    int child_index_left {heap->left_most_child_index->at(parent)}, child_index_right {child_index_left + 1};

    if(child_index_left >= heap->size) // No left child means no right child.
    {
        return INT_MIN; // Behaves like a flag denoting that there are no valid children.
    }

    if(child_index_right >= heap->size) // No right child doesn't necessary mean there is no left child.
    {
        return child_index_left;
    }

    if(heap->values->at(heap->inverse_map->at(child_index_left)) >= heap->values->at(heap->inverse_map->at(child_index_right)))
    {
        return child_index_left;
    }
    else
    {
        return child_index_right;
    }
}

void sink(Indexed_Binary_Max_Heap *heap, int index) // target node will move down the indexed binary max heap till the heap condition is maintained.
{
    int child_index {select_max_child_index(heap, index)};

    while(true)
    {
        if(child_index == INT_MIN)
        {
            break;
        }

        if(heap->values->at(heap->inverse_map->at(index)) >= heap->values->at(heap->inverse_map->at(child_index)))
        {
            break;
        }

        swap_node(heap, index, child_index);

        index = child_index;

        child_index = select_max_child_index(heap, index);
    }
}

void insert_indexed_binary_max_heap(Indexed_Binary_Max_Heap *heap, int key, int value)
{
    if(heap == nullptr)
    {
        throw string {"ERROR - Invalid operation, indexed binary max heap is not valid ....."};
    }

    if(heap->size == heap->alloted_size)
    {
        throw string {"ERROR - Invalid operation, overflow detected ....."};
    }

    if(key < 0)
    {
        throw string {"ERROR - Invalid key value, key value cannot be a negative value ....."};
    }

    if(key >= heap->alloted_size)
    {
        throw string {"ERROR - Invalid key value, key value should be lesser than the alloted size of the indexed binary max heap ....."};
    }

    if(heap->position_map->at(key) != INT_MIN)
    {
        throw string {"ERROR - Invalid operation, key is already present in the indexed binary max heap ....."};
    }

    heap->values->at(key) = value;

    heap->position_map->at(key) = heap->size;

    heap->inverse_map->at(heap->size) = key;

    swim(heap, heap->size);

    heap->size++;
}

void handle_insert_indexed_binary_max_heap(Indexed_Binary_Max_Heap *heap, int key, int value)
{
    try
    {
        insert_indexed_binary_max_heap(heap, key, value);
    }
    catch(string &ex)
    {
        cout<<ex;
    }
}

int delete_indexed_binary_max_heap(Indexed_Binary_Max_Heap *heap, int key)
{
    if(heap == nullptr)
    {
        throw string {"ERROR - Invalid operation, indexed binary max heap is not valid ....."};
    }

    if(key < 0)
    {
        throw string {"ERROR - Invalid key value, key value cannot be a negative value ....."};
    }

    if(key >= heap->alloted_size)
    {
        throw string {"ERROR - Invalid key value, key value exceeds the alloted size of the indexed binary max heap ....."};
    }

    if(heap->position_map->at(key) == INT_MIN)
    {
        throw string {"ERROR - Invalid operation, key is not present in the indexed binary max heap ....."};
    }

    int deleted_value {heap->values->at(key)};

    heap->size--;

    int target_index {heap->position_map->at(key)};

    swap_node(heap, target_index, heap->size);

    sink(heap, target_index);

    swim(heap, target_index);

    heap->values->at(key) = INT_MIN; // resetting the value of the deleted key.

    heap->position_map->at(key) = INT_MIN; // resetting the position map of the deleted key.

    heap->inverse_map->at(heap->size) = INT_MIN; // resetting the last index of the indexed binary max heap.

    return deleted_value;
}

pair<string, int> pop_indexed_binary_max_heap(map<int, string> *key_member, Indexed_Binary_Max_Heap *heap)
{
    if(heap == nullptr)
    {
        throw string {"ERROR - Invalid operation, indexed binary max heap is not valid ....."};
    }

    if(heap->size == 0)
    {
        throw string {"ERROR - Invalid operation, indexed binary max heap is not valid ....."};
    }

    pair<string, int> popped_element {};

    popped_element.first = (*key_member)[heap->inverse_map->at(0)];

    popped_element.second = heap->values->at(heap->inverse_map->at(0));

    delete_indexed_binary_max_heap(heap, heap->inverse_map->at(0));

    return popped_element;
}

pair<string, int> handle_pop_indexed_binary_max_heap(map<int, string> *key_member, Indexed_Binary_Max_Heap *heap)
{
    try
    {
        return pop_indexed_binary_max_heap(key_member, heap);
    }
    catch(string &ex)
    {
        cout<<ex;

        return make_pair("", INT_MIN);
    }
}

int main()
{
    map<int, string> key_member {};

    key_member[1] = "vaisakh_01";
    key_member[2] = "vaisakh_02";
    key_member[5] = "vaisakh_05";
    key_member[9] = "vaisakh_09";
    key_member[8] = "vaisakh_08";
    key_member[3] = "vaisakh_03";

    map<int, int> key_value {};

    key_value[1] = 20;
    key_value[2] = -2;
    key_value[5] = 89;
    key_value[9] = 6;
    key_value[8] = 1;
    key_value[3] = -100;

    Indexed_Binary_Max_Heap *idx_bin_max_heap {handle_create_indexed_binary_max_heap()};

    handle_insert_indexed_binary_max_heap(idx_bin_max_heap, 1, key_value[1]);
    handle_insert_indexed_binary_max_heap(idx_bin_max_heap, 5, key_value[5]);
    handle_insert_indexed_binary_max_heap(idx_bin_max_heap, 9, key_value[9]);
    handle_insert_indexed_binary_max_heap(idx_bin_max_heap, 8, key_value[8]);
    handle_insert_indexed_binary_max_heap(idx_bin_max_heap, 2, key_value[2]);
    handle_insert_indexed_binary_max_heap(idx_bin_max_heap, 3, key_value[3]);

    pair<string, int> result {handle_pop_indexed_binary_max_heap(&key_member, idx_bin_max_heap)};

    cout<<"result: {"<<result.first<<", "<<result.second<<"}\n";

    cout<<"idx_bin_max_heap: ";
    display_binary_max_heap(&key_member, idx_bin_max_heap);
    cout<<"\n";

    return 0;
}