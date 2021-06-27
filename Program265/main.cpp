/*
Created by  : Vaisakh Dileep
Date		: 26, June, 2021
Description : This program creates a directed graph.
*/

// Note: Nodes in the graph are labelled from '0'.

#include<iostream>

using namespace std;

struct Directed_Graph // Using adjacency matrix.
{
	int **A; // dynamically created 2-D array.

	int rows; // number of rows.

	int columns; // number of columns.
};

struct Edge
{
	int vertex_1;

	int vertex_2;
};

int main()
{
	Directed_Graph d_graph {new int*[5] {new int[5] {0, 1, 0, 0, 1}, new int[5] {0, 0, 1, 0, 0}, new int[5] {1, 1, 0, 0, 0}, new int[5] {1, 1, 0, 0, 0}, new int[5] {1, 0, 0, 0, 0}}, 5, 5};

	return 0;
}