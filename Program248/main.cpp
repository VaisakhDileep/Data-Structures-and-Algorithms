/*
Created by  : Vaisakh Dileep
Date		: 19, June, 2021
Description : This program removes an edge from a weighed undirected graph.
*/

#include<iostream>

#include<iomanip>

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

void display_weighed_undirected_graph(Weighed_Undirected_Graph *wu_graph)
{
	if(wu_graph == nullptr)
	{
		cout<<"[\n]";

		return ;
	}

	cout<<"[\n     ";
	for(int i {0}; i < wu_graph->n; i++)
	{
		cout<<setw(3)<<i<<" ";
	}
	cout<<"\n";

	for(int i {0}; i < wu_graph->n; i++)
	{
		cout<<setw(3)<<left<<i<<right<<"[ ";
		for(int j {0}; j < wu_graph->n; j++)
		{
			cout<<setw(3)<<wu_graph->A[i][j]<<" ";
		}
		cout<<"]\n";
	}
	cout<<"]";
}

void remove_edge_weighed_undirected_graph(Weighed_Undirected_Graph *wu_graph, Weighed_Edge w_edge)
{
	if(wu_graph == nullptr)
	{
		throw string {"ERROR - Invalid operation, graph is not valid ....."};
	}

	if((w_edge.vertex_1 < 0) or (w_edge.vertex_2 < 0))
	{
		throw string {"ERROR - Invalid operation, given edge contains negative vertex ....."};
	}

	if((w_edge.vertex_1 >= wu_graph->n) or (w_edge.vertex_2 >= wu_graph->n))
	{
		throw string {"ERROR - Invalid operation, given edge not present in the graph ....."};
	}

	wu_graph->A[w_edge.vertex_1][w_edge.vertex_2] = wu_graph->A[w_edge.vertex_2][w_edge.vertex_1] = 0;
}

void handle_remove_edge_weighed_undirected_graph(Weighed_Undirected_Graph *wu_graph, Weighed_Edge w_edge)
{
	try
	{
		remove_edge_weighed_undirected_graph(wu_graph, w_edge);
	}
	catch(string &ex)
	{
		cout<<ex;
	}
}

int main()
{
	Weighed_Undirected_Graph wu_graph {new int*[5] {new int[5] {9, 3, 0, 0, 7}, new int[5] {3, 0, 0, 0, 0}, new int[5] {0, 0, 0, 8, 0}, new int[5] {0, 0, 8, 0, 0}, new int[5] {7, 0, 0, 0, 0}}, 5};

	cout<<"u_graph: \n";
	display_weighed_undirected_graph(&wu_graph);
	cout<<"\n";

	handle_remove_edge_weighed_undirected_graph(&wu_graph, Weighed_Edge {0, 1, 0}); // Providing "weight" is not necessary.

	cout<<"u_graph [after removing {0, 1}]: \n";
	display_weighed_undirected_graph(&wu_graph);
	cout<<"\n";

	handle_remove_edge_weighed_undirected_graph(&wu_graph, Weighed_Edge {0, 0, 0});

	cout<<"u_graph [after removing {0, 0}]: \n";
	display_weighed_undirected_graph(&wu_graph);
	cout<<"\n";

	handle_remove_edge_weighed_undirected_graph(&wu_graph, Weighed_Edge {-1, 2});
	cout<<"\n";

	handle_remove_edge_weighed_undirected_graph(&wu_graph, Weighed_Edge {0, 5});
	cout<<"\n";

	return 0;
}