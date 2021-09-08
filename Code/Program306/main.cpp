/*
Created by  : Vaisakh Dileep
Date		: 6, July, 2021
Description : This program displays a binary min heap.
*/

#include<iostream>

using namespace std;

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

int main()
{
	Binary_Min_Heap heap {new int[8] {1, 5, 15, 12, 20, 25, 30, 18}, 8, 15};

	cout<<"heap: ";
	display_binary_min_heap(&heap);
	cout<<"\n";

	return 0;
}