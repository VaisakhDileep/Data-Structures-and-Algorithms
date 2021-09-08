/*
Created by  : Vaisakh Dileep
Date		: 7, July, 2021
Description : This program converts a binary tree into a binary min heap(heapify algorithm).
*/

#include<iostream>

#include<math.h>

using namespace std;

namespace Binary_Tree_Using_Array // Binary Tree is designed using array representation.
{
	struct Binary_Tree
	{
		int *A;

		int size {0};

		int alloted_size {0};
	};

	void display_binary_tree(Binary_Tree *T)
	{
		if(T == nullptr)
		{
			return ;
		}

		for(int i {0}; i < T->size; i++)
		{
			if(T->A[i] == INT_MIN)
			{
				cout<<"- ";
			}
			else
			{
				cout<<T->A[i]<<" ";
			}
		}
	}

	int height_binary_tree(Binary_Tree *T)
	{
		if(T == nullptr)
		{
			throw string {"ERROR - Invalid operation, binary tree is not valid ....."};
		}

		if(T->size == 0)
		{
			return 0;
		}

		int height {0};

		int total_nodes {0};

		while(total_nodes < T->size)
		{
			total_nodes += pow(2, height);

			height++;
		}

		return height - 1;
	}

	void create_binary_tree(Binary_Tree *T, int *A, int size)
	{
		if(T == nullptr)
		{
			throw string {"ERROR - Invalid operation, binary tree is not valid ....."};
		}

		T->size = size;

		int height {height_binary_tree(T)};

		int number_nodes {static_cast<int>(pow(2, height + 1)) - 1}; // Number of nodes to safely hold the tree.

		T->size = size;

		T->alloted_size = number_nodes;

		T->A = new int[number_nodes] {};

		for(int i {0}; i < size; i++)
		{
			T->A[i] = A[i];
		}

		for(int i {size}; i < T->alloted_size; i++)
		{
			T->A[i] = INT_MIN;
		}
	}

	void handle_create_binary_tree(Binary_Tree *T, int *A, int size)
	{
		try
		{
			create_binary_tree(T, A, size);
		}
		catch(string &ex)
		{
			cout<<ex;
		}
	}
}

using namespace Binary_Tree_Using_Array;

void swap(int &x, int &y)
{
	int temp {y};

	y = x;
	x = temp;
}

void heapify_binary_tree_to_binary_min_heap(Binary_Tree *T, int node)
{
	if(T->A[node] == INT_MIN)
	{
		throw string {"ERROR - Invalid operation, binary tree is not complete ....."};
	}

	int left_child_index {2 * (node + 1) - 1}, right_child_index {left_child_index + 1};

	int smallest_child_index {-1};

	if((left_child_index >= T->size) and (right_child_index >= T->size)) // leaf node
	{
		return ;
	}

	if(left_child_index < T->size)
	{
		if(T->A[left_child_index] < T->A[node])
		{
			smallest_child_index = left_child_index;
		}
	}

	if(right_child_index < T->size)
	{
		if(T->A[right_child_index] < T->A[node])
		{
			if(smallest_child_index != -1)
			{
				if(T->A[right_child_index] < T->A[left_child_index])
				{
					smallest_child_index = right_child_index;
				}
			}
			else
			{
				smallest_child_index = right_child_index;
			}
		}
	}

	if(smallest_child_index != -1)
	{
		swap(T->A[node], T->A[smallest_child_index]);

		heapify_binary_tree_to_binary_min_heap(T, smallest_child_index);
	}
}

void handle_heapify_binary_tree_to_binary_min_heap(Binary_Tree *T)
{
	if(T == nullptr)
	{
		cout<<"ERROR - Invalid operation, binary tree is not valid .....";
	}

	if(T->size == 0)
	{
		cout<<"ERROR - Invalid operation, binary tree is empty .....";
	}

	for(int i {T->size - 1}; i >= 0; i--)
	{
		try
		{
			heapify_binary_tree_to_binary_min_heap(T, i);
		}
		catch(string &ex)
		{
			cout<<ex;

			return ;
		}
	}
}

int main()
{
	Binary_Tree T1 {}, T2 {};

	handle_create_binary_tree(&T1, new int[6] {50, 20, 40, 10, 5, 0}, 6);
	handle_create_binary_tree(&T2, new int[6] {50, 20, 40, 10, INT_MIN, 0}, 6);

	cout<<"T1: ";
	display_binary_tree(&T1);
	cout<<"\n";

	handle_heapify_binary_tree_to_binary_min_heap(&T1);

	cout<<"T2 [after heapify]: ";
	display_binary_tree(&T1);
	cout<<"\n";

	handle_heapify_binary_tree_to_binary_min_heap(&T2);
	cout<<"\n";

	return 0;
}