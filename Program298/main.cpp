/*
Created by  : Vaisakh Dileep
Date		: 5, July, 2021
Description : This program finds the height of a binary max heap.
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

	return (height - 1);
}

int handle_height_binary_max_heap(Binary_Max_Heap *heap)
{
	try
	{
		return height_binary_max_heap(heap);
	}
	catch(string &ex)
	{
		cout<<ex;

		return -1;
	}
}

int main()
{
	Binary_Max_Heap heap {new int[8] {40, 30, 15, 20, 10, 12, 6, 5}, 8, 15};

	cout<<"handle_height_binary_max_heap(heap): "<<handle_height_binary_max_heap(&heap)<<"\n";

	return 0;
}