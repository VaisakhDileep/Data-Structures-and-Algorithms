/*
Created by  : Vaisakh Dileep
Date		: 11, July, 2021
Description : This program demonstrates depth first search for a weighed directed graph represented using adjacency matrix.
*/

#include<iostream>

#include<iomanip>

using namespace std;

namespace Weighed_Directed_Graph_Using_Adjacency_Matrix // Weighed Directed Graph is designed using Adjacency Matrix representation.
{
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

	void add_edge_weighed_directed_graph(Weighed_Directed_Graph *wd_graph, Weighed_Edge w_edge)
	{
		if(wd_graph == nullptr)
		{
			throw string {"ERROR - Invalid operation, graph is not valid ....."};
		}

		if((w_edge.vertex_1 < 0) or (w_edge.vertex_2 < 0))
		{
			throw string {"ERROR - Invalid operation, given edge contains negative vertex ....."};
		}

		if((w_edge.vertex_1 < wd_graph->rows) and (w_edge.vertex_2 < wd_graph->columns))
		{
			wd_graph->A[w_edge.vertex_1][w_edge.vertex_2] = w_edge.weight;
		}
		else
		{
			int new_rows {(w_edge.vertex_1 > (wd_graph->rows - 1)) ? w_edge.vertex_1 + 1 : wd_graph->rows};

			int new_columns {(w_edge.vertex_2 > (wd_graph->columns - 1)) ? w_edge.vertex_2 + 1 : wd_graph->columns};

			Weighed_Directed_Graph temp {new int*[new_rows] {}, new_rows, new_columns};

			for(int i {0}; i < new_rows; i++)
			{
				temp.A[i] = new int[new_columns] {};
			}

			for(int i {0}; i < wd_graph->rows; i++)
			{
				for(int j {0}; j < wd_graph->columns; j++)
				{
					temp.A[i][j] = wd_graph->A[i][j];
				}
			}

			temp.A[w_edge.vertex_1][w_edge.vertex_2] = w_edge.weight;

			delete_weighed_directed_graph(wd_graph);

			wd_graph->A = temp.A;

			wd_graph->rows = temp.rows;

			wd_graph->columns = temp.columns;
		}
	}

	void create_weighed_directed_graph(Weighed_Directed_Graph *wd_graph, Weighed_Edge *w_edges, int num_edges)
	{
		if(wd_graph == nullptr)
		{
			throw string {"ERROR - Invalid operation, graph is not valid ....."};
		}

		for(int i {0}; i < num_edges; i++)
		{
			try
			{
				add_edge_weighed_directed_graph(wd_graph, w_edges[i]);
			}
			catch(string &ex)
			{
				throw string {"ERROR - Invalid operation, given set of edges is not valid ....."};
			}
		}
	}

	void handle_create_weighed_directed_graph(Weighed_Directed_Graph *wd_graph, Weighed_Edge *w_edges, int num_edges)
	{
		try
		{
			create_weighed_directed_graph(wd_graph, w_edges, num_edges);
		}
		catch(string &ex)
		{
			cout<<ex;
		}
	}
}

using namespace Weighed_Directed_Graph_Using_Adjacency_Matrix;

void depth_first_search(Weighed_Directed_Graph *wd_graph, int node, int *visited)
{
	if(visited[node] == 0)
	{
		cout<<node<<" ";

		visited[node] = 1;

		for(int i {0}; i < wd_graph->columns; i++)
		{
			if((wd_graph->A[node][i] != 0) and (visited[i] == 0)) // Not necessary to include "visited[i] == 0", but saves recursive calls.
			{
				depth_first_search(wd_graph, i, visited);
			}
		}
	}
}

void handle_depth_first_search(Weighed_Directed_Graph *wd_graph, int root = 0)
{
	if(wd_graph == nullptr)
	{
		cout<<"ERROR - Invalid operation, graph is not valid .....";

		return ;
	}

	if(root < 0)
	{
		cout<<"ERROR - Invalid root vertex, vertex cannot be negative .....";

		return ;
	}

	int max_node {(wd_graph->rows > wd_graph->columns) ? wd_graph->rows : wd_graph->columns};

	depth_first_search(wd_graph, root, new int[max_node] {0});
}

int main()
{
	Weighed_Directed_Graph wd_graph {};

	Weighed_Edge w_edges[11] {Weighed_Edge {0, 1, 10}, Weighed_Edge {1, 2, 20}, Weighed_Edge {1, 3, 30}, Weighed_Edge {3, 4, 40}, Weighed_Edge {4, 5, 50}, Weighed_Edge {4, 6, 60}, Weighed_Edge {4, 7, 70}, Weighed_Edge {5, 6, 80}, Weighed_Edge {5, 8, 90}, Weighed_Edge {7, 8, 100}, Weighed_Edge {8, 2, 110}};

	handle_create_weighed_directed_graph(&wd_graph, w_edges, 11);

	cout<<"wd_graph: \n";
	display_weighed_directed_graph(&wd_graph);
	cout<<"\n";

	cout<<"DFS(wd_graph): ";
	handle_depth_first_search(&wd_graph);
	cout<<"\n";

	handle_depth_first_search(&wd_graph, -1);
	cout<<"\n";

	return 0;
}