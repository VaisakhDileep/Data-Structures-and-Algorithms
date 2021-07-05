/*
Created by  : Vaisakh Dileep
Date		: 5, July, 2021
Description : This program displays a binary max heap.
*/

#include<iostream>

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

int main()
{
	Binary_Max_Heap heap {new int[8] {40, 30, 15, 20, 10, 12, 6, 5}, 8, 15};

	cout<<"heap: ";
	display_binary_max_heap(&heap);
	cout<<"\n";

	return 0;
}