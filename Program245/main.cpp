/*
Created by  : Vaisakh Dileep
Date		: 19, June, 2021
Description : This program displays a weighed undirected graph.
*/

#include<iostream>

#include<iomanip>

using namespace std;

struct Weighed_Undirected_Graph
{
	int **A;

	int n;
};

struct Weighed_Edge
{
	int vertex_1;

	int vertex_2;

	int weight;
};

void display_weighed_undirected_graph(Weighed_Undirected_Graph *wu_graph)
{
	if(wu_graph == nullptr)
	{
		cout<<"[\n]";

		return ;
	}

	cout<<"[\n     ";
	for(int i {0}; i < wu_graph->n; i++)
	{
		cout<<setw(3)<<i<<" ";
	}
	cout<<"\n";

	for(int i {0}; i < wu_graph->n; i++)
	{
		cout<<setw(3)<<left<<i<<right<<"[ ";
		for(int j {0}; j < wu_graph->n; j++)
		{
			cout<<setw(3)<<wu_graph->A[i][j]<<" ";
		}
		cout<<"]\n";
	}
	cout<<"]";
}

int main()
{
	Weighed_Undirected_Graph wu_graph {new int*[5] {new int[5] {0, 3, 0, 0, 7}, new int[5] {3, 0, 0, 0, 0}, new int[5] {0, 0, 0, 8, 0}, new int[5] {0, 0, 8, 0, 0}, new int[5] {7, 0, 0, 0, 0}}, 5};

	cout<<"wu_graph: \n";
	display_weighed_undirected_graph(&wu_graph);
	cout<<"\n";

	return 0;
}