/*
Created by  : Vaisakh Dileep
Date		: 19, June, 2021
Description : This program creates a weighed undirected graph.
*/

// Note: Nodes in the graph are labelled from '0'.

#include<iostream>

using namespace std;

struct Weighed_Undirected_Graph // Using adjacency matrix.
{
	int **A; // dynamically created 2-D array.

	int n; // number of rows or columns.
};

struct Weighed_Edge // edge with weight.
{
	int vertex_1;

	int vertex_2;

	int weight;
};

int main()
{
	Weighed_Undirected_Graph wu_graph {new int*[5] {new int[5] {0, 3, 0, 0, 7}, new int[5] {3, 0, 0, 0, 0}, new int[5] {0, 0, 0, 8, 0}, new int[5] {0, 0, 8, 0, 0}, new int[5] {7, 0, 0, 0, 0}}, 5};

	return 0;
}