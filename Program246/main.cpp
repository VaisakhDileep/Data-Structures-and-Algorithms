/*
Created by  : Vaisakh Dileep
Date		: 19, June, 2021
Description : This program deletes a weighed undirected graph.
*/

#include<iostream>

using namespace std;

struct Weighed_Undirected_Graph
{
	int **A;

	int n;
};

struct Weighed_Edge
{
	int vertex_1;

	int vertex_2;

	int weight;
};

void delete_weighed_undirected_graph(Weighed_Undirected_Graph *u_graph)
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

void handle_delete_weighed_undirected_graph(Weighed_Undirected_Graph *wu_graph)
{
	try
	{
		delete_weighed_undirected_graph(wu_graph);
	}
	catch(string &ex)
	{
		cout<<ex;
	}
}

int main()
{
	Weighed_Undirected_Graph wu_graph {new int*[5] {new int[5] {0, 3, 0, 0, 7}, new int[5] {3, 0, 0, 0, 0}, new int[5] {0, 0, 0, 8, 0}, new int[5] {0, 0, 8, 0, 0}, new int[5] {7, 0, 0, 0, 0}}, 5};

	handle_delete_weighed_undirected_graph(&wu_graph);

	return 0;
}