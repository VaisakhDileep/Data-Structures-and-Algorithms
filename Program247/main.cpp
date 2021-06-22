/*
Created by  : Vaisakh Dileep
Date		: 19, June, 2021
Description : This program inserts an edge to a weighed undirected graph.
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

void add_edge_weighed_undirected_graph(Weighed_Undirected_Graph *wu_graph, Weighed_Edge w_edge)
{
	if(wu_graph == nullptr)
	{
		throw string {"ERROR - Invalid operation, graph is not valid ....."};
	}

	if((w_edge.vertex_1 < 0) or (w_edge.vertex_2 < 0))
	{
		throw string {"ERROR - Invalid operation, given edge contains negative vertex ....."};
	}

	if((w_edge.vertex_1 < wu_graph->n) and (w_edge.vertex_2 < wu_graph->n))
	{
		wu_graph->A[w_edge.vertex_1][w_edge.vertex_2] = wu_graph->A[w_edge.vertex_2][w_edge.vertex_1] = w_edge.weight;
	}
	else
	{
		int new_n {(w_edge.vertex_1 > w_edge.vertex_2) ? w_edge.vertex_1 + 1 : w_edge.vertex_2 + 1};

		Weighed_Undirected_Graph temp {new int*[new_n] {}, new_n};

		for(int i {0}; i < new_n; i++)
		{
			temp.A[i] = new int[new_n] {};
		}

		for(int i {0}; i < wu_graph->n; i++)
		{
			for(int j {0}; j < wu_graph->n; j++)
			{
				temp.A[i][j] = wu_graph->A[i][j];
			}
		}

		temp.A[w_edge.vertex_1][w_edge.vertex_2] = temp.A[w_edge.vertex_2][w_edge.vertex_1] = w_edge.weight;

		delete_weighed_undirected_graph(wu_graph);

		wu_graph->A = temp.A;

		wu_graph->n = temp.n;
	}
}

void handle_add_edge_weighed_undirected_graph(Weighed_Undirected_Graph *wu_graph, Weighed_Edge w_edge)
{
	try
	{
		add_edge_weighed_undirected_graph(wu_graph, w_edge);
	}
	catch(string &ex)
	{
		cout<<ex;
	}
}

int main()
{
	Weighed_Undirected_Graph wu_graph {new int*[5] {new int[5] {0, 3, 0, 0, 7}, new int[5] {3, 0, 0, 0, 0}, new int[5] {0, 0, 0, 8, 0}, new int[5] {0, 0, 8, 0, 0}, new int[5] {7, 0, 0, 0, 0}}, 5};

	cout<<"u_graph:\n";
	display_weighed_undirected_graph(&wu_graph);
	cout<<"\n\n";

	handle_add_edge_weighed_undirected_graph(&wu_graph, Weighed_Edge {0, 4, 10});

	cout<<"u_graph [after adding {0, 4, 10}]: \n";
	display_weighed_undirected_graph(&wu_graph);
	cout<<"\n\n";

	handle_add_edge_weighed_undirected_graph(&wu_graph, Weighed_Edge {1, 5, 11});

	cout<<"u_graph [after adding {1, 5, 11}]: \n";
	display_weighed_undirected_graph(&wu_graph);
	cout<<"\n\n";

	handle_add_edge_weighed_undirected_graph(&wu_graph, Weighed_Edge {-1, 2, 12});
	cout<<"\n";

	return 0;
}