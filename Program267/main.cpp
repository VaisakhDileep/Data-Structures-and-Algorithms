/*
Created by  : Vaisakh Dileep
Date		: 26, June, 2021
Description : This program deletes a directed graph.
*/

#include<iostream>

using namespace std;

struct Directed_Graph
{
	int **A;

	int rows;

	int columns;
};

struct Edge
{
	int vertex_1;

	int vertex_2;
};

void delete_directed_graph(Directed_Graph *d_graph)
{
	if(d_graph == nullptr)
	{
		throw string {"ERROR - Invalid operation, graph is not valid ....."};
	}

	for(int i {0}; i < d_graph->rows; i++)
	{
		delete[] d_graph->A[i];
	}

	delete[] d_graph->A;
}

void handle_delete_directed_graph(Directed_Graph *d_graph)
{
	try
	{
		delete_directed_graph(d_graph);
	}
	catch(string &ex)
	{
		cout<<ex;
	}
}

int main()
{
	Directed_Graph d_graph {new int*[5] {new int[4] {0, 1, 0, 1}, new int[4] {0, 0, 1, 0}, new int[4] {1, 1, 0, 0}, new int[4] {1, 1, 0, 0}, new int[4] {1, 0, 0, 0}}, 5, 4};

	handle_delete_directed_graph(&d_graph);

	return 0;
}