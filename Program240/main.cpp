/*
Created by  : Vaisakh Dileep
Date		: 17, June, 2021
Description : This program displays an undirected graph.
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

int main()
{
	Undirected_Graph u_graph_1 {new int*[5] {new int[5] {0, 1, 1, 1, 0}, new int[5] {1, 0, 1, 0, 0}, new int[5] {1, 1, 0, 1, 1}, new int [5] {1, 0, 1, 0, 1}, new int[5] {0, 0, 1, 1, 0}}, 5};

	Undirected_Graph u_graph_2 {};

	cout<<"u_graph_1:\n";
	display_undirected_graph(&u_graph_1);
	cout<<"\n";

	cout<<"u_graph_2:\n";
	display_undirected_graph(&u_graph_2);
	cout<<"\n";

	return 0;
}