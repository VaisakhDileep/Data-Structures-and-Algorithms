/*
Created by  : Vaisakh Dileep
Date		: 28, June, 2021
Description : This program creates a weighed directed graph.
*/

// Note: Nodes in the graph are labelled from '0'.

#include<iostream>

using namespace std;

struct Weighed_Directed_Graph // Using adjacency matrix.
{
	int **A; // dynamically created 2-D array.

	int rows; // number of rows.

	int columns; // number of columns.
};

struct Weighed_Edge
{
	int vertex_1;

	int vertex_2;

	int weight;
};

int main()
{
	Weighed_Directed_Graph wd_graph {new int*[5] {new int[3] {0, 0, 4}, new int[3] {1, 0, 0}, new int[3] {1, 2, 0}, new int[3] {7, 5, 0}, new int[3] {8, 3, 2}}, 5, 3};

	return 0;
}