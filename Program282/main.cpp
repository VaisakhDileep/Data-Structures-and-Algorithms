/*
Created by  : Vaisakh Dileep
Date		: 29, June, 2021
Description : This program inserts an edge to a weighed directed graph.
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

void handle_add_edge_weighed_directed_graph(Weighed_Directed_Graph *wd_graph, Weighed_Edge w_edge)
{
	try
	{
		add_edge_weighed_directed_graph(wd_graph, w_edge);
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

	handle_add_edge_weighed_directed_graph(&wd_graph, Weighed_Edge {10, 2, 13});

	cout<<"wd_graph [after adding {10, 2, 13}]: \n";
	display_weighed_directed_graph(&wd_graph);
	cout<<"\n";

	handle_add_edge_weighed_directed_graph(&wd_graph, Weighed_Edge {3, 7, 15});

	cout<<"wd_graph [after adding {3, 7, 15}]: \n";
	display_weighed_directed_graph(&wd_graph);
	cout<<"\n";

	handle_add_edge_weighed_directed_graph(&wd_graph, Weighed_Edge {2, 6, 19});

	cout<<"wd_graph [after adding {2, 6, 19}]: \n";
	display_weighed_directed_graph(&wd_graph);
	cout<<"\n";

	handle_add_edge_weighed_directed_graph(&wd_graph, Weighed_Edge {-1, 2, 4});
	cout<<"\n";

	return 0;
}