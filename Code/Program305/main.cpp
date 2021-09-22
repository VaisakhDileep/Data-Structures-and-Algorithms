/*
Created by  : Vaisakh Dileep
Date		: 6, July, 2021
Description : This program finds the height of a binary min heap.
*/

#include<iostream>

#include<math.h>

using namespace std;

struct Binary_Min_Heap
{
	int *A;

	int size {0};

	int alloted_size {0};
};

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

	return height - 1; // We are only counting the edges for height.
}

int handle_height_binary_min_heap(Binary_Min_Heap *heap)
{
	try
	{
		return height_binary_min_heap(heap);
	}
	catch(string &ex)
	{
		cout<<ex;

		return -1;
	}
}

int main()
{
	Binary_Min_Heap heap {new int[8] {1, 5, 15, 12, 20, 25, 30, 18}, 8, 15};

	cout<<"handle_height_binary_min_heap(heap): "<<handle_height_binary_min_heap(&heap)<<"\n";

	return 0;
}