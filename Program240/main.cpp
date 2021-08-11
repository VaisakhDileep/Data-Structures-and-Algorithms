/*
Created by  : Vaisakh Dileep
Date		: 17, June, 2021
Description : This program displays an undirected graph.
*/

#include<iostream>

#include<iomanip>

#include<vector>

using namespace std;

struct Undirected_Graph
{
	vector<vector<int>*> *A;
};

struct Edge
{
	int vertex_1;

	int vertex_2;
};

void display_undirected_graph(Undirected_Graph *u_graph)
{
	if((u_graph == nullptr) or (u_graph->A == nullptr) or (u_graph->A->size() == 0))
	{
		cout<<"[\n]";

		return ;
	}

	cout<<"[\n     ";
	for(int i {0}; i < u_graph->A->size(); i++)
	{
		cout<<setw(3)<<i<<" ";
	}
	cout<<"\n";

	for(int i {0}; i < u_graph->A->size(); i++)
	{
		cout<<setw(3)<<left<<i<<right<<"[ ";
		for(int j {0}; j < u_graph->A->size(); j++)
		{
			cout<<setw(3)<<u_graph->A->at(i)->at(j)<<" ";
		}
		cout<<"]\n";
	}
	cout<<"]";
}

int main()
{
	Undirected_Graph u_graph_1 {new vector<vector<int>*> {new vector<int> {0, 1, 1, 1, 0}, new vector<int> {1, 0, 1, 0, 0}, new vector<int> {1, 1, 0, 1, 1}, new vector<int> {1, 0, 1, 0, 1}, new vector<int> {0, 0, 1, 1, 0}}};

	Undirected_Graph u_graph_2 {};

	cout<<"u_graph_1: \n";
	display_undirected_graph(&u_graph_1);
	cout<<"\n";

	cout<<"u_graph_2: \n";
	display_undirected_graph(&u_graph_2);
	cout<<"\n";

	return 0;
}