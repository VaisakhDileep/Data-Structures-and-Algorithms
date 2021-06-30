/*
Created by  : Vaisakh Dileep
Date		: 30, June, 2021
Description : This program demonstrates depth first search for an undirected graph represented using adjacency matrix.
*/

#include<iostream>

#include<iomanip>

using namespace std;

namespace Undirected_Graph_Using_Adjacency_Matrix // Undirected Graph is designed using Adjacency Matrix representation.
{
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
			int new_n {(edge.vertex_1 > edge.vertex_2) ? edge.vertex_1 + 1 : edge.vertex_2 + 1};

			Undirected_Graph temp {new int*[new_n] {}, new_n};

			for(int i {0}; i < new_n; i++)
			{
				temp.A[i] = new int[new_n] {};
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
}

using namespace Undirected_Graph_Using_Adjacency_Matrix;

void depth_first_search(Undirected_Graph *u_graph, int node, int *visited)
{
	if(visited[node] == 0)
	{
		cout<<node<<" ";

		visited[node] = 1;

		for(int i {0}; i < u_graph->n; i++)
		{
			if((u_graph->A[node][i] == 1) and (visited[i] == 0)) // Not necessary to include "visited[i] == 0", but saves recursive calls.
			{
				depth_first_search(u_graph, i, visited);
			}
		}
	}
}

void handle_depth_first_search(Undirected_Graph *u_graph, int root = 0)
{
	if(u_graph == nullptr)
	{
		cout<<"ERROR - Invalid operation, graph is not valid .....";

		return ;
	}

	if(root < 0)
	{
		cout<<"ERROR - Invalid root vertex, vertex cannot be negative .....";

		return ;
	}

	depth_first_search(u_graph, root, new int[u_graph->n] {0});
}

int main()
{
	Undirected_Graph u_graph {};

	Edge edges[9] {Edge {0, 1}, Edge {0, 2}, Edge {0, 3}, Edge {1, 2}, Edge {3, 4}, Edge {2, 4}, Edge {4, 5}, Edge {4, 6}, Edge {3, 2}};

	handle_create_undirected_graph(&u_graph, edges, 9);

	cout<<"u_graph: \n";
	display_undirected_graph(&u_graph);
	cout<<"\n";

	cout<<"DFS(u_graph): ";
	handle_depth_first_search(&u_graph);
	cout<<"\n";

	handle_depth_first_search(&u_graph, -1);
	cout<<"\n";

	return 0;
}