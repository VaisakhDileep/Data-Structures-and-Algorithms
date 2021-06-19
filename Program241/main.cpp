/*
Created by  : Vaisakh Dileep
Date		: 17, June, 2021
Description : This program removes an edge from an undirected graph.
*/

#include<iostream>

#include<iomanip>

using namespace std;

struct Undirected_Graph
{
	int **A;

	int n;
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

void remove_edge_undirected_graph(Undirected_Graph *u_graph, int *edge)
{
	if(u_graph == nullptr)
	{
		throw string {"ERROR - Invalid operation, graph is not valid ....."};
	}

	if((edge[0] < 0) or (edge[1] < 0))
	{
		throw string {"ERROR - Invalid operation, given edge contains negative vertex ....."};
	}

	if((edge[0] >= u_graph->n) or (edge[1] >= u_graph->n))
	{
		throw string {"ERROR - Invalid operation, given edge not present in the graph ....."};
	}

	u_graph->A[edge[0]][edge[1]] = u_graph->A[edge[1]][edge[0]] = 0;
}

void handle_remove_edge_undirected_graph(Undirected_Graph *u_graph, int *edge)
{
	try
	{
		remove_edge_undirected_graph(u_graph, edge);
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
	cout<<"\n";

	handle_remove_edge_undirected_graph(&u_graph, new int[2] {0, 1});

	cout<<"u_graph: [after removing {0, 1}]: \n";
	display_undirected_graph(&u_graph);
	cout<<"\n";

	handle_remove_edge_undirected_graph(&u_graph, new int[2] {-1, 2});
	cout<<"\n";

	handle_remove_edge_undirected_graph(&u_graph, new int[2] {0, 5});
	cout<<"\n";

	return 0;
}