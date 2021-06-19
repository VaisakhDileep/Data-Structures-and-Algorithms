/*
Created by  : Vaisakh Dileep
Date		: 18, June, 2021
Description : This program creates an undirected graph from an array of edges.
*/

#include<iostream>

#include<iomanip>

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

void display_undirected_graph(Undirected_Graph *u_graph)
{
	if(u_graph == nullptr)
	{
		cout<<"[\n]";

		return ;
	}

	cout<<"[\n     ";
	for(int i {0}; i < u_graph->n; i++)
	{
		cout<<setw(3)<<i<<" ";
	}
	cout<<"\n";

	for(int i {0}; i < u_graph->n; i++)
	{
		cout<<setw(3)<<left<<i<<right<<"[ ";
		for(int j {0}; j < u_graph->n; j++)
		{
			cout<<setw(3)<<u_graph->A[i][j]<<" ";
		}
		cout<<"]\n";
	}
	cout<<"]";
}

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

void add_edge_undirected_graph(Undirected_Graph *u_graph, Edge edge)
{
	if(u_graph == nullptr)
	{
		throw string {"ERROR - Invalid operation, graph is not valid ....."};
	}

	if((edge.vertex_1 < 0) or (edge.vertex_2 < 0))
	{
		throw string {"ERROR - Invalid operation, given edge contains negative vertex ....."};
	}

	if((edge.vertex_1 < u_graph->n) and (edge.vertex_2 < u_graph->n))
	{
		u_graph->A[edge.vertex_1][edge.vertex_2] = u_graph->A[edge.vertex_2][edge.vertex_1] = 1;
	}
	else
	{
		int new_num_nodes {(edge.vertex_1 > edge.vertex_2) ? edge.vertex_1 + 1 : edge.vertex_2 + 1};

		Undirected_Graph temp {new int*[new_num_nodes] {}, new_num_nodes};

		for(int i {0}; i < new_num_nodes; i++)
		{
			temp.A[i] = new int[new_num_nodes] {};
		}

		for(int i {0}; i < u_graph->n; i++)
		{
			for(int j {0}; j < u_graph->n; j++)
			{
				temp.A[i][j] = u_graph->A[i][j];
			}
		}

		temp.A[edge.vertex_1][edge.vertex_2] = temp.A[edge.vertex_2][edge.vertex_1] = 1;

		delete_undirected_graph(u_graph);

		u_graph->A = temp.A;

		u_graph->n = temp.n;
	}
}

void create_undirected_graph(Undirected_Graph *u_graph, Edge *edges, int num_edges)
{
	if(u_graph == nullptr)
	{
		throw string {"ERROR - Invalid operation, graph is not valid ....."};
	}

	for(int i {0}; i < num_edges; i++)
	{
		try
		{
			add_edge_undirected_graph(u_graph, edges[i]);
		}
		catch(string &ex)
		{
			throw string {"ERROR - Invalid operation, given set of edges is not valid ....."};
		}
	}
}

void handle_create_undirected_graph(Undirected_Graph *u_graph, Edge *edges, int num_edges)
{
	try
	{
		create_undirected_graph(u_graph, edges, num_edges);
	}
	catch(string &ex)
	{
		cout<<ex;
	}
}

int  main()
{
	Undirected_Graph u_graph {};

	Edge edges[10] {Edge {0, 1}, Edge {0, 3}, Edge {1, 2}, Edge {0, 10}, Edge {5, 9}, Edge {9, 7}, Edge {0, 6}, Edge {3, 4}, Edge {4, 5}, Edge {8, 1}};

	handle_create_undirected_graph(&u_graph, edges, 10);

	cout<<"u_graph:\n";
	display_undirected_graph(&u_graph);
	cout<<"\n";

	return 0;
}