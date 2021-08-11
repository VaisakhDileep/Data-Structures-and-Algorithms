/*
Created by  : Vaisakh Dileep
Date		: 10, August, 2021
Description : This program detects the presence of a negative cycle in a weighed directed graph represented using adjacency matrix(Floyd Warshall's algorithm).
*/

#include<iostream>

#include<iomanip>

#include<vector>

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

bool detect_negative_cycle_weighed_directed_graph(Weighed_Directed_Graph *wd_graph) // Floyd Warshall algorithm.
{
	if(wd_graph == nullptr)
	{
		throw string {"ERROR - Invalid operation, graph is not valid ....."};
	}

	int max_dimension {(wd_graph->rows > wd_graph->columns) ? wd_graph->rows : wd_graph->columns};

	vector<vector<int>*> *distance {new vector<vector<int>*>(wd_graph->rows, new vector<int>(wd_graph->columns, INT_MAX))};

	for(int i {0}; i < wd_graph->rows; i++)
	{
		for(int j {0}; j < wd_graph->columns; j++)
		{
			distance->at(i)->at(j) = wd_graph->A[i][j];
		}
	}

	for(int k {0}; k < max_dimension; k++)
	{
		
	}
}

int main()
{
	return 0;
}