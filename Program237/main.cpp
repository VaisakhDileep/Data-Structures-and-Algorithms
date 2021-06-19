/*
Created by  : Vaisakh Dileep
Date		: 16, June, 2021
Description : This program creates an undirected graph.
*/

// Note: Nodes in the graph are labelled from '0'.

#include<bits/stdc++.h>

using namespace std;

struct Undirected_Graph // This is a square matrix.
{
	int **A; // dynamically created 2-D array.

	int n; // number of rows or columns.
};

struct Edge // Unweighted edge.
{
	int vertex_1;

	int vertex_2;
};

int main()
{
	Undirected_Graph u_graph {new int*[5] {new int[5] {0, 1, 1, 1, 0}, new int[5] {1, 0, 1, 0, 0}, new int[5] {1, 1, 0, 1, 1}, new int [5] {1, 0, 1, 0, 1}, new int[5] {0, 0, 1, 1, 0}}, 5};

	return 0;
}