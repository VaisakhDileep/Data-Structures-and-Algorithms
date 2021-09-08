/*
Created by  : Vaisakh Dileep
Date		: 19, June, 2021
Description : This program creates a weighed undirected graph.
*/

// Note: Nodes in the graph are labelled from '0'.

#include<iostream>

#include<vector>

using namespace std;

struct Weighed_Undirected_Graph // Using adjacency matrix.
{
	vector<vector<int>*> *A; // dynamically created 2-D array.
};

struct Weighed_Edge // edge with weight.
{
	int vertex_1;

	int vertex_2;

	int weight;
};

int main()
{
	Weighed_Undirected_Graph wu_graph {new vector<vector<int>*> {new vector<int> {0, 3, INT_MAX, INT_MAX, 7}, new vector<int> {3, 0, INT_MAX, INT_MAX, INT_MAX}, new vector<int> {INT_MAX, INT_MAX, 0, 8, INT_MAX}, new vector<int> {INT_MAX, INT_MAX, 8, 0, INT_MAX}, new vector<int> {7, INT_MAX, INT_MAX, INT_MAX, 0}}};

	return 0;
}