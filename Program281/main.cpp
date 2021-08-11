/*
Created by  : Vaisakh Dileep
Date		: 29, June, 2021
Description : This program deletes a weighed directed graph.
*/

#include<iostream>

#include<vector>

using namespace std;

struct Weighed_Directed_Graph
{
	vector<vector<int>*> *A;
};

struct Weighed_Edge
{
	int vertex_1;

	int vertex_2;

	int weight;
};

void delete_weighed_directed_graph(Weighed_Directed_Graph *wd_graph)
{
	if(wd_graph == nullptr)
	{
		throw string {"ERROR - Invalid operation, graph is not valid ....."};
	}

	if((wd_graph->A == nullptr) or (wd_graph->A->size() == 0))
	{
		return ;
	}

	for(int i {0}; i < wd_graph->A->size(); i++)
	{
		delete wd_graph->A->at(i);
	}

	delete wd_graph->A;
}

void handle_delete_weighed_directed_graph(Weighed_Directed_Graph *wd_graph)
{
	try
	{
		delete_weighed_directed_graph(wd_graph);
	}
	catch(string &ex)
	{
		cout<<ex;
	}
}

int main()
{
	Weighed_Directed_Graph wd_graph {new vector<vector<int>*> {new vector<int> {0, INT_MAX, 4}, new vector<int> {1, 0, INT_MAX}, new vector<int> {1, 2, 0}, new vector<int> {7, 5, INT_MAX}, new vector<int> {8, 3, 2}}};

	handle_delete_weighed_directed_graph(&wd_graph);

	return 0;
}