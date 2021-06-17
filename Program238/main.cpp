/*
Created by  : Vaisakh Dileep
Date		: 16, June, 2021
Description : This program inserts an edge in an undirected graph.
*/

#include<iostream>

#include<iomanip>

using namespace std;

struct Undirected_Graph
{
	int **A;

	int num_nodes;
};

void display_undirected_graph(Undirected_Graph *u_graph)
{
	if(u_graph == nullptr)
	{
		cout<<"[\n]";

		return ;
	}

	cout<<"[\n     ";
	for(int i {0}; i < u_graph->num_nodes; i++)
	{
		cout<<setw(3)<<i<<" ";
	}
	cout<<"\n";

	for(int i {0}; i < u_graph->num_nodes; i++)
	{
		cout<<setw(3)<<left<<i<<right<<"[ ";
		for(int j {0}; j < u_graph->num_nodes; j++)
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

	for(int i {0}; i < u_graph->num_nodes; i++)
	{
		delete[] u_graph->A[i];
	}

	delete[] u_graph->A;
}

void add_edge_undirected_graph(Undirected_Graph *u_graph, int *edge)
{
	if(u_graph == nullptr)
	{
		throw string {"ERROR - Invalid operation, graph is not valid ....."};
	}

	if((edge[0] < 0) or (edge[1] < 0))
	{
		throw string {"ERROR - Invalid operation, given edge contains negative vertex ....."};
	}

	if((edge[0] < u_graph->num_nodes) and (edge[1] < u_graph->num_nodes))
	{
		u_graph->A[edge[0]][edge[1]] = u_graph->A[edge[1]][edge[0]] = 1;
	}
	else
	{
		int new_num_nodes {(edge[0] > edge[1]) ? edge[0] + 1 : edge[1] + 1};

		Undirected_Graph temp {new int*[new_num_nodes] {}, new_num_nodes};

		for(int i {0}; i < new_num_nodes; i++)
		{
			temp.A[i] = new int[new_num_nodes] {};
		}

		for(int i {0}; i < u_graph->num_nodes; i++)
		{
			for(int j {0}; j < u_graph->num_nodes; j++)
			{
				temp.A[i][j] = u_graph->A[i][j];
			}
		}

		temp.A[edge[0]][edge[1]] = temp.A[edge[1]][edge[0]] = 1;

		delete_undirected_graph(u_graph);

		u_graph->A = temp.A;

		u_graph->num_nodes = temp.num_nodes;
	}
}

void handle_add_edge_undirected_graph(Undirected_Graph *u_graph, int *A)
{
	try
	{
		add_edge_undirected_graph(u_graph, A);
	}
	catch(string &ex)
	{
		cout<<ex;
	}
}

int main()
{
	Undirected_Graph u_graph {new int*[5] {new int[5] {0, 1, 1, 1, 0}, new int[5] {1, 0, 1, 0, 0}, new int[5] {1, 1, 0, 1, 1}, new int [5] {1, 0, 1, 0, 1}, new int[5] {0, 0, 1, 1, 0}}, 5};

	cout<<"u_graph:\n";
	display_undirected_graph(&u_graph);
	cout<<"\n\n";

	handle_add_edge_undirected_graph(&u_graph, new int[2] {0, 4});

	cout<<"u_graph [after adding {0, 4}]: \n";
	display_undirected_graph(&u_graph);
	cout<<"\n\n";

	handle_add_edge_undirected_graph(&u_graph, new int[2] {1, 5});

	cout<<"u_graph [after adding {1, 5}]: \n";
	display_undirected_graph(&u_graph);
	cout<<"\n\n";

	handle_add_edge_undirected_graph(&u_graph, new int[2] {-1, 2});
	cout<<"\n";

	return 0;
}