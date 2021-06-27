/*
Created by  : Vaisakh Dileep
Date		: 26, June, 2021
Description : This program displays a directed graph.
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

int main()
{
	Directed_Graph d_graph_1 {new int*[5] {new int[4] {0, 1, 0, 1}, new int[4] {0, 0, 1, 0}, new int[4] {1, 1, 0, 0}, new int[4] {1, 1, 0, 0}, new int[4] {1, 0, 0, 0}}, 5, 4};

	Directed_Graph d_graph_2 {};

	cout<<"d_graph_1:\n";
	display_directed_graph(&d_graph_1);
	cout<<"\n";

	cout<<"d_graph_2:\n";
	display_directed_graph(&d_graph_2);
	cout<<"\n";

	return 0;
}