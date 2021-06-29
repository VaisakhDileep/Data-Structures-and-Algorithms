/*
Created by  : Vaisakh Dileep
Date		: 29, June, 2021
Description : This program deletes a weighed directed graph.
*/

#include<iostream>

using namespace std;

struct Weighed_Directed_Graph
{
	int **A;

	int rows;

	int columns;
};

struct Weighed_Edge
{
	int vertex_1;

	int vertex_2;

	int weight;
};

void delete_weighed_directed_graph(Weighed_Directed_Graph *wd_graph)
{
	if(wd_graph == nullptr)
	{
		throw string {"ERROR - Invalid operation, graph is not valid ....."};
	}

	for(int i {0}; i < wd_graph->rows; i++)
	{
		delete[] wd_graph->A[i];
	}

	delete[] wd_graph->A;
}

void handle_delete_weighed_directed_graph(Weighed_Directed_Graph *wd_graph)
{
	try
	{
		delete_weighed_directed_graph(wd_graph);
	}
	catch(string &ex)
	{
		cout<<ex;
	}
}

int main()
{
	Weighed_Directed_Graph wd_graph {new int*[5] {new int[3] {0, 0, 4}, new int[3] {1, 0, 0}, new int[3] {1, 2, 0}, new int[3] {7, 5, 0}, new int[3] {8, 3, 2}}, 5, 3};

	handle_delete_weighed_directed_graph(&wd_graph);

	return 0;
}