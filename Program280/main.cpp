/*
Created by  : Vaisakh Dileep
Date		: 28, June, 2021
Description : This program displays a weighed directed graph.
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

int main()
{
	Weighed_Directed_Graph wd_graph {new int*[5] {new int[3] {0, 0, 4}, new int[3] {1, 0, 0}, new int[3] {1, 2, 0}, new int[3] {7, 5, 0}, new int[3] {8, 3, 2}}, 5, 3};

	cout<<"wd_graph: \n";
	display_weighed_directed_graph(&wd_graph);
	cout<<"\n";

	return 0;
}