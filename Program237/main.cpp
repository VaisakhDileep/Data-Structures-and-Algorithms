/*
Created by  : Vaisakh Dileep
Date		: 16, June, 2021
Description : This program creates an undirected graph.
*/

// Note: Nodes in the graph are labelled from '0'.

#include<bits/stdc++.h>

using namespace std;

struct Undirected_Graph
{
	int **A;

	int num_nodes;
};

int main()
{
	Undirected_Graph u_graph {new int*[5] {new int[5] {0, 1, 1, 1, 0}, new int[5] {1, 0, 1, 0, 0}, new int[5] {1, 1, 0, 1, 1}, new int [5] {1, 0, 1, 0, 1}, new int[5] {0, 0, 1, 1, 0}}, 5};

	return 0;
}