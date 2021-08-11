/*
Created by  : Vaisakh Dileep
Date		: 26, June, 2021
Description : This program displays a directed graph.
*/

#include<iostream>

#include<iomanip>

#include<vector>

using namespace std;

struct Directed_Graph
{
	vector<vector<int>*> *A;
};

struct Edge
{
	int vertex_1;

	int vertex_2;
};

void display_directed_graph(Directed_Graph *d_graph)
{
	if((d_graph == nullptr) or (d_graph->A == nullptr) or (d_graph->A->size() == 0))
	{
		cout<<"[\n]";

		return ;
	}

	cout<<"[\n     ";
	for(int i {0}; i < d_graph->A->at(0)->size(); i++)
	{
		cout<<setw(3)<<i<<" ";
	}
	cout<<"\n";

	for(int i {0}; i < d_graph->A->size(); i++)
	{
		cout<<setw(3)<<left<<i<<right<<"[ ";
		for(int j {0}; j < d_graph->A->at(0)->size(); j++)
		{
			cout<<setw(3)<<d_graph->A->at(i)->at(j)<<" ";
		}
		cout<<"]\n";
	}
	cout<<"]";
}

int main()
{
	Directed_Graph d_graph_1 {new vector<vector<int>*> {new vector<int> {1, 1, 0, 1}, new vector<int> {0, 0, 1, 0}, new vector<int> {1, 1, 0, 0}, new vector<int> {1, 1, 0, 0}, new vector<int> {1, 0, 0, 0}}};

	Directed_Graph d_graph_2 {};

	cout<<"d_graph_1: \n";
	display_directed_graph(&d_graph_1);
	cout<<"\n";

	cout<<"d_graph_2: \n";
	display_directed_graph(&d_graph_2);
	cout<<"\n";

	return 0;
}