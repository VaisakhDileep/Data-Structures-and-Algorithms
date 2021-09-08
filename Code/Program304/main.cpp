/*
Created by  : Vaisakh Dileep
Date		: 6, July, 2021
Description : This program creates a binary min heap.
*/

#include<iostream>

using namespace std;

struct Binary_Min_Heap // binary min heap is a complete tree.
{
	int *A;

	int size {0};

	int alloted_size {0};
};

int main()
{
	Binary_Min_Heap heap {new int[8] {1, 5, 15, 12, 20, 25, 30, 18}, 8, 15};

	return 0;
}