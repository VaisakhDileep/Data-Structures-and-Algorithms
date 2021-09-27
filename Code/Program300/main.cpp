/*
Created by  : Vaisakh Dileep
Date        : 5, July, 2021
Description : This program inserts an element into a binary max heap.
*/

#include<iostream>

#include<math.h>

using namespace std;

struct Binary_Max_Heap
{
    int *A;

    int size {0};

    int alloted_size {0};
};

void display_binary_max_heap(Binary_Max_Heap *heap)
{
    if(heap == nullptr)
    {
        return ;
    }

    for(int i {0}; i < heap->size; i++)
    {
        cout<<heap->A[i]<<" ";
    }
}

int height_binary_max_heap(Binary_Max_Heap *heap)
{
    if(heap == nullptr)
    {
        throw string {"ERROR - Invalid operation, binary max heap is not valid ....."};
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

    return height - 1;
}

void insert_node_binary_max_heap(Binary_Max_Heap *heap, int value)
{
    if(heap == nullptr)
    {
        throw string {"ERROR - Invalid operation, binary max heap is not valid ....."};
    }

    if(heap->size == heap->alloted_size)
    {
        int new_alloted_size {static_cast<int>(pow(2, height_binary_max_heap(heap) + 2) - 1)};

        int *temp {new int[new_alloted_size] {}};

        for(int i {0}; i < heap->size; i++)
        {
            temp[i] = heap->A[i];
        }

        delete[] heap->A;

        heap->A = temp;

        temp = nullptr;

        heap->alloted_size = new_alloted_size;
    }

    int i {heap->size};

    while((i > 0) and (value > heap->A[((i + 1) / 2) - 1]))
    {
        heap->A[i] = heap->A[((i + 1) / 2) - 1];

        i = ((i + 1) / 2) - 1;
    }

    heap->A[i] = value;

    heap->size++;
}

void handle_insert_node_binary_max_heap(Binary_Max_Heap *heap, int value)
{
    try
    {
        insert_node_binary_max_heap(heap, value);
    }
    catch(string &ex)
    {
        cout<<ex;
    }
}

int main()
{
    Binary_Max_Heap heap {};

    handle_insert_node_binary_max_heap(&heap, 10); // We can create a binary max heap from scratch like this.
    handle_insert_node_binary_max_heap(&heap, 30);
    handle_insert_node_binary_max_heap(&heap, 40);
    handle_insert_node_binary_max_heap(&heap, 50);
    handle_insert_node_binary_max_heap(&heap, 60);
    handle_insert_node_binary_max_heap(&heap, 70);
    handle_insert_node_binary_max_heap(&heap, 80);

    cout<<"heap: ";
    display_binary_max_heap(&heap);
    cout<<"\n";

    return 0;
}