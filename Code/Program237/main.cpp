/*
Created by  : Vaisakh Dileep
Date		: 16, June, 2021
Description : This program creates an undirected graph.
*/

// Note: Nodes in the graph are labelled from '0'.

#include<iostream>

#include<vector>

using namespace std;

struct Undirected_Graph // Using adjacency matrix.
{
	vector<vector<int>*> *A; // dynamically created 2-D vector array.
};

struct Edge // Unweighted edge.
{
	int vertex_1;

	int vertex_2;
};

int main()
{
	Undirected_Graph u_graph {new vector<vector<int>*> {new vector<int> {0, 1, 1, 1, 0}, new vector<int> {1, 0, 1, 0, 0}, new vector<int> {1, 1, 0, 1, 1}, new vector<int> {1, 0, 1, 0, 1}, new vector<int> {0, 0, 1, 1, 0}}};

	return 0;
}