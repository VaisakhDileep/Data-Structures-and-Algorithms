/*
Created by  : Vaisakh Dileep
Date		: 26, June, 2021
Description : This program inserts an edge to a directed graph.
*/

#include<iostream>

#include<iomanip>

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

void display_directed_graph(Directed_Graph *d_graph)
{
	if(d_graph == nullptr)
	{
		cout<<"[\n]";

		return ;
	}

	cout<<"[\n     ";
	for(int i {0}; i < d_graph->columns; i++)
	{
		cout<<setw(3)<<i<<" ";
	}
	cout<<"\n";

	for(int i {0}; i < d_graph->rows; i++)
	{
		cout<<setw(3)<<left<<i<<right<<"[ ";
		for(int j {0}; j < d_graph->columns; j++)
		{
			cout<<setw(3)<<d_graph->A[i][j]<<" ";
		}
		cout<<"]\n";
	}
	cout<<"]";
}

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

void add_edge_directed_graph(Directed_Graph *d_graph, Edge edge)
{
	if(d_graph == nullptr)
	{
		throw string {"ERROR - Invalid operation, graph is not valid ....."};
	}

	if((edge.vertex_1 < 0) or (edge.vertex_2 < 0))
	{
		throw string {"ERROR - Invalid operation, given edge contains negative vertex ....."};
	}

	if((edge.vertex_1 < d_graph->rows) and (edge.vertex_2 < d_graph->columns))
	{
		d_graph->A[edge.vertex_1][edge.vertex_2] = 1;
	}
	else
	{
		int new_rows {(edge.vertex_1 > (d_graph->rows - 1)) ? edge.vertex_1 + 1 : d_graph->rows};

		int new_columns {(edge.vertex_2 > (d_graph->columns - 1)) ? edge.vertex_2 + 1 : d_graph->columns};

		Directed_Graph temp {new int*[new_rows] {}, new_rows, new_columns};

		for(int i {0}; i < new_rows; i++)
		{
			temp.A[i] = new int[new_columns] {};
		}

		for(int i {0}; i < d_graph->rows; i++)
		{
			for(int j {0}; j < d_graph->columns; j++)
			{
				temp.A[i][j] = d_graph->A[i][j];
			}
		}

		temp.A[edge.vertex_1][edge.vertex_2] = 1;

		delete_directed_graph(d_graph);

		d_graph->A = temp.A;

		d_graph->rows = temp.rows;

		d_graph->columns = temp.columns;
	}
}

void handle_add_edge_directed_graph(Directed_Graph *d_graph, Edge edge)
{
	try
	{
		add_edge_directed_graph(d_graph, edge);
	}
	catch(string &ex)
	{
		cout<<ex;
	}
}

int main()
{
	Directed_Graph d_graph {new int*[5] {new int[3] {0, 1, 0}, new int[3] {0, 0, 1}, new int[3] {1, 1, 0}, new int[3] {1, 1, 0}, new int[3] {1, 0, 0}}, 5, 3};

	cout<<"d_graph: \n";
	display_directed_graph(&d_graph);
	cout<<"\n";

	handle_add_edge_directed_graph(&d_graph, Edge {0, 10});

	cout<<"d_graph [after adding {0, 10}]: \n";
	display_directed_graph(&d_graph);
	cout<<"\n";

	handle_add_edge_directed_graph(&d_graph, Edge {5, 4});

	cout<<"d_graph [after adding {0, 4}]: \n";
	display_directed_graph(&d_graph);
	cout<<"\n";

	handle_add_edge_directed_graph(&d_graph, Edge {-1, 2});
	cout<<"\n";

	return 0;
}