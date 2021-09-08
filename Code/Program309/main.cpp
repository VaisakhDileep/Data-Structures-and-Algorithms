/*
Created by  : Vaisakh Dileep
Date		: 6, July, 2021
Description : This program removes an element from a binary min heap.
*/

#include<iostream>

#include<math.h>

using namespace std;

void swap(int &x, int &y)
{
	int temp {y};

	y = x;
	x = temp;
}

struct Binary_Min_Heap
{
	int *A;

	int size {0};

	int alloted_size {0};
};

void display_binary_min_heap(Binary_Min_Heap *heap)
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

int height_binary_min_heap(Binary_Min_Heap *heap)
{
	if(heap == nullptr)
	{
		throw string {"ERROR - Invalid operation, binary min heap is not valid ....."};
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

void insert_node_binary_min_heap(Binary_Min_Heap *heap, int value)
{
	if(heap == nullptr)
	{
		throw string {"ERROR - Invalid operation, binary min heap is not valid ....."};
	}

	if(heap->size == heap->alloted_size)
	{
		int new_alloted_size {static_cast<int>(pow(2, height_binary_min_heap(heap) + 2) - 1)};

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

	while((i > 0) and (value < heap->A[((i + 1) / 2) - 1]))
	{
		heap->A[i] = heap->A[((i + 1) / 2) - 1];

		i = ((i + 1) / 2) - 1;
	}

	heap->A[i] = value;

	heap->size++;
}

void create_binary_min_heap(Binary_Min_Heap *heap, int *A, int size)
{
	if(heap == nullptr)
	{
		throw string {"ERROR - Invalid operation, binary min heap is not valid ....."};
	}

	for(int i {0}; i < size; i++)
	{
		insert_node_binary_min_heap(heap, A[i]);
	}
}

void handle_create_binary_min_heap(Binary_Min_Heap *heap, int *A, int size)
{
	try
	{
		create_binary_min_heap(heap, A, size);
	}
	catch(string &ex)
	{
		cout<<ex;
	}
}

void remove_node_binary_min_heap(Binary_Min_Heap *heap)
{
	if(heap == nullptr)
	{
		throw string {"ERROR - Invalid operation, binary min heap is not valid ....."};
	}

	if(heap->size == 0)
	{
		throw string {"ERROR - Invalid operation, binary min heap is empty ....."};
	}

	int removed_node {heap->A[0]};

	heap->A[0] = heap->A[heap->size - 1];

	int i {0};

	int left_child_index {(2 * (i + 1) - 1)}, right_child_index {left_child_index + 1};

	while(left_child_index < heap->size)
	{
		int target {left_child_index};

		if(right_child_index < heap->size)
		{
			if(heap->A[right_child_index] < heap->A[left_child_index])
			{
				target = right_child_index;
			}
		}

		if(heap->A[i] > heap->A[target])
		{
			swap(heap->A[i], heap->A[target]);

			i = target;

			left_child_index = 2 * (target + 1) - 1;

			right_child_index = left_child_index + 1;
		}
		else
		{
			break;
		}
	}
	heap->A[heap->size - 1] = removed_node; // We place the deleted value at the end of the min heap.

	heap->size--;
}

void handle_remove_node_binary_min_heap(Binary_Min_Heap *heap)
{
	try
	{
		remove_node_binary_min_heap(heap);
	}
	catch(string &ex)
	{
		cout<<ex;
	}
}

int main()
{
	Binary_Min_Heap heap {};

	handle_create_binary_min_heap(&heap, new int[10] {100, 90, 80, 70, 60, 50, 40, 30, 20, 10}, 10);

	cout<<"heap: ";
	display_binary_min_heap(&heap);
	cout<<"\n";

	handle_remove_node_binary_min_heap(&heap);

	cout<<"heap [after performing remove operation]: ";
	display_binary_min_heap(&heap);
	cout<<"\n";

	cout<<"removed value: "<<heap.A[heap.size]<<"\n";

	handle_remove_node_binary_min_heap(&heap);

	cout<<"heap [after performing remove operation]: ";
	display_binary_min_heap(&heap);
	cout<<"\n";

	cout<<"removed value: "<<heap.A[heap.size]<<"\n";

	return 0;
}