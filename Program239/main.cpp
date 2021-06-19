/*
Created by  : Vaisakh Dileep
Date		: 17, June, 2021
Description : This program deletes an undirected graph.
*/

#include<iostream>

using namespace std;

struct Undirected_Graph
{
	int **A;

	int n;
};

struct Edge
{
	int vertex_1;

	int vertex_2;
};

void delete_undirected_graph(Undirected_Graph *u_graph)
{
	if(u_graph == nullptr)
	{
		throw string {"ERROR - Invalid operation, graph is not valid ....."};
	}

	for(int i {0}; i < u_graph->n; i++)
	{
		delete[] u_graph->A[i];
	}

	delete[] u_graph->A;
}

void handle_delete_undirected_graph(Undirected_Graph *u_graph)
{
	try
	{
		delete_undirected_graph(u_graph);
	}
	catch(string &ex)
	{
		cout<<ex;
	}
}

int main()
{
	Undirected_Graph u_graph {new int*[5] {new int[5] {0, 1, 1, 1, 0}, new int[5] {1, 0, 1, 0, 0}, new int[5] {1, 1, 0, 1, 1}, new int [5] {1, 0, 1, 0, 1}, new int[5] {0, 0, 1, 1, 0}}, 5};

	handle_delete_undirected_graph(&u_graph);

	return 0;
}