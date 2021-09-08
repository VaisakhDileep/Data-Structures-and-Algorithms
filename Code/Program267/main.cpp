/*
Created by  : Vaisakh Dileep
Date		: 26, June, 2021
Description : This program deletes a directed graph.
*/

#include<iostream>

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

void delete_directed_graph(Directed_Graph *d_graph)
{
	if(d_graph == nullptr)
	{
		throw string {"ERROR - Invalid operation, graph is not valid ....."};
	}

	if((d_graph->A == nullptr) or (d_graph->A->size() == 0))
	{
		return ;
	}

	for(int i {0}; i < d_graph->A->size(); i++)
	{
		delete d_graph->A->at(i);
	}

	delete d_graph->A;
}

void handle_delete_directed_graph(Directed_Graph *d_graph)
{
	try
	{
		delete_directed_graph(d_graph);
	}
	catch(string &ex)
	{
		cout<<ex;
	}
}

int main()
{
	Directed_Graph d_graph {new vector<vector<int>*> {new vector<int> {1, 1, 0, 1}, new vector<int> {0, 0, 1, 0}, new vector<int> {1, 1, 0, 0}, new vector<int> {1, 1, 0, 0}, new vector<int> {1, 0, 0, 0}}};

	handle_delete_directed_graph(&d_graph);

	return 0;
}