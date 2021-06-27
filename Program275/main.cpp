/*
Created by  : Vaisakh Dileep
Date		: 27, June, 2021
Description : This program inserts an edge to a directed graph.
*/

#include<iostream>

#include<iomanip>

using namespace std;

struct Node
{
	int vertex;

	Node *next;
};

struct Linked_list
{
	Node *head;
};

struct Edge
{
	int vertex_1;

	int vertex_2;
};

struct Directed_Graph
{
	Linked_list **A;

	int n;
};

void display_directed_graph(Directed_Graph *d_graph)
{
	if(d_graph == nullptr)
	{
		return ;
	}

	for(int i {0}; i < d_graph->n; i++)
	{
		if(d_graph->A[i] == nullptr)
		{
			continue;
		}
		else
		{
			cout<<setw(3)<<left<<i;

			Node *last {d_graph->A[i]->head};

			while(last != nullptr)
			{
				cout<<" -> "<<setw(3)<<last->vertex;

				last = last->next;
			}
			cout<<"\n";
		}
	}
}

void add_edge_directed_graph(Directed_Graph *d_graph, Edge edge)
{

}

int main()
{
	return 0;
}