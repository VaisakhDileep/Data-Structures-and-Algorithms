/*
Created by  : Vaisakh Dileep
Date		: 10, August, 2021
Description : This program performs the range minimum query operation on the segment tree.
*/

#include<iostream>

#include<vector>

#include<math.h>

using namespace std;

struct Segment_Tree
{
	vector<int> *tree;
};

void insert_segment_tree(vector<int> *input_array, Segment_Tree *segment_tree, int start, int end, int root)
{
	if(start == end)
	{
		segment_tree->tree->at(root) = input_array->at(start);

		return ;
	}

	int mid {(start + end) / 2};

	insert_segment_tree(input_array, segment_tree, start, mid, 2 * root + 1); // left child.

	insert_segment_tree(input_array, segment_tree, mid + 1, end, 2 * root + 2); // right child.

	segment_tree->tree->at(root) = min(segment_tree->tree->at(2 * root + 1), segment_tree->tree->at(2 * root + 2));
}

Segment_Tree* construct_segment_tree(vector<int> *input_array)
{
	if(input_array == nullptr)
	{
		throw string {"ERROR - Invalid operation, input array is not valid ....."};
	}

	if(input_array->size() == 0)
	{
		throw string {"ERROR - Invalid operation, input array is empty ....."};
	}

	int num_leaf_nodes {pow(2, ceil(log2(input_array->size())))}; // Minimum number of leaf nodes required.

	int segment_tree_node_count {num_leaf_nodes + (num_leaf_nodes - 1)}; // For a complete binary tree, "num_leaf_nodes = num_internal_nodes + 1".

	Segment_Tree *segment_tree {new Segment_Tree {new vector<int>(segment_tree_node_count, 0)}};

	insert_segment_tree(input_array, segment_tree, 0, input_array->size() - 1, 0);

	return segment_tree;
}

Segment_Tree* handle_construct_segment_tree(vector<int> *input_array)
{
	try
	{
		return construct_segment_tree(input_array);
	}
	catch(string &ex)
	{
		cout<<ex;
	}
}

void display_segment_tree(Segment_Tree *segment_tree)
{
	if(segment_tree == nullptr)
	{
		return ;
	}

	for(int i {0}; i < segment_tree->tree->size(); i++)
	{
		cout<<segment_tree->tree->at(i)<<" ";
	}
}

int search_segment_tree(Segment_Tree *segment_tree, int query_low, int query_high, int low, int high, int position)
{
	if((query_low <= low) and (query_high >= high)) // Total overlap.
	{
		return segment_tree->tree->at(position);
	}

	if((query_low > high) or (query_high < low)) // No overlap.
	{
		return INT_MAX;
	}

	int mid {(low + high) / 2};

	return min(search_segment_tree(segment_tree, query_low, query_high, low, mid, 2 * position + 1), search_segment_tree(segment_tree, query_low, query_high, mid + 1, high, 2 * position + 2)); // Partial overlap.
}

int range_minimum_query_segment_tree(vector<int> *input_array, Segment_Tree *segment_tree, int query_low, int query_high) // Both "query_low" and "query_high" are inclusive.
{
	if(segment_tree == nullptr)
	{
		throw string {"ERROR - Invalid operation, segment tree is not valid ....."};
	}

	if(segment_tree->tree->size() == 0)
	{
		throw string {"ERROR - Invalid operation, segment tree is empty ....."};
	}

	if((query_low < 0) or (query_high < 0))
	{
		throw string {"ERROR - Invalid operation, query bounds cannot be negative ....."};
	}

	if((query_low >= input_array->size()) or (query_high >= input_array->size()))
	{
		throw string {"ERROR - Invalid operation, query bounds exceeds the input_array size ....."};
	}

	if(query_low > query_high)
	{
		throw string {"ERROR - Invalid operation, query lower bound exceeds query upper bound ....."};
	}

	return search_segment_tree(segment_tree, query_low, query_high, 0, input_array->size() - 1, 0);
}

int handle_range_minimum_query_segment_tree(vector<int> *input_array, Segment_Tree *segment_tree, int query_low, int query_high)
{
	try
	{
		return range_minimum_query_segment_tree(input_array, segment_tree, query_low, query_high);
	}
	catch(string &ex)
	{
		cout<<ex;
	}
}

int main()
{
	vector<int> *input_array {new vector<int> {-1, -2, -3, -4, 5}};

	Segment_Tree *segment_tree {handle_construct_segment_tree(input_array)};

	cout<<"segment_tree: ";
	display_segment_tree(segment_tree);
	cout<<"\n";

	cout<<"range_minimum_query_segment_tree(input_array, segment_tree, 0, 1): "<<handle_range_minimum_query_segment_tree(input_array, segment_tree, 0, 1)<<"\n";

	cout<<"range_minimum_query_segment_tree(input_array, segment_tree, 0, 4): "<<handle_range_minimum_query_segment_tree(input_array, segment_tree, 0, 4)<<"\n";

	cout<<"range_minimum_query_segment_tree(input_array, segment_tree, 1, 0): "<<handle_range_minimum_query_segment_tree(input_array, segment_tree, 1, 0)<<"\n";

	cout<<"range_minimum_query_segment_tree(input_array, segment_tree, 0, -1): "<<handle_range_minimum_query_segment_tree(input_array, segment_tree, 0, -1)<<"\n";

	cout<<"range_minimum_query_segment_tree(input_array, segment_tree, 6, 1): "<<handle_range_minimum_query_segment_tree(input_array, segment_tree, 6, 1)<<"\n";

	return 0;
}