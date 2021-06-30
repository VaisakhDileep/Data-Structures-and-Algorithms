/*
Created by  : Vaisakh Dileep
Date		: 29, June, 2021
Description : This program removes an edge from a weighed directed graph.
*/

#include<iostream>

#include<iomanip>

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

void display_weighed_directed_graph(Weighed_Directed_Graph *wd_graph)
{
	if(wd_graph == nullptr)
	{
		cout<<"[\n]";

		return ;
	}

	cout<<"[\n     ";
	for(int i {0}; i < wd_graph->columns; i++)
	{
		cout<<setw(3)<<i<<" ";
	}
	cout<<"\n";

	for(int i {0}; i < wd_graph->rows; i++)
	{
		cout<<setw(3)<<left<<i<<right<<"[ ";
		for(int j {0}; j < wd_graph->columns; j++)
		{
			cout<<setw(3)<<wd_graph->A[i][j]<<" ";
		}
		cout<<"]\n";
	}
	cout<<"]";
}

void remove_edge_weighed_directed_graph(Weighed_Directed_Graph *wd_graph, Weighed_Edge w_edge)
{
	if(wd_graph == nullptr)
	{
		throw string {"ERROR - Invalid operation, graph is not valid ....."};
	}

	if((w_edge.vertex_1 < 0) or (w_edge.vertex_2 < 0))
	{
		throw string {"ERROR - Invalid operation, given edge contains negative vertex ....."};
	}

	if((w_edge.vertex_1 >= wd_graph->rows) or (w_edge.vertex_2 >= wd_graph->columns))
	{
		throw string {"ERROR - Invalid operation, given edge not present in the graph ....."};
	}

	wd_graph->A[w_edge.vertex_1][w_edge.vertex_2] = 0;
}

void handle_remove_edge_weighed_directed_graph(Weighed_Directed_Graph *wd_graph, Weighed_Edge w_edge)
{
	try
	{
		remove_edge_weighed_directed_graph(wd_graph, w_edge);
	}
	catch(string &ex)
	{
		cout<<ex;
	}
}

int main()
{
	Weighed_Directed_Graph wd_graph {new int*[5] {new int[3] {0, 0, 4}, new int[3] {1, 0, 0}, new int[3] {1, 2, 0}, new int[3] {7, 5, 0}, new int[3] {8, 3, 2}}, 5, 3};

	cout<<"wd_graph: \n";
	display_weighed_directed_graph(&wd_graph);
	cout<<"\n";

	handle_remove_edge_weighed_directed_graph(&wd_graph, Weighed_Edge {0, 2, 0}); // Providing "weight" is not necessary.

	cout<<"wd_graph: [after removing {0, 2}] \n";
	display_weighed_directed_graph(&wd_graph);
	cout<<"\n";

	handle_remove_edge_weighed_directed_graph(&wd_graph, Weighed_Edge {-1, 2});
	cout<<"\n";

	handle_remove_edge_weighed_directed_graph(&wd_graph, Weighed_Edge {0, 3});
	cout<<"\n";

	handle_remove_edge_weighed_directed_graph(&wd_graph, Weighed_Edge {0, 5});
	cout<<"\n";

	return 0;
}